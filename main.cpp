#include "part1.h"
#include "part2.h"

#include <iostream>
using namespace std;

int main()
{
	vector<int> a{1, 2, 3, 4, 5, 1, 2, 3};
	cout << has_duplicates(a) << '\n';

	for (int i : get_duplicates(a))
	{
		cout << i << ' ';
	}
	cout << '\n';
	cout << "\nend";
}