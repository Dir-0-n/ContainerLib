#pragma once

#include <cstring>

template <class T>
class Vector
{
	unsigned int m_size{ 0 };
	unsigned int m_capacity{ 0 };

	T* m_data{ nullptr };

public:

	Vector() = default;

	Vector(unsigned int size)
		: m_size{ size }
		, m_capacity{ size }
		, m_data{ new T[m_capacity]{} }
	{
	}

	Vector(unsigned int size, const T& value)
		: Vector(size)
	{
		for (unsigned int i = 0; i < m_size; ++i)
		{
			m_data[i] = value;
		}
	}

	/* TODO
	* Vector(const Vector& other);
	* Vector(Vector&& other);
	*/

	~Vector()
	{
		delete[] m_data;
	}

	const T& operator[](unsigned int index) const
	{
		return m_data[index];
	}

	unsigned int capacity() const noexcept
	{
		return m_capacity;
	}

	bool empty() const noexcept
	{
		return m_size == 0;
	}

	void erase(unsigned int index)
	{
	}

	void insert(unsigned int index, const T& value)
	{
	}

	void insert_end(const T& value)
	{
		if (m_size >= m_capacity)
		{
			// growth factor = 2
			reserve(2 * m_capacity);
		}

		m_data[m_size++] = value;
	}

	void reserve(unsigned int newCapacity)
	{
		T* tmp = new T[newCapacity]{};
		memcpy(tmp, m_data, sizeof(T) * m_size);
		delete[] m_data;
		m_data = tmp;
		m_capacity = newCapacity;
	}

	unsigned int size() const noexcept
	{
		return m_size;
	}
};
