/*****************************************************************//**
 * @file   Face.h
 * @brief  Class to store data related to one face
 * 
 * @author Joao Soares
 * @date   14 August 2021
 *********************************************************************/
#pragma once

#include "Math/vector3.h"

#include <vector>
#include <sstream>
#include <iostream>

using namespace Math;

/**
 * 
 */
struct indexes
{
	int v, vn, vt;

};


class Face
{
private:

	/// Vector to store indexes of one face
	std::vector<indexes> face;

public:

	/**
	 * @brief	Acessor for face vector
	 * 
	 * @return  Vector of indexes
	 */
	std::vector<indexes> getFace() const;

	/**
	 * @brief	Mutator for face vector
	 * 
	 * @param	fac - vector of indexes
	 * @return	void
	 */
	void setFace(std::vector<indexes> fac);

};