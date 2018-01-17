# libcp
libcp is a library for competitive programming and has code for commonly used data structures and algorithms. 

## DS
It has some of the most commonly used data structures in competitive programming. All the data structures are in the namesace libcp::ds .For now it has -

### Segment Tree
Segment tree doensn't need any introduction. You can read about it [here](https://codeextractor.wordpress.com/). The information you need to supply is the node structure of the segment tree and any merge function that will be used to merge the nodes. Let's see its generic use. You can find easy examples [here](./ds/examples/segmentTree.cpp)
```C++
class Node
{
// The node type to be used in tree
};

Node mergeFunc(const Node& a, const Node& b)
{
// Implements the logic to merge two nodes and return merged node
// By defualt the operator+ of the Node class will be used to merge
}
// If you have an array on which you want to build the tree
vector<SomeType> v;
// Note - If you want to build segment tree on any non primitive type you should have operator= overloaded in the Node class. In this case Node class should have operator= overloaded for object of class SomeType.

// 1st way to build the tree from array size
auto tree1 = make_segmentTree<Node>(6, mergeFunc);
tree1.build(arr.begin(), array.end()-1);
// 2nd Way to build the segment tree from array 
auto tree2 = make_segmentTree<Node>(arr.begin(), arr.end()-1, mergeFunc);
// Querying the tree
Node ans = tree1.query(5, 10);
```
### BIT (Fenwik Tree)
Binary indexed tree or Fenwick Tree is the next data structure implemented in this library. You can read about it [here](https://www.topcoder.com/community/data-science/data-science-tutorials/binary-indexed-trees/). The use is similar to the use of Segment tree. You need to provide the Node type to be used in BIT and the add and substract functions that adds a value of type "SomeType" to the type "Node" of the Bit. Let's see its generic use. You can find easy examples [here](./ds/examples/bit.cpp).

```C++
class Node
{
// The node type to be used in BIT
};
Node addFunc(const Node& a, const someType& b)
{
// This function will be used to add two nodes
// By default operator+ of the Node class will be used
}
Node subFunc(const Node& a, const someType& b)
{
// This function will be used to substract two nodes
// By default operator- of the Node class will be used
}
// If you have an array on which you want to build the tree
vector<SomeType> v;
// Note - If you want to build segment tree on any non primitive type you should have operator= overloaded in the Node class. In this case Node class should have operator= overloaded for object of class SomeType.

// 1st way to build the tree from array size
auto tree1 = make_bit<Node>(6, addFunc, subFunc);
// 2nd Way to build the BIT from array 
auto tree2 = make_bit<Node>(arr.begin(), arr.end()-1, addFunc, subFunc);
// Querying the tree
Node point = tree1.pointQery(5);
Node range = tree1.rangequery(2, 10);
```
### Trie
In progress
