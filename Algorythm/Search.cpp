/*****************************************************************************
	order			@ My make sort library
	compiler		@ x86_64-w64-mingw32-gcc (cygwin x64)
	file name		@ Search.cpp
	creation date	@ 2016-07-14
*****************************************************************************/
/*
	History of revision
*/

/*****************************************************************************
	include, namespace
*****************************************************************************/
#include <iostream>
#include <string>
#include "Algorythm.hpp"

namespace alg
{
/*****************************************************************************
	define, namespace
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

/*****************************************************************************
	discription	@ Linear Search
	argument	@ iFind = search number
	return		@ found number
	note		@ -
*****************************************************************************/
int Algorythm::LinearSearch(int iFind)
{
	int iIdx, iCnt;
	for(iIdx = 0, iCnt = 0; iIdx < this->iSize; iIdx++){
		if(this->piData[iIdx] == iFind){
			cout << "Index: " << iIdx << endl;
			iCnt++;
		}
	}

	cout << "Count: " << iCnt << endl;

	return iCnt;
}

/*****************************************************************************
	discription	@ Binary Search
	argument	@ iFind = search number
	return		@ found index
	note		@ use to sorted data
*****************************************************************************/
int Algorythm::BinarySearch(int iFind)
{
	int iMid;
	int iLeft = 0;
	int iRight = this->iSize;

	while(iLeft <= iRight){
		// find the sorted point(binary search)
		iMid = (iLeft + iRight) / 2;
		if(this->piData[iMid] == iFind){
			return iMid;
		}

		if(this->piData[iMid] < iFind){
			iLeft = iMid + 1;
		}
		else{
			iRight = iMid - 1;
		}
	}
	return 0;

}

} // namespace alg

