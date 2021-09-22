#include "object.h"
#include <stdio.h>

Object::Object(char* path, float scale, float orbitSpeed, float spinSpeed, Object *p)
{  
  /*
    # Blender File for a Cube
    o Cube
    v 1.000000 -1.000000 -1.000000
    v 1.000000 -1.000000 1.000000
    v -1.000000 -1.000000 1.000000
    v -1.000000 -1.000000 -1.000000
    v 1.000000 1.000000 -0.999999
    v 0.999999 1.000000 1.000001
    v -1.000000 1.000000 1.000000
    v -1.000000 1.000000 -1.000000
    s off
    f 2 3 4
    f 8 7 6
    f 1 5 6
    f 2 6 7
    f 7 8 4
    f 1 4 8
    f 1 2 4
    f 5 8 6
    f 2 1 6
    f 3 2 7
    f 3 7 4
    f 5 1 8
  

  Vertices = {
    {{1.0f, -1.0f, -1.0f}, {0.0f, 0.0f, 0.0f}},
    {{1.0f, -1.0f, 1.0f}, {1.0f, 0.0f, 0.0f}},
    {{-1.0f, -1.0f, 1.0f}, {0.0f, 1.0f, 0.0f}},
    {{-1.0f, -1.0f, -1.0f}, {0.0f, 0.0f, 1.0f}},
    {{1.0f, 1.0f, -1.0f}, {1.0f, 1.0f, 0.0f}},
    {{1.0f, 1.0f, 1.0f}, {1.0f, 0.0f, 1.0f}},
    {{-1.0f, 1.0f, 1.0f}, {0.0f, 1.0f, 1.0f}},
    {{-1.0f, 1.0f, -1.0f}, {1.0f, 1.0f, 1.0f}}
  };

  Indices = {
    2, 3, 4,
    8, 7, 6,
    1, 5, 6,
    2, 6, 7,
    7, 8, 4,
    1, 4, 8,
    1, 2, 4,
    5, 8, 6,
    2, 1, 6,
    3, 2, 7,
    3, 7, 4,
    5, 1, 8
  };*/
  
  bool res = loadOBJ(path, Vertices, Indices);
  
  // The index works at a 0th index
  /*for(unsigned int i = 0; i < Indices.size(); i++)
  {
    Indices[i] = Indices[i] - 1;
  }*/
	
 
  
  rot_angle = 0.0f;
  spin_angle = 0.0f;
  rev_Orbit = false;
  pauseOrbit = false;
  rev_Spin = false;
  pauseSpin = false;
  position = glm::mat4(1.0f);
  
  defaultScale = scale;
  scaleMultiplier = 1.0f;
  maxScale = 3.0f;
  minScale = 0.25f;
  
  defaultOrbSpeed = orbitSpeed;
  defaultSpinSpeed = spinSpeed;
  orbSpeedMultiplier = 1.0f;
  spinSpeedMultiplier = 1.0f;
  maxSpeed = 3.0f;
  minSpeed = 0.25f;
  
  parent = p;

  glGenBuffers(1, &VB);
  glBindBuffer(GL_ARRAY_BUFFER, VB);
  glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * Vertices.size(), &Vertices[0], GL_STATIC_DRAW);

  glGenBuffers(1, &IB);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IB);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * Indices.size(), &Indices[0], GL_STATIC_DRAW);
}

Object::~Object()
{
  Vertices.clear();
  Indices.clear();
}

void Object::Update(unsigned int dt, glm::mat4 origin)
{
	spin_angle += dt * M_PI/(defaultSpinSpeed /  spinSpeedMultiplier);
	/*if(parent != nullptr)
	{
		model = parent->GetModel();
	}
	//when buttons pressed bool value changes
	if(!pauseOrbit)
	{
		if(rev_Orbit)//if orbit not paused and key to reverse orbit is pressed
		{
			rot_angle -= dt * M_PI/(defaultOrbSpeed / orbSpeedMultiplier);
		}
		else
		{
			rot_angle += dt * M_PI/(defaultOrbSpeed / orbSpeedMultiplier);
		}
	}
	if(!pauseSpin)
	{
		if(rev_Spin)//checking if both not paused and reverse spin key is pressed change based on reverse orbit value
		{
			if(rev_Orbit)
			{
				spin_angle -= 2 * dt * M_PI/(defaultSpinSpeed /  spinSpeedMultiplier);
			}
			else if(!rev_Orbit)
			{
				spin_angle -= 3 * dt * M_PI/(defaultSpinSpeed /  spinSpeedMultiplier);
			}
		}
		else
		{
			if(rev_Orbit)
			{	
				spin_angle += 2 * dt * M_PI/(defaultSpinSpeed /  spinSpeedMultiplier);
			}
			else
			{
				spin_angle += dt * M_PI/(defaultSpinSpeed /  spinSpeedMultiplier);	
			}
		}
	}
	else
	{
		spin_angle -= dt * M_PI/(defaultSpinSpeed /  spinSpeedMultiplier);
	}
  
	position = glm::translate(origin, glm::vec3((5.0f * sin(rot_angle)), 0.0f, (5.0f * cos(rot_angle))));
	glm::mat4 rotate = glm::rotate(glm::mat4(1.0f), spin_angle, glm::vec3(0.0, 1.0, 0.0));
	glm::mat4 scale = glm::scale(glm::vec3((scaleMultiplier * defaultScale), (scaleMultiplier * defaultScale), (scaleMultiplier * defaultScale)));
	
	model = position * rotate * scale;*/
	
	model = glm::rotate(model, spin_angle, glm::vec3(0.0f, 1.0f, 0.0f));
		
}

glm::mat4 Object::GetModel()
{
	return model;
}

glm::mat4 Object::GetPosition()
{
	return position;
}

void Object::Render()
{
  glEnableVertexAttribArray(0);
  glEnableVertexAttribArray(1);

  glBindBuffer(GL_ARRAY_BUFFER, VB);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex,color));

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IB);

  glDrawElements(GL_TRIANGLES, Indices.size(), GL_UNSIGNED_INT, 0);

  glDisableVertexAttribArray(0);
  glDisableVertexAttribArray(1);
}

void Object::Scale(bool scalar)
{
	if(scalar)
	{
		if(scaleMultiplier + 0.25f > maxScale)
		{
			scaleMultiplier = maxScale;
		}
		else
		{
			scaleMultiplier += 0.25f;
		}
	}
	else
	{
		if(scaleMultiplier + 0.25f < minScale)
		{
			scaleMultiplier = minScale;
		}
		else
		{
			scaleMultiplier -= 0.25f;
		}
	}
}

void Object::OrbitSpeed(bool speed)
{
	if(speed)
	{
		if(orbSpeedMultiplier + 0.25f > maxSpeed)
		{
			orbSpeedMultiplier = maxSpeed;
		}
		else
		{
			orbSpeedMultiplier += 0.25f;
		}
	}
	else
	{
		if(orbSpeedMultiplier - 0.25f < minSpeed)
		{
			orbSpeedMultiplier = minSpeed;
		}
		else
		{
			orbSpeedMultiplier -= 0.25f;
		}
	}
}

void Object::SpinSpeed(bool speed)
{
	if(speed)
	{
		if(spinSpeedMultiplier + 0.25f > maxSpeed)
		{
			spinSpeedMultiplier = maxSpeed;
		}
		else
		{
			spinSpeedMultiplier += 0.25f;
		}
	}
	else
	{
		if(spinSpeedMultiplier - 0.25f < minSpeed)
		{
			spinSpeedMultiplier = minSpeed;
		}
		else
		{
			spinSpeedMultiplier -= 0.25f;
		}
	}
}

bool Object::loadOBJ(char* path, std::vector<glm::vec3> & out_vertices, std::vector<unsigned int> & out_indices)
{
  	std::vector<unsigned int> vertexIndices;
	std::vector<glm::vec3> temp_vertices; 
	std::vector<unsigned int> temp_indices;
  	bool blenderFormat = 1; //if first format works, blenderFormat = 1, else blenderFormat = 0;

	FILE * file = fopen(path, "r");
	if( file == NULL ){
		printf("There was an error opening the object file!\n");
		getchar();
		return false;
	}

	while( 1 ){

		char lineHeader[128];
		// read the first word of the line
		int res = fscanf(file, "%s", lineHeader);
		if (res == EOF)
			break; // EOF = End Of File. Quit the loop.

		// else : parse lineHeader
		
		if ( strcmp( lineHeader, "v" ) == 0 ){
			glm::vec3 vertex;
			fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z );
			temp_vertices.push_back(vertex);
		}else if ( strcmp( lineHeader, "f" ) == 0 ){
			std::string vertex1, vertex2, vertex3;
			unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
			int matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &vertexIndex[0], &uvIndex[0], &normalIndex[0], &vertexIndex[1], &uvIndex[1], &normalIndex[1], &vertexIndex[2], &uvIndex[2], &normalIndex[2] );
			if (matches != 9){
				printf("File can't be read by our simple parser :-( Try exporting with other options\n");
				fclose(file);
				return false;
			}
			Indices.push_back(vertexIndex[0]);
			Indices.push_back(vertexIndex[1]);
			Indices.push_back(vertexIndex[2]);
		}else{
			// Probably a comment, eat up the rest of the line
			char stupidBuffer[1000];
			fgets(stupidBuffer, 1000, file);
		}

	}

	// For each vertex of each triangle
	for( unsigned int i=0; i<vertexIndices.size(); i++ ){

		// Get the indices of its attributes
		unsigned int vertexIndex = vertexIndices[i];
		
		// Get the attributes thanks to the index
		glm::vec3 vertex = temp_vertices[ vertexIndex-1 ];
		
		// Put the attributes in buffers
		out_vertices.push_back(vertex);
	
	}
	fclose(file);
	return true;
}
