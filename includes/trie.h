#ifndef LIBCP_TRIE
#define LIBCP_TRIE
#include<bits/stdc++.h>
#include<functional>

namespace libcp {
namespace ds {

template <typename T>
class Trie {


	private:
	struct Node
	{
		std::unordered_map<T, int> 	next;
		int 						finished;
		int 						count;
		Node()
		: next()
		, finished(0)
		, count(0)
		{}

	};

	public:
	typedef int 	size_type;
	typedef Node 	node_type;


	size_type 				N;
	std::vector<node_type>	trie;
	size_type				object_count;
	size_type				index;
	
	public:
	// constructors	
	Trie();
	Trie(size_type n);

	// Trie functions
	template <typename I>
	void insert(I s, I e);

	template <typename I>
	void remove(I s, I e);
	

	template <typename I>
	bool contains(I s, I e);

	template <typename I>
	size_type count(I s, I e);
	// Getters
	const size_type& size();

	// Destructor
	~Trie();
};

	///////////////
	// class Trie
	///////////////
	

// constructors

template <typename T>
Trie<T>::Trie()
: N(100001)
, trie(std::vector<node_type>(N))
, object_count(0)
, index(0)
{
}

template <typename T>
Trie<T>::Trie(size_type n)
: N(n)
, trie(std::vector<node_type>(N))
, object_count(0)
, index(0)
{
}


// Trie functions

/* 
 * Inserts into the trie
 * s - Iterator to begining of container
 * e - Iterator to end of the container
 */
template <typename T>
template <typename I>
void Trie<T>::insert(I s, I e)
{
	int ind = 0;
	while(s != e && trie[ind].next.count(*s))
	{
		ind = trie[ind].next[*s];
		trie[ind].count++;
		s++;
	}

	while(s != e)
	{
		trie[ind].next[*s] = ++index;
		ind = index;
		trie[ind].count++;
		++s;
	}
	trie[ind].finished++;
	return;
}

/*
 * Remove one instance from the trie
 * s - Iterator to the begining of container
 * e - Iterator to the end of container
 */

template <typename T>
template <typename I>
void Trie<T>::remove(I s, I e)
{
	if(!contains(s, e))
		return;

	int ind = 0;
	while(s != e && trie[ind].next.count(*s))
	{
		ind = trie[ind].next[*s];
		trie[ind].count--;
		s++;
	}
	trie[ind].finished--;

}

/*
 * Checks if trie containes the iterable
 * s - Iterator to the begining of container
 * e - Iterator to the end of the conatiner
 */
template <typename T>
template <typename I>
bool Trie<T>::contains(I s, I e)
{
	int ind = 0;
	while(s != e && trie[ind].next.count(*s))
	{
		ind = trie[ind].next[*s];
		s++;
	}

	return trie[ind].finished > 0;

}
/*
 * Checks the number of instances of an iterable in the trie
 * s - Iterator to the begining of container
 * e - Iterator to the end of the container
 */
template <typename T>
template <typename I>
typename Trie<T>::size_type Trie<T>::count(I s, I e)
{
	int ind = 0;
	while(s != e && trie[ind].next.count(*s))
	{
		ind = trie[ind].next[*s];
		s++;
	}
	return trie[ind].finished;
}	

// Destructor

template <typename T>
Trie<T>::~Trie()
{
}

} // namespace ds ends
} // namespace libcp ends


#endif

