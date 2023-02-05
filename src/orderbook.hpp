#include <deque>
#include <map>
#include <unordered_map>

struct Order {
    uint64_t order_id;
    /// @brief 6.4 fixed point number
    uint64_t price;
    uint64_t quantity;
};

class PriceLevel {
   public:
    auto add(const Order& order) -> void { orders.push_back(order); }
    auto remove(const Order& order) -> void {
        orders.erase(std::remove(orders.begin(), orders.end(), order));
    }

   private:
    std::deque<Order> orders;
};

// manages a set of price buckets and allows us to
// 1. find some bucket for a specifed price-level
// 2. find the successor bucket for the specified price-level
// 3. find the predecessor bucket for the specified price-level
// 4. add a new price-bucket for a given price-level
class PriceLevelManager {
   private:
    std::map<uint64_t, std::shared_ptr<PriceLevel>> levels;

   public:
    std::shared_ptr<PriceLevel> find(uint64_t price) {
        if (auto it(this->levels.find(price)); it != this->levels.end()) {
            return it->second;
        }
        return nullptr;
    }

    void remove(uint64_t price) { this->levels.erase(price); }
};

class OrderBook {};
