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
bool isBRopen(string test);
bool isBRclose(string test);
bool isInt(string test);
bool isOP(string test);

int main()
{
  LinkedListStack<int> circleBR;
  LinkedListStack<int> squareBR;
  LinkedListStack<int> curlyBR;
  int count = 0 ;
  int tempInt = 0;
  int sum = 0;
  int sentanceCounter = 0;
  string op;
  string ins,s1;
  bool itCool = true;

  while (getline(cin, ins)) // per line
  {
    istringstream inputstr(ins);

    while (inputstr >> s1 && itCool ) //per word
    {
    	count ++;
      if (isBRopen(s1)) //open brackets check per word
      {
      	if (s1 == "{")
	      	curlyBR.push(count);
	      else if (s1 == "[")
	      	squareBR.push(count);
	      else if (s1 == "(")
	      	circleBR.push(count);
      }
	    else if (isBRclose(s1)) //closed brackets check per word
	    {
	     	if (s1 == "}")
	     	{
	     		if (curlyBR.isEmpty())
	     			itCool = false;
	      	curlyBR.pop();
	     	}
	      else if (s1 == "]")
	      {
	     		if (squareBR.isEmpty())
	     			itCool = false;
	      	squareBR.pop();
	      }	
	      else if (s1 == ")")
	      {
	     		if (circleBR.isEmpty())
	     			itCool = false;
	      	circleBR.pop();
	   		}
	   	}
	    else if (isInt(s1))
	    {
	    	tempInt = atoi(s1.c_str());
	    }
	    
	    else if (isOP(s1))
	    {
	    	op = s1;
	    }
	 } //end while per word
    if (s1 != ".")
    {  
  	  count = 0;
      if (!(curlyBR.isEmpty() && circleBR.isEmpty() && squareBR.isEmpty()))
        itCool = false;
      curlyBR.clear();
      circleBR.clear();
      squareBR.clear();
  	  cout << endl << "#" << sentanceCounter+1 << " : ";
  	  if (itCool)
  		  cout << sum ;
  		else
  		  cout << "INVALID!" ;
      itCool = true;
      sentanceCounter++;
    }
  } //end while per line
  
  cout << endl;
  return 0;
}

bool isBRopen(string test)
{
  if (test == "{"
	  ||
	  test == "("
	  ||
	  test == "["
	   )
  return true;
  return false;
}
bool isBRclose(string test)
{
  if (test == "}"
	   ||  
	  test == ")"
	   ||
	  test == "]" )
  return true;
  return false;
}
bool isInt(string test)
{
  if (test == "1" ||
  test ==  "2"|| 
  test == "3" || 
  test == "4" || 
  test == "5" || 
  test == "6" || 
  test == "7" || 
  test == "8" || 
  test == "9" || 
  test == "0")
  	return true;
  return false;
}
bool isOP(string test)
{
  if (test == "+"
  ||
  test == "-"
   ||
  test == "*"
   ||
  test == "/"
   ||
  test == "%"
  )
    return true;
  return false;
}
