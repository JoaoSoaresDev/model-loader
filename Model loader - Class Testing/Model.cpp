#include "Model.h"

#include <iostream>

std::vector<Vector3> Model::getVertices() const
{
	return vertices;
}

std::vector<Vector3> Model::getNormals() const
{
	return normals;
}

std::vector<Vector3> Model::getTextures() const
{
	return textures;
}

void Model::setVertices(std::vector<Vector3> vert)
{
	vertices = vert;
}

void Model::setNormals(std::vector<Vector3> norm)
{
	normals = norm;
}

void Model::setTextures(std::vector<Vector3> text)
{
	textures = text;
}

void Model::loadModel(FILE& file)
{
	while (1)
	{
		char header[128];

		int res = fscanf(&file, "%s", header);
		if (res == EOF)
			break;

		if (strcmp(header, "v") == 0)
		{
			Vector3 vertex;
			float x, y, z;
			fscanf(&file, "%f %f %f\n", &x, &y, &z);
			vertex.SetX(x);
			vertex.SetY(y);
			vertex.SetZ(z);
			vertices.push_back(vertex);
			std::cout << vertex.GetX() << " " << vertex.GetY() << " " << vertex.GetZ() << std::endl;
		}	
		else if (strcmp(header, "vn") == 0)
		{
			Vector3 vertexNormal;
			float x, y, z;
			fscanf(&file, "%f %f %f\n", &x, &y, &z);
			vertexNormal.SetX(x);
			vertexNormal.SetY(y);
			vertexNormal.SetZ(z); 
			normals.push_back(vertexNormal);
			std::cout << vertexNormal.GetX() << " " << vertexNormal.GetY() << " " << vertexNormal.GetZ() << std::endl;
		}
		else if (strcmp(header, "vt") == 0)
		{
			Vector3 vertexTexture;
			float x, y;
			fscanf(&file, "%f %f\n", &x, &y);
			vertexTexture.SetX(x);
			vertexTexture.SetY(y);
			textures.push_back(vertexTexture);
			std::cout << vertexTexture.GetX() << " " << vertexTexture.GetY() << std::endl;
		}
		else if (strcmp(header, "f") == 0)
		{
			
		}
		else
		{

		}


	}

}
