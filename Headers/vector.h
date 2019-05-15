#ifndef Vector
#define VECTOR
#include<iostream>
#include<exception>
#include<iterator>
using std::cout;
using std::endl;
using std::size_t;
template <typename T>
class Vector
{
private:
	size_t cap;
	size_t sz;
	T* member;
public:
	//Constructor
	Vector() : cap(1), sz(0), member{new T[cap]} {}
	Vector(size_t s, T val) : cap(s), sz(s), member(new T[cap]) { std::fill_n(member, s, val); }
	Vector(const Vector& v)
	{
		sz = v.size();
		cap = v.capacity();
		for (int i = 0; i != sz; i++)
		{
			member[i] = v.member[i];
		}
	}
	Vector(Vector&& a)
	{
		a.member = nullptr;
		a.sz = 0;
	}
	Vector(size_t a) : cap(a), sz(a), member(new T[sz]) {}
	Vector(std::initializer_list<T> il) : cap(static_cast<int>(il.size())), sz(static_cast<int>(il.size())), member(new T[il.size()])
	{
		std::copy(il.begin(), il.end(), member);
	}
	//Member
	void assign(size_t a, const T& value)
	{
		T* temp = new T[a];
		for (int i = 0; i < a; i++)
		{
			temp[i] = value;
		}
		delete[] member;
		member = temp;
		sz = a;
		cap = a;
	}
	void assign(int start, int end)
	{
		if (start <= 0 || start > sz || end > sz) throw std::out_of_range("No value found");
		T* temp = new T[end - start];
		size_t count = start;
		for (int i = 0; i < end - start; i++)
		{
			temp[i] = member[count];
			count++;
		}
		delete[] member;
		member = temp;
		sz = end - start;
		cap = sz;
	}
	//Iterator
	T* begin()
	{
		if (sz <= 0) throw std::runtime_error("No value found");
		T* p_start = &member[0];
		return p_start;
	}
	const T* begin() const
	{
		if (sz <= 0) throw std::runtime_error("No value found");
		T* p_start = &member[0];
		return p_start;
	}
	T* end()
	{
		if (sz <= 0) throw std::runtime_error("No value found");
		T* p_end = &member[sz];
		return p_end;
	}
	const T* end() const
	{
		if (sz <= 0) throw std::runtime_error("No value found");
		T* p_end = &member[sz];
		return p_end;
	}
	T* rbegin()
	{
		if (sz <= 0) throw std::runtime_error("No value found");
		T* p_rstart = &member[sz - 1];
		return p_rstart;
	}
	const T* rbegin() const
	{
		if (sz <= 0) throw std::runtime_error("No value found");
		T* p_rstart = &member[sz - 1];
		return p_rstart;
	}
	T* rend()
	{
		if (sz <= 1) throw std::runtime_error("No value found");
		T* p_rend = &member[0];
		return --p_rend;
	}
	const T* rend() const
	{
		if (sz <= 1) throw std::runtime_error("No value found");
		T* p_rend = &member[-1];
		return --p_rend;
	}
	//Capacity
	size_t size() const { return sz; }
	size_t capacity() const { return cap; }
	double front()
	{
		if (sz == 0) throw std::out_of_range {"No value assigned"};
		return member[0];
	}
	double back()
	{
		if (sz == 0) throw std::out_of_range {"No value assigned"};
		return member[sz - 1];
	}
	bool empty()
	{
		if (sz == 0) return true;
		return false;
	}
	void reserve(size_t a)
	{
		if (a < sz) throw std::out_of_range {"size is bigger"};
		cap = a;
		T* temp = new T[cap];
		for (int i = 0; i != sz; i++)
		{
			temp[i] = member[i];
		}
		delete[] member;
		member = temp;
	}
	void shrink_to_fit()
	{
		if (cap > sz)
		{
			cap = sz;
			T* temp = new T[sz];
			for (int i = 0; i != sz; i++)
			{
				temp[i] = member[i];
			}
			delete[] member;
			member = temp;
		}
	}
	//Modifiers
	void swap(T* other)
	{
		T* temp;
		temp = *this;
	    *this = other;
	    other = temp;
	}
	void push_back(const T &a)
	{
		if (cap == sz)
		{
			cap *= 2;
			T* temp = new T[cap];
			for (int i = 0; i != sz; i++)
			{
				temp[i] = member[i];
			}
			temp[sz] = a;
			sz++;
			delete[] member;
			member = temp;
		}
		else
		{
			member[sz] = a;
			sz++;
		}
	}
	void pop_back()
	{
		if (sz = 0) throw std::runtime_error("No elements in container");
		T* temp = new T[cap];
		sz -= 1;
		for (int i = 0; i != sz; i++)
		{
			temp[i] = member[i];
		}
		delete[] member;
		member = temp;
	}
	void clear()
	{
		delete[] member;
		member = new T[cap];
		sz = 0;
	}
	void resize(size_t a)
	{
		T* temp = new T[a];
		if (a < sz)
		{
			sz = a;
			for (int i = 0; i < sz; i++)
			{
				temp[i] = member[i];
			}
			delete[] member;
			member = temp;
		}
		else
		{
			T* temp = new T[a];
			for (int i = 0; i < sz; i++)
			{
				temp[i] = member[i];
			}
			for (int i = sz; i < a; i++)
			{
				temp[i] = T();
			}
			delete[] member;
			member = temp;
			sz = a;
			if (cap < sz)
				cap = sz;
		}
	}
	T* erase(T* pos)
	{
		if (pos == member[sz - 1])
		{
			delete member[sz - 1];
			sz--;
			return end();
		}
		std::move(pos + 1, end(), pos);
		return pos;
	}
	T* erase(T* first, T* last)
	{
		size_t temp = 0;
		T* f = &member[first - member];
		if (first == last)
			return f;
		for (; first != last; first++)
		{
			(*first).~T();
			temp++;
		}

		memmove(f, last, (sz - (last - member))* sizeof(T));
		sz -= temp;
		return f;
	}
	void resize(size_t a, T value)
	{
		T* temp = new T[a];
		if (a < sz)
		{
			sz = a;
			for (int i = 0; i < sz; i++)
			{
				temp[i] = member[i];
			}
			delete[] member;
			member = temp;
		}
		else
		{
			for (int i = 0; i < sz; i++)
			{
				temp[i] = member[i];
			}
			for (int i = sz; i < a; i++)
			{
				temp[i] = value;
			}
			delete[] member;
			member = temp;
			sz = a;
			if (cap < sz)
				cap = sz;

		}
	}
	//Operators
	Vector<T> operator+(const Vector & b)
	{
		if (sz != b.size()) throw std::runtime_error("uncompatible size");
		auto size = sz;
		Vector c(size);
		for (auto i = 0; i != sz; i++)
		{
			c[i] = member[i] + b[i];
		}
		return c;
	}
	T& operator[](size_t i)
	{
		if (i < 0 || i >= size()) throw std::out_of_range {"Vector::operator[]"};
		return member[i];
	}
	const T& operator[](size_t i) const
	{
		if (i < 0 || i >= size()) throw std::out_of_range {"Vector::operator[]"};
		return member[i];

	}
	Vector<T>& operator=(Vector && a)
	{
		if (&a == this)
			return *this;
		delete[] member;
		member = a.member;
		sz = a.sz;
		cap = a.cap;
		a.member = nullptr;
		a.sz = 0;
		return *this;
	}
	Vector<T>& operator=(const Vector & v)
	{
		if (&v == this) return *this;

		T* temp = new T[v.cap];
		for (int i = 0; i != v.sz; i++)
		{
			temp[i] = v.member[i];
		}
		delete[] member;
		member = temp;
		sz = v.sz;
		return *this;
	}
	//Destructors
	~Vector() { delete[] member; }
};
#endif