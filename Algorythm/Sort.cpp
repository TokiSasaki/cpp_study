/*****************************************************************************
	order			@ My make sort library
	compiler		@ x86_64-w64-mingw32-gcc (cygwin x64)
	file name		@ Sort.cpp
	creation date	@ 2016-07-05
*****************************************************************************/
/*
	History of revision
*/

/*****************************************************************************
	include, namespace
*****************************************************************************/
#include <iostream>
#include <string.h>
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
	discription	@ Bubble sort
	argument	@ -
	return		@ -
	note		@ -
*****************************************************************************/
int Algorythm::BubbleSort()
{
	int iTmp;
	int iFlag = 0;

	for(int i = this->iSize; 0 < i; i--){
		for(int j = 0; j < i - 1; j++){
			if(this->piData[j] > this->piData[j + 1]){
				iTmp = this->piData[j + 1];
				this->piData[j + 1] = this->piData[j];
				this->piData[j] = iTmp;
				iFlag = 1;
			}
		}

		if(iFlag == 0){
			break;
		}
	}

	return 0;
}

/*****************************************************************************
	discription	@ internal quick sort
	argument	@ iFront = first of data, iBehind = end of data
	return		@ 0 = succeed, else error
	note		@ -
*****************************************************************************/
void Algorythm::prQuickSort(int iFront, int iBehind)
{
	int iDiv, iTmp;
	int i = iFront;
	int j = iBehind;

	//recuresive stopper
	if(iFront >= iBehind){
		return;
	}

	//division value
	//The first data in array is the division value.
	iDiv = this->piData[iFront];
	
	while(true){
		// "(i <= j)" is a little ugly.
		while((i <= j) && (this->piData[i] <= iDiv)){
			i++;
		}
		while((i <= j) && (iDiv < this->piData[j])){
			j--;
		}

		// !! brady?(increase number of evaluation formula)
		//while(i <= j){
		//	if(this->piData[i] <= iDiv){
		//		i++;
		//	}
		//	if(iDiv < this->piData[j]){
		//		j--;
		//	}
		//}

		if(i < j){
			//interchange
			iTmp = this->piData[i];
			this->piData[i] = this->piData[j];
			this->piData[j] = iTmp;
		}
		else{
			break;
		}
	}

	//interchange front data with decrease count data
	iTmp = this->piData[iFront];
	this->piData[iFront] = this->piData[j];
	this->piData[j] = iTmp;

	prQuickSort(iFront, j - 1);
	prQuickSort(j + 1, iBehind);

	return;
}

/*****************************************************************************
	discription	@ Quick sort
	argument	@ -
	return		@ -
	note		@ -
*****************************************************************************/
int Algorythm::QuickSort()
{
	this->prQuickSort(0, this->iSize - 1);
	return 0;
}

/*****************************************************************************
	discription	@ internal merge sort
	argument	@ -
	return		@ -
	note		@ -
*****************************************************************************/
void Algorythm::prMergeSort(int iSize, int* piData, int* piBuf)
{
	int iMid;
	int i, j, iCnt;

	//recursive stopper
	if(iSize <= 1){
		return;
	}

	//truncation(cutoff)
	iMid = iSize / 2;

	//divide in the middle
	this->prMergeSort(iMid, piData, piBuf);
	this->prMergeSort(iSize - iMid, piData + iMid, piBuf);

	memcpy(&piBuf[0], &piData[0], sizeof(int) * iMid);

	for(i = 0, iCnt = 0, j = iMid; (i < iMid) && (j < iSize); iCnt++){
		if(piBuf[i] <= piData[j]){
			piData[iCnt] = piBuf[i];
			i++;
		}
		else{
			piData[iCnt] = piData[j];
			j++;
		}
	}

	if(i < iMid){
		memcpy(&piData[iCnt], &piBuf[i], sizeof(int) * (iMid - i));
	}

	return;
}

/*****************************************************************************
	discription	@ Merge sort
	argument	@ -
	return		@ -
	note		@ -
*****************************************************************************/
int Algorythm::MergeSort()
{
	int* piBuf = new int[(this->iSize / 2) + 1]();

	this->prMergeSort(this->iSize, this->piData, piBuf);

	delete [] piBuf;

	return 0;
}

/*****************************************************************************
	discription	@ Insert sort
	argument	@ -
	return		@ -
	note		@ -
*****************************************************************************/
void Algorythm::InsertSort()
{
	int iSortedIdx;
	int iCnt;
	int iInsData;
	int iTmp;

	for(iSortedIdx = 0; iSortedIdx < (this->iSize - 1); iSortedIdx++){
		iInsData = this->piData[iSortedIdx + 1];

		iCnt = 0;
		// run to the sorted point(linear search)
		while(iCnt <= iSortedIdx){
			if(this->piData[iCnt] > iInsData){
				break;
			}
			iCnt++;
		}

		// displace(move) to behind the insert point.
		if(iCnt <= (iSortedIdx + 1)){
			iTmp = (iSortedIdx + 1) - iCnt;
			memmove(&this->piData[iCnt + 1],
					&this->piData[iCnt],
					sizeof(int) * iTmp);
			this->piData[iCnt] = iInsData;
		}
	}
	return;
}

/*****************************************************************************
	discription	@ Binary Insert sort
	argument	@ -
	return		@ -
	note		@ -
*****************************************************************************/
void Algorythm::BinaryInsertSort()
{
	int iSortedIdx;
	int iInsData;
	int iTmp;
	int iSrchMid;
	int iSrchLeft;
	int iSrchRight;

	for(iSortedIdx = 0; iSortedIdx < this->iSize; iSortedIdx++){
		iInsData = this->piData[iSortedIdx + 1];

		iSrchLeft = 0;
		iSrchRight = iSortedIdx;
		// find the sorted point(binary search)
		while(iSrchLeft < iSrchRight){
			iSrchMid = (iSrchLeft + iSrchRight) / 2;
			if(this->piData[iSrchMid] < iInsData){
				iSrchLeft = iSrchMid + 1;
			}
			else{
				iSrchRight = iSrchMid;
			}

		}

		// displace(move) to behind the insert point.
		if(iSrchLeft <= iSortedIdx){
			iTmp = (iSortedIdx + 1) - iSrchLeft;
			memmove(&this->piData[iSrchLeft + 1],
					&this->piData[iSrchLeft],
					sizeof(int) * iTmp);
			this->piData[iSrchLeft] = iInsData;
		}
	}
	return;
}

} // namespace alg

