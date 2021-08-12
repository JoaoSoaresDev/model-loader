#ifndef VECTOR3_H
#define VECTOR3_H
#include <cmath>

namespace Math
{
	/** Stores 3D points and vectors along with common vector operations
	 *  @author Rhys Mader 33705134
	 */
	class Vector3
	{
	public:
		/** Default constructor
		 *  \param x The x component
		 *  \param y The y component
		 *  \param z The z component
		 */
		Vector3(float x = 0, float y = 0, float z = 0);
		/** Copy constructor
		 *  \param other Object to copy from
		 */
		Vector3(const Vector3& other);
		/** Assignment operator
		 *  \param other Object to assign from
		 *  \return A reference to this
		 */
		Vector3& operator=(const Vector3& other);
		/** Access x
		 * \return The current value of x
		 */
		float GetX() const { return x; }
		/** Set x
		 * \param val New value to set
		 */
		void SetX(float val) { x = val; }
		/** Access y
		 * \return The current value of y
		 */
		float GetY() const { return y; }
		/** Set y
		 * \param val New value to set
		 */
		void SetY(float val) { y = val; }
		/** Access z
		 * \return The current value of z
		 */
		float GetZ() const { return z; }
		/** Set z
		 * \param val New value to set
		 */
		void SetZ(float val) { z = val; }
		/** Dot product operator
		 *  \param other Other Vector3 argument
		 *  \return Float dot product of this and other
		 */
		float Dot(const Vector3& other) const;
		/** Cross product operator
		 *  \param rhs Right hand Vector3 argument
		 *  \return Vector3 cross product of this and rhs
		 */
		Vector3 Cross(const Vector3& rhs) const;
		/** Addition operator
		 *  \param other Other Vector3 argument
		 *  \return Vector3 sum of this and other
		 */
		Vector3 operator+(const Vector3& other) const;
		/** Subtraction operator
		 *  \param rhs Right hand Vector3 argument
		 *  \return Vector3 difference of this and other
		 */
		Vector3 operator-(const Vector3& rhs) const;
		/** Scalar multiply operator
		 *  \param other Other scalar float argument
		 *  \return Vector3 scalar product of this and other
		 */
		Vector3 operator*(float other) const;
		/** Scalar divide operator
		 *  \param rhs Right hand scalar float argument
		 *  \return Vector3 quotient of this and rhs
		 */
		Vector3 operator/(float rhs) const;
		/** Negation operator
		 *  \return Vector3 negation of this
		 */
		Vector3 operator-() const;
		/** Vector magnitude
		 *  \return Float magnitude of this
		 */
		float Magnitude() const;
		/** Normalized vector
		 *  \return Vector3 normalised copy of this
		 */
		Vector3 Normalised() const;
		/** Addition assignment operator
		 *  \param rhs Right hand argument
		 *  \return This Vector3
		 */
		Vector3& operator+=(const Vector3& rhs);
		/** Subtraction asignment operator
		 *  \param rhs Right hand argument
		 *  \return This Vector3
		 */
		Vector3& operator-=(const Vector3& rhs);
		/** Scalar multiply assignment operator
		 *  \param rhs Scalar right hand argument
		 *  \return This Vector3
		 */
		Vector3& operator*=(float rhs);
		/** Scalar divide assignment operator
		 *  \param rhs Scalar right hand argument
		 *  \return This Vector3
		 */
		Vector3& operator/=(float rhs);
		/** Value equality comparison operator
		 *  \param other Other vector to compare
		 *  \return True if this and other are equal, false otherwise
		 */
		bool operator==(const Vector3& other) const;
		/** Component-wise multiplication
		 *  \param other Other Vector3 argument
		 *  \return Component-wise product of this and other
		 */
		Vector3& Scale(const Vector3& other) const;
	protected:
	private:
		float x; //!< Member variable "x"
		float y; //!< Member variable "y"
		float z; //!< Member variable "z"
	};
}

#endif // VECTOR3_H
