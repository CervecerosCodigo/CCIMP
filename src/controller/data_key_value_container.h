#ifndef DATA_KEY_VALUE_CONTAINER
#define DATA_KEY_VALUE_CONTAINER

#include <iostream>
#include <vector>
#include <stdexcept>
#include <deque>


template<class K, class V>
/**This is a cool template class.
 * @brief The data_key_value_container class
 */
class data_key_value_container {


private:

    std::deque<std::pair<K,V>> data_d;

public:
    void push(K const&, V const&);
    void pop();
    void pop_first();
    std::pair<K,V> first() const;
    std::pair<K,V> last() const;
    bool empty() const{
        return data_d.empty();
    }
    void print_data();
    int size()
    {
        return data_d.size();
    }
};


template<class K, class V>
void data_key_value_container<K,V>::push(const K& key_el, const V& val_el){
    data_d.push_back(std::make_pair(key_el, val_el));
}

template<class K, class V>
void data_key_value_container<K,V>::pop()
{
    if(data_d.empty())
        throw std::out_of_range("data_key_value_container: stack out of range");

    data_d.pop_back();
}

template<class K, class V>
void data_key_value_container<K,V>::pop_first()
{
    if(data_d.empty())
        throw std::out_of_range("data_key_value_container: stack out of range");

    data_d.pop_front();
}

template<class K, class V>
std::pair<K,V> data_key_value_container<K,V>::first() const
{
    if(data_d.empty())
        throw std::out_of_range("data_key_value_container: stack out of range");

    return data_d.front();
}

template<class K, class V>
std::pair<K, V> data_key_value_container<K,V>::last() const
{
    if(data_d.empty())
        throw std::out_of_range("data_key_value_container: stack out of range");

    return data_d.back();
}


template<class K, class V>
/**Used mainly for local debugging
 * @brief data_key_value_container<K, V>::print_data
 */
void data_key_value_container<K,V>::print_data(){

    for(const auto& p : data_d){
        std::cout << p.first << ", " << p.second << std::endl;
    }
}

#endif // DATA_KEY_VALUE_CONTAINER

