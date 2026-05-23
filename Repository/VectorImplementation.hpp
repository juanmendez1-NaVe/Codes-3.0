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
    std::cout << "{ ";
    for (unsigned int i = 0; i < sz; i++) {
        std::cout << storage[i];
        if (i < sz - 1) std::cout << " ";
    }
    std::cout << " }" << std::endl;
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



bool contains(const T &elem) const {
    for (unsigned int i = 0; i < sz; i++) {
        if (storage[i] == elem) {
            cout<<"1"<<endl;
            return true; 
        }
    }
    cout<<"0"<<endl;
    return false; 
}

int find(const T &elem) const{
     for (unsigned int i = 0; i < sz; i++) {
        if (storage[i] == elem) {
            //cout<<"index"i<<endl;
            return i; 
        }
    }
    cout<<"ou ou stinky"<<endl;
    return -1;
}

void remove(const T &elem){
    int pos = find(elem); 
    if (pos != -1) { 
        erase(pos);   
    }
    
}

 void replace(const T &oldVal, const T &newVal) {
    int pos = find(oldVal);  
    if (pos != -1) {
        storage[pos] = newVal;  
    }
}

    void remove_all(const T& elem) {
    unsigned int w = 0; 
    for (unsigned int i = 0; i < sz; i++) {
        if (storage[i] != elem) {
            storage[w] = storage[i];
            w++;
        }
    }
    sz = w;
}

 void replace_all(const T &oldVal, const T &newVal){ 
    for (unsigned int i = 0; i < sz; i++) {
        if (storage[i] == oldVal){
            storage[i]==newVal;
        }
    }


}

int count(const T &elem) const{
    unsigned int w = 0; 
    for (unsigned int i = 0; i < sz; i++) {
        if (storage[i] == elem) {
            w++;
        }   
    }
    cout<<w<<endl;
    return w;
}

Vector<int> indices_of(const T &elem) const{
    Vector<int> indices;  
    for (unsigned int i = 0; i < sz; i++) {
        if (storage[i] == elem) {
        indices.push_back(i);  
        }
    }
    indices.print();
    return indices;

}

 void swap(unsigned int i, unsigned int j){
    assert(i < sz && j < sz);
    if (i == j) return;
    T tmp = storage[i];  
    storage[i]= storage[j]; 
    storage[j]= tmp;      
}

    void reverse(){
    if (sz <= 1) return; 
    unsigned int i= 0;
    unsigned int j= sz - 1;
    while (i < j) {
        swap(i, j); 
        i++;
        j--;
    }
}

 void Simplerotate_left(unsigned int k){
    if (sz == 0) return;
    k = k % sz;
    if (k == 0) return;
    T* temp = new T[sz];
    for (unsigned int i = 0; i < sz; i++){
        unsigned int newPos = (i + (sz - k)) % sz;
        temp[newPos] = storage[i];
    }
    for (unsigned int i = 0; i < sz; i++){
        storage[i] = temp[i];
    }
    delete[] temp;
}

public:
    void rotate_left(unsigned int k) {
        if (sz == 0) return;
        k = k % sz;
        if (k == 0) return;
        RangeReverse(0, k - 1);
        RangeReverse(k, sz - 1);
        RangeReverse(0, sz - 1);
    }

    void rotate_right(unsigned int k) {
        if (sz == 0) return;
        k = k % sz;
        rotate_left(sz - k);
    }

   void sort(){
    if (sz > 1){
        int option = 0;
        cout << "Elija el algoritmo de ordenamiento:\n1. MergeSort\n2. QuickSort\nSeleccion: ";
        cin >> option; 

        if (option == 1) {
            mergeSort(0, sz - 1);
            cout << "Ordenado con MergeSort." << endl;
        } 
        else if (option == 2) {
            quickSort(0, sz - 1);
            cout << "Ordenado con QuickSort." << endl;
        }
        else {
            cout << "Opcion no valida." << endl;
        }
    }
}
    void quickSort(int low, int high) {
        if (low < high) {
            int PI = partition(low, high);
            quickSort(low, PI - 1);
            quickSort(PI + 1, high);
        }
    }

    void mergeSort(int left, int right){
        if (left < right) {
            int mid = left + (right - left) / 2;
            mergeSort(left, mid);
            mergeSort(mid + 1, right);
            merge(left, mid, right);
        }
    }
    void append(const Vector<T> &other){
    for (unsigned int i = 0; i < other.size(); i++) {
        push_back(other[i]);
    }
}
Vector<T> slice(unsigned int start, unsigned int end) const{
    assert(start <= end && end <= sz);
    Vector<T> result;
    for (unsigned int i = start; i < end; i++){
    result.push_back(storage[i]);
    }
    return result;
}
Vector<T>& operator=(const Vector<T> &other){
    if (this != &other){ 
    delete[] storage;
    sz = other.sz;
    cap = other.cap;
    storage = new T[cap];
    for (unsigned int i = 0; i < sz; i++){
    storage[i] = other.storage[i];
    }
}
return *this; 
}
private: 
    void RangeReverse(unsigned int from, unsigned int to){
        if (sz == 0 || from >= to) return;
        unsigned int i = from;
        unsigned int j = to;
        while (i < j) {
            swap(i, j);
            i++;
            j--;
        }
    }

    int partition(int low, int high) {
        T pivot = storage[high]; // pivot
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (storage[j] < pivot) {
                i++;
                swap(i, j);
            }
        }
        swap(i + 1, high);
        return i + 1;
    }

    void merge(int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;
        T* L = new T[n1];
        T* R = new T[n2];
        for (int i = 0; i < n1; i++) L[i] = storage[left + i];
        for (int j = 0; j < n2; j++) R[j] = storage[mid + 1 + j];
        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) { storage[k] = L[i]; i++; }
            else { storage[k] = R[j]; j++; }
            k++;
        }
        while (i < n1) { storage[k] = L[i]; i++; k++; }
        while (j < n2) { storage[k] = R[j]; j++; k++; }
        delete[] L;
        delete[] R;
    }

    public:
    
    bool any(bool (*p)(const T&)) const {
    for (unsigned int i = 0; i < sz; i++) {
        if (p(storage[i])) return true; 
    }
    return false;
}

bool all(bool (*p)(const T&)) const {
    for (unsigned int i = 0; i < sz; i++) {
        if (!p(storage[i])) return false; 
    }
    return true; 
}

bool none(bool (*p)(const T&)) const{
    return !any(p); 
}

Vector<T> filter(bool (*p)(const T&)) const {
    Vector<T> result;
    for (unsigned int i = 0; i < sz; i++) {
        if (p(storage[i])) { 
            result.push_back(storage[i]); 
        }
    }
    return result; 
}


template <typename Function> 
auto map(Function f) const {
    using R = decltype(f(std::declval<T>())); 
    
    Vector<R> result; 
    for (unsigned int i = 0; i < sz; i++) {
        result.push_back(f(storage[i])); 
    }
    return result;
}


template <typename Function>
void for_each(Function f) {
    for (unsigned int i = 0; i < sz; i++) {
        f(storage[i]); 
    }
}


using iterator = T*;
using const_iterator = const T*;


iterator begin() { return storage; }
const_iterator begin() const { return storage; }


iterator end() { return storage + sz; }
const_iterator end() const { return storage + sz; }

};





