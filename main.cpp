#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include "ang.h"

using namespace std;

//global variables
int how_much;

int main()
{

   Question p[how_much_quest(how_much)];                             //amount of declared classes, possible asked questions
   int sum=0, choose;

   cout << "Choose how you want to read a file?" << endl << "-----------------------------------" << endl << "1 - read file line by line" << endl << "2 - read file word by word" << endl << "Your choose: (1 or 2)" << endl;
   cin >> choose;                                                   //variable for chosen mode read file


if ((choose==0 ) || (choose>2))                                                      //program protect for wrong chosen number
{
    cout<<"The chosen number is wrong!";
       exit(0);
}

   for(int i=0; i<how_much_quest(how_much); i++)                     //i = number of asking questions

   {
      p[i].quest_nr=i+1;
      if (choose==1)    //1 - by line
      {
      p[i].loadbyline();
      }
      if (choose==2)    //2 - by word
      {
      p[i].loadbyword();
      }
      p[i].ask();
      p[i].check();
      sum+=p[i].points;
   }

   cout<<"END PROGRAM! POINTS = "<<sum;

   return 0;
}
