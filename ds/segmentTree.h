#ifndef SEGMENTTREE
#define SEGMENTTREE
#include<bits/stdc++.h>

namespace libcp {
namespace ds {
/*
 * Segment Tree class where
 * T - is the type of Node in segment Tree
 */
template <typename T>
class SegmentTree {

	private:
		int 			size;
		std::vector<T>	tree;
		
	public:
		// Constructors
		SegmentTree();
		SegmentTree(int n);

		// build functions
		template <typename I, typename F>
		void build(I l, I r, F func, int i = 1);
		
		// Destructors
		~SegmentTree();
};

		/* class SegmentTree */

// Constructors

template <typename T>
SegmentTree<T>::SegmentTree()
: tree(std::vector<T>(100000))
{
}
template <typename T>
SegmentTree<T>::SegmentTree(int n)
: tree(std::vector<T>(n))
{
}

// Build functions
// Assuming I is a random access iterator type
template <typename T>
template <typename I, typename F>
void SegmentTree<T>::build(I l, I r, F func, int i) {
	if (l == r)
	{
		tree[i] = *l;
		return;
	}

	int m = l + (r-l)/2;
	build(l, l+m, i*2);
	build(l+m+1, r, i*2+1);
	tree[i] = F(tree[2*1], tree[2*i+1]);
}


// Destructors

template<typename T>
SegmentTree<T>::~SegmentTree()
{

}

}
}



#endif
