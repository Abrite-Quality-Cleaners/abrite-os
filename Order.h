#ifndef ORDER_H
#define ORDER_H

#include <vector>
#include <string>
#include "Customer.h"
#include "OrderItem.h"
#include "Note.h"

class Order
{
public:
    Order(const Customer& customer, double tax_percent);

    void    addItem(const OrderItem& item);
    void removeItem(const std::string& itemName);

    Customer   getCustomer() const;
    double   getTaxPercent() const;
    int64_t       getTotal() const;

    void    updateTotal();

    Note getNote() const;
    void setNote(const Note& note);

private:
    Customer               customer;
    std::vector<OrderItem> items;
    Note                   note;
    double                 tax_percent;
    int64_t                total;
};

#endif // ORDER_H