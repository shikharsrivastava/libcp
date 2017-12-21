#ifndef LIBCP_TRIE
#define LIbCP_TRIE
#include<bits/stdc++.h>
#include<functional>

namespace libcp {
namespace ds {

template <typename T>
class Trie {

	public:
	typedef int 	size_type;
	typedef Node 	node_type;

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

	size_type 				N;
	std::vector<node_type>	trie;
	size_type				object_count;
	size_type				index;
	
	public:
	// constructors	
	Trie();
	Trie(size_type n);

	// Trie functions
	template <typename I, typename F = std::equal_to<T>>
	void insert(I s, I e, F equalFunc = F());

	template <typename I, typename F = std::equal_to<T>>
	void remove(I s, I e, F equalFunc = F());
	

	template <typename I, typename F = std::equal_to<T>>
	bool contains(I s, I e, F euqlaFunc = F());

	template <typename I, typename F = std::equal_to<T>>
	size_type count(I s, I e, F equalFunc = F());
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

template <typename T>
template <typename I, typename F>
void Trie<T>::insert(I s, I e, F equalFunc)
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

template <typename T>
template <typename I, typename F>
void Trie<T>::remove(I s, I e, F equalFunc)
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

template <typename T>
template <typename I, typename F>
bool Trie<T>::contains(I s, I e, F equalFunc)
{
	int ind = 0;
	while(s != e && trie[ind].next.count(*s))
	{
		ind = trie[ind].next[*s];
		s++;
	}

	return trie[ind].finished > 0;

}

template <typename T>
template <typename I, typename F>
typename Trie<T>::size_type Trie<T>::count(I s, I e, F equalFunc)
{
}	

// Deestructor

template <typename T>
Trie<T>::~Trie()
{
}

} // namespace ds ends
} // namespace libcp ends


#endif

