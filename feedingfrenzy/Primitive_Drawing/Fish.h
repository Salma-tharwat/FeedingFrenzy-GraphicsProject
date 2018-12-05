#pragma once
#include <gl/glew.h>
#include "shader.hpp"
#include<GL/glfw3.h>

// Include GLM
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include "FPCamera.h"
#include "texture.h"
#include <string>

using namespace std;
class Fish
{
public:
    void moveUP();
	void moveDOWN();
	void moveRIGHT();
	void moveLEFT();


	void Fish::drawfish(GLuint programID, glm::mat4 projection, glm::mat4 view);
	Fish::Fish(const GLfloat points[], string texture, float size, float speed, GLuint PointSize);
	~Fish();
private:
	GLuint pointSize;
	GLuint vertexBuffer;
	Texture *mtextute;
	float fish_size;
	float speed;
	glm::mat4 MVP;
	glm::mat4 trans;
	
};

