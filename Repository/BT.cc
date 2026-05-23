#include <iostream>
#include <locale.h>

using namespace std;

template <typename k, typename v>
class map {
private:
    class Node {
    private:
        k key;
        v val;
        Node* left;
        Node* right;
    public:
        Node() : key(), val(), left(nullptr), right(nullptr) {}
        Node(k a, v b) : key(a), val(b), left(nullptr), right(nullptr) {}
        
        bool hasleft() const { return left != nullptr; }
        bool hasright() const { return right != nullptr; }
        const k& getkey() const { return key; }
        v& getval() { return val; }
        Node* getleft() { return left; }
        Node* getright() { return right; }
        
        void setleft(Node* l) { left = l; }
        void setright(Node* r) { right = r; } 
        void setval(const v& value) { val = value; } 
    };

    Node* root;
    unsigned int sz;

    //cool
    Node* insert(const k& key, const v& val, Node* n) {
        if (n == nullptr) {
            sz++;
            return new Node(key, val);
        }

        if (key < n->getkey()) {
            n->setleft(insert(key, val, n->getleft()));
        } 
        else if (n->getkey() < key) {
            n->setright(insert(key, val, n->getright()));
        } 
        else {
            n->setval(val); 
        }
        return n;
    }



public:
    map() : root(nullptr), sz(0) {}

    unsigned int size() const { return sz; }
    bool empty() const { return root == nullptr; }

    void insert(const k& key, const v& val) {
        root = insert(key, val, root);
    }

   
    void print() const {
        if (empty()) {
            cout << "{}";
        } else {
            cout << "{ ";
            print(root); 
            cout << "}";
        }
        cout << endl;
    }

private:
    void setkey(const k& newKey) { key = newKey; }
    Node* findMin(Node* n) {
    while (n->hasleft()) {
        n = n->getleft();
    }
    return n;
}
    
  
    void print(Node* n) const { 
        if (n == nullptr) {
            return;
        }
        
      
        print(n->getleft()); 
        
        cout << "[" << n->getkey() << ":" << n->getval() << "] ";
        
        print(n->getright());
    }


    

    Node* remove(const k& key, Node* n){
        if(n==nullptr){
            return n;
        }
        if (key< n->getkey()){
        n->setleft(remove(key, n->getleft()));
        return n;
    }
        else if (n-> getkey()< key){
        n->setright(remove(key, n->getright()));
        return n;
    }
        else{
            if(!n->hasleft()&& !n->hasright()){
                delete n;
                sz--;
            }
            else if(!n->hasleft()){
                Node* p=n->getright();
                delete n;
                sz--;
                return p;
            }
            else if(!n->hasright()){
                Node* p=n->getleft();
                delete n;
                sz--;
                return p;
            }
            else{
                Node* m=findmin(n->getright());
                n->setkey(m->getkey());
                n->setval(m->getval());
                n->setright(remove(m->getkey(), n->getright()));
            }
        }
    }
};

int main(){
    setlocale(LC_ALL, "spanish");
    map<int, string> Map;
    Map.insert(10, "Hola");
    Map.insert(1, "Adios");
    Map.print();
    cout << "El tamaño del mapa es: " << Map.size() << endl;
    
    return 0;
}