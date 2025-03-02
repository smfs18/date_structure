#include <iostream>
#include <string>
using namespace std;

const int TABLE_SIZE = 101;
const string EMPTY = "";
const string DELETED = "DELETED";

string table[TABLE_SIZE];

int Hash(string key) {
    int h = 0;
    for (int i = 0; i < key.length(); i++) {
        h += key[i] * (i + 1);
    }
    return (19 * h) % TABLE_SIZE;
}

int findIndex(string key) {
    int index = Hash(key);
    for (int j = 0; j < 20; j++) {
        int probe = (index + j * j + 23 * j) % TABLE_SIZE;
        if (table[probe] == key) {
            return probe;
        }
        if (table[probe] == EMPTY) {
            break;
        }
    }
    return -1;
}

void insertKey(string key) {
    if (findIndex(key) != -1) return;
    int index = Hash(key);
    for (int j = 0; j < 20; j++) {
        int probe = (index + j * j + 23 * j) % TABLE_SIZE;
        if (table[probe] == EMPTY || table[probe] == DELETED) {
            table[probe] = key;
            return;
        }
    }
}

void deleteKey(string key) {
    int index = findIndex(key);
    if (index != -1) {
        table[index] = DELETED;
    }
}

int countKeys() {
    int count = 0;
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i] != EMPTY && table[i] != DELETED) {
            count++;
        }
    }
    return count;
}

void printTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i] != EMPTY && table[i] != DELETED) {
            cout << i << ":" << table[i] << endl;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = EMPTY;
        }

        int n;
        cin >> n;
        cin.ignore();
        for (int i = 0; i < n; i++) {
            string line;
            getline(cin, line);
            size_t colon_pos = line.find(':');
            if (colon_pos == string::npos) continue;
            string op = line.substr(0, colon_pos);
            string key = line.substr(colon_pos + 1);
            if (op == "ADD") {
                insertKey(key);
            } else if (op == "DEL") {
                deleteKey(key);
            }
        }

        cout << countKeys() << endl;
        printTable();
    }
    return 0;
}