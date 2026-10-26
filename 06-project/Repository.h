#pragma once
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <typename T>
class Repository
{
private:
    vector<T> items;

public:
    void add(T item)
    {
        items.push_back(item);
    }

    T get(int index)
    {
        if (index < 0 || index >= (int)items.size())
        {
            throw out_of_range("Item not found at index " + to_string(index));
        }
        return items[index];
    }

    int size()
    {
        return (int)items.size();
    }
};
