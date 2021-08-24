/*****************************************************************//**
 * @file    Model.h
 * @brief   Class to load and store data related to a single model
 * @biref   This class reads data from files with OBJ format only
 * 
 * @author  Joao Soares
 * @version 1
 * @date    12 August 2021
 *********************************************************************/

#include <vector>
#include <fstream>

#include "Math/vector3.h"
#include "Face.h"

using namespace Math;

class Model
{
private: 
	
	/// Vector to store vertices
	std::vector<Vector3> vertices;

	/// Vector to store faces
	std::vector<Face> faces;

	/// Vector to store vertex textures
	std::vector<Vector3> textures;

	/// Vector to store vertex normals
	std::vector<Vector3> normals;

public:

	/**
	 * @brief Constructor
	 * 
	 */
	Model() {}

	/**
	 * @brief Deconstructor
	 * 
	 */
	~Model() {}

	/**
	 * @brief Acessor for vector vertices
	 * 
	 * @return vector of vertices
	 */
	std::vector<Vector3> getVertices() const;
	
	/**
	 * @brief Accessor for vector of normals
	 * 
	 * @return vector of normals 
	 */
	std::vector<Vector3> getNormals() const;
	
	/**
	 * @brief Acessor for vector of textures
	 * 
	 * @return vector of textures 
	 */
	std::vector<Vector3> getTextures() const;

	/**
	 * @brief Accessor for vector of faces
	 * 
	 * @return vector of faces 
	 */
	std::vector<Face> getFaces() const;

	/**
	 * @brief	Mutator, assigns whole vector to param
	 *
	 * @param	vert
	 * @return	void
	 */
	void setVertices(std::vector<Vector3> vert);

	/**
	 * @brief	Mutator, assigns whole vector to param
	 *
	 * @param	norm
	 * @return	void
	 */
	void setNormals(std::vector<Vector3> norm);

	/**
	 * @brief	Mutator, assigns whole vector to param
	 *
	 * @param	text
	 * @return	void
	 */
	void setTextures(std::vector<Vector3> text);

	/**
	 * @brief	Mutator, assigns whole vector to param
	 *
	 * @param	fac
	 * @return	void
	 */
	void setFaces(std::vector<Face> fac);

	/**
	 * @brief	Insert a new Vector3 to vertices vector
	 * 
	 * @param	vert
	 * @return	void
	 */
	void setVertices(Vector3 vert);

	/**
	 * @brief	Insert a new Vector3 to normals vector
	 *
	 * @param	norm
	 * @return	void
	 */
	void setNormals(Vector3 norm);

	/**
	 * @brief	Insert a new Vector3 to texture vector
	 *
	 * @param	text
	 * @return	void
	 */
	void setTextures(Vector3 text);

	/**
	 * @brief	Insert a new Face to faces vector
	 *
	 * @param	fac
	 * @return	void
	 */
	void setFaces(Face fac);
};

std::istream& operator>>(std::istream& input, Model& M);
