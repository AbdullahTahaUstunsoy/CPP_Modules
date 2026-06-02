#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <string>
#include <iomanip>

class PhoneBook {
	
    private:
    Contact contacts[8];
    
    public:
		  PhoneBook();
      void addContact(int contactIndex, std::string (&input)[5]);
      void displayContacts(int contactCount) const;
      void displayContactDetails(int index) const;
};

#endif