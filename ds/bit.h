

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
	// build the bit from the iterarors
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
	return subFunc(pointQuery(r), pointQuery(l));
}


}
}

#endif
