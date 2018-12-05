#include <gl/glew.h>
#include "shader.hpp"
#include<GL/glfw3.h>
// Include GLM
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

#include "FPCamera.h"
#include "texture.h"
#include "Fish.h"

#include <vector>
#include <iostream>

class Renderer
{
    GLuint vertexArrayID;
    GLuint programID;
	// 3D Drawing
	glm::mat4 ProjectionMatrix;
	glm::mat4 ViewMatrix;

    std::vector<Fish> Fishes;
	FPCamera cam;
	double time;
public:
    void Update();
    Renderer();
    ~Renderer();
	void HandleMouseClick(double,double);
	void HandleKeyboardInput(int);
    void Initialize();
    void Draw();
    void Cleanup();
};
