#include "Address.h"

Address::Address(const std::string& street, const std::string& city, 
                 const std::string& state, const std::string& postalCode,
                 const std::string& country)
    : street(street), city(city), state(state), postalCode(postalCode),
      country(country) {}

std::string Address::getStreet() const {
    return street;
}

std::string Address::getCity() const {
    return city;
}

std::string Address::getState() const {
    return state;
}

std::string Address::getPostalCode() const {
    return postalCode;
}

std::string Address::getCountry() const {
    return country;
}

void Address::setStreet(const std::string& street) {
    this->street = street;
}

void Address::setCity(const std::string& city) {
    this->city = city;
}

void Address::setState(const std::string& state) {
    this->state = state;
}

void Address::setPostalCode(const std::string& postalCode) {
    this->postalCode = postalCode;
}

void Address::setCountry(const std::string& country) {
    this->country = country;
}