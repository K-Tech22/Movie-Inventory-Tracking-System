#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename T>
class HashTable
{
private:
  struct Node
  {
    std::string key;
    T value;
  };
  static const int max_size = 100;
  Node table[100];
  int numOfItems;

public:
  HashTable()
  {
    for (int i = 0; i < max_size; i++)
    {
      table[i].key = "";
    }
    numOfItems = 0;
  }

  int hashFunction(const std::string &key) const
  {
    int hash = 0;
    for (int i = 0; i < key.length(); i++)
    {
      hash += key[i];
    }
    return hash % max_size;
  }

  void insert(const std::string &key, const T value)
  {
    int index = hashFunction(key);
    if (table[index].key == "")
    {
      table[index].key = key;
      table[index].value = value;
    }
    else
    {
      int i = (index + 1) % max_size;
      while (i != index)
      {
        if (table[i].key == "")
        {
          table[i].key = key;
          table[i].value = value;
          numOfItems++;
          break;
        }
        i = (i + 1) % max_size;
      }
      if (i == index)
      {
        std::cerr << "Hashtable is full." << std::endl;
      }
    }
  }

  T get(const std::string key)
  {
    int index = hashFunction(key);
    if (table[index].key == key)
    {
      return table[index].value;
    }
    else
    {
      int i = (index + 1) % max_size;
      while (i != index && table[i].key != "")
      {
        if (table[i].key == key)
        {
          return table[i].value;
        }
        i = (i + 1) % max_size;
      }
      return NULL;
    }
  }

  vector<T> getAll()
  {
    vector<T> array;
    for (int i = 0; i < max_size; i++)
    {
      if (table[i].key != "")
      {
        array.push_back(table[i].value);
      }
    }
    return array;
  }
};