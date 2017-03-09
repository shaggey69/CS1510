/*
Programmer: Ari Sherman 
Section: 1510 A
Date: 3/15/2017
Description: brain lab implement 
*/

#include <cstdlib>
#include <iostream>
#include <sstream>
#include "stack.h"

using namespace std; 
bool isBR(char test);
bool isInt(char test);
bool isOP(char test);

int main()
{
  LinkedListStack<char> circleBR;
  LinkedListStack<char> squareBR;
  LinkedListStack<char> curlyBR;

  
  string ins,s1,s2,s3,s4;
  while (getline(cin, ins))
  {
    istringstream inputstr(ins);      
    inputstr >> s1 >> s2; 
    inputstr >> s3 >>s4;                               
    while (ins != ".")  
    {
      cout << endl << s1 << " + " << s2 << " = ";
      cout <<endl << "first word: " << s3 << " second word: " << s4;
    getline(cin, ins);  
    istringstream inputstr(ins);      
    inputstr >> s1 >> s2; 
    inputstr >> s3 >> s4;

    }
  }
  cout << endl;
  return 0;
}

bool isBR(char test)
{
  if (test == '{'
  ||
  test == '}'
   ||
  test == '('
   ||
  test == ')'
   ||
  test == '['
   ||
  test == ']' )
  return true;
  return false;
}
bool isInt(char test)
{
  if (test >= 48 && test <= 57 )
  return true;
  return false;
}
bool isOP(char test)
{
  if (test == '+'
  ||
  test == '-'
   ||
  test == '*'
   ||
  test == '/'
   ||
  test == '%'
  )
  return true;
  return false;
}

