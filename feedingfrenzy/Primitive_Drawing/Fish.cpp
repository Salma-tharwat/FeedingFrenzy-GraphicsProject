#include "Fish.h"

Fish::Fish(const GLfloat points[], string texture, float size, float speed, GLuint PointSize)
{
	this->pointSize = PointSize / sizeof(float);
	glGenBuffers(1, &this->vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, this->vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, PointSize, points, GL_STATIC_DRAW);
	mtextute = new Texture(texture, 1);
	this->fish_size = size;
	this->speed = speed;
	trans = glm::mat4(1);
}

void Fish::moveUP()
{
     trans*=glm::translate(0.0f,1.0f,0.0f);
}

void Fish::moveDOWN()
{
	trans *= glm::translate(0.0f, -1.0f, 0.0f);
}

void Fish::moveRIGHT()
{
	trans *= glm::translate(-1.0f, 0.0f, 0.0f);
}
void Fish::moveLEFT()
{
	trans *= glm::translate(1.0f, 0.0f, 0.0f);
}

void Fish::drawfish(GLuint programID, glm::mat4 projection, glm::mat4 view)
{
	glBindBuffer(GL_ARRAY_BUFFER, this->vertexBuffer);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (char*)(sizeof(float) * 3));

	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (char*)(sizeof(float) * 6));

	glm::mat4 model = glm::mat4(1);
	model *= trans;
	model *= glm::scale(fish_size, fish_size, 1.0f);
	MVP = projection * view * model;
	GLuint MVP_ID = glGetUniformLocation(programID, "MVP");
	glUniformMatrix4fv(MVP_ID, 1, GL_FALSE, &MVP[0][0]);
	mtextute->Bind();
	glDrawArrays(GL_TRIANGLE_FAN, 0, 22);
	glDrawArrays(GL_TRIANGLE_FAN, 23, 4);
	glDrawArrays(GL_TRIANGLE_FAN, 27, 4);
	glPointSize(10);
	glDrawArrays(GL_POINTS,31, 1);
	glDrawArrays(GL_TRIANGLE_FAN, 32, 4);

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(2);
}


Fish::~Fish()
{
	//delete mtextute;
}
