#include <iostream>
#include <string>

using namespace std;

const int SIZE = 10;

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
        while (keys[index] != key)
        {
            index++;
            index %= SIZE;
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

int main()
{
    HashTable<int, string> ht;
    ht.insertItem(10, "apple");
    ht.insertItem(12, "banana");
    ht.insertItem(22, "cherry");
    ht.insertItem(42, "durian");
    ht.insertItem(67, "elderberry");
    ht.display();
    ht.deleteItem(22);
    ht.display();
    cout << "Value for key 10: " << ht.find(10) << endl;
    cout << "Value for key 22: " << ht.find(22) << endl;

    HashTable<string, int> ht2;
    ht2.insertItem("apple", 10);
    ht2.insertItem("banana", 12);
    ht2.insertItem("cherry", 22);
    ht2.insertItem("durian", 42);
    ht2.insertItem("elderberry", 67);
    ht2.display();
    ht2.deleteItem("cherry");
    ht2.display();
    cout << "Value for key \"apple\": " << ht2.find("apple") << endl;
    cout << "Value for key \"cherry\": " << ht2.find("cherry") << endl;

    return 0;
}
