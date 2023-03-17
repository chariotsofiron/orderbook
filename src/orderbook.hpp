#include <deque>
#include <map>
#include <unordered_map>

typedef uint64_t OrderId;
typedef uint64_t Quantity;
typedef uint64_t Price;

struct Order {
    OrderId id;
    Quantity quantity;
};

template<bool is_ask>
class HalfBook {
  public:
    auto get_top_of_book() const -> std::pair<Price, Quantity> {
        if (levels.empty()) {
            return {0, 0};
        }

        auto it = levels.begin();
        return {it->first, it->second.size()};
    }

    auto add(Price price, Order order) -> void {
        levels[price].push_back(order);
    }

    // cancel the order by setting the quantity to 0
    auto cancel(OrderId order_id) -> void {
        for (auto& [price, orders] : levels) {
            for (auto& order : orders) {
                if (order.id == order_id) {
                    order.quantity = 0;
                    return;
                }
            }
        }
    }

  private:
  // we use an ordered map to store the price levels
  // each price level is a queue represented by a vector
    std::map<
        Price,
        std::vector<Order>,
        typename std::conditional<is_ask, std::greater<Price>, std::less<Price>>::type>
        levels;
};



// An order book for a specific product
class OrderBook {
  public:

    // Adds an order to the order book
    auto add(const Price price, const Quantity qty, const bool is_ask)
        -> OrderId {
        OrderId order_id = this->next_order_id++;

        Order order = {order_id, qty};
        if (is_ask) {
            this->asks.add(price, order);
        } else {
            this->bids.add(price, order);
        }

        return order_id;
    }

    auto remove(OrderId order_id) -> void {
        bool is_ask = this->orders[order_id];
        if (is_ask) {
            this->asks.cancel(order_id);
        } else {
            this->bids.cancel(order_id);
        }
    }

  private:
    HalfBook<true> bids;
    HalfBook<false> asks;
    std::unordered_map<OrderId, bool> orders;
    uint64_t next_order_id = 0;
};

