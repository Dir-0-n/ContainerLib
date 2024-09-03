#pragma once

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
		, m_capacity{ m_size }
		, m_data{ new T[m_capacity] }
	{
	}

	Vector(unsigned int size, const T& value)
		: m_size{ size }
		, m_capacity{ m_size }
		, m_data{ new T[m_capacity] }
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

	unsigned int Capacity() const
	{
		return m_capacity;
	}

	bool Empty() const
	{
		return m_size == 0;
	}

	void Erase(unsigned int index)
	{
	}

	void Insert(unsigned int index, const T& value)
	{
	}

	unsigned int Size() const
	{
		return m_size;
	}
};
