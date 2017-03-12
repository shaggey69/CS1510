/*
Programmer: Ari Sherman
Section: 1510 A
Date: 3/15/2017
Description: brain lab implement
*/

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>

#include "stack.h"
using namespace std;
bool isBRopen(string test);
bool isBRclose(string test);
bool isInt(string test);
bool isOP(string test);
int calcPerBR(string temp);
int main()
{

  LinkedListStack<int> circleBR;
  LinkedListStack<int> squareBR;
  LinkedListStack<int> curlyBR;
  int countWordsPerSentance = 0 ; //counts words in sentance
  int tempInt = 0; //int exttracred from input
  int totalSum = 0; // per sentancce 
  int sumPerBR = 0; // per brackts 
  int sentanceCounter = 0;
  string op =  "";
  string ins,s1;
  bool itCool = true;

  while (getline(cin, ins)) // per line
  {
    istringstream inputstr(ins);

    while (inputstr >> s1 && itCool ) //per word
    {
    	countWordsPerSentance ++;
      if (isBRopen(s1)) //open brackets check per word
      {
      	if (s1 == "{")
	      	curlyBR.push(countWordsPerSentance);
	      else if (s1 == "[")
	      	squareBR.push(countWordsPerSentance);
	      else if (s1 == "(")
	      	circleBR.push(countWordsPerSentance);
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
          else
          {
            int start = 0; //index of ins
            int end = 0; //index of ins

            string temp;
            cout << endl << "Test: "
            <<endl << "Top: " <<circleBR.top() 
            <<endl << "word in sentance: " <<countWordsPerSentance
            <<endl << "the sentce itself: " <<ins;
            istringstream moreTemps(ins);

            
            for (int i =0; i <circleBR.top() ; i++)
            {
              
              
            }  
            
            
            
            temp.append(ins,,);
            calcPerBR(temp);
            
          }
          circleBR.pop();
          }
	   		}
	   	}
 
	    

	  //end while per word
    if (s1 != ".")
    {  
  	  countWordsPerSentance = 0;
      if (!(curlyBR.isEmpty() && circleBR.isEmpty() && squareBR.isEmpty()))
        itCool = false;
      curlyBR.clear();
      circleBR.clear();
      squareBR.clear();
  	  cout << endl << "#" << sentanceCounter+1 << " : ";
  	  if (itCool)
  		  cout << totalSum ;
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
int calcPerBR(string inBr)
{
  int sum = 0;
  cout << endl << inBr;
  
  
  /*
  else if (isInt(s1))
	    {
	    	tempInt = atoi(s1.c_str());
        if (op != NULL)
          if (op == "+")
            sumPerBR =+ tempInt;
           else if (op == "-")
            sumPerBR =- tempInt;
           else if (op == "/")
            sumPerBR =/ tempInt;
           else if (op == "*")
            sumPerBR =* tempInt;
           else if (op == "%")
            sumPerBR = sumPerBR% tempInt;
          else 
            sumPerBR = tempInt;
        op = NULL;
	    }
	    
	    else if (isOP(s1))
	    {
	    	op = s1;
	    }
  */
  return sum;
}
