#ifndef CCIMP_VECTOR
#define CCIMP_VECTOR



#include <vector>

using namespace std;

template <class T>
class ccimp_vector {

private:
    vector<T> vect;

public:
    ccimp_vector();
    ~ccimp_vector();
    ccimp_vector(ccimp_vector& v); // copy constructor
    void operator=(ccimp_vector& v); // copy assignment
    ccimp_vector(ccimp_vector&& v); // move constructor
    void operator=(ccimp_vector&& v); // move assignment


    void operator+=(T& t);    //insert at the back


    void insert_front(T);
    void insert_back(T);
    T& look_at_last();
    T get_last_and_remove();
    bool is_empty();
    int size();
    T remove(int i);
    void remove_front();
    void remove_back();
    T at_element(int i);
};


template <class T>
ccimp_vector<T>::ccimp_vector() {   // constructor

}


template <class T>
ccimp_vector<T>::~ccimp_vector() {  // destructor

}


template <class T>
ccimp_vector<T>::ccimp_vector(ccimp_vector& v) {    //copy constructor
    for(int i = 0; i < v.size(); i++)
        vect.push_back(v.at_element(i));
}


template <class T>
void ccimp_vector<T>::operator=(ccimp_vector& v) {     // copy assignment operator
    for(int i = 0; i < v.size(); i++)
        vect.push_back(v.at_element(i));
}

template <class T>
void ccimp_vector<T>::operator+=(T& t){              //overloaded +=
    vect.push_back(t);
}

template <class T>
ccimp_vector<T>::ccimp_vector(ccimp_vector&& v) {   // move constructor
    for(int i = 0; i < v.size(); i++)
        vect.push_back(v.remove(i));
}


template <class T>
void ccimp_vector<T>::operator=(ccimp_vector&& v) {     // move assignment operator
    for(int i = 0; i < v.size(); i++)
        vect.push_back(v.remove(i));
}


template <class T>
void ccimp_vector<T>::insert_front(T t) {
    vect.insert(vect.begin(), t);
}


template <class T>
void ccimp_vector<T>::insert_back(T t) {
    vect.push_back(t);
}


template <class T>
bool ccimp_vector<T>::is_empty() {
    return vect.empty();
}

template <class T>
int ccimp_vector<T>::size() {
    return vect.size();
}


template <class T>
T ccimp_vector<T>::remove(int i) {
    T erasedElement = vect.at(i);
    vect.erase(vect.begin() + i);
    return erasedElement;
}


template <class T>
void ccimp_vector<T>::remove_front() {
    vect.erase(vect.begin());
}


template <class T>
void ccimp_vector<T>::remove_back() {
    vect.pop_back();
}


template <class T>
T ccimp_vector<T>::at_element(int i) {
    return vect.at(i);
}

template <class T>
T& ccimp_vector<T>::look_at_last(){
    return vect.at(size()-1);
}

template <class T>
T ccimp_vector<T>::get_last_and_remove(){
    if(!is_empty()){
        T temp = vect.back();
        vect.pop_back();
        return temp;
    }else
        return nullptr;
}

#endif // CCIMP_VECTOR
