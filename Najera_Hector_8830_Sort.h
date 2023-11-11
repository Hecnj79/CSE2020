#ifndef SORT_H_
#define SORT_H_

#include "Vector.h"
using namespace std;

template <typename T>
void insertionSort( Vector<T>& a, int& ops )
{
    ops = 0;
    for( int p = 1; p < a.size(); ++p)
    {
	ops++;
	T tmp = a[p];
	int j;
	for (j = p; j > 0 && tmp < a[j - 1]; --j)
	{
	    a[j] = a[j - 1];
	    ops++;
	}
	a[j] = tmp;
    }
}

template <typename T>
void selectionSort(Vector<T>& a, int& ops)
{
    ops = 0;
    int mindex;
    for (int i = 0; i < a.size(); i++)
    {
	ops++;
	mindex = i;
	for (int j = i; j < a.size(); j++)
	{
	    if (a[j] < a[mindex])
		mindex = j;
	    ops++;
	}
	std::swap(a[i], a[mindex]);
    }
}

template <typename T>
void mergeSort(Vector<T>& vec, int& ops)
{
    ops = 0;
    Vector<T> tmpvec(vec.size());
    mergeSort(vec, tmpvec, 0, vec.size() - 1, ops);
}

template <typename T>
void mergeSort(Vector<T>& vec, Vector<T>& tmpvec, int left, int right, int& ops)
{
    ops = 1;
    int leftops = 0;
    int rightops = 0;
    int mergeops = 0;
    if(left < right)
    {
	int center = (left + right) / 2;
	mergeSort(vec, tmpvec, left, center, leftops);
	mergeSort(vec, tmpvec, center + 1, right, rightops);
	merge(vec, tmpvec, left, center + 1, right, mergeops);

	ops = ops + leftops + rightops + mergeops;
    }
}

template <typename T>
void merge(Vector<T>& vec, Vector<T>& tmpvec, int leftPos, int rightPos, int rightEnd, int& ops)
{
    int leftEnd = rightPos - 1;
    int tmpPos = leftPos;
    int numElements = rightEnd - leftPos + 1;


    while(leftPos <= leftEnd && rightPos <= rightEnd)
	if(vec[leftPos] <= vec[rightPos])
	    tmpvec[tmpPos++] = vec[leftPos++];
	else
	    tmpvec[tmpPos++] = vec[rightPos++];

    while(leftPos <= leftEnd)
	tmpvec[tmpPos++] = vec[leftPos++];

    while(rightPos <= rightEnd)
	tmpvec[tmpPos++] = vec[rightPos++];

    for(int i = 0; i < numElements; ++i, -- rightEnd)
	vec[rightEnd] = tmpvec[rightEnd];

    ops = 2 * numElements;
}

#endif
