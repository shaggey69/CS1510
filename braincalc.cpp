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
bool isInt(char test);
bool isOP(char test);
int calcPerBR(string temp);
int extractBR(LinkedListStack<int> & brStack, string &  ins,
const int countWordsPerSentance);
int main()
{

  LinkedListStack<int> circleBR;
  LinkedListStack<int> squareBR;
  LinkedListStack<int> curlyBR;
  int countWordsPerSentance = 0 ; //counts words in sentance
  int totalSum = 0; // per sentancce 
  //int sumPerBR = 0; // per brackts 
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
          else
          {
            extractBR(curlyBR,ins,countWordsPerSentance);
            curlyBR.pop();
          }
	     	}
	      else if (s1 == "]")
	      {
	     		if (squareBR.isEmpty())
	     			itCool = false;
          else
          {
            extractBR(squareBR,ins,countWordsPerSentance);
            squareBR.pop();
          }
	      }	
	      else if (s1 == ")")
	      {
	     		if (circleBR.isEmpty())
	     			itCool = false;
          else
          {
            extractBR(circleBR,ins,countWordsPerSentance);
            circleBR.pop();        
          }
        }
	   	}
	   } //end while per word of sentance
    if (s1 != ".")
    {  

      totalSum = calcPerBR(ins);
      if (!(curlyBR.isEmpty() && circleBR.isEmpty() && squareBR.isEmpty()))
        itCool = false;
      
  	  cout << endl << "#" << sentanceCounter+1 << " : ";
  	  if (itCool)
  		  cout << totalSum ;
  		else
  		  cout << "INVALID!" ;

      //restarting paramters for next sentacne
      itCool = true;
      sentanceCounter++;
      countWordsPerSentance = 0;
      curlyBR.clear();
      circleBR.clear();
      squareBR.clear();

    }
  } //end while per line of input
  
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
bool isInt(char test)
{
  if (test >= 48 && test <= 57)
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
int calcPerBR(string inBr)
{
  //cout << endl << inBr;
  int tempInt = 0;
  char op = ' ';
  int sumPerBR = 0;
  int inBrLength = inBr.length();
  for (int i = 0 ; i < inBrLength ; i++)
  {
    if (isInt(inBr[i]) && isInt(inBr[i+1]))
	  {
	    tempInt = inBr[i]-48; //translating ascii code to int :)
        if (op == '+')
          sumPerBR += tempInt; 
        else if (op == '-')
          sumPerBR -= tempInt;
        else if (op == '/')
          sumPerBR = sumPerBR / tempInt;
        else if (op == '*')
          sumPerBR = sumPerBR * tempInt;
        else if (op == '%')
          sumPerBR = sumPerBR % tempInt; 
        else
          sumPerBR = tempInt;
	  }    
  	if (isOP(inBr[i]))
  	 op = inBr[i];	 
  }
  return sumPerBR;
}
int extractBR(LinkedListStack<int> & brStack, string & ins,
 const int countWordsPerSentance)
{
  int sum;
  int start = 0; //index of ins
  int end = 0; //index of ins
  int temp_numofWS = 0;
  int temp2_numofWS = 0;
  string temp ;
  ostringstream sumInStr;
  istringstream inputstr2(ins);

  while (temp_numofWS < brStack.top())
  {
    if (ins[start] == 32)
      temp_numofWS++;   
    start++;
  }     
  while (temp2_numofWS < countWordsPerSentance)
  {
    if (ins[end] == 32)
      temp2_numofWS++;   
    end++;
  }  
  end--;
  
  temp = ins.substr(start-2,end-start+2);
  cout << endl << "the Xtracted string: " << temp;
  sum = calcPerBR(temp);
  sumInStr << sum; 
  cout << endl << sumInStr.str();
  ins.replace(start-2,end-start+2,sumInStr.str()); 
 // cout << endl << ins;


  return sum;

}