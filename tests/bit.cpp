#include "../bit.h"

using namespace std;
using namespace libcp::ds;


int main()
{
	vector<int> a{1,2,3,4,5,6};

	auto bt = make_bit<int>(a.begin(), a.end());
	int n, l , r;
	cin >> n;
	while(n > 0)
	{
		cin >> l >> r;
		cout << bt.rangeQuery(l, r)<< endl;
	}
}
