#include <iostream>

bool isOnlyWhitespace(const std::string str)
{
	int i;
	int len;

	i = 0;
	len = (int)str.length();
	while (i < len)
	{
		if (str[i] != ' ' && str[i] != '\t')
			return false;
		i++;
	}
	return true;
}

bool isAlphaSpace(std::string str)
{
    int i;
    int len;

    if (str.empty() || isOnlyWhitespace(str))
        return false;
    i = 0;
    len = (int)str.length();
    while (i < len)
    {
        char c = str[i];
        if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || 
              (c == ' ' || c == '\t')))
        {
            return false;
        }
        i++;
    }
    return true;
}


bool is_num(std::string str)
{
    if (str.empty())
        return false;
    int i = 0;
    int len = (int)str.length();
    while (i < len)
    {
        if (str[i] < '0' || str[i] > '9')
            return false;
        i++;
    }
    return true;
}