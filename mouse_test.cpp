#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main()
{
    POINT pPnt;

    GetCursorPos(&pPnt);
    while(1){
        bool Click = GetAsyncKeyState(VK_LBUTTON) & 0x8000;
        if(Click == 1)
        {
            printf("\033[44mOPA NAHUY\033[0m");
        }
        Sleep(210);
    }

}