#include <vector>
#include <utility>
#include <stdexcept>

template <class Key, class TVal>
class Table {
private:
    std::vector<std::pair<Key, TVal>> data;

public:
    void insert(TVal value) {
        Key key = static_cast<Key>(data.size()); 
        data.emplace_back(key, value);
    }

    void insert(Key key, TVal value) {
        for (const auto& pair : data) {
            if (pair.first == key) {
                throw std::runtime_error("Ключ уже существует");
            }
        }
        data.emplace_back(key, value);
    }

    void erase(Key key) {
        for (auto it = data.begin(); it != data.end(); ++it) {
            if (it->first == key) {
                data.erase(it);
                return;
            }
        }
        throw std::runtime_error("Ключ не найден");
    }
};
