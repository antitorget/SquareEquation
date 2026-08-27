#include "unit_test.h"

#define BLUE_SELECTION "\033[44m"

void RunOneTest(TestCase test)
{
    double x1 = 0, x2 = 0;
    int nRoots = SolveEquation(test.a, test.b, test.c, &x1, &x2);
    if(IsZero(x1 - test.x1Ref) && IsZero(x2-test.x2Ref)){
        if(nRoots == test.nRootsRef){
        }
        else{
            printf("TypeTest %d\nTest %d ", test.TestType, test.TestNum);
            printf(RED_COLOR "FAILED" CLEAR);
            printf(": a = %lg, b = %lg, c = %lg\n"
                    "expected: %d roots, x1Ref = %lg, x2Ref = %lg\n"
                    "got: %d roots, x1 = %lg, x2 = %lg\n",
                    test.a, test.b, test.c, test.nRootsRef, test.x1Ref, test.x2Ref,
                    nRoots, x1, x2);
            printf("Отдохни, посмотри видосик:");
            sleep(5);
            system("start \"\" \".\\video.mp4\"");
            exit(EXIT_FAILURE);       
        }
    }
    else{
            printf("TypeTest %d\nTest %d ", test.TestType, test.TestNum);
            printf(RED_COLOR "FAILED" CLEAR);
            printf(": a = %lg, b = %lg, c = %lg\n"
                    "expected: %d roots, x1Ref = %lg, x2Ref = %lg\n"
                    "got: %d roots, x1 = %lg, x2 = %lg\n",
                    test.a, test.b, test.c, test.nRootsRef, test.x1Ref, test.x2Ref,
                    nRoots, x1, x2);
            printf("Отдохни, посмотри видосик:");
            sleep(5);
            system("start \"\" \".\\video.mp4\"");
            exit(EXIT_FAILURE); 
    }
}

void DiscrPosTests()
{
    for(int i = 1; i <= 500; i++){
        double x1 = (double)rand()/((double)RAND_MAX/10000.0);
        double x2 = (double)rand()/((double)RAND_MAX/10000.0);
        int IsPosx1 = rand() % 2;
        int IsPosx2 = rand() % 2;

        if(IsZero(x1 - x2))
        {
            i--;
            continue;
        }

        if(IsPosx1 == 0){
            x1 = -x1;
        }
        if(IsPosx2 == 0){
            x2 = -x2;
        }

        if(x1 < x2){
            double change = x1;
            x1 = x2;
            x2 = change;
        }
        double b = -(x1 + x2);
        double c = x1 * x2;
        TestCase test = {.TestType = 1, .TestNum = i, .a = 1, .b = b, .c = c, .nRootsRef = 2, .x1Ref = x1, .x2Ref = x2};
        RunOneTest(test);
    }
}

void DiscrZeroTests()
{
    for(int i = 1; i <= 500; i++)
    {
        double x1 = (double)rand()/((double)RAND_MAX/1000.0);
        int IsPosx1 = rand() % 2;
        
        if(IsPosx1 == 0){
            x1 = -x1;
        }
        double b = -2 * x1;
        double c = x1 * x1;
        
        TestCase test = {.TestType = 2, .TestNum = i, .a = 1, .b = b, .c = c, .nRootsRef = 1, .x1Ref = x1};
        RunOneTest(test);   
    }
}

void DiscrNegTests()
{
    for(int i = 1; i <= 500; i++)
    {
        double c = (double)rand()/((double)RAND_MAX/10000.0);
        double b = (double)rand()/((double)RAND_MAX/199.9999);
        if(b > 2 * sqrt(c)){
            i--;
            continue;
        }
        else{
            TestCase test = {.TestType = 3, .TestNum = i, .a = 1, .b = b, .c = c, .nRootsRef = 0};
            RunOneTest(test);
        }
    }
}

void BNotZero()
{
    double b = 0.0001 + (double)rand()/((double)RAND_MAX/10000.0);
    TestCase test = {.TestType = 4, .TestNum = 1, .a = 0, .b = b, .c = 0, .nRootsRef = 1};
    RunOneTest(test);

    for(int i = 2; i <= 500; i++)
    {
        b = 0.0001 + (double)rand()/((double)RAND_MAX/10000.0);
        double c = (double)rand()/((double)RAND_MAX/10000.0);
        double x1 = -c/b;
        TestCase test = {.TestType = 4, .TestNum = i, .a = 0, .b = b, .c = c, .nRootsRef = 1, .x1Ref = x1};
        RunOneTest(test);
    }   
}

void AllCoefIsZero()
{
    for(int i = 1; i <= 500; i++)
    {
        TestCase test = {.TestType = 5, .TestNum = i, .nRootsRef = 3};
        RunOneTest(test);
    }
}

void CIsntZero()
{
    for(int i = 1; i <= 500; i++)
    {
        double c = 0.0001 + (double)rand()/((double)RAND_MAX / 10000.0);
        TestCase test = {.TestType = 6, .TestNum = i, .c = c, .nRootsRef = 0};
        RunOneTest(test);
    }
}

void RunTableTests() //TODO: массив структур
{
    TestCase test1 = {.TestType = 1, .TestNum = 1, .a = 1, .b = -2, .c = -8, .nRootsRef = 2, .x1Ref = 4, .x2Ref = -2};
    RunOneTest(test1);

    TestCase test2 = {.TestType = 1, .TestNum = 2, .a = -1, .b = -2.5, .c = 44, .nRootsRef = 2, .x1Ref = -8, .x2Ref = 5.5};
    RunOneTest(test2);

    TestCase test3 = {.TestType = 2, .TestNum = 3, .a = -1, .b = 2, .c = -1, .nRootsRef = 1, .x1Ref = 1};
    RunOneTest(test3);

    TestCase test4 = {.TestType = 2, .TestNum = 4, .a = 4, .b = -12, .c = 9, .nRootsRef = 1, .x1Ref = 1.5};
    RunOneTest(test4);

    TestCase test5 = {.TestType = 3, .TestNum = 5, .a = 2, .b = 5, .c = 69.69, .nRootsRef = 0};
    RunOneTest(test5);

    TestCase test6 = {.TestType = 4, .TestNum = 6, .a = 0, .b = 1, .c = -2, .nRootsRef = 1, .x1Ref = 2};
    RunOneTest(test6);

    TestCase test7 = {.TestType = 4, .TestNum = 7, .a = 0, .b = 1, .c = 2, .nRootsRef = 1, .x1Ref = -2};
    RunOneTest(test7);  

    TestCase test8 = {.TestType = 5, .TestNum = 8, .a = 0, .b = 0, .c = 0, .nRootsRef = 3};
    RunOneTest(test8);

    TestCase test9 = {.TestType = 6, .TestNum = 9, .a = 0, .b = 0, .c = 1, .nRootsRef = 0};
    RunOneTest(test9);
}

void TestMenu()
{
    printf("1. Провести автоматическую проверку \n\n"
        "2. Просмотреть результаты автоматической проверки \n\n"
        "3. Провести выборочную проверку \n\n"
        "4. Просмотреть результаты выборочной проверки \n\n");

    POINT pPnt;
    int state = 1;
    bool PreClick = false;

    while(1){
        bool Click = GetAsyncKeyState(VK_LBUTTON) & 0x8000;
        if (Click == true)
        {
            GetCursorPos(&pPnt);
            if(state == 1)
            {
                if(0 <= pPnt.x && pPnt.x <= 332 && 36 <= pPnt.y && pPnt.y <= 61)
                {
                    printf("\033[2J\033[H");
                    printf(BLUE_SELECTION"1. Провести автоматическую проверку \n\n"CLEAR
                           "2. Просмотреть результаты автоматической проверки \n\n"
                           "3. Провести выборочную проверку \n\n"
                           "4. Просмотреть результаты выборочной проверки \n\n");
                    
                    state = 2;
                }
                Sleep(230);
                continue;
            }

            if(state == 2)
            {
                if(0 <= pPnt.x && pPnt.x <= 332 && 36 <= pPnt.y && pPnt.y <= 61)
                {
                    printf("\033[2J\033[H");
                    RunAllTests();
                    printf("Проверка прошла успешно\n\n\n\n\nВернутся в меню тестов");
                    
                    state = 3;
                }
                Sleep(230);
                continue;
            }

            // if(state == 3)
            // {
            //     if()
            // }
            printf("\n%d %d\n", pPnt.x, pPnt.y);
        }
    }
}

void RunAllTests()
{
    DiscrPosTests();
    DiscrZeroTests();
    DiscrNegTests();
    BNotZero();
    AllCoefIsZero();
    CIsntZero();
    RunTableTests();
}