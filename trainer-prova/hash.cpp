#include <iostream>
#include <list>
#include<vector>
using namespace std;

struct KeyValue{
    int key;
    int value;
    KeyValue(int k, int v) : key(k), value(v) {}
};

class HashTable{
    private:
    int size;
    vector<list<KeyValue>>table; //Vetor de listas de KeyValue.

    int hashFuncition(int key){
        return key % size;
    }
    public:
    HashTable(int tableSize) : size(tableSize){
        table.resize(size);
    }
    void insert(int key, int value){
        int index = hashFuncition(key);
        for (auto& kv : table[index]){
            if(kv.key == key){
                kv.value = value;
                return;
            }
        }
    }
};