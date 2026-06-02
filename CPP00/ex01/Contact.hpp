#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <string>

class Contact {

    private:
        std::string firstName;
        std::string lastName;
        std::string nickName;
        std::string phoneNumber;
        std::string darkestSecret;
    public:
        Contact();
        Contact(std::string _firstName, std::string _lastName, std::string _nickName, std::string _phoneNumber, std::string _darkestSecret);
        void setFirstName(std::string _firstName);
        void setLastName(std::string _lastName);
        void setNickName(std::string _nickName);
        void setPhoneNumber(std::string _phoneNumber);
        void setDarkestSecret(std::string _darkestSecret);
        std::string getFirstName() const;
        std::string getLastName() const;
        std::string getNickName() const;
        std::string getPhoneNumber() const;
        std::string getDarkestSecret() const;
};

#endif