#include <iostream>
using namespace std;



double lambda = 2.0 / (3.96 + 6.44);
double Function(double x)
{
    return acos(pow(x, 0.5) - 1) / 2;
}

double func(double x)
{
    return pow(x, 0.5) - cos(2 * x) - 1;
}

double derivFunc(double x)
{
    return (1 / (2 * pow(x, 0.5))) + 2 * sin(x);
}

double SimpleIteration(double x0, double epsilon)
{
    x0 = Function(x0);
    while (abs(x0 - Function(x0)) >= epsilon)
    {
        x0 = Function(x0);
    }
    return x0;
}

double EquationRelaxationMethod(double firstApproach, double epsilon)
{

    double curr, next = firstApproach;
    do {
        curr = next;
        next = curr - lambda * func(curr);
    } while (abs(next - curr) > epsilon);
    return next;
}
double modifNewton(double x, double epsilon)
{
    double h = func(x) / derivFunc(x);
    while (abs(h) >= epsilon)
    {
        h = func(x) / derivFunc(x);
        x = x - h;
    }
    return x;
}


int main()
{
    cout << SimpleIteration(0.5, 0.0001) << endl;
    cout << EquationRelaxationMethod(0.5, 0.0001) << endl;
    cout << modifNewton(0.5, 0.0001);
}
