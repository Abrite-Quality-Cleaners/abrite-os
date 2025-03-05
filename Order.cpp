#include "Order.h"
#include <algorithm>

Order::Order(const Customer& customer, double tax_percent)
    : customer(customer), tax_percent(tax_percent), total(0) {}

void Order::addItem(const OrderItem& item) {
    auto it = std::find_if(items.begin(), items.end(), 
        [&item](const OrderItem& i) 
        { return i.getName() == item.getName(); });
    if (it == items.end()) {
        items.push_back(item);
        updateTotal();
    }
}

void Order::removeItem(const std::string& itemName) {
    items.erase(std::remove_if(items.begin(), items.end(), 
        [&itemName](const OrderItem& item) 
            {return item.getName() == itemName; }), 
        items.end());
    updateTotal();
}

Customer Order::getCustomer() const {
    return customer;
}

double Order::getTaxPercent() const {
    return tax_percent;
}

int64_t Order::getTotal() const {
    return total;
}

void Order::updateTotal() {
    total = 0;
    for (const auto& item : items) {
        total += item.getSubtotal();
    }
    total += static_cast<int64_t>(total * tax_percent / 100);
}

Note Order::getNote() const {
    return note;
}

void Order::setNote(const Note& note) {
    this->note = note;
}
