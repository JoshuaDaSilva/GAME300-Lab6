#pragma once
#include "SDL.h"

// new OpenGL/GLEW headers:
#define GL3_PROTOTYPES 1
#include "glew.h"
#include "Math.h"


class ShaderManager
{
public:
	static ShaderManager* GetInstance()
	{
		if (instance == nullptr)
		{
			instance = new ShaderManager();
		}
		return instance;
	}

	void Init();

	void Startup();

	void LoadShaders();

	void Render(GLuint texture, Vec3 position);

	void Shutdown();

	void LoadShaderFromFile(const char * shaderfile, GLenum type);
	void LoadVertices(static const GLfloat CubeVB[], int numVerts);
	void LoadUVs(static const GLfloat CubeVB[], int numUVs);
	void LoadNormal(static const GLfloat normalsVB[], int uv_buffer);

private:

	ShaderManager();
	~ShaderManager();

	void ProcessShaderFile(GLuint shader, char *shaderData, GLenum type);
	void FindUniformHandles();

	GLuint programObj;
	GLuint vao;

	GLint TextureUniformHandle;
	GLint ProjectionUniformHandle;
	GLint ModelViewUniformHandle;

	GLuint verticesHandle;
	GLuint UVHandle;
	GLuint uv_buffer;
	
	static ShaderManager* instance;
};

