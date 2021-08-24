#include "Model.h"

#include <iostream>
#include <string>
#include <sstream>

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

std::vector<Face> Model::getFaces() const
{
	return faces;
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

void Model::setFaces(std::vector<Face> fac)
{
	faces = fac;
}

void Model::setVertices(Vector3 vert)
{
	vertices.push_back(vert);
}

void Model::setNormals(Vector3 norm)
{
	normals.push_back(norm);
}

void Model::setTextures(Vector3 text)
{
	textures.push_back(text);
}

void Model::setFaces(Face fac)
{
	faces.push_back(fac);
}


std::istream& operator>>(std::istream& input, Model& M)
{
	while (input)
	{
		std::string header;
		std::string dump;

		input >> header;

		if (header == "v")
		{
			Vector3 vertex;
			float x, y, z;

			input >> x >> y >> z;

			vertex.SetX(x);
			vertex.SetY(y);
			vertex.SetZ(z);

			M.setVertices(vertex);
		}
		else if (header == "vn")
		{
			Vector3 vertexNormal;
			float x, y, z;

			input >> x >> y >> z;

			vertexNormal.SetX(x);
			vertexNormal.SetY(y);
			vertexNormal.SetZ(z);

			M.setNormals(vertexNormal);
		}
		else if (header == "vt")
		{
			Vector3 vertexTexture;
			float x, y;

			input >> x >> y;

			vertexTexture.SetX(x);
			vertexTexture.SetY(y);

			M.setTextures(vertexTexture);
		}
		else if (header == "f")
		{
			indexes tempIndex;
			std::vector<indexes> tempFace;
			Face tempFaceObj;

			std::string str;

			std::getline(input >> std::ws, str);

			std::stringstream token(str);

			while (std::getline(token, str, ' '))
			{
				std::stringstream tempStr;
				tempStr << str;

				std::string singleToken;

				getline(tempStr, singleToken, '/');
				tempIndex.v = std::stoi(singleToken);
				
				getline(tempStr, singleToken, '/');
				tempIndex.vn = std::stoi(singleToken);
				
				getline(tempStr, singleToken);
				tempIndex.vt = std::stoi(singleToken);

				tempFace.push_back(tempIndex);
			}

			tempFaceObj.setFace(tempFace);
			
			M.setFaces(tempFaceObj);
		}
		else
		{
			getline(input, dump);
		}
	}
}