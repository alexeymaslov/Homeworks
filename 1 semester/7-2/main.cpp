#include <iostream>
#include "mystring.h"

using namespace std;

int main()
{
    MyString* string1 = createString("qwerty11");
    MyString* string2 = createString("");
    MyString* string3 = createString("qwerty");
    MyString* string4 = createString("qwerty");

    cout << "String \"" << changeToChar(string1) << "\" symbol number 0 is: " << index(string1, 0) << ", symbol number 1 is: " << index(string1, 4) << ", symbol number 2 is: " << index(string1, 123) << "\n";

    cout << "String \"" << changeToChar(string1) << "\" is empty: " << isEmpty(string1) << "\n";
    cout << "String \"" << changeToChar(string2) << "\" is empty: " << isEmpty(string2) << "\n";

    cout << "String \"" << changeToChar(string1) << "\" is equal to string \"" << changeToChar(string2) << "\": " << isEqual(string1, string2) << "\n";
    cout << "String \"" << changeToChar(string1) << "\" is equal to string \"" << changeToChar(string3) << "\": " << isEqual(string1, string3) << "\n";
    cout << "String \"" << changeToChar(string3) << "\" is equal to string \"" << changeToChar(string4) << "\": " << isEqual(string3, string4) << "\n";

    cout << "Substring of string \"" << changeToChar(string1) << "\" from symbol 0 to symbol 2: " << changeToChar(getSubstring(string1, 0, 2)) << "\n";


    deleteString(string1);

    deleteString(string2);

    deleteString(string3);

    deleteString(string4);
}

