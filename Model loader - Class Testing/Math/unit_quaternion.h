#ifndef UNITQUATERNION_H
#define UNITQUATERNION_H

#include "vector3.h"

namespace Math 
{
	/** Quaternion class for storing and manipulating rotations
	 *  \author Rhys Mader 33705134
	 */
	class UnitQuaternion
	{
	public:
		/** Default constructor */
		UnitQuaternion();
		/** Construct UnitQuaternion from angle and axis
		 *  \param deg Angle of rotation in degrees
		 *  \param axis Axis of rotation
		 *  \return Constructed UnitQuaternion
		 */
		static UnitQuaternion AngleAxis(float deg, Vector3 axis);
		/** Construct UnitQuaternion from euler rotations z, y, then x
		 *  \param degs Vector3 of the rotation angles in degrees around each axis
		 *  \return Constructed UnitQuaternion
		 */
		static UnitQuaternion Euler(Vector3 degs);
		/** Copy constructor
		 *  \param other Object to copy from
		 */
		UnitQuaternion(const UnitQuaternion& other);
		/** Assignment operator
		 *  \param other Object to assign from
		 *  \return A reference to this
		 */
		UnitQuaternion& operator=(const UnitQuaternion& other);
		/** W getter
		 *  \return Float w
		 */
		float GetW() const { return this->w; }
		/** V getter
		 *  \return Vector3 v
		 */
		const Vector3& GetV() const { return this->v; }
		/** Combine rotations in sequence
		 *  \param rhs The rotation performed after this
		 *  \return Product of this and rhs
		 */
		UnitQuaternion operator*(const UnitQuaternion& rhs) const;
		/** Apply rotation to this
		 *  \param rhs The rotation to apply
		 *  \return This after combining rotations
		 */
		UnitQuaternion& operator*=(const UnitQuaternion& rhs);
		/** Quaternion conjugate
		 *  \return The conjugate of this
		 *  \note Also the inverse as the norm is 1
		 */
		UnitQuaternion Conjugate() const;
		/** Rotate rhs by this
		 *  \param rhs The Vector3 to rotate
		 *  \return The rhs after rotion by this
		 */
		Vector3 operator*(const Vector3& rhs) const;
		/** Value equality comparison
		 *  \param other The other UnitQuaternion to compare with this
		 *  \return True if this and other are equal by value, false otherwise
		 */
		bool operator==(const UnitQuaternion& other) const;
	protected:
	private:
		UnitQuaternion(float w, const Vector3& v);
		float w;
		Vector3 v;
	};
}
#endif // UNITQUATERNION_H
