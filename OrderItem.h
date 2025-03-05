#ifndef ORDERITEM_H
#define ORDERITEM_H

#include <cstdint>

#include "Item.h"

class OrderItem : public Item
{
public:
    OrderItem(const std::string& name, int64_t price, int quantity);
    OrderItem(const std::string& name, int64_t price,
              const std::string& icon_png, int quantity);

    int64_t getQuantity() const;
    int64_t getSubtotal() const;

    void    setPrice(int64_t price) override;
    void setQuantity(int64_t quantity);

private:
    int64_t quantity;
    int64_t subtotal;

    void updateSubtotal();
};

#endif // ORDERITEM_H
