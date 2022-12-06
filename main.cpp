#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <time.h>
#include "ang.h"

using namespace std;

//global variables for service the main program
   int how_much, choose, random_number;

int main()
{
      //First step of program
   cout << "Choose how/which file do you want to read?" << endl << "-----------------------------------" << endl << "1 - read file line by line (questionsbyline.txt)" << endl << "2 - read file word by word (questionsbyword.txt)" << endl << endl << "Your choose: (1 or 2)" << endl;
   cin >> choose;                                                                                       //variable for chosen mode read file
   cout << endl;


   //Conditions for program running
    if ((choose==0 ) || (choose>2))                                                                 //program protection for wrong chosen number (choose - variable defining which file should be read)
    {
    cout<<"The chosen number is wrong!";
       exit(0);
    }

    //Function for random number (time value download)
    srand(time(NULL));

    //Function for count lines in file and change it for amount questions (for service main loop)
   how_much = how_much_quest(choose);                                                                 //how_much - amount of questions

    //Declaration variables
   int sum=0;

    //Array for random numbers of questions
    int array_recent[how_much];
    for (int i=0; i<=how_much; i++)
    {
        array_recent[i]=0;
    }
    //Main loop for random questions
    for (int i=0; i<how_much; i++)
    {
    random_number = new_rdm_nb(how_much, array_recent);
    array_recent[i] = random_number;
    }

    //Declaration class
   Question p[how_much];                                                                           //amount of declared classes, possible asked questions

   //Main program loop
   for(int i=0; i<how_much; i++)                                                                //i = number of asking questions
   {
      p[i].quest_nr=array_recent[i];
      cout<<p[i].quest_nr<<endl;
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
