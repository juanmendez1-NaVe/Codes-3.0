#include <iostream>
#include <cassert>

using namespace std;

template<typename T>
class Vector{
private:
    T* storage;
    unsigned int cap;
    unsigned int sz;
public:
    Vector(){
        cap= 5;
        storage = new T[cap];
        sz = 0;
    }
    Vector(unsigned int c){
        cap = c;
        storage = new T[cap];
        sz = 0;
    }
    Vector(const Vector<T>& other){
        cap= other.cap;
        sz = other.sz;
        storage = new T[cap];
        for (unsigned int i=0;i<sz; i++){
            storage[i] = other.storage[i];
        }
    }
    ~Vector() {
        delete [] storage;
    }
    unsigned int size() const {
        return sz;
    }
    bool empty() const {
        return sz == 0;
    }
    unsigned int capacity() const {
        return cap;
    }

    void push_back(const T& elem) {
        resize();
        storage[sz] = elem;
        sz++;
    }

    void erase(unsigned int pos){
        assert(pos<sz && sz != 0);
        for(unsigned int i=pos; i<sz; i++){
            storage[i]=storage[i+1];
        }
        sz--;
    }

void rangeErase(unsigned int from, unsigned int to) {
    assert(sz > 0 && from < to && to <= sz);
    unsigned int range = to - from;
    for (unsigned int i = from; i < sz - range; i++){
        storage[i] = storage[i + range];
    }

    sz -= range;
}

void push_front(const T& elem){
        resize();
        for(unsigned int i=sz; i>0;i--){
            storage[i]= storage[i-1];
        }
        storage[0] =elem;
        sz++;
    }

    void insert(const T& elem,unsigned int pos){
        assert(pos >= 0 && pos <= sz);
        resize();
        for(unsigned int i = sz;i>pos;i++)
        {
            storage[i] = storage[i-1];
        }
        storage[pos] = elem;
        sz++;
    }
    void pop_front(){
        assert(!empty());
        for(unsigned int i=0;i<sz-1;i++){
            storage[i] = storage[i+1];
        }
        sz--;
    }

    void pop_back() {
        assert(!empty());
        sz--;
    }

    const T& front() const {
        assert(!empty());
        return storage[0];
    }
    T& front() {
        assert(!empty());
        return storage[0];
    }
    const T& back() const {
        assert(!empty());
        return storage[sz-1];
    }
    T& back(){
        assert(!empty());
        return storage[sz-1];
    }

    const T& at(unsigned int pos) const{
        assert(pos < sz);
        return storage[pos];
    }
    T& at(unsigned int pos){
        assert(pos < sz);
        return storage[pos];
    }

    const T& operator[](unsigned int pos) const{
        return storage[pos];
    }
    T& operator[](unsigned int pos){
        return storage[pos];
    }

    void shrink_to_fit(){
        if (sz == cap) return;
        T* newStorage = new T[sz];
        for(unsigned int i=0;i < sz; i++){
            newStorage[i] = storage[i];
        }
        delete[]storage;
        storage = newStorage;
        cap = sz;
    }
private:
    void resize() {
        if(sz == cap){
            cout<<"real resize"<<endl;
            unsigned int newCapacity = cap*1.5;
            T* newStorage = new T[newCapacity];
            for(unsigned int i=0;i < sz; i++){
                newStorage[i] = storage[i];
            }
            delete[] storage;
            storage = newStorage;
            cap = newCapacity;
        }
    }
public:
    void print() const {
        cout<<"{";
        for(unsigned int i=0;i <sz; i++){
            cout << storage[i] << " ";
        }
        cout << "}" << endl;
    }

};


