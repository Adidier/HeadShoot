#pragma once
#include "Platform.h"
#include <Windows.h>
#include "mesh.h"
#include "shader.h"
#include "texture.h"
#include "transform.h"
#include "camera.h"

#include <tchar.h>			// Unicode support	.. we will use TCHAR rather than char	
#include "GL/glew.h"

static const TCHAR* DATABASE_PROPERTY = _T("OurDataStructure");

typedef struct OpenGLData {
	HGLRC Rc;											// Our render context ** Always Needed
	GLuint glTexture;									// Our texture to draw
	GLfloat	xrot;										// X Rotation
	GLfloat	yrot;										// Y Rotation
} GLDATABASE;



class PlatformWIN32 : public Platform
{
private:
	static LRESULT CALLBACK WindowHandler(HWND Wnd, UINT Msg, WPARAM wParam, LPARAM lParam);
	static HGLRC InitGL(HWND Wnd);
	static void ReSizeGLScene(HWND Wnd);
	static Mesh *monkey;
	static Shader *shader;
	static Transform transform;
	static Camera camera;
	static void DrawGLScene(GLDATABASE* db, HDC Dc);
public:
	void init() override;
	int inputOne() override;
	void winMessage();
	PlatformWIN32();
	~PlatformWIN32();
	void draw() override;
};

