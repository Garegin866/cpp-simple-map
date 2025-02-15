#pragma once

#include <vector>
#include <utility>
#include <string>
#include <algorithm>

template <typename K, typename V>
class SimpleMap {
public:
    SimpleMap() = default;

    SimpleMap(std::initializer_list<std::pair<K, V>> init) : data_(init) {}

    inline bool Contains(const K& key) const {
        return Find(key) != data_.end();
    }

    inline void Insert(const K& key, const V& value) {
        auto it = Find(key);
        if (it == data_.end()) {
            data_.push_back({key, value});
        } else {
            it->second = value;
        }
    }

    inline void Delete(const K& key) {
        auto it = Find(key);
        if (it != data_.end()) {
            data_.erase(it);
        }
    }

    inline const V& operator[](const K& key) const {
        auto it = Find(key);
        if (it == data_.end()) {
            std::abort();
        }

        return it->second;
    }

    inline V& operator[](const K& key) {
        auto it = Find(key);
        if (it == data_.end()) {
            std::abort();
        }

        return it->second;
    }

    [[nodiscard]] inline size_t GetSize() const {
        return data_.size();
    }
private:
    std::vector<std::pair<K, V>> data_;

    auto Find(const K& key) {
        auto predicate = [&key](const std::pair<K, V>& item) {
            return item.first == key;
        };

        return std::find_if(data_.begin(), data_.end(), predicate);
    }

    auto Find(const K& key) const {
        return const_cast<SimpleMap*>(this)->Find(key);
    }
};