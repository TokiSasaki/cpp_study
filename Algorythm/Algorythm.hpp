/*****************************************************************************
	order			@ My make sort library
	compiler		@ x86_64-w64-mingw32-gcc (cygwin x64)
	file name		@ Algorythm.cpp
	creation date	@ 2016-07-05
*****************************************************************************/
/*
	History of revision
*/

#ifndef _SORTER_HPP_
#define _SORTER_HPP_
/*****************************************************************************
	include, namespace
*****************************************************************************/
#include <iostream>

namespace alg
{
/*****************************************************************************
	define, namespace
*****************************************************************************/
using namespace std;

/*****************************************************************************
	class, structure
*****************************************************************************/

/*****************************************************************************
	description @ Algorythm base class
*****************************************************************************/
class Algorythm
{
	private:
		int iSize;
		int* piData;
		void prQuickSort(int iFront, int iBehind);
		void prMergeSort(int iSize, int* piData, int* piBuf);
	public:
		Algorythm();
		Algorythm(int iSize);
		~Algorythm();
		int get(int iIdx);
		int set(int iIdx, int iData);
		int getSize();
		int setSize(int iSize);
		void show();

		// sort algorythm
		int BubbleSort();
		int QuickSort();
		int MergeSort();
		void InsertSort();
		void BinaryInsertSort();
		
		// search algorythm
		int Search();
};

} //namespace alg

/*****************************************************************************
	external variables
*****************************************************************************/

/*****************************************************************************
	internal variables
*****************************************************************************/

/*****************************************************************************
	prototype declaration
*****************************************************************************/

#endif /* _SORTER_HPP_ */


