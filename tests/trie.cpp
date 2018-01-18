#include "../trie.h"


using namespace std;
using namespace libcp::ds;


int main()
{
	Trie<char> tr;

	std::string s1 = "hello";
	std::string s2 = "world";
	std::string s3 = "No worries\n";

	tr.insert(s1.begin(), s1.end());
	tr.insert(s2.begin(), s2.end());


	std::cout<< tr.contains(s1.begin(), s1.end())<<std::endl;
	std::cout<< tr.contains(s2.begin(), s2.end())<< std::endl;
	std::cout<< tr.contains(s3.begin(), s3.end())<< std::endl;
}
