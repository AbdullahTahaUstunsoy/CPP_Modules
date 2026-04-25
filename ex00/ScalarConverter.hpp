#include <string>

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);
        ~ScalarConverter();

        static void analyzeLiteral(const std::string& literal, bool& hasSign, bool& hasDot, bool& hasF, int& length);
        static int isInt(const std::string& literal, bool& hasSign, int length);
        static int isDouble(const std::string& literal, bool& hasSign, int length);
        static int isFloat(const std::string& literal, bool& hasSign, int length);
        static int detectType(const std::string& literal);
    public:
        static void convert(const std::string& literal);
};

enum e_type {
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    PSEUDO,
    INVALID
};