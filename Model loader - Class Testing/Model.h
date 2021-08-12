#include <vector>
#include <fstream>

#include "Math/vector3.h"

using namespace Math;

class Model
{
private: 
	
	// A vector to store vertices
	std::vector<Vector3> vertices;

	// A vector to store faces
	//std::vector<Vector3> faces;

	// A vector to store vertex textures
	std::vector<Vector3> textures;

	// A vector to store vertex normals
	std::vector<Vector3> normals;

public:
	Model()
	{

	}

	~Model()
	{

	}

	std::vector<Vector3> getVertices() const;
	
	std::vector<Vector3> getNormals() const;
	
	std::vector<Vector3> getTextures() const;

	void setVertices(std::vector<Vector3> vert);

	void setNormals(std::vector<Vector3> norm);

	void setTextures(std::vector<Vector3> text);

	void loadModel(FILE &file);

};

