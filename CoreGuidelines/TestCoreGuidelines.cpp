#include "stdafx.h"


using namespace std;

#define USING_GSL

#ifdef USING_GSL
#include <gsl/gsl>
int readPositionN(gsl::span<int> p, int n)
{
    std::cout << "with GSL" << endl;
    return p[n];
}
#else
int readPositionN(int* p, int n)
{
    std::cout << "without GSL" << endl;
    return p[n]; // Bad: Pointer Aritmetic
}
#endif

int main()
{
    const unsigned int SIZE = 100;
#ifdef USING_GSL
    int a[SIZE] = { 0 };
    std::cout << "First Position is " <<a[0]<< endl;
    for (auto i = 0U; i < SIZE; ++i)
       gsl::at(a, i) = i;
    int res = readPositionN(a, 50);
    
#else    
    int a[SIZE]; // Bad: Variable Unitialized
    std::cout << "First Position is " << a[0] << endl; // Warning: Using unitialized Memory
    for (auto i = 0U; i < SIZE; ++i)
        a[i] = i; // Bad: Only index into array using constant
    int res = readPositionN(a, 50);    // Bad: Array to pointer decay.    
#endif

    std::cout << "Return value " << res << endl;
    return 0;
}

