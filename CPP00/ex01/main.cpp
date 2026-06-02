#include <iostream>
#include <cstdlib>
#include "PhoneBook.hpp"
#include "utils.hpp"

int main()
{
	PhoneBook phonebook;
    std::string command;
    std::string input[5];
    int oldest ;
    int contactCount;
    int targetIndex;
	int temp_index;

	oldest = 0;
	contactCount = 0;
	targetIndex = 0;
	temp_index = 0;
	while(1)
	{
		std::cout << "Enter a command (ADD, SEARCH, EXIT):" << std::endl;
		if (!std::getline(std::cin, command))
			return (1);
		if(command == "ADD")
        {
            if(contactCount < 8)
                targetIndex = contactCount;
            else
            {
                if(oldest >= 8) 
					oldest = 0;
                targetIndex = oldest;
            }
            while (true)
			{
                std::cout << "Enter First Name:" << std::endl;
                if (!std::getline(std::cin, input[0]))
					return (1);
                if (!input[0].empty() && isAlphaSpace(input[0]))
					break;
                std::cout << "First Name cannot be empty, numeric or just spaces. Try again:" << std::endl;
            }
            while (true) {
                std::cout << "Enter Last Name:" << std::endl;
                if (!std::getline(std::cin, input[1]))
					return (1);
                if (!input[1].empty() && isAlphaSpace(input[1]))
					break;
                std::cout << "Last Name cannot be empty, numeric or just spaces. Try again:" << std::endl;
            }
            while (true) {
                std::cout << "Enter Nick Name:" << std::endl;
                if (!std::getline(std::cin, input[2]))
					return (1);
                if (!input[2].empty() && !isOnlyWhitespace(input[2]))
					break;
                std::cout << "Nick Name cannot be empty. Try again:" << std::endl;
            }
            while (true) {
                std::cout << "Enter Phone Number:" << std::endl;
                if (!std::getline(std::cin, input[3]))
					return (1);
                if (is_num(input[3]) && !isOnlyWhitespace(input[3]))
					break;
                std::cout << "Invalid phone number! Try again:" << std::endl;
            }
            while (true) {
                std::cout << "Enter Darkest Secret:" << std::endl;
                if (!std::getline(std::cin, input[4]))
					return (1);
                if (!input[4].empty() && !isOnlyWhitespace(input[4]))
					break;
                std::cout << "Darkest Secret cannot be empty. Try again:" << std::endl;
            }
            phonebook.addContact(targetIndex, input);
            if (contactCount < 8)
                contactCount++;
            else
                oldest++;
    	}
	
		else if(command == "SEARCH")
		{
				std::cout << "|     Index|First Name| Last Name| Nick Name|" << std::endl;
				phonebook.displayContacts(contactCount);
				std::cout << "Enter the index of the contact you want to see details for:";
				if(!std::getline(std::cin, command))
					return (1);
				if (is_num(command))
				{
				    temp_index = std::atoi(command.c_str()); 	
				    if (temp_index >= 0 && temp_index < contactCount)
				        phonebook.displayContactDetails(temp_index);
				    else
				        std::cout << "Error: Index out of range (0-" << contactCount - 1 << ")." << std::endl;
				}
				else
				    std::cout << "Error: Invalid input. Please enter a valid numeric index." << std::endl;
		}
		else if(command == "EXIT")
			break;
		else
			continue;
	}
	return 0;
}