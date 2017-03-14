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
int extractBR(LinkedListStack<int> & brStack, string &  ins,
const int countWordsPerSentance, const string insOriginal);
int main()
{

  LinkedListStack<int> circleBR;
  LinkedListStack<int> squareBR;
  LinkedListStack<int> curlyBR;
  int countWordsPerSentance = 0 ; //counts words in sentance
  int totalSum = 0; // per sentancce 
  int sentanceCounter = 0;
  string op =  "";
  string ins,insOriginal,s1;
  bool itCool = true;

  while (getline(cin, ins)) // per line
  {
    insOriginal = ins;
    istringstream inputstr(insOriginal);

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
            totalSum = extractBR(curlyBR,ins,countWordsPerSentance,insOriginal);
            curlyBR.pop();
          }
	     	}
	      else if (s1 == "]")
	      {
	     		if (squareBR.isEmpty())
	     			itCool = false;
          else
          {
            totalSum = extractBR(squareBR,ins,countWordsPerSentance,insOriginal);
            squareBR.pop();
          }
	      }	
	      else if (s1 == ")")
	      {
	     		if (circleBR.isEmpty())
	     			itCool = false;
          else
          {
            totalSum = extractBR(circleBR,ins,countWordsPerSentance,insOriginal);
            circleBR.pop();        
          }
        }
	   	}
	   } //end while per word of sentance
    if (s1 != ".")
    {  

      if (!(curlyBR.isEmpty() && circleBR.isEmpty() && squareBR.isEmpty()))
        itCool = false;
      
  	  cout  << "#" << sentanceCounter+1 << " : " ;
  	  if (itCool)
  		  cout << totalSum << endl ;
  		else
  		  cout << "INVALID!" << endl ;

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
bool isInt(string test)
{
  bool isDIG = true;  
  int length = test.length();
  for (int i = 0 ; i < length ; i++)
   if (!(isdigit(test[i])))
    isDIG = false;
  return isDIG;
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
  int tempInt = 0;
  string op = " ";
  int sumPerBR = 0;
  istringstream inputstr2(inBr);
  string s2;

  while (inputstr2 >> s2)
  {
    if (isInt(s2))
	  {
        tempInt = atoi(s2.c_str()); 
        if (op == "+")
          sumPerBR += tempInt; 
        else if (op == "-")
          sumPerBR -= tempInt;
        else if (op == "/")
          sumPerBR = sumPerBR / tempInt;
        else if (op == "*")
          sumPerBR = sumPerBR * tempInt;
        else if (op == "%")
          sumPerBR = sumPerBR % tempInt; 
        else
          sumPerBR = tempInt;
	  }    
  	if (isOP(s2))
  	 op = s2;	 
  }
  return sumPerBR;
}
int extractBR(LinkedListStack<int> & brStack, string & ins,
 const int countWordsPerSentance, const string insOriginal)
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
    if (insOriginal[start] == 32)
      temp_numofWS++;   
    start++;
  }  
  
  /*
  cout << endl << "end: " << end;
  cout << endl << "temp2_numofWS: " << temp2_numofWS;
  cout << endl << "countWordsPerSentance: " << countWordsPerSentance;
  
  cout << endl << "insOriginal: " << insOriginal << "  is untill here";
  */
  while (temp2_numofWS < countWordsPerSentance-1)
  {
    if (insOriginal[end] == 32)
      temp2_numofWS++;
    end++;
  }
  end++;
 //cout << endl << "start  of sub is: " << start-2;
//cout << endl << "end of sub is: " << end-start+1+start-2;

  temp = ins.substr(start-2,end-start+2);

  sum = calcPerBR(temp);
  sumInStr << sum; 
  ins.replace(start-2,end-start+2,sumInStr.str()); 

 //  cout << endl << "# of changied charcters " << end-start+2;
  // cout << endl << "# if new input " << sumInStr.str().length();

   int tempBEG = end-start+2;
   int tempEND = sumInStr.str().length();

   for (int i = tempEND; i < tempBEG; i++)
    ins.insert(start-2+ tempEND ," "); 

/*
  cout << endl << "the extcatred part: "<< temp;
  cout << endl << "the extcatred part sumation: "<<  sumInStr.str();
  cout << endl << "the orignl sentace with replacment: "<<  ins;

  */
  return sum;

}