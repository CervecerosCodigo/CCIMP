#ifndef DATA_KEY_VALUE_CONTAINER
#define DATA_KEY_VALUE_CONTAINER

#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

template<class K, class V>
/** This is a cool template class.
 * @brief The data_key_value_container class
 */
class data_key_value_container {


private:
    vector<pair<K,V>> data_v;

public:
    void push(K const&, V const&);
    void pop();
    pair<K,V> top() const;
    bool empty() const{
        return data_v.empty();
    }
    void print_data();
    int size()
    {
        return data_v.size();
    }
};


template<class K, class V>
void data_key_value_container<K,V>::push(const K& key_el, const V& val_el){
    data_v.push_back(make_pair(key_el, val_el));
}

template<class K, class V>
void data_key_value_container<K,V>::pop()
{
    if(data_v.empty())
        throw out_of_range("data_key_value_container: stack out of range");

    data_v.pop_back();
}

template<class K, class V>
pair<K, V> data_key_value_container<K,V>::top() const
{
    if(data_v.empty())
        throw out_of_range("data_key_value_container: stack out of range");

    return data_v.back();
}


template<class K, class V>
/** Used mainly for local debugging
 * @brief data_key_value_container<K, V>::print_data
 */
void data_key_value_container<K,V>::print_data(){

    for(const auto& p : data_v){
        cout << p.first << ", " << p.second << endl;
    }
}

#endif // DATA_KEY_VALUE_CONTAINER

