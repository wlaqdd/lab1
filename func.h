#pragma once
#include <iostream>
#include <chrono> // время

#include <vector>
#include <list>
#include <set>
#include <unordered_set>

#include <algorithm> // find

using namespace std;
using namespace std::chrono;

void ins_time(int n = 1)
{
	cout << "N: " << n << '\n';
	{
		vector<int> cont;
		auto t1 = steady_clock::now();
		for (int i{}; i < n; ++i)
		{
			cont.insert(cont.begin(), i);
		}
		auto t2 = steady_clock::now();
		auto time = duration<double>(t2 - t1).count();
		cout << "Vector insert to begin time: " << time << " sec." << '\n';
	}
	{
		vector<int> cont;
		auto t1 = steady_clock::now();
		for (int i{}; i < n; ++i)
		{
			cont.push_back(i);
		}
		auto t2 = steady_clock::now();
		auto time = duration<double>(t2 - t1).count();
		cout << "Vector push_back time: " << time << " sec." << '\n';
	}
	{
		list<int> cont;
		auto t1 = steady_clock::now();
		for (int i{}; i < n; ++i)
		{
			cont.insert(cont.begin(), i);
		}
		auto t2 = steady_clock::now();
		auto time = duration<double>(t2 - t1).count();
		cout << "List insert to begin time: " << time << " sec." << '\n';
	}
	{
		list<int> cont;
		auto t1 = steady_clock::now();
		for (int i{}; i < n; ++i)
		{
			cont.push_back(i);
		}
		auto t2 = steady_clock::now();
		auto time = duration<double>(t2 - t1).count();
		cout << "List push_back time: " << time << " sec." << '\n';
	}
	{
		set<int> cont;
		auto t1 = steady_clock::now();
		for (int i{}; i < n; ++i)
		{
			cont.insert(i);
		}
		auto t2 = steady_clock::now();
		auto time = duration<double>(t2 - t1).count();
		cout << "Set insert time: " << time << " sec." << '\n';
	}
	{
		unordered_set<int> cont;
		auto t1 = steady_clock::now();
		for (int i{}; i < n; ++i)
		{
			cont.insert(i);
		}
		auto t2 = steady_clock::now();
		auto time = duration<double>(t2 - t1).count();
		cout << "Unordered_set insert time: " << time << " sec." << '\n';
	}
}


void find_m(int n, int m)
{
	unordered_set<int> all_m; // рандомные m значений из диапазона [0 N)
	while (all_m.size() != m)
	{
		all_m.insert(rand() % n);
	}

	cout << "Find " << m << " elements in " << n << " size cont: \n";
	{
		vector<int> cont; // заполнение контейнера от [0 до N)
		for (int i{}; i < n; ++i)
		{
			cont.push_back(i);
		}

		auto ptr = all_m.begin();

		auto t1 = steady_clock::now();
		for (int j{}; j < m; ++j)
		{
			find(cont.begin(), cont.end(), *ptr);
			++ptr;
		}
		auto t2 = steady_clock::now();
		auto time = duration<double>(t2 - t1).count();
		cout << "Vector: " << time << " sec." << '\n';
	}
	{
		list<int> cont; // заполнение контейнера от [0 до N)
		for (int i{}; i < n; ++i)
		{
			cont.push_back(i);
		}

		auto ptr = all_m.begin();

		auto t1 = steady_clock::now();
		for (int j{}; j < m; ++j)
		{
			find(cont.begin(), cont.end(), *ptr);
			++ptr;
		}
		auto t2 = steady_clock::now();
		auto time = duration<double>(t2 - t1).count();
		cout << "List: " << time << " sec." << '\n';
	}
	{
		set<int> cont; // заполнение контейнера от [0 до N)
		for (int i{}; i < n; ++i)
		{
			cont.insert(i);
		}


		auto ptr = all_m.begin();

		auto t1 = steady_clock::now();
		for (int j{}; j < m; ++j)
		{
			cont.find(*ptr);
			++ptr;
		}
		auto t2 = steady_clock::now();
		auto time = duration<double>(t2 - t1).count();
		cout << "Set: " << time << " sec." << '\n';
	}
	{
		unordered_set<int> cont; // заполнение контейнера от [0 до N)
		for (int i{}; i < n; ++i)
		{
			cont.insert(i);
		}


		auto ptr = all_m.begin();

		auto t1 = steady_clock::now();
		for (int j{}; j < m; ++j)
		{
			cont.find(*ptr);
			++ptr;
		}
		auto t2 = steady_clock::now();
		auto time = duration<double>(t2 - t1).count();
		cout << "Unordered set: " << time << " sec." << '\n';
	}
}