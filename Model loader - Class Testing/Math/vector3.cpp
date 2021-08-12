#include "vector3.h"

using namespace Math;

Vector3::Vector3(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3::Vector3(const Vector3& other)
{
	this->x = other.x;
	this->y = other.y;
	this->z = other.z;
}

Vector3& Vector3::operator=(const Vector3& rhs)
{
	if (this == &rhs) return *this; // handle self assignment
	//assignment operator
	this->x = rhs.x;
	this->y = rhs.y;
	this->z = rhs.z;
	return *this;
}
float Vector3::Dot(const Vector3& other) const
{
	return this->x * other.x + this->y * other.y + this->z * other.z;
}
Vector3 Vector3::Cross(const Vector3& rhs) const
{
	return Vector3(this->y * rhs.z - this->z * rhs.y, this->z * rhs.x - this->x * rhs.z, this->x * rhs.y - this->y * rhs.x);
}
Vector3 Vector3::operator+(const Vector3& other) const
{
	return Vector3(this->x + other.x, this->y + other.y, this->z + other.z);
}
Vector3 Vector3::operator-() const
{
	return Vector3(-this->x, -this->y, -this->z);
}
Vector3 Vector3::operator-(const Vector3& rhs) const
{
	return *this + (-rhs);
}
Vector3 Vector3::operator*(float other) const
{
	return Vector3(this->x * other, this->y * other, this->z * other);
}
Vector3 Vector3::operator/(float rhs) const
{
	return *this * (1 / rhs);
}
float Vector3::Magnitude() const
{
	return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
}
Vector3 Vector3::Normalised() const
{
	return *this / this->Magnitude();
}
Vector3& Vector3::operator+=(const Vector3& rhs)
{
	*this = *this + rhs;
	return *this;
}
Vector3& Vector3::operator-=(const Vector3& rhs)
{
	*this = *this - rhs;
	return *this;
}
Vector3& Vector3::operator*=(float rhs)
{
	*this = *this * rhs;
	return *this;
}
Vector3& Vector3::operator/=(float rhs)
{
	*this = *this / rhs;
	return *this;
}
bool Vector3::operator==(const Vector3& other) const
{
	return this->x == other.x && this->y == other.y && this->z == other.z;
}
