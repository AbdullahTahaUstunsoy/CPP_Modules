#include <iostream>

int to_upper(char c)
{
	if(c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

int main(int argc, char *argv[])
{
	int i;

	i = 1;
	if(argc == 1)
      std :: cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std :: endl;
	else
	{
		int j;
		
		j = 0;
		while(i < argc)
		{
			j = 0;
			while(argv[i][j] != '\0')
			{
				std :: cout << (char)to_upper(argv[i][j]);
				j++;
			}
			i++;
		}
		std :: cout << std :: endl;
	}
	return (0);
}