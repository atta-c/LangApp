#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include "ang.h"

using namespace std;

//global variables for service the main program
   int how_much, choose;

int main()
{
      //First step of program
   cout << "Choose how you want to read a file?" << endl << "-----------------------------------" << endl << "1 - read file line by line" << endl << "2 - read file word by word" << endl << endl << "Your choose: (1 or 2)" << endl;
   cin >> choose;
                                                                              //variable for chosen mode read file

   //Conditions for program running
    if ((choose==0 ) || (choose>2))                                                                 //program protect for wrong chosen number
    {
    cout<<"The chosen number is wrong!";
       exit(0);
    }

    //Function for count lines in file and change it for amount a questions (for service main loop)
   how_much = how_much_quest(choose);                                                                 //how_much - amount of questions

    //Declaration variables
   int sum=0;
    //Declaration class
   Question p[how_much];                                                                           //amount of declared classes, possible asked questions


   //Main loop
   for(int i=0; i<how_much; i++)                                                                //i = number of asking questions
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
