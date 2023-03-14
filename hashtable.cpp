#include <iostream>
#include <string>

using namespace std;

const int SIZE = 100;

template <typename K, typename V>
class HashTable
{
private:
    K keys[SIZE];
    V values[SIZE];

public:
    HashTable()
    {
        for (int i = 0; i < SIZE; i++)
        {
            keys[i] = K();
            values[i] = V();
        }
    }

    int hashFunction(K key)
    {
        return hash<K>()(key) % SIZE;
    }

    void insertItem(K key, V value)
    {
        int index = hashFunction(key);
        while (keys[index] != K())
        {
            index++;
            index %= SIZE;
        }
        keys[index] = key;
        values[index] = value;
    }

    void deleteItem(K key)
    {
        int index = hashFunction(key);
        while (keys[index] != key)
        {
            index++;
            index %= SIZE;
        }
        keys[index] = K();
        values[index] = V();
    }

    V find(K key)
    {
        int index = hashFunction(key);
        int startingIndex = index;
        while (keys[index] != key)
        {
            index++;
            index %= SIZE;
            if (index == startingIndex)
            {
                return values[startingIndex];
            }
        }
        return values[index];
    }

    void display()
    {
        for (int i = 0; i < SIZE; i++)
        {
            if (keys[i] != K())
            {
                cout << keys[i] << " --> " << values[i] << endl;
            }
            else
            {
                cout << i << endl;
            }
        }
    }
};