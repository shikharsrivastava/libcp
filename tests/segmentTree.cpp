#include "../segmentTree.h"
using namespace std;
using namespace libcp::ds;


int mf(const int& a, const int& b)
{
	return a + b;
}
int main()
{
	vector<int> a{1,2,3,4,5,6};
	auto s = make_segmentTree<int>(a.begin(), a.end()-1, mf);
	
	std::cout<<"Constructed \n";

	int n,l,r;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin >> l >> r;
		cout << s.query(l,r)<<endl;
	}

	return 0;

		
}
