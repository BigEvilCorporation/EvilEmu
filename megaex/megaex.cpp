////////////////////////////////////////////////////////////////////////////////
// megaEx
// Game framework using ion::engine with embedded SEGA Mega Drive ROM emulator
//
// Uses mega emulation code based on the work of Lee Hammerton and Jake Turner
//
// Matt Phillips
// http://www.bigevilcorporation.co.uk
////////////////////////////////////////////////////////////////////////////////

#include "megaex.h"
#include "config.h"

MegaEx::MegaEx() : ion::framework::Application("megaEx")
{
	m_renderer = NULL;
	m_window = NULL;
	m_viewport = NULL;
	m_camera = NULL;
	m_keyboard = NULL;
	m_mouse = NULL;
	m_gamepad = NULL;
	m_resourceManager = NULL;

	m_stateControlsConfig = NULL;
	m_stateGame = NULL;
	m_stateMenu = NULL;
}

bool MegaEx::Initialise()
{
	if(!InitialiseRenderer())
	{
		return false;
	}

	if(!InitialiseInput())
	{
		return false;
	}

	if(!InitialiseEmulator("ROMS\\TANGLEWD.BIN"))
	{
		return false;
	}

	//Set window title
	m_window->SetTitle(EmulatorGetROMTitle());

	//ChangeWindowSize(ion::Vector2i(m_viewport->GetWidth() * 2, m_viewport->GetHeight() * 2));

	//Create resource manager
	m_resourceManager = new ion::io::ResourceManager();

	//Create game states
	m_stateControlsConfig = new StateControlsConfig(m_stateManager, *m_resourceManager);
	m_stateGame = new StateGame(m_stateManager, *m_resourceManager, ion::Vector2i(m_window->GetClientAreaWidth(), m_window->GetClientAreaHeight()), ion::Vector2i(WIDTH, HEIGHT));
	m_stateMenu = new StateMenu(m_stateManager, *m_resourceManager);

	//Push first state
	m_stateManager.PushState(*m_stateGame);

	return true;
}

void MegaEx::Shutdown()
{
	ShutdownInput();
	ShutdownRenderer();
}

bool MegaEx::Update(float deltaTime)
{
	//Update input
	bool inputQuit = !UpdateInput();

	//Update window
	bool windowQuit = !m_window->Update();

	//Update game state
	m_stateManager.Update(deltaTime, m_keyboard, m_mouse, m_gamepad);

	return !windowQuit && !inputQuit;
}

void MegaEx::Render()
{
	m_renderer->BeginFrame(*m_viewport, m_window->GetDeviceContext());
	m_renderer->ClearColour();
	m_renderer->ClearDepth();

	//Render current state
	m_stateManager.Render(*m_renderer, *m_camera);

	m_renderer->SwapBuffers();
	m_renderer->EndFrame();
}

bool MegaEx::InitialiseRenderer()
{
	m_window = ion::render::Window::Create("megaEx", DEFAULT_SCREEN_WIDTH, DEFAULT_SCREEN_HEIGHT, false);
	m_renderer = ion::render::Renderer::Create(m_window->GetDeviceContext());
	m_viewport = new ion::render::Viewport(m_window->GetClientAreaWidth(), m_window->GetClientAreaHeight(), ion::render::Viewport::eOrtho2DAbsolute);
	m_camera = new ion::render::Camera();

	m_viewport->SetClearColour(ion::Colour(1.0f, 0.0f, 0.0f, 1.0f));
	m_camera->SetPosition(ion::Vector3(-(float)m_window->GetClientAreaWidth() / 2.0f, -(float)m_window->GetClientAreaHeight() / 2.0f, 0.1f));

	return true;
}

void MegaEx::ShutdownRenderer()
{
	if(m_camera)
		delete m_camera;

	if(m_viewport)
		delete m_viewport;

	if(m_renderer)
		delete m_renderer;

	if(m_window)
		delete m_window;
}

bool MegaEx::InitialiseInput()
{
	m_keyboard = new ion::input::Keyboard();
	m_mouse = new ion::input::Mouse();
	m_gamepad = new ion::input::Gamepad();
	return true;
}

void MegaEx::ShutdownInput()
{
	if(m_gamepad)
		delete m_gamepad;

	if(m_mouse)
		delete m_mouse;

	if(m_keyboard)
		delete m_keyboard;
}

bool MegaEx::UpdateInput()
{
	m_keyboard->Update();
	m_mouse->Update();
	m_gamepad->Update();

	u16 buttonState = 0;

	if(m_keyboard->KeyDown(DIK_UP))
		buttonState |= eBtn_Up;

	if(m_keyboard->KeyDown(DIK_DOWN))
		buttonState |= eBtn_Down;

	if(m_keyboard->KeyDown(DIK_LEFT))
		buttonState |= eBtn_Left;

	if(m_keyboard->KeyDown(DIK_RIGHT))
		buttonState |= eBtn_Right;

	if(m_keyboard->KeyDown(DIK_RETURN))
		buttonState |= eBtn_Start;

	if(m_keyboard->KeyDown(DIK_D))
		buttonState |= eBtn_A;

	if(m_keyboard->KeyDown(DIK_S))
		buttonState |= eBtn_B;

	if(m_keyboard->KeyDown(DIK_A))
		buttonState |= eBtn_C;

	EmulatorSetButtonState(buttonState);

	return !m_keyboard->KeyDown(DIK_ESCAPE);
}

void MegaEx::ChangeWindowSize(const ion::Vector2i& size)
{
	m_window->Resize(size.x, size.y);
	m_viewport->Resize(size.x, size.y);
	m_camera->SetPosition(ion::Vector3(-size.x / 2.0f, -size.y / 2.0f, 0.1f));
	m_renderer->OnResize(size.x, size.y);

	//Recreate quad
	//delete m_quadPrimitive;
	//m_quadPrimitive = new ion::render::Quad(ion::render::Quad::xy, ion::Vector2(size.x / 2, size.y / 2));
	//m_quadPrimitive->SetTexCoords(s_texCoordsGame);
}