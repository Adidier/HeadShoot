#include "ImageScreen.h"
#include "stb_image.h"
#include <iostream>

ImageScreen::ImageScreen(const std::string& fileName):
camera1(glm::vec3(0.0f, 0.0f, -0.50f), 140.0f, (float)600 / (float)400, 0.1f, 100.0f)
{

	int width, height, numComponents;
	unsigned char* data = stbi_load((fileName).c_str(), &width, &height, &numComponents, 4);

	if (data == NULL)
		std::cerr << "Unable to load texture: " << fileName << std::endl;


	glGenTextures(1, &framebuffer);
	glBindTexture(GL_TEXTURE_2D, framebuffer);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
	stbi_image_free(data);


	float quadVertices[] = { // vertex attributes for a quad that fills the entire screen in Normalized Device Coordinates.
							 // positions   // texCoords
		-1.0f,  1.0f,  0.0f, 1.0f,
		-1.0f, -1.0f,  0.0f, 0.0f,
		1.0f, -1.0f,  1.0f, 0.0f,

		-1.0f,  1.0f,  0.0f, 1.0f,
		1.0f, -1.0f,  1.0f, 0.0f,
		1.0f,  1.0f,  1.0f, 1.0f
	};
	glGenVertexArrays(1, &quadVAO);
	glGenBuffers(1, &quadVBO);
	glBindVertexArray(quadVAO);
	glBindBuffer(GL_ARRAY_BUFFER, quadVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(quadVertices), &quadVertices, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));


	screenShader = new Shader("./Resources/Shaders/screenImageShader");

	transform1.GetRot()->x = 3.1;
	transform1.GetRot()->y = 0;
}

void ImageScreen::Bind()
{
	//glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);
	glBindTexture(GL_TEXTURE_2D, framebuffer);
	glEnable(GL_DEPTH_TEST); // enable depth testing (is disabled for rendering screen-space quad)
}


ImageScreen::~ImageScreen()
{

}


void ImageScreen::Draw()
{
	glBindTexture(GL_TEXTURE_2D, framebuffer);
	glEnable(GL_DEPTH_TEST); // enable depth testing (is disabled for rendering screen-space quad)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glColor3f(1.0f, 1.0f, 1.0f);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	// now bind back to default framebuffer and draw a quad plane with the attached framebuffer color texture
	//glBindFramebuffer(GL_FRAMEBUFFER, 0);
	//glDisable(GL_DEPTH_TEST); // disable depth test so screen-space quad isn't discarded due to depth test.
							  // clear all relevant buffers
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // set clear color to white (not really necessery actually, since we won't be able to see behind the quad anyways)
	glClear(GL_COLOR_BUFFER_BIT);
	screenShader->Bind();
	screenShader->Update(transform1, camera1);
	glBindVertexArray(quadVAO);
	glBindTexture(GL_TEXTURE_2D, framebuffer);	// use the color attachment texture as the texture of the quad plane
	glDrawArrays(GL_TRIANGLES, 0, 6);
}