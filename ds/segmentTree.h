#ifndef SEGMENTTREE
#define SEGMENTTREE
#include<bits/stdc++.h>
#include<functional>
namespace libcp {
namespace ds {
/*
 * Segment Tree class where
 * T - is the type of Node in segment Tree
 * F - the merge function for two nodes of type T
 */
template <typename T, typename F>
class SegmentTree {

	private:
		int 			size;
		int 			N;
		std::vector<T>	tree;
		int 			L;
		int 			R;
		F				mergeFunc;
		
	public:
		// Constructors
		SegmentTree(F func);
		SegmentTree(int n, F func);
		template <typename I>
		SegmentTree(I l, I r, F func);
		
		// build functions
		template <typename I>
		void build(I l, I r, int i = 1);
		
		// query functions
		T doActualQuery(int l, int r, int L, int R, int i = 1);
		T query(int l, int r);

		// Getters
		const int& getArraySize();

		// void Setters
		void setArraySize(int n);
		void setFunction(F func);
		// Destructors
		~SegmentTree();
};

		/////////////////////
		//class SegmentTree 
		/////////////////////

// Constructors
template <typename T, typename F>
SegmentTree<T, F>::SegmentTree(F func)
: N(100001)
, mergeFunc(func)
, tree(std::vector<T>(4*N+1))
{
	L = 1;
   	R = 100000;

}
template <typename T, typename F>
SegmentTree<T, F>::SegmentTree(int n, F func)
: N(n)
, mergeFunc(func)
, tree(std::vector<T>(4*N+1))
{
	L = 1;
	R = N;
}

template <typename T, typename F>
template <typename I>
SegmentTree<T, F>::SegmentTree(I l, I r, F func)
: N(r-l+1)
, tree(std::vector<T>(4*N+1))
, mergeFunc(func)
{

	L = 1;
	R = std::distance(l, r) + 1;
	build(l,r);
}

// Build functions

/* Builds the Tree
 * l - iterator to the begining of array
 * r - iterator to the end of the aarray (inclusive)
 * i - index of the segement tree (defaults to 1)
 */
template <typename T, typename F>
template <typename I>
void SegmentTree<T, F>::build(I l, I r, int i) {
	
	if (l == r)
	{
		tree[i] = *l;
		return;
	}

	I m = std::next(l, std::distance(l,r)/2);
	build(l, m, i*2);
	build(m+1, r, i*2+1);
	tree[i] = mergeFunc(tree[2*i], tree[2*i+1]);
}

// Query functions
/* Query wrapper to put default values of L and R
 * l - the begining of range to query
 * r - the end of the range to query
 */
template <typename T, typename F>
T SegmentTree<T, F>::query(int l, int r)
{
	return doActualQuery(l, r, L, R, 1);
}

/* The recursive function to query the tree
 * l - the begining of range to query
 * r - the end of rrange to query
 * L - the begining of the current window
 * R - the end of the current window
 * i - current index in the tree
 */
template <typename T, typename F>
T SegmentTree<T, F>::doActualQuery(int l, int r, int L, int R, int i)
{
	if(l > R || r < L)
	{
		T ret(0);
		return ret;
	}
	else if(L >= l && R <= r)
		return tree[i];
	else
	{
		int M = L + (R-L)/2;
		T left = doActualQuery(l, r, L, M, i*2);
		T right = doActualQuery(l, r, M+1, R, i*2+1);
		return mergeFunc(left, right);
	}
}

// Getters
template <typename T, typename F>
const int& SegmentTree<T, F>::getArraySize()
{
	return N;
}

//Setters
template <typename T, typename F>
void SegmentTree<T, F>::setArraySize(int n)
{
	N = n;
	tree.resize(4*N+1);
	return;
}

template <typename T, typename F>
void SegmentTree<T, F>::setFunction(F func)
{
	mergeFunc = func;
	return;
}

// Destructors

template<typename T, typename F>
SegmentTree<T, F>::~SegmentTree()
{

}


/* wrapper make_ functions
 * to build tree easily
 */

template <typename T, typename F = std::plus<T>>
SegmentTree<T, F>make_segmentTree(F mergeFunc = F())
{
	return SegmentTree<T, F>(mergeFunc);
}

template <typename T, typename F = std::plus<T>>
SegmentTree<T, F> make_segmentTree(int n, F mergeFunc = F())
{
	return SegmentTree<T, F>(n, mergeFunc);
}

template <typename T, typename I, typename F = std::plus<T>>
SegmentTree<T, F> make_segmentTree(I l, I r, F mergeFunc = F())
{
	return SegmentTree<T, F>(l, r, mergeFunc);
}


}
}



#endif
