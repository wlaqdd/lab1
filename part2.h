#include <iostream>
#include <chrono>

#include <vector>
#include <unordered_set>

#include <algorithm>

using namespace std;
using namespace std::chrono;

bool has_duplicates(const vector<int> &arr)
{
    auto p1{arr.begin()};
    while (p1 != arr.end())
    {
        auto p2 = p1 + 1;
        while (p2 != arr.end())
        {
            if (*p2 == *p1)
            {
                return true;
            }
            else
            {
                ++p2;
            }
        }
        ++p1;
    }
    return false;
}

unordered_set<int> get_duplicates(const vector<int> &arr)
{
    unordered_set<int> dupl;
    auto p1{arr.begin()};
    while (p1 != arr.end())
    {
        auto p2 = p1 + 1;
        while (p2 != arr.end())
        {
            if (*p2 == *p1)
            {
                dupl.insert(*p1);
                break;
            }
            else
            {
                ++p2;
            }
        }
        ++p1;
    }
    return dupl;
}

bool better_has_duplicates(const vector<int> &arr)
{
    vector<int> s_arr{arr};
    if (s_arr.size() == 0)
    {
        return false;
    }

    sort(s_arr.begin(), s_arr.end());

    auto p1{s_arr.begin()};

    while (p1 != (s_arr.end() - 1))
    {
        auto p2 = p1 + 1;
        if (*p2 != *p1)
        {
            ++p1;
        }
        else
        {
            return true;
        }
    }
    return false;
}

unordered_set<int> better_get_duplicates(const vector<int> &arr)
{
    unordered_set<int> dupl;
    vector<int> s_arr{arr};
    if (s_arr.size() == 0)
    {
        return dupl;
    }

    sort(s_arr.begin(), s_arr.end());

    auto p1{s_arr.begin()};

    while (p1 != (s_arr.end() - 1))
    {
        auto p2 = p1 + 1;
        if (*p2 != *p1)
        {
            ++p1;
        }
        else
        {
            dupl.insert(*(p1++));
        }
    }
    return dupl;
}

void test_duplicated(int n)
{
    vector<int> a;

    for (int i{}; i < n; ++i)
    {
        a.push_back(rand() % 20);
    }

    cout << "N: " << n << '\n';
    {
        auto t1 = steady_clock::now(); // сейчас
        has_duplicates(a);
        auto t2 = steady_clock::now(); // после
        auto time = duration<double>(t2 - t1).count();
        cout << "Has duplicates time: " << time << " sec." << '\n';
    }
    {
        auto t1 = steady_clock::now(); // сейчас
        better_has_duplicates(a);
        auto t2 = steady_clock::now(); // после
        auto time = duration<double>(t2 - t1).count();
        cout << "Better has duplicates time: " << time << " sec." << '\n';
    }
    {
        auto t1 = steady_clock::now(); // сейчас
        get_duplicates(a);
        auto t2 = steady_clock::now(); // после
        auto time = duration<double>(t2 - t1).count();
        cout << "Get duplicates time: " << time << " sec." << '\n';
    }
    {
        auto t1 = steady_clock::now(); // сейчас
        better_get_duplicates(a);
        auto t2 = steady_clock::now(); // после
        auto time = duration<double>(t2 - t1).count();
        cout << "Better get duplicates time: " << time << " sec." << "\n\n";
    }
}