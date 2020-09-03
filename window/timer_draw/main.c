#ifndef UNICODE
#define UNICODE
#endif
#include <windows.h>
#define ID_TIMER1 1

int x = 0;

//https://docs.microsoft.com/en-us/windows/win32/winmsg/using-timers#related-topics
void CALLBACK OnTimerProc(
    HWND hWnd,
    UINT uMsg,
    UINT_PTR idTimer,
    DWORD dwTime)
{
    x += 1;
    HDC hdc = GetDC(hWnd);
    SetPixel(hdc, x, 200, RGB(255, 0, 0));
    ReleaseDC(hWnd, hdc);
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

//https://docs.microsoft.com/en-us/windows/win32/api/wingdi/
int main(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
    wchar_t const *CLASS_NAME = L"Sample Window Class";
    BOOL bDone = FALSE;

    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    // wc.hIcon = LoadIcon(hInstance, IDI_APPLICATION);

    RegisterClass(&wc);

    // Create the window.
    HWND hWnd = CreateWindowEx(
        0,                   // Optional window styles.
        CLASS_NAME,          // Window class
        L"Timer Draw",       // Window text
        WS_OVERLAPPEDWINDOW, // Window style

        // Size and position
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

        NULL,      // Parent window
        NULL,      // Menu
        hInstance, // Instance handle
        NULL       // Additional application data
    );

    SetTimer(hWnd, ID_TIMER1, 1000 / 60, OnTimerProc);

    if (hWnd == NULL)
    {
        return 0;
    }

    ShowWindow(hWnd, nCmdShow);

    MSG msg;
    HWND hwndTimer;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_DESTROY:
        KillTimer(hWnd, ID_TIMER1);
        PostQuitMessage(0);
    case WM_TIMER:
    {
    }
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));
        EndPaint(hWnd, &ps);
    }
    default:
        return DefWindowProc(hWnd, uMsg, wParam, lParam);
    }
    return 0;
}