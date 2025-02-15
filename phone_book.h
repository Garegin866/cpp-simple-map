#pragma once

#include <cstdlib>
#include <cstdint>
#include <optional>
#include <string>
#include <map>

class PhoneBook {
public:
    PhoneBook() = default;
    PhoneBook(std::initializer_list<std::pair<std::string, uint64_t>> init) {
        for (const auto& [name, number] : init) {
            data_[name] = number;
        }
    }

    inline bool AddName(const std::string& name, const uint64_t& number) {
        auto it = data_.find(name);
        if (it != data_.end()) {
            return false;
        }

        data_[name] = number;
        return true;
    }

    inline bool DeleteName(const std::string& name) {
        auto it = data_.find(name);
        if (it == data_.end()) {
            return false;
        }

        data_.erase(it);
        return true;
    }

    inline bool ChangeNumber(const std::string& name, const uint64_t& number) {
        auto it = data_.find(name);
        if (it == data_.end()) {
            return false;
        }

        it->second = number;
        return true;
    }

    [[nodiscard]] inline std::optional<uint64_t> GetNumber(const std::string& name) const {
        auto it = data_.find(name);
        if (it == data_.end()) {
            return std::nullopt;
        }

        return it->second;
    }
private:
    std::map<std::string, uint64_t> data_;
};