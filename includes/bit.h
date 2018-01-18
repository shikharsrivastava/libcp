
#ifndef LIBCP_BIT
#define LIBCP_BIT

#include<bits/stdc++.h>
namespace libcp {
namespace ds {

template <typename T, typename AF, typename SF>
class Bit
{
	public:
	// typedefs
	typedef int size_type;
	typedef int index_type;
	typedef AF	add_func_type;
	typedef SF	sub_func_type;

	private:
	// data members
	size_type			N;
	std::vector<T>		bit;	
	add_func_type		addFunc;
	sub_func_type		subFunc;
	public:
	// constructors
	Bit(add_func_type addfunc, sub_func_type subfunc);
	Bit(size_type n, add_func_type addfunc, sub_func_type subfunc);
	template <typename I>
	Bit(I s, I e, add_func_type addfunc, sub_func_type subfunc);


	// Bit functions
	void update(index_type ind, T val);

	T pointQuery(index_type i);
	
	T rangeQuery(index_type l, index_type r);

	// Destructors
	~Bit();

};

template <typename T, typename AF, typename SF>
Bit<T, AF, SF>::Bit(add_func_type addfunc, sub_func_type subfunc)
: N(100001)
, bit(std::vector<T>(N))
, addFunc(addfunc)
, subFunc(subfunc)
{
}

template <typename T, typename AF, typename SF>
Bit<T, AF, SF>::Bit(size_type n, add_func_type addfunc, sub_func_type subfunc)
: N(n)
, bit(std::vector<T>(N))
, addFunc(addfunc)
, subFunc(subfunc)
{
}

template <typename T, typename AF, typename SF>
template <typename I>
Bit<T, AF, SF>::Bit(I s, I e, add_func_type addfunc, sub_func_type subfunc)
: N(e-s+2)
, bit(std::vector<T>(N))
, addFunc(addfunc)
, subFunc(subfunc)
{
	for(int ind = 1 ; s != e; s++, ind++)
		update(ind, *s);
}

// Bit functions
template <typename T, typename AF, typename SF>
void Bit<T, AF, SF>::update(index_type ind, T val)
{
	while(ind <= N)
	{
		bit[ind] = addFunc(bit[ind], val);
		ind += ind & -ind;
	}
}

template <typename T, typename AF, typename SF>
T Bit<T, AF, SF>::pointQuery(index_type ind)
{
	T ans(0);
	while(ind > 0)
	{
		ans = addFunc(ans, bit[ind]);
		ind -= ind & -ind;
	}
	return ans;
}

template <typename T, typename AF, typename SF>
T Bit<T, AF, SF>::rangeQuery(index_type l, index_type r)
{
	l--;
	return subFunc(pointQuery(r), pointQuery(l));
}

// Destructors

template <typename T, typename AF, typename SF>
Bit<T, AF, SF>::~Bit()
{
}

// wrapper make_functions
// for easy creation of bit
// with callbacks
// wouldn't need this in C++17 

template <typename T, typename AF = std::plus<T>, typename SF = std::minus<T> >
Bit<T, AF, SF> make_bit(AF addFunc = AF(), SF subFunc = SF())
{
	return Bit<T, AF, SF>(addFunc, subFunc);
}

template <typename T, typename AF = std::plus<T>, typename SF = std::minus<T> >
Bit<T, AF, SF> make_bit(int n, AF addFunc = AF(), SF subFunc = SF())
{
	return Bit<T, AF, SF>(n, addFunc, subFunc);
}

template <typename T, typename I, typename AF = std::plus<T>, typename SF = std::minus<T> >
Bit<T, AF, SF> make_bit(I s, I e, AF addFunc = AF(), SF subFunc = SF())
{
	return Bit<T, AF, SF>(s, e, addFunc, subFunc);
}
}
}

#endif
