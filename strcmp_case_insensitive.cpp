//week 1 Gary Gallopin
// "Hi" == "hi" lab with case insensitivity

#include <iostream>
#include <cassert>
#include <string>
#include <cctype>  //needed for the function tolower
using namespace std;

int compareStrings(string str1, string str2);

int main()
{
    int result;
    result = compareStrings("Hi", "hi"); // test case insensitivity
    assert(result == 0);
    cout << "The comparison of \"Hi\" and \"hi\" returns " << result << "." << endl;

    result = compareStrings("ba", "bb"); // test alphabetical order
    assert(result == -1);
    cout << "The comparison of \"ba\" and \"bb\" returns " << result << "." << endl;

    result = compareStrings("bc", "bb");
    assert(result == 1);
    cout << "The comparison of \"bc\" and \"bb\" returns " << result << "." << endl;

    result = compareStrings("bc", "bca"); // aa < aaa
    assert(result == -1);
    cout << "The comparison of \"bc\" and \"bca\" returns " << result << "." << endl;
    
    result = compareStrings("bca", "bc");
    assert(result == 1);
    cout << "The comparison of \"bca\" and \"bc\" returns " << result << "." << endl;

    result = compareStrings("bc", "Bca"); // ASCII number of B is lower than b
    assert(result == -1);
    cout << "The comparison of \"bc\" and \"Bca\" returns " << result << "." << endl;

    result = compareStrings("123", "321"); // numbers
    assert(result == -1);
    cout << "The comparison of \"123\" and \"321\" returns " << result << "." << endl;

    result = compareStrings("bca", "bc1");
    assert(result == 1);
    cout << "The comparison of \"bca\" and \"bc1\" returns " << result << "." << endl;

    result = compareStrings("bc a", "bcaa"); // blanks
    assert(result == -1);
    cout << "The comparison of \"bc a\" and \"bcaa\" returns " << result << "." << endl;

    result = compareStrings("bc a", "BC A"); // blanks and caps
    assert(result == 0);
    cout << "The comparison of \"bc a\" and \"BC A\" returns " << result << "." << endl;

    result = compareStrings("bc.", "bc?"); // punctuation-- "." has a lower ASCII number than "?"
    assert(result == -1);
    cout << "The comparison of \"bc.\" and \"bc?\" returns " << result << "." << endl;

    result = compareStrings("b", "a");  // single character
    assert(result == 1);
    cout << "The comparison of \"b\" and \"a\" returns " << result << "." << endl;

    result = compareStrings("B", "b");  // single character
    assert(result == 0);
    cout << "The comparison of \"B\" and \"b\" returns " << result << "." << endl;

    result = compareStrings("Bz", "buzz");  // shorter not lower
    assert(result == 1);
    cout << "The comparison of \"Bz\" and \"buzz\" returns " << result << "." << endl;

    result = compareStrings("abc", "");  // empty string
    assert(result == 1);
    cout << "The comparison of \"abc\" and \"\" returns " << result << "." << endl;

    // create a test to see what happens to a string of/with capital letters
    string testString1 = "ABC";
    string testString2 = "xYz";
    result = compareStrings(testString1, testString2);
    cout << "\nShow that data in each string is not destroyed." << endl;
    cout << "\nResult: " << result << endl;
    cout << "testString1: " << testString1 << endl;
    cout << "testString2: " << testString2 << endl;   

    /*
    Output:

    Show that data in each string is not destroyed.

    Result: -1
    testString1: ABC
    testString2: xYz


    The comparison of "String one" and "string two" returns -1.
    The comparison of "String one" and "string one" returns 0.
    The comparison of "String two" and "string one" returns 1.



    */ 




    return 0;
}

int compareStrings(string str1, string str2)
{
    // loop through string one character at a time until
    // a mismatch is found or the entire string is equal
    // it uses tolower to turn upper case into lower case; found this function using A.I.
    int length;
    int length1 = str1.length();
    int length2 = str2.length();
    // First determine if the two strings have the same length
    // to determine loop termination.
    if (length1 <= length2) {length = length1;}
    else {length = length2;}

    for (int i = 0; i < length; i++)
    {
        if (tolower(str1[i]) != tolower(str2[i]))
        {
            if (tolower(str1[i]) < tolower(str2[i]) ){return -1;}
            else {return 1;}
        }
    }
    // check for length diff between to determine if there is a tie breaker
    if (length1 != length2) 
    {
        if (length1 < length2) {return -1;}
        else {return 1;}
    }
    return 0;
}