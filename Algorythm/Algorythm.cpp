/*****************************************************************************
	order			@ My make sort library
	compiler		@ x86_64-w64-mingw32-gcc (cygwin x64)
	file name		@ Sorter.cpp
	creation date	@ 2016-07-05
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
	discription	@ Constructer
	argument	@ -
	return		@ -
	note		@ -
*****************************************************************************/
Algorythm::Algorythm()
{
	this->iSize = 0;
	this->piData = NULL;
}

/*****************************************************************************
	discription	@ Constructer with size
	argument	@ iSize = data size
	return		@ -
	note		@ -
*****************************************************************************/
Algorythm::Algorythm(int iSize)
{
	this->iSize = iSize;
	this->piData = new int[iSize]();
}

/*****************************************************************************
	discription	@ Destructor
	argument	@ -
	return		@ -
	note		@ -
*****************************************************************************/
Algorythm::~Algorythm()
{
	delete [] this->piData;
	this->piData = NULL;
}

/*****************************************************************************
	discription	@ Get data at index
	argument	@ iIdx = index
	return		@ 0 = succeed, else = error
	note		@ -
*****************************************************************************/
int Algorythm::get(int iIdx)
{
	if((this->piData == NULL) || (this->iSize <= iIdx)){
		return -1;
	}
	else{
		return this->piData[iIdx];
	}
}

/*****************************************************************************
	discription	@ set data at index
	argument	@ iIdx = index, iData = data
	return		@ 0 = succeed, else = error
	note		@ -
*****************************************************************************/
int Algorythm::set(int iIdx, int iData)
{
	if((this->piData == NULL) || (this->iSize <= iIdx)){
		return -1;
	}
	else{
		this->piData[iIdx] = iData;
	}
	return 0;
}

/*****************************************************************************
	discription	@ get data size
	argument	@ -
	return		@ data size
	note		@ -
*****************************************************************************/
int Algorythm::getSize()
{
	return iSize;
}

/*****************************************************************************
	discription	@ set data size
	argument	@ iSize = data size
	return		@ 0 = succeed, else = error
	note		@ deleted already existing data
*****************************************************************************/
int Algorythm::setSize(int iSize)
{
	if(this->piData != NULL){
		delete [] this->piData;
	}

	this->iSize = iSize;
	this->piData = new int[iSize]();

	return 0;
}

/*****************************************************************************
	discription	@ show all data
	argument	@ -
	return		@ -
	note		@ -
*****************************************************************************/
void Algorythm::show()
{
	if(this->iSize == 0){
		cout << "Data nothing." << endl;
	}
	else{
		cout << "Data Size: " << this->iSize << endl;
		for(int i = 0; i < this->iSize; i++){
			cout << this->piData[i] << endl;
		}
	}
	return;
}

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
	int iSorted;
	int iCnt;
	int iInsert;
	int iTmp;

	for(iSorted = 0; iSorted < (this->iSize - 1); iSorted++){
		iInsert = this->piData[iSorted + 1];

		iCnt = 0;
		// run to the sorted point
		while(iCnt <= iSorted){
			if(this->piData[iCnt] > iInsert){
				break;
			}
			iCnt++;
		}

		// displace(move) to behind the insert point.
		while(iCnt <= (iSorted + 1)){
			iTmp = this->piData[iCnt];
			this->piData[iCnt] = iInsert;
			iInsert = iTmp;
			iCnt++;
		}
	}
	return;
}

} // namespace alg

