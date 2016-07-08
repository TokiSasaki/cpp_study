/*****************************************************************************
	order			@ Main
	compiler		@ x86_64-w64-mingw32-gcc (cygwin x64)
	file name		@ main.cpp
	creation date	@ 2016-07-07
*****************************************************************************/
/*
	History of revision
*/

/*****************************************************************************
	include, namespace
*****************************************************************************/
#include <iostream>
#include <random>
#include "Algorythm.hpp"

/*****************************************************************************
	define
*****************************************************************************/

/*****************************************************************************
	class, structure
*****************************************************************************/

/*****************************************************************************
	external variables
*****************************************************************************/

/*****************************************************************************
	internal variables
*****************************************************************************/

/*****************************************************************************
	prototype declaration
*****************************************************************************/

using namespace std;
using namespace alg;

/*****************************************************************************
	discription	@ entry
	argument	@ -
	return		@ -
	note		@ -
*****************************************************************************/
int main()
{
	random_device rnd;
	Algorythm alg;
	int iInSize;

	cout << "Please input data number: ";
	cin >> iInSize;

	alg.setSize(iInSize);

	for(int i = 0; i < iInSize; i++){
		alg.set(i, (rnd() % 50000));
	}

	
	alg.show();

	cout << "Bubble Sort()" << endl;
	alg.BubbleSort();

	alg.show();
	cout << "Hit enter key to exit...";
	cin.sync();	// input stream flush
	cin.get();	// wait enter key

	return 0;
}

