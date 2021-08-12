#pragma once

#include <limits>
#include <cmath>

namespace Math
{
		/** Approximate equal comparison
		 *  \param lhs Left hand float argument
		 *  \param rhs Right hand float argument
		 *  \param tol Tolerence positive float range
		 *  \return True if lhs and rhs difference is lesser than tol
		 */
		template <class T>
		bool Approx(T a, T b, T tol = std::numeric_limits<T>::epsilon()) { return std::abs(a - b) <= tol; }
};
