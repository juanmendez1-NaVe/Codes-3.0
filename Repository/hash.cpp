#include <iostream>
#include <vector>
#include <list>
#include <string>

template <typename k, typename v>
class HashNode {
private:
    k key;
    v val;
public:
    HashNode(k _key, v _val) : key(_key), val(_val) {}
    k getkey() const { return key; }   // ← agregado const
    v& getval()      { return val; }   // ← cambiado a v& (retorna referencia)
    void setval(v _val) { val = _val; }
};

template <typename k, typename v>
class hashTable {
private:
    std::vector<std::list<HashNode<k, v>*>> table;
    int capacity;
    int sz;

    int hashFunction(k key) {
        return std::hash<k>{}(key) % capacity;
    }

public:
    hashTable(int _capacity = 10) : capacity(_capacity), sz(0) {
        table.resize(capacity);
    }

    ~hashTable() {
        clear();
    }

    void insert(k key, v value) {
        int index = hashFunction(key);
        for (auto node : table[index]) {
            if (node->getkey() == key) {
                node->setval(value);
                return;
            }
        }
        table[index].push_back(new HashNode<k, v>(key, value));
        sz++;
    }


    std:: pair<bool, v> find(k key){
        int index = hashFunction(key);
        for (HashNode* node : table[index]) {
            if (node->getkey() == key) {
                return std::make_pair(true, node->getval());  // ← ahora válido porque getval() retorna v&
            }
        }
        return std::make_pair(false, v());
    }

    void erase(k key) {
        int index = hashFunction(key);
        auto& bucket = table[index];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if ((*it)->getkey() == key) {
                delete *it;
                bucket.erase(it);
                sz--;
                return;
            }
        }
    }

    void clear() {
        for (int i = 0; i < capacity; i++) {
            for (auto node : table[i]) {
                delete node;
            }
            table[i].clear();
        }
        sz = 0;
    }

    int size() { return sz; }
};

int main() {
    hashTable<std::string, std::string> tabla(100);

    tabla.insert("John Smith", "555-1234");
    tabla.insert("Sandra Dee", "555-6789");

    std::cout << *tabla.find("Sandra Dee") << std::endl;

    return 0;
}