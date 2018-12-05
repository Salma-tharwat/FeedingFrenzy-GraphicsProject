#include "Renderer.h"

using namespace glm;

static const GLfloat verts[] =
{
	0.2f, 0.4f, -3.0f,
	0.0,1.0,1.0,
	0.0f,1.0f,


	0.22f, 0.42f, -3.0f,
	0.0,1.0,1.0,
	1.0f,0.0f,

	0.26f, 0.5f, -3.0f,
	0.0,1.0,1.0,
	1.0f,1.0f,

	0.32f, 0.58f, -3.0f,
	0.0,1.0,1.0,
	0.0f,0.0f,

	0.36f, 0.6f, -3.0f,
	0.0,1.0,1.0,
	0.5f,1.0f,

	0.4f, 0.6f, -3.0f,
	0.0,1.0,1.0,
	1.0f,0.5f,

	0.5f, 0.6f, -3.0f,
	0.0,1.0,1.0,
	1.0f,0.0f,

	0.54f, 0.6f, -3.0f,
	0.0,1.0,1.0,
	0.5f,0.25f,

	0.6f, 0.58f, -3.0f,
	0.0,1.0,1.0,
	0.0f,0.5f,

	0.7f, 0.5f, -3.0f,
	0.0,1.0,1.0,
	0.0f,1.0f,

	0.75f, 0.42f, -3.0f,
	0.0,1.0,1.0,
	1.0f,0.25f,

	0.75f, 0.4f, -3.0f,
	0.0,1.0,1.0,
	0.2f,0.3f,

	0.7f, 0.3f, -3.0f,
	0.0,1.0,1.0,
	1.0f,0.6f,

	0.6f, 0.22f, -3.0f,
	0.0,1.0,1.0,
	0.25f,1.0f,

	0.54f, 0.2f, -3.0f,
	0.0,1.0,1.0,
	1.0f,0.25f,

	0.5f, 0.2f, -3.0f,
	0.0,1.0,1.0,
	0.45f,0.0f,

	0.4f, 0.2f, -3.0f,
	0.0,1.0,1.0,
	1.0f,0.25f,

	0.36f, 0.2f, -3.0f,
	0.0,1.0,1.0,
	0.15f,0.0f,

	0.32f, 0.22f, -3.0f,
	0.0,1.0,1.0,
	0.5f,1.0f,

	0.26f, 0.3f, -3.0f,
	0.0,1.0,1.0,
	1.0f,0.75f,

	0.22f, 0.38f, -3.0f,
	0.0,1.0,1.0,
	0.75f,0.0f,

	0.2f, 0.4f, -3.0f,
	0.0,1.0,1.0,
	1.0f,0.6f,
	////////
	0.75f, 0.4f, -3.0f,
	0.0,1.0,1.0,
	1.0f,0.7f,

	0.26f, 0.5f, -3.0f,
	0.0,1.0,1.0,
	0.75f,1.0f,

	0.1f, 0.6f, -3.0f,
	0.0,1.0,1.0,
	0.0f,0.9f,

	0.1f, 0.2f, -3.0f,
	0.0,1.0,1.0,
	1.0f,0.8f,

	0.26f, 0.3f, -3.0f,
	0.0,1.0,1.0,
	0.80f,0.0f,

	0.54f, 0.6f, -3.0f,
	0.0,1.0,1.0,
	0.65f,1.0f,

	0.45f, 0.75f, -3.0f,
	0.0,1.0,1.0,
	1.0f,0.75f,

	0.25f, 0.75f, -3.0f,
	0.0,1.0,1.0,
	1.0f,1.0f,

	0.36f, 0.6f, -3.0f,
	0.0,1.0,1.0,
	0.75f,0.75f,

	0.67f, 0.47f, -3.0f,
	0.0, 1.0, 1.0,
	1.0f,1.0f,

	0.54f, 0.2f, -3.0f,
	0.0,1.0,1.0,
	0.0f,1.0f,

	0.45f, 0.1f, -3.0f,
	0.0,1.0,1.0,
	0.0f,0.0f,

	0.25f, 0.1f, -3.0f,
	0.0,1.0,1.0,
	0.5f,0.6f,

	0.36f, 0.2f, -3.0f,
	0.0,1.0,1.0,
	0.0f,0.0f
};

Renderer::Renderer()
{

}

Renderer::~Renderer()
{
	Cleanup();
}

void Renderer::Initialize()
{
	time = glfwGetTime();

	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);

	glClearColor(0.8f, 0.8f, 1.0f, 1.0f);

	Fish Player(verts, "Fish-Texture-8.bmp", 1.0, 0, sizeof(verts));
	Fishes.push_back(Player);

	programID = LoadShaders("SimpleVertexShader.vertexshader", "SimpleFragmentShader.fragmentshader");

	ProjectionMatrix = cam.GetProjectionMatrix();
	glm::mat4 ViewMatrix = cam.GetViewMatrix();
}



void Renderer::Update()
{
	
}

void Renderer::HandleKeyboardInput(int keyPressed)
{
    
	float stepSize = 0.1;
	printf("renderer::KEY=%d\n", keyPressed);
	switch (keyPressed)
	{
	case GLFW_KEY_UP:
		cam.Walk(0.5);
		break;
	case GLFW_KEY_DOWN:
		cam.Strafe(0.5);
		break;
	default:
		break;
	}
}

void Renderer::HandleMouseClick(double xpos, double ypos)
{
	cout << xpos << ' ' << ypos;
}

void Renderer::Draw()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glUseProgram(programID);

	ViewMatrix = cam.GetViewMatrix();
	ProjectionMatrix = cam.GetProjectionMatrix();

	for (Fish &F : Fishes)
		F.drawfish(programID, ProjectionMatrix, ViewMatrix);
}

void Renderer::Cleanup()
{
	glDeleteProgram(programID);
}