/*
 * Author: Oscar Lima, olima_84@yahoo.com
 *
 * Learn c++ pointers!
 *
 * Documentation available at:
 *
 * https://www.youtube.com/watch?v=_ja8iizm7nk
 * http://www.cs.bu.edu/teaching/c/string/intro/
 *
 */

#include <iostream>

using namespace std;

void add_one(int *this_pointer)
{
    *this_pointer = *this_pointer + 1;
}

int main()
{
    cout << "Pointers!!!" << endl;

    string hello = "hello";

    //integer pointers (double holds same idea, so no double example)
    int number = 8;
    int *int_pointer;
    cout << "int pointers" << endl;
    int_pointer = &number; //operator & : returns adress
    cout << *int_pointer << endl; //operator * : returns or access to content
    *int_pointer = 4;
    cout << int_pointer << endl;
    cout << *int_pointer << endl;
    add_one(&number);
    int nine = number;
    cout <<  nine << endl; //passing value by reference

    //char pointers
    cout << "----------" << endl;
    cout << "char pointers" << endl;
    char caracter = 'a';
    char *caracter_pointer;
    caracter_pointer = &caracter;
    *caracter_pointer = 'r';
    cout << *caracter_pointer << endl;

    char *string;
    string = "string as a char pointer";
    //look: http://www.cs.bu.edu/teaching/c/string/intro/
    cout << string << endl;
    string = "changing string";
    cout << string << endl;

    cout << "end of program" << endl;
    return 0;
}
