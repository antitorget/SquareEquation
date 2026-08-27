#include "scanfs.h"
#include <ncurses/ncurses.h>

//  argc argv
int main()
{
    RussianLanguage();

    double a = 0, b = 0, c = 0;
    double x1 = 0, x2 = 0;

    RunAllTests();
    printf(CLEAR);

    TestMenu();

    POINT cursorPos;
    while(1){
        printf("X = %d, Y = %d\n", cursorPos.x, cursorPos.y);
    }
    //Input(&a, &b, &c);

    //RunTests();
    //int nRoots = SolveEquation(a, b, c, &x1, &x2);

    //Output(nRoots, x1, x2);
}

void Input(double *a, double *b, double *c)
{
    assert(a);
    assert(b);
    assert(c);

    printf("Введите квадратное уравнение типа ax^2 + bx + c = 0:\n\n");
    while (1)
    {
        ReplaceLine("Коэффициент a: ");
        *a = get_coef();
        ReplaceLine("Коэффициент b: ");
        *b = get_coef();
        ReplaceLine("Коэффициент c: ");
        *c = get_coef();
        if (*a != *a || *b != *b || *c != *c)
        {
            printf("Братан хуйня. Давай по новой");
            continue;
        }
        else
        {
            break;
        }
    }
}

void ReplaceLine(const char *text) // чистим терминал
{
    assert(text);

    printf(GetUp);
    printf(Clear);
    printf("%s", text);
}

double get_coef()
{
    char Term_Input[100] = {};
    fgets(Term_Input, 100, stdin);

    double Coef = atof(Term_Input);
    int len = length(Coef);
    if (isdigit(Term_Input[0]) != 0 || Term_Input[0] == '-')
    {
        if (Term_Input[len + 1] != '\0')
        {
            return NAN;
        }
        else
        {   
            if(len > 10){
                Coef = round(Coef);
            }
            return Coef;
        }
    }
    else
    {
        return NAN;
    }
}

int length(double num)
{
    char len_str[100] = {};
    sprintf(len_str, "%.40lg", num);
    size_t len = strlen(len_str);
    return len;
}

void Output(int nRoots, double x1, double x2)
{
    switch (nRoots)
    {
    case inf:
        ReplaceLine("Брат тут дохуя корней");
        break;
    case 0:
        ReplaceLine("Бля корней нет, хуйня уравнение");
        break;
    case 1:
        ReplaceLine("Сучка здесь один мать его корень x = ");
        printf("%lg", x1);
        break;
    case 2:
        ReplaceLine("ЕБАААААТЬ 2 КОРНЯ НАХУЙ:\n");
        printf("%lg\n%lg", x1, x2);
        break;
    default:
        ReplaceLine("Хуйня братан, давай по новой");
        break;
    }
}

bool IsZero(double num)
{
    if(fabs(num) < delta) return 1;
    else return 0;
}


void RussianLanguage()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
}
