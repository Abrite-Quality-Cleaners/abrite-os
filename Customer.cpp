#include "Customer.h"

Customer::Customer(const std::string& firstName, const std::string& lastName,
                   const std::string& phoneNumber, const Address& address,
                   const std::string& email)
    : id(0), createdAt(std::chrono::system_clock::now()),
    modifiedAt(std::chrono::system_clock::now()),
    firstName(firstName), lastName(lastName), phoneNumber(phoneNumber),
    address(address), email(email), balance(0) {}

uint64_t Customer::getId() const {
    return id;
}

std::chrono::system_clock::time_point Customer::getCreatedAt() const {
    return createdAt;
}

std::chrono::system_clock::time_point Customer::getModifiedAt() const {
    return modifiedAt;
}

std::string Customer::getFirstName() const {
    return firstName;
}

std::string Customer::getLastName() const {
    return lastName;
}

std::string Customer::getPhoneNumber() const {
    return phoneNumber;
}

Address Customer::getAddress() const {
    return address;
}

std::string Customer::getEmail() const {
    return email;
}

int64_t Customer::getBalance() const {
    return balance;
}

void Customer::setFirstName(const std::string& firstName) {
    this->firstName = firstName;
    updateModifiedAt();
}

void Customer::setLastName(const std::string& lastName) {
    this->lastName = lastName;
    updateModifiedAt();
}

void Customer::setPhoneNumber(const std::string& phoneNumber) {
    this->phoneNumber = phoneNumber;
    updateModifiedAt();
}

void Customer::setAddress(const Address& address) {
    this->address = address;
    updateModifiedAt();
}

void Customer::setEmail(const std::string& email) {
    this->email = email;
    updateModifiedAt();
}

void Customer::setBalance(int64_t balance) {
    this->balance = balance;
    updateModifiedAt();
}

void Customer::updateModifiedAt() {
    modifiedAt = std::chrono::system_clock::now();
}
