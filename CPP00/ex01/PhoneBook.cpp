#include <iostream>
#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook()
{ 
}

void PhoneBook::addContact(int contactIndex, std::string (&input)[5])
{
    contacts[contactIndex].setFirstName(input[0]);
	contacts[contactIndex].setLastName(input[1]);
	contacts[contactIndex].setNickName(input[2]);
	contacts[contactIndex].setPhoneNumber(input[3]);
	contacts[contactIndex].setDarkestSecret(input[4]);
}

void PhoneBook::displayContacts(int contactCount) const
{
	int i;
	std::string new_name;
	std::string new_last_name;
	std::string new_nick_name;

	i = 0;
	std::cout << "---------------------------------------------" << std::endl;
	while(i < contactCount)
	{
		new_name = contacts[i].getFirstName();
		new_last_name = contacts[i].getLastName();
		new_nick_name = contacts[i].getNickName();
		if(contacts[i].getFirstName().length() > 10)
		{
			new_name = contacts[i].getFirstName().substr(0, 9);
			new_name += ".";
		}
		if(contacts[i].getLastName().length() > 10)
		{
			new_last_name = contacts[i].getLastName().substr(0,9);
			new_last_name += ".";
		}
		if(contacts[i].getNickName().length() > 10)
		{
			new_nick_name = contacts[i].getNickName().substr(0,9);
			new_nick_name += ".";
		}
		std::cout << "|" << std::right << std::setw(10) << i << "|";
		std::cout << std::right << std::setw(10) << new_name << "|";
		std::cout << std::right << std::setw(10) << new_last_name << "|";
		std::cout << std::right << std::setw(10) << new_nick_name << "|" << std::endl;
		std::cout << "---------------------------------------------" << std::endl;
		i++;
	}
}

void PhoneBook::displayContactDetails(int index) const
{
	std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
	std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: " << contacts[index].getNickName() << std::endl;
	std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
}