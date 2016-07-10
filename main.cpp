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
#include <iomanip>
#include <random>
#include <chrono>
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

	const auto start = chrono::system_clock::now(); // 計測開始時間

//	alg.BubbleSort();
//	alg.QuickSort();
	alg.MergeSort();

	const auto end = chrono::system_clock::now();  // 計測終了時間
	const auto timeSpan = end - start;

	alg.show();

	cout << "Sorting Time ... :"
		<< chrono::duration_cast<chrono::milliseconds>(timeSpan).count()
		<< endl;
	cout << "Hit enter key to exit...";
	cin.sync();	// input stream flush
	cin.get();	// wait enter key

	return 0;
}

