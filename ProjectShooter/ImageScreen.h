#pragma once
#include <string>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include "shader.h"
#include "camera.h"
class ImageScreen
{
public:
	ImageScreen(const std::string& fileName);

	void Bind();
	void Draw();
	virtual ~ImageScreen();
private:
	void operator=(const ImageScreen& texture) {}

	unsigned int framebuffer;
	unsigned int quadVAO, quadVBO;
	Transform transform1;
	Camera camera1;
	Shader *screenShader;
};

