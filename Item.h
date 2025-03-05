#ifndef ITEM_H
#define ITEM_H

#include <cstdint>

#include <string>

class Item
{
public:
    Item(const std::string& name, int64_t price);
    Item(const std::string& name, int64_t price, const std::string& icon_png);

    std::string    getName() const;
    int64_t       getPrice() const;
    std::string getIconPng() const;

    void    setName(const std::string& name);
    void   setPrice(int64_t price);
    void setIconPng(const std::string& icon_png);

private:
    std::string name;
    int64_t     price;
    std::string icon_png;
};

#endif // ITEM_H