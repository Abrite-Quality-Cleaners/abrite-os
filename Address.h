#ifndef ADDRESS_H
#define ADDRESS_H

#include <string>

class Address
{
public:
    Address(const std::string& street, const std::string& city,
            const std::string& state,  const std::string& postalCode,
            const std::string& country);

    std::string     getStreet() const;
    std::string       getCity() const;
    std::string      getState() const;
    std::string getPostalCode() const;
    std::string    getCountry() const;

    void     setStreet(const std::string& street);
    void       setCity(const std::string& city);
    void      setState(const std::string& state);
    void setPostalCode(const std::string& postalCode);
    void    setCountry(const std::string& country);

private:
    std::string street;
    std::string city;
    std::string state;
    std::string postalCode;
    std::string country;
};

#endif // ADDRESS_H