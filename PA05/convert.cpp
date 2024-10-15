// You will need to edit this file and turn this one in.

#include <iostream>
#include <string>

// char2int
// Converts from a character to an integer digit
// if character '0'..'9' convert to 0..9
// else if character 'A'..'F' convert to 10..15
// else convert to -1
int char2int(char digit)
{
        if (digit >= '0' && digit <= '9') 
                return digit - '0';
        else if (digit >= 'A' && digit <= 'F') 
                return digit - 'A' + 10; 

        return -1;
}

// int2char
// Converts from an integer digit to a character
// if integer 0..9 convert to '0'..'9'
// else if integer 10..15 convert to 'A'..'F'
// else convert to 'X'
char int2char(int digit)
{
        if (digit >= 0 && digit <= 9)
                return digit + '0';
        else if (digit >= 10 && digit <= 15)
                return digit + 'A' - 10;
        return 'X';
}

// Convert integer to string in specified base and print
// 2 <= base <= 16
void int2ascii(int value, int base)
{
        std::string result = "";
        for (; value > 0; value /= base)
                result = int2char(value % base) + result; 
        std::cout << result;
        return;
}

// Convert string in specified base to integer and print
// 2 <= base <= 16
void ascii2int(const std::string &ascii, int base)
{
        int result = 0;
        for (char c : ascii) { 
               int digit = char2int(c); 
               result = result * base + digit;
        }
        std::cout << result;
        return;
}

