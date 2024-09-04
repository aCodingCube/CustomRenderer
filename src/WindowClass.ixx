export module WindowClass;

// includes
#include <Windows.h>
import std;

namespace cWND
{

	LRESULT CALLBACK WindowProc(HWND hWnd,UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		switch (uMsg)
		{
		case WM_CLOSE:
			DestroyWindow(hWnd);
			break;

		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;
		}

		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}

	export class Window
	{
	private:
		HINSTANCE m_hInstance = nullptr;
		

		const wchar_t* CLASS_NAME = L"Basic Window Class";

	public:
		// public member variables
		HWND m_hWnd = nullptr;
		int width = 640;
		int height = 480;

	public:
		Window()
			: m_hInstance(GetModuleHandle(nullptr))
		{
			// load custom icon

			HICON m_Icon = static_cast<HICON>(LoadImageA(
				NULL,
				"C://Users/Lorenz/Documents/Dokumente/Hobby/Coding/C++/CustomRenderer/res/pixel-icon2.ico",
				IMAGE_ICON,
				23,
				24,
				LR_LOADFROMFILE
			));

			// window class
			WNDCLASS wndClass = {};

			wndClass.lpszClassName = CLASS_NAME;
			wndClass.hInstance = m_hInstance;
			wndClass.hIcon = m_Icon;
			wndClass.hCursor = LoadCursor(NULL, IDC_CROSS);
			wndClass.lpfnWndProc = WindowProc;

			RegisterClass(&wndClass);

			DWORD style = WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU;

			RECT rect = {}; // window sizes
			rect.left = 250;
			rect.top = 250;
			rect.right = rect.left + width;
			rect.bottom = rect.top + height;

			AdjustWindowRect(&rect, style, false);

			m_hWnd = CreateWindowEx(
				0,
				CLASS_NAME,
				L"Custom Render Engine", // title
				style,
				rect.left, // x offset
				rect.top, // y offset
				rect.right - rect.left, // width (with offset)
				rect.bottom - rect.top, // height (with offset)
				NULL,
				NULL,
				m_hInstance,
				NULL
			);

			if (m_hWnd == NULL)
			{
				std::cout << "[ERROR] Failed to create Window\n";
			}

			ShowWindow(m_hWnd, SW_SHOW);
		}

		~Window()
		{
			UnregisterClass(CLASS_NAME, m_hInstance);
		}

		bool ProcessMessages()
		{
			MSG msg = {};

			while (PeekMessage(&msg, nullptr, 0u, 0u, PM_REMOVE))
			{
				if (msg.message == WM_QUIT)
				{
					return false;
				}

				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}

			return true;

		}
	};
}