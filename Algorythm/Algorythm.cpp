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

} // namespace alg

