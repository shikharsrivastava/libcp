//19:55

#ifndef LIBCP_BIT
#define LIBCP_BIT

#include<bits/stdc++.h>
namespace libcp {
namespace ds {

template <typename T, typename F>
class Bit
{
	public:
	// typedefs
	typedef int size_type;
	typedef F	func_type;

	private:
	// data members
	

	public:
	// constructors
	Bit();
	Bit(size_type n);
	template <typename I>
	Bit(I s, I e, func_type addFunc);


	// Bit functions
	void

};



}
}

#endif
