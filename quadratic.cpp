#include "quadratic.h"

int SolveEquation(double a, double b, double c,
                   double *x1, double *x2)
{
    if (IsZero(a))
    {
        if (IsZero(b))
        {
            if (IsZero(c))
                return 3;
            else
                return 0;
        }
        else
        {
            *x1 = -c / b;
            return 1;
        }
    }

    double discr = b * b - 4 * a * c;

    if (discr < 0)
    {
        return 0;
    }
    else if (IsZero(discr))
    {
        *x1 = -b / (2 * a);
        return 1;
    }
    else
    {
        double sqvirt = sqrt(discr);
        *x1 = (-b + sqvirt) / (2 * a);
        *x2 = (-b - sqvirt) / (2 * a);
        return 2;
    }
}