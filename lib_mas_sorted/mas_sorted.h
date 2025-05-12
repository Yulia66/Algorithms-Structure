#include <iostream>
#include <vector>
#include <list>
#include <utility>
#include <stdexcept>
#include <random>
#include <optional>
template <class TKey, class TVal>
class ITable {


  
public:
    virtual TKey insert(TVal value) = 0;
    virtual void insert(TKey key, TVal value) = 0;
    virtual  void remove(TKey key) = 0;
    virtual TVal* _find(TKey key) = 0;
    virtual std::pair<TKey, TVal>& find(TKey key) = 0;
    virtual void print() = 0;
    virtual TKey generate_key() = 0;

    virtual int binary_find(TKey key) = 0;
};

template <class TKey, class TVal>
class sorted : public ITable<TKey, TVal> {
  
    std::vector< std::pair<TKey, TVal>> _data;
    size_t _size;

public:
    sorted() {
        _size = 0;

    }

    sorted(std::vector<std::pair<TKey, TVal>>& data) : _data(data) {
        _size = _data.size();
    }


    sorted(const sorted& tab) {
        _data = (tab._data);
        _size = (tab._size);
    }



    int binary_find(TKey key)override {
        int mid;
        int left = 0;
        int right = _size - 1;

        while ((left <= right)) {
            mid = (left + right) / 2;
            if (_data[mid].first == key) {
                return mid;
            }
            if (_data[mid].first > key) {
                right = mid - 1;
            }
            else left = mid + 1;
        }
        return left;
    }

    void insert(TKey key, TVal val) override {


        if (_size > 0) {
            if (_find(key)) {
                throw std::logic_error("Key busy! \n");
            }
        }
        std::pair<TKey, TVal> new_row(key, val);
        if (_size == 0) {
            _data.push_back(new_row);
            _size++;
            return;
        }
        int position = binary_find(key);
        _data.insert(_data.begin() + position, new_row);
        _size++;
    }

    TKey insert(TVal value) override {
        TKey key = generate_key();
        std::pair<TKey, TVal> new_row(key, value);
        int position = binary_find(key);
        _data.insert(_data.begin() + position, new_row);
        _size++;
        return key;
    }

    TKey generate_key() override {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        static std::uniform_int_distribution<> dis(1, 100);
        return dis(gen);
    }


    void print() override {
        for (int i = 0; i < _data.size(); i++) {
            std::cout << " Key: " << _data[i].first << " Value: " << _data[i].second << "\n";
        }
    }

    // бинарный поиск
    TVal* _find(TKey key) override {

        for (int i = 0; i < _data.size(); i++) {
            if (_data[i].first == key) {
                return &_data[i].second;
            }

        }
        return nullptr;
    }

    // бинарный поиск
    std::pair<TKey, TVal>& find(TKey key) override {

        for (int i = 0; i < _data.size(); i++) {
            if (_data[i].first == key) {
                return _data[i];
            }

        }
        throw std::logic_error("No key");
    }


    /// <summary>
    /// применить бинарный поиск !
    /// </summary>
    /// <param name="key"></param>

    void remove(TKey key) override {
        typename std::vector<std::pair<TKey, TVal>>::iterator it;
        for (it = _data.begin(); it != _data.end(); ++it) {
            if (it->first == key) {
                _data.erase(it);
                _size--;
                return;
            }

        }
        throw std::logic_error("No key");
    }
};
