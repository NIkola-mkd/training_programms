#pragma once
#include "Exception.h"

template <class T>
class DynamicArray
{

private:

	T* arrptr_;
	size_t size_;
	size_t limit_;
	static const size_t LIMIT_STEP = 6;

	void expand()
	{
		limit_ += LIMIT_STEP;
		T* newptr = new T[limit_];
		for (int i = 0; i < size_; i++)
		{
			newptr[i] = arrptr_[i];
		}
		delete[] arrptr_;
		arrptr_ = newptr;
	}

	DynamicArray(const DynamicArray&);
	DynamicArray& operator=(const DynamicArray&);

public:

	DynamicArray()
	{
		size_ = 0;
		limit_ = LIMIT_STEP;
		arrptr_ = new T[limit_];
	}

	~DynamicArray()
	{
		delete[] arrptr_;
	}

	size_t getSize()
	{
		return size_;
	}

	bool isEmpty()
	{
		return !size_;
	}

	void add(const T& item)
	{
		if (size_ == limit_)
		{
			expand();
		}
		arrptr_[size_++] = item;
	}

	T& operator[](const int index)
	{
		if (index < 0 || index >= size_)
		{
			throw Exception("Index out of range!");
		}
		return arrptr_[index];
	}

};
