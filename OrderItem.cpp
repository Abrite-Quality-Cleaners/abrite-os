#include "OrderItem.h"

OrderItem::OrderItem(const std::string& name, int64_t price, int quantity)
    : Item(name, price), quantity(quantity) {
    updateSubtotal();
}

OrderItem::OrderItem(const std::string& name, int64_t price, 
                     const std::string& icon_png, int quantity)
    : Item(name, price, icon_png), quantity(quantity), 
      subtotal(price * quantity) {}

int64_t OrderItem::getQuantity() const {
    return quantity;
}

int64_t OrderItem::getSubtotal() const {
    return subtotal;
}

void OrderItem::setPrice(int64_t price) {
    Item::setPrice(price);
    updateSubtotal();
}

void OrderItem::setQuantity(int64_t quantity) {
    this->quantity = quantity;
    updateSubtotal();
}

void OrderItem::updateSubtotal() {
    subtotal = getPrice() * getQuantity();
}
