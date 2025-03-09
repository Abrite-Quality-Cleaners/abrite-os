#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <chrono>
#include <cstdint>
#include <string>
#include <vector>

#include "Address.h"
#include "Order.h"
#include "Note.h"

class Customer
{
public:
    Customer(const std::string& firstName, const std::string& lastName, 
             const std::string& phoneNumber, const Address& address,
             const std::string& email);

    uint64_t getId() const;
    std::chrono::system_clock::time_point getCreatedAt() const;
    std::chrono::system_clock::time_point getModifiedAt() const;
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getPhoneNumber() const;
    Address getAddress() const;
    std::string getEmail() const;
    int64_t getBalance() const;

    void setFirstName(const std::string& firstName);
    void setLastName(const std::string& lastName);
    void setPhoneNumber(const std::string& phoneNumber);
    void setAddress(const Address& address);
    void setEmail(const std::string& email);
    void setBalance(int64_t balance);

    void updateModifiedAt();

private:
    uint64_t                              id;
    std::chrono::system_clock::time_point createdAt;
    std::chrono::system_clock::time_point modifiedAt;
    std::string                           firstName;
    std::string                           lastName;
    std::string                           phoneNumber;
    Address                               address;
    std::string                           email;
    int64_t                               balance;
    std::vector<Order>                    orders;
    std::vector<Note>                     notes;
};

#endif // CUSTOMER_H
