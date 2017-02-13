// TestCoreGuidelines.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"


using namespace std;

#define USING_GSL

#ifndef USING_GSL
// 2) WITHOUT USING GSL
int readPositionN(int* p, int n)
{
    cout << "without GSL" << endl;
    return p[n];
}
#else
#include <gsl.h>
// 3) WITH GSL
int readPositionN(gsl::span<int> p, int n)
{
    cout << "with GSL" << endl;
    return p[n];
}
#endif

int main()
{
    //// 1) CORE GUIDLEINES PLUGIN

	int arr[10];		// BAD, warning 26494 will be fired	
	int* p = arr;          // BAD, warning 26485 will be fired
	//arr[0] = 6;

	cout << "CPP CORE GUIDELINES " << endl;
	cout << " arr[10] " << arr[0]<<endl; // Normal Warning

#ifndef USING_GSL
    // 2) WITHOUT USING GSL
    const unsigned int SIZE = 100;
    int a[SIZE];
    for (auto i = 0U; i < SIZE; ++i)
        a[i] = i;
    int res = readPositionN(a, 50);    // bad
    cout << "Return value " << res << endl;
#else
    // 3) USING GSL
    const unsigned int SIZE = 100;
    int a[SIZE];
    for (auto i = 0U; i < SIZE; ++i)
        a[i] = i;
    int res = readPositionN(a, 50);  
    cout << "Return value " << res << endl;
#endif

    return 0;
}

