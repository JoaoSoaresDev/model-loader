#include "unit_quaternion.h"

using namespace Math;

UnitQuaternion::UnitQuaternion()
{
	this->w = 1;
	this->v = Vector3(0, 0, 0);
}
UnitQuaternion::UnitQuaternion(float w, const Vector3& v)
{
	this->w = w;
	this->v = v;
}
UnitQuaternion UnitQuaternion::AngleAxis(float deg, Vector3 axis)
{
    return UnitQuaternion(cos(deg / 2), axis * (float)(sin(deg / 2)));
}
UnitQuaternion UnitQuaternion::Euler(Vector3 degs)
{
	return UnitQuaternion::AngleAxis(degs.GetX(), Vector3(1, 0, 0))
	* UnitQuaternion::AngleAxis(degs.GetY(), Vector3(0, 1, 0))
	* UnitQuaternion::AngleAxis(degs.GetZ(), Vector3(0, 0, 1));

}
UnitQuaternion::UnitQuaternion(const UnitQuaternion& other)
{
	this->w = other.w;
	this->v = other.v;
}

UnitQuaternion& UnitQuaternion::operator=(const UnitQuaternion& rhs)
{
	if (this == &rhs) return *this; // handle self assignment
	//assignment operator
	this->w = rhs.w;
	this->v = rhs.v;
	return *this;
}
UnitQuaternion UnitQuaternion::operator*(const UnitQuaternion& rhs) const
{
	return UnitQuaternion(this->w * rhs.w - this->v.Dot(rhs.v), this->v.Cross(rhs.v) + rhs.v * this->w + this->v * rhs.w);
}
UnitQuaternion& UnitQuaternion::operator*=(const UnitQuaternion& rhs)
{
	*this = *this * rhs;
	return *this;
}
UnitQuaternion UnitQuaternion::Conjugate() const
{
	return UnitQuaternion(this->w, -this->v);
}
Vector3 UnitQuaternion::operator*(const Vector3& rhs) const
{
	return (*this * UnitQuaternion(0, rhs) * this->Conjugate()).v;
}
bool UnitQuaternion::operator==(const UnitQuaternion& other) const
{
	return this->w == other.w && this->v == other.v;
}
