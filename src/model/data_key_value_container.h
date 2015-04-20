#ifndef DATA_KEY_VALUE_CONTAINER
#define DATA_KEY_VALUE_CONTAINER

#include <iostream>
#include <vector>

template<typename K, typename V>

class data_key_value_container {


private:
    vector<pair<K,V>> data_v;

public:
    void push(K const&, V const&);
    void pop();
    T top() const;
    bool empty() const{
        return data_v.empty();
    }
    void print_data();

};

template<typename K, typename V>
void data_key_value_container::push(const K &, const V &){
    data_v.push_back(make_pair(K,V));
}


template<typename K, typename V>
void data_key_value_container::print_data(){

    for(const auto& p : data_v){
        std::cout << p.first << ", " << p.second << std::endl;
    }
}


#endif // DATA_KEY_VALUE_CONTAINER

