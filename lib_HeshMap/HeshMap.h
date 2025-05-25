#include <vector>
#include <list>
#include <utility>
#include <stdexcept>
#include <random>
#include <optional>
#include <iostream>
#include <string>
#include <type_traits>

#define CAPACITY 50
template <class TKey>
int Hesh_function(TKey key);

template <class TKey>
int Hesh_function(TKey key) {
    int p = 31, m = 1e9 + 7;
    int hash_value;

    if constexpr (std::is_same<TKey, std::string>::value) {
        int hash_so_far = 0;
        int p_pow = 1;
        const int n = key.length();
        for (int i = 0; i < n; ++i) {
            hash_so_far = (hash_so_far + (key[i] - 'a' + 1) * p_pow) % m;
            p_pow = (p_pow * p) % m;
        }
        hash_value = hash_so_far % CAPACITY;
    }
    else if constexpr (std::is_integral<TKey>::value) {

        hash_value = key % CAPACITY;
    }
    else {
        throw std::logic_error("Unsupported key type");
    }
    
    return hash_value;
}



template <class TKey, class TVal>
class Link {
public:

    std::vector<std::pair<TKey, TVal>> _chain;
    TKey _key;
    TVal _val;
    int _number;
    Link();
    Link(TKey key, TVal val);

    void print_chain();
    void insert(TKey key, TVal val);

};

template <class TKey, class TVal>
Link< TKey, TVal>::Link() {
    _number = 0;
}

template <class TKey, class TVal>
Link< TKey, TVal>::Link(TKey key, TVal val) {
    _key = key;
    _val = val;
    _chain.push_back(std::make_pair(key, val));
}



template <class TKey, class TVal>
void Link< TKey, TVal>::insert(TKey key, TVal val) {
    std::pair< TKey, TVal> _pair = { key,val };
    _chain.push_back(_pair);
    _number++;
}

template <class TKey, class TVal>
void Link<TKey, TVal>::print_chain() {
    for (int i = 0;i < _number;i++) {
        std::cout << "Key: " << _chain[i].first << ", Value: " << _chain[i].second<< '\t';
       
    }
}






template <class TKey, class TVal>
class Hesh_table {
public:
    std::vector<Link<TKey, TVal>> _data;


    int _size;
    void print();
    int insert(TKey key, TVal val);
    Hesh_table();

};


template <class TKey, class TVal>
Hesh_table<TKey, TVal>::Hesh_table() : _size(0), _data(CAPACITY) {

}

template <class TKey, class TVal>
void Hesh_table<TKey, TVal>::print() {
    for (int i = 0; i < CAPACITY; ++i) {
        if (!_data[i]._chain.empty()) {
            _data[i].print_chain();
            std::cout << '\n';
        }
    }
}


template <class TKey, class TVal>
int Hesh_table< TKey, TVal>::insert(TKey key, TVal val) {

    int index = Hesh_function(key);
    _data[index].insert(key, val);
    _size++;
    return index;
}





/*
int main() {
    Hesh_table<int, int> f;
    Hesh_table<std::string, int> h;
    //   f.insert(34, 55);
    h.insert("pol", 55);
    h.insert("ned", 56);
    h.insert("nedo", 58);
    h.print();
    return 0;
}*/


// список а не вектор