#include <Windows.h>

int main(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
    MessageBox(0, "Blah blah...", "My Windows app!", MB_SETFOREGROUND);
    return EXIT_SUCCESS;
}