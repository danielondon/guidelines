// TestCoreGuidelines.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

int main()
{
	int arr[10];		// BAD, warning 26494 will be fired	
	int* p = arr;          // BAD, warning 26485 will be fired
	//arr[0] = 6;

	cout << "CPP CORE GUIDELINES " << endl;
	cout << " arr[10] " << arr[0]<<endl;
    return 0;
}

