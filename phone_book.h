#pragma once

#include <cstdlib>
#include <cstdint>
#include <optional>
#include <string>

#include "simple_map.h"

class PhoneBook {
public:
    PhoneBook() = default;
    PhoneBook(std::initializer_list<std::pair<std::string, uint64_t>> init) : data_(init) {}

    inline bool AddName(const std::string& name, const uint64_t& number) {
        if (data_.Contains(name)) {
            return false;
        }

        data_.Insert(name, number);
        return true;
    }

    inline bool DeleteName(const std::string& name) {
        if (!data_.Contains(name)) {
            return false;
        }

        data_.Delete(name);
        return true;
    }

    inline bool ChangeNumber(const std::string& name, const uint64_t& number) {
        if (!data_.Contains(name)) {
            return false;
        }

        data_[name] = number;
        return true;
    }

    inline std::optional<uint64_t> GetNumber(const std::string& name) const {
        if (!data_.Contains(name)) {
            return std::nullopt;
        }

        return data_[name];
    }

private:
    SimpleMap<std::string, uint64_t> data_;
};