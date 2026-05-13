#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <vector>

int main()
{
    std::cout << "---Subject Test---" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    std::cout << "---List Test---" << std::endl;
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);
    std::cout << lst.back() << std::endl;
    lst.pop_back();
    std::cout << lst.size() << std::endl;
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    //[...]
    lst.push_back(0);
    std::list<int>::iterator it2 = lst.begin();
    std::list<int>::iterator ite2 = lst.end();
    ++it2;
    --it2;
    while (it2 != ite2)
    {    
        std::cout << *it2 << std::endl;
        ++it2;
    }
    std::cout << "---Constant MutantStack Test---" << std::endl;
    const MutantStack<int> const_mstack(mstack);
    MutantStack<int>::const_iterator it3 = const_mstack.begin();
    MutantStack<int>::const_iterator ite3 = const_mstack.end();
    while (it3 != ite3)
    {    
        std::cout << *it3 << std::endl;
        ++it3;
    }
    return 0;
}