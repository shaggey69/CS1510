/*
Programmer: Ari Sherman 
Section: 1510 A
Date: 3/15/2017
Description: brain lab implement 
*/


#include <iostream>
#include "stack.h"
using namespace std;


int main ()
{
  LinkedListStack<string> justinBiberORdie;
  
 
 
  justinBiberORdie.push("ups bc he's so fit");
  justinBiberORdie.push("ing in line, bc I wabt to see him first");
  justinBiberORdie.push("into my arms");
  justinBiberORdie.push("his love all over the known universe");
  
  cout << endl <<  justinBiberORdie;
  cout << endl <<  justinBiberORdie.top();
  
  justinBiberORdie.pop(); //all over him
  justinBiberORdie.pop(); // his virgintiy

    cout << endl <<  justinBiberORdie;

  
	return 0;
}
