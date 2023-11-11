#ifndef VECTOR_H
#define VECTOR_H

#include <cstdlib>
#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std;

template <typename T>
class Vector
{
public:
	explicit Vector(int initSize = 0)
		: theSize( initSize ),
		theCapacity( initSize + SPARE_CAPACITY )
	{ data = new T[theCapacity]; }

	Vector(int initSize, int initVal)
		:theSize(initSize),
		theCapacity(initSize + SPARE_CAPACITY)
	{
		data = new T[theCapacity];
		for (int i = 0; i < theCapacity; i++)
			data[i] = initVal;
	}

	Vector(const Vector& rhs)
		: theSize( rhs.theSize ),
		theCapacity( rhs.theCapacity ),
		data( nullptr )
	{
		data = new T[theCapacity];
		for (int k = 0; k < theSize; ++k)
			data[k] = rhs.data[k];
	}

	Vector(Vector&& rhs)
		:theSize{ rhs.theSize}, theCapacity{rhs.theCapacity},
		data{rhs.data}
	{
		rhs.data = nullptr;
		rhs.theSize = 0;
		rhs.theCapacity = 0;
	}

	Vector& operator= (Vector&& rhs)
	{
		swap(theSize, rhs.theSize);
		swap(theCapacity, rhs.theCapacity);
		swap(data, rhs.data);
		return *this;
	}

	Vector& operator= (const Vector& rhs)
	{
		Vector copy = rhs;
		std::swap(*this, copy);
	return *this;
	}

	void clear()
	{
		theSize = 0;
	}

	~Vector()
	{
		delete[] data;
	}

	bool empty() const
	{
		return size() == 0;
	}

	int size() const
	{
		return theSize;
	}

	int capacity() const
	{
		return theCapacity;
	}

	T& operator[] (int index)
	{
		assert(index >= 0 && index < theSize);
		return data[index];
	}

	const T& operator[] (int index) const
	{
		assert(index >= 0 && index < theSize);
		return data[index];
	}

	void resize(int newSize)
	{
		if (newSize > theCapacity)
			reserve(newSize * 2);
		theSize = newSize;
	}

	void reserve(int newCapacity)
	{
		if (newCapacity < theSize)
			return;
		T* newArray = new T[newCapacity];
		for (int k = 0; k < theSize; ++k)
			newArray[k] = std::move(data[k]);

		theCapacity = newCapacity;
		std::swap(data, newArray);
		delete[] newArray;
	}

	void push_back(const T& x)
	{
		if (theSize == theCapacity)
			reserve(2 * theCapacity + 1);
		data[theSize++] = x;
	}

	void pop_back()
	{
		assert(theSize >= 1);
		--theSize;
	}

	const T& back() const
	{
		assert(theSize >= 1);
		return data[theSize - 1];
	}
	//2
	void reverse()
	{
		int i = 0;
		int j = theSize-1;
		while(i < j) {
		std::swap((*this)[i],(*this)[j]);
		i++;
		j--;
		}
	}
	//3
	void replace(T oldval, T newval)
	{
		for(int i = 0; i < theSize; i++){
			if((*this)[i] == oldval){
				(*this)[i] = newval;
			}
		}

	}
	//4
	const T& front() const
	{
		assert(theSize >= 1);
		return data[0];

	}

	typedef T* iterator;
	typedef const T* const_iterator;

	iterator begin()
	{
		return &data[0];
	}

	const_iterator begin() const
	{
		return &data[0];
	}

	iterator end()
	{
		return &data[size()];
	}

	const_iterator end() const
	{
		return &data[size()];
	}
	// 1
	typedef T* reverse_iterator;
	typedef const T* const_reverse_iterator;

	reverse_iterator rbegin()
	{
		return &data[size()-1];
	}

	const_reverse_iterator rbegin() const
	{
		return &data[size()-1];
	}

	reverse_iterator rend()
	{
		return &data[-1];
	}

	const_reverse_iterator rend() const
	{
		return &data[-1];
	}

	static const int SPARE_CAPACITY = 2;

private:
	int theSize;
	int theCapacity;
	T* data;
};

#endif
