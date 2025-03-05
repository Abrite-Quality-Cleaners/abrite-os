#include "Item.h"

Item::Item(const std::string& name, int64_t price)
    : name(name), price(price), icon_png("") {}

Item::Item(const std::string& name, int64_t price, const std::string& icon_png)
    : name(name), price(price), icon_png(icon_png) {}

std::string Item::getName() const {
    return name;
}

int64_t Item::getPrice() const {
    return price;
}

std::string Item::getIconPng() const {
    return icon_png;
}

void Item::setName(const std::string& name) {
    this->name = name;
}

void Item::setPrice(int64_t price) {
    this->price = price;
}

void Item::setIconPng(const std::string& icon_png) {
    this->icon_png = icon_png;
}
