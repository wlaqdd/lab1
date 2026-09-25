#include "part1.h" // ins_time find_m
#include "part2.h" //

#include <iostream>
using namespace std;

int main()
{
	ins_time(10);
	ins_time(100);
	ins_time(1000);
	ins_time(10000);

	find_m(10, 2);
	find_m(100, 20);
	find_m(1000, 200);
	find_m(10000, 2000);

	test_duplicated(10);
	test_duplicated(100);
	test_duplicated(1000);
	test_duplicated(10000);

	cout << "Done\n";
	return 0;
}