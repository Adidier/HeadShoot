#include "pch.h"
#include "PlatformWIN32.h"
#include <Windows.h>
#include "mesh.h"
#include "shader.h"
#include "texture.h"
#include "transform.h"
#include "camera.h"
#include "GL/glew.h"


Camera PlatformWIN32::camera(glm::vec3(0.0f, 0.0f, -5.0f), 70.0f, (float)600 / (float)400, 0.1f, 100.0f);
Mesh *PlatformWIN32::monkey;
Shader *PlatformWIN32::shader;
Transform PlatformWIN32::transform;

void PlatformWIN32::DrawGLScene(GLDATABASE* db, HDC Dc) {
	if ((db == 0)) return;					// Cant draw .. no render context
	wglMakeCurrent(Dc, db->Rc);										// Make our render context current

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);				// Clear The Screen And The Depth Buffer
	glLoadIdentity();												// Reset The View

	glTranslatef(0.0f, 0.0f, -5.0f);



	// Draw our texture cube to screen :-)
	glBegin(GL_QUADS);
	// Front Face
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	// Back Face
	glNormal3f(0.0f, 0.0f, -1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);
	// Top Face
	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);
	// Bottom Face
	glNormal3f(0.0f, -1.0f, 0.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, -1.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	// Right face
	glNormal3f(1.0f, 0.0f, 0.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
	// Left Face
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	glEnd();

	shader->Bind();

	shader->Update(transform, camera);
	monkey->Draw();

}


void PlatformWIN32::ReSizeGLScene(HWND Wnd) {
	GLDATABASE* db = (GLDATABASE*)GetProp(Wnd, DATABASE_PROPERTY); // Fetch the data base
	if (db == 0) return;											// Cant resize .. no render context
	HDC Dc = GetWindowDC(Wnd);										// Get the window DC
	RECT r;
	GetWindowRect(Wnd, &r);											// Fetch the window size
	int Width = r.right - r.left;									// Window width
	int Height = r.bottom - r.top;									// Window height
	if (Height == 0) Height = 1;									// Stop divid by zero
	wglMakeCurrent(Dc, db->Rc);										// Make our render context current
	
	GLenum res = glewInit();
	if (res != GLEW_OK)
	{
		std::cerr << "Glew failed to initialize!" << std::endl;
	}


	ReleaseDC(Wnd, Dc);												// Release the window DC
}


HGLRC PlatformWIN32::InitGL(HWND Wnd) {
	HGLRC ourOpenGLRC = 0;											// Preset render context to zero

																	//  We need to make sure the window create in a suitable DC format
	PIXELFORMATDESCRIPTOR pfd = {
		sizeof(PIXELFORMATDESCRIPTOR),
		1,
		PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER, //Flags
		PFD_TYPE_RGBA,												// The kind of framebuffer. RGBA or palette.
		32,															// Colordepth of the framebuffer.
		0, 0, 0, 0, 0, 0,
		0,
		0,
		0,
		0, 0, 0, 0,
		24,															// Number of bits for the depthbuffer
		8,															// Number of bits for the stencilbuffer
		0,															// Number of Aux buffers in the framebuffer.
		PFD_MAIN_PLANE,
		0,
		0, 0, 0
	};

	HDC ourWindowHandleToDeviceContext = GetDC(Wnd);				// Get a DC for our window
	int letWindowsChooseThisPixelFormat = ChoosePixelFormat(ourWindowHandleToDeviceContext, &pfd); // Let windows select an appropriate pixel format
	if (SetPixelFormat(ourWindowHandleToDeviceContext, letWindowsChooseThisPixelFormat, &pfd)) { // Try to set that pixel format
		ourOpenGLRC = wglCreateContext(ourWindowHandleToDeviceContext);
		if (ourOpenGLRC != 0) {
			wglMakeCurrent(ourWindowHandleToDeviceContext, ourOpenGLRC); // Make our render context current
		}
	}
	ReleaseDC(Wnd, ourWindowHandleToDeviceContext);					// Release the window device context we are done
	return (ourOpenGLRC);											// Return the render context
}


LRESULT CALLBACK PlatformWIN32::WindowHandler(HWND Wnd, UINT Msg, WPARAM wParam, LPARAM lParam) {

	switch (Msg) {
	case WM_CREATE: {											// WM_CREATE MESSAGE

																// Make a data structure, initialize it and attach to Wnd
		GLDATABASE* db = (GLDATABASE*)malloc(sizeof(GLDATABASE)); // Allocate structure
		db->Rc = InitGL(Wnd);								// Initialize OpenGL and get render context
		db->glTexture = 0;									// Zero the texture
		db->xrot = 0.0f;									// Zero x rotation
		db->yrot = 0.0f;									// Zero y rotation
		SetProp(Wnd, DATABASE_PROPERTY, (HANDLE)db);		// Set the database structure to a property on window
		ReSizeGLScene(Wnd);									// Rescale the OpenGL window
	}
					break;
	case WM_DESTROY: {											// WM_DESTROY MESSAGE
	}
					 break;
	case WM_COMMAND:
		break;
	case WM_PAINT: {
		PAINTSTRUCT Ps;
		GLDATABASE* db = (GLDATABASE*)GetProp(Wnd, DATABASE_PROPERTY);// Fetch the data base
		BeginPaint(Wnd, &Ps);								// Begin paint
		DrawGLScene(db, Ps.hdc);							// Draw the OpenGL scene
		SwapBuffers(Ps.hdc);								// Swap buffers
		EndPaint(Wnd, &Ps);									// End paint// WM_PAINT MESSAGE
		return 0;
	}
				   break;
	case WM_TIMER: {											// WM_TIMER MESSAGE
	}
				   break;
	case WM_WINDOWPOSCHANGED:									// WM_WINDOWPOSCHANGED
		if ((lParam == 0) || ((((PWINDOWPOS)lParam)->flags & SWP_NOSIZE) == 0)) {
			ReSizeGLScene(Wnd);									// Rescale the GL window							
			InvalidateRect(Wnd, 0, TRUE);						// We need a redraw now so invalidate us
		}
		break;
	case WM_ERASEBKGND:											// WM_ERASEBKGND MESSAGE
		return (FALSE);
	default: return DefWindowProc(Wnd, Msg, wParam, lParam);	// Default handler
	};// end switch case
	return 0;
};

void PlatformWIN32::draw()
{

}

void PlatformWIN32::init()
{
	RECT R;
	HWND Wnd;
	WNDCLASSEX WndClass;
	const TCHAR* AppClassName = _T("Project Shooter");

	memset(&WndClass, 0, sizeof(WNDCLASSEX));						// Clear the class record
	WndClass.cbSize = sizeof(WNDCLASSEX);							// Size of this record
	WndClass.style = CS_OWNDC;										// Class styles
	WndClass.lpfnWndProc = WindowHandler;						// Handler for this class
	WndClass.cbClsExtra = 0;										// No extra class data
	WndClass.cbWndExtra = 0;										// No extra window data
	WndClass.hInstance = GetModuleHandle(NULL);						// This instance
	WndClass.hIcon = LoadIcon(0, IDI_APPLICATION);					// Set icon
	WndClass.hCursor = LoadCursor(0, IDC_ARROW);					// Set cursor
	WndClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);	// Set background brush
	WndClass.lpszMenuName = NULL;									// No menu yet
	WndClass.lpszClassName = AppClassName;							// Set class name
	RegisterClassEx(&WndClass);										// Register the class
	GetClientRect(GetDesktopWindow(), &R);							// Get desktop area					
	

	Wnd = CreateWindowEx(0, AppClassName, _T("Project Shooter"),
		WS_VISIBLE | WS_OVERLAPPEDWINDOW, 0, 0,
		600, 400,
		0, 0, 0, NULL);
	

	Vertex vertices[] =
	{
		Vertex(glm::vec3(-1, -1, -1), glm::vec2(1, 0), glm::vec3(0, 0, -1)),
		Vertex(glm::vec3(-1, 1, -1), glm::vec2(0, 0), glm::vec3(0, 0, -1)),
		Vertex(glm::vec3(1, 1, -1), glm::vec2(0, 1), glm::vec3(0, 0, -1)),
		Vertex(glm::vec3(1, -1, -1), glm::vec2(1, 1), glm::vec3(0, 0, -1)),

		Vertex(glm::vec3(-1, -1, 1), glm::vec2(1, 0), glm::vec3(0, 0, 1)),
		Vertex(glm::vec3(-1, 1, 1), glm::vec2(0, 0), glm::vec3(0, 0, 1)),
		Vertex(glm::vec3(1, 1, 1), glm::vec2(0, 1), glm::vec3(0, 0, 1)),
		Vertex(glm::vec3(1, -1, 1), glm::vec2(1, 1), glm::vec3(0, 0, 1)),

		Vertex(glm::vec3(-1, -1, -1), glm::vec2(0, 1), glm::vec3(0, -1, 0)),
		Vertex(glm::vec3(-1, -1, 1), glm::vec2(1, 1), glm::vec3(0, -1, 0)),
		Vertex(glm::vec3(1, -1, 1), glm::vec2(1, 0), glm::vec3(0, -1, 0)),
		Vertex(glm::vec3(1, -1, -1), glm::vec2(0, 0), glm::vec3(0, -1, 0)),

		Vertex(glm::vec3(-1, 1, -1), glm::vec2(0, 1), glm::vec3(0, 1, 0)),
		Vertex(glm::vec3(-1, 1, 1), glm::vec2(1, 1), glm::vec3(0, 1, 0)),
		Vertex(glm::vec3(1, 1, 1), glm::vec2(1, 0), glm::vec3(0, 1, 0)),
		Vertex(glm::vec3(1, 1, -1), glm::vec2(0, 0), glm::vec3(0, 1, 0)),

		Vertex(glm::vec3(-1, -1, -1), glm::vec2(1, 1), glm::vec3(-1, 0, 0)),
		Vertex(glm::vec3(-1, -1, 1), glm::vec2(1, 0), glm::vec3(-1, 0, 0)),
		Vertex(glm::vec3(-1, 1, 1), glm::vec2(0, 0), glm::vec3(-1, 0, 0)),
		Vertex(glm::vec3(-1, 1, -1), glm::vec2(0, 1), glm::vec3(-1, 0, 0)),

		Vertex(glm::vec3(1, -1, -1), glm::vec2(1, 1), glm::vec3(1, 0, 0)),
		Vertex(glm::vec3(1, -1, 1), glm::vec2(1, 0), glm::vec3(1, 0, 0)),
		Vertex(glm::vec3(1, 1, 1), glm::vec2(0, 0), glm::vec3(1, 0, 0)),
		Vertex(glm::vec3(1, 1, -1), glm::vec2(0, 1), glm::vec3(1, 0, 0)),
	};

	unsigned int indices[] = { 0, 1, 2,
		0, 2, 3,

		6, 5, 4,
		7, 6, 4,

		10, 9, 8,
		11, 10, 8,

		12, 13, 14,
		12, 14, 15,

		16, 17, 18,
		16, 18, 19,

		22, 21, 20,
		23, 22, 20
	};

	Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]), indices, sizeof(indices) / sizeof(indices[0]));
	monkey=new Mesh("./Resources/Models/monkey3.obj");
	shader = new Shader("./Resources/Shaders/basicShader");
	Texture texture("./Resources/Sprites/bricks.jpg");
	Transform transform;
	

	return;
}

int PlatformWIN32::inputOne()
{

	return 0;
}

void PlatformWIN32::winMessage()
{
	MSG Msg;
	while (GetMessage(&Msg, 0, 0, 0)) {								// Get messages
		TranslateMessage(&Msg);										// Translate each message
		DispatchMessage(&Msg);										// Dispatch each message
	};
	return;
}

PlatformWIN32::PlatformWIN32()	
{
}


PlatformWIN32::~PlatformWIN32()
{
}
