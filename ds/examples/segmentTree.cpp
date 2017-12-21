#include "../segmentTree.h"

using namespace std;
using namespace libcp::ds;

/*
 * Simple example to make a segment tree
 * on an integer array
 * */
int main()
{
	// Number of elements in the array
	int n;
	cin >> n;

	// The array. The 'SomeType' in 'int'
	vector<int> arr(n);

	for(int i=0;i<n;i++)
		cin >> arr[i];

	// building the segment tree on the array. The Node type is 'int'
	auto tree = make_segmentTree<int>(arr.begin(), arr.end()-1);

	int queryCount, l, r;
	cin >> queryCount;

	while(queryCount--)
	{
		cin >> l >> r;
		cout << "Sum from "<< l << " To "<< r << " = " << tree.query(l,r) << endl; 
	}
	return 0;
}
