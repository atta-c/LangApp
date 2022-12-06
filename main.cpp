#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <time.h>
#include "ang.h"

using namespace std;

//global variables for service the main program
   int how_much, choose_file, random_number;
   char choose_display;



int main()
{
    //Declaration variables
    int sum=0;


    //First step of program
   cout << "Choose how/which file do you want to read?" << endl << "-----------------------------------" << endl << "1 - read file line by line (questionsbyline.txt)" << endl << "2 - read file word by word (questionsbyword.txt)" << endl << endl << "Your choose: (1 or 2)" << endl;
   cin >> choose_file;                                                                                       //variable for chosen mode read file
   cout << endl;

    //Conditions for program running
    if ((choose_file==0 ) || (choose_file>2))                                                                 //program protection for wrong chosen number (choose_file - variable defining which file should be read)
    {
    cout<<"Uncategorized char!";
       exit(0);
    }

    //Second step of program
   cout << "Do you want to randomizing display question numbers?" << endl << "-----------------------------------" << endl << "Y - Yes, i want to randomizing words" << endl << "n - no, i don't want to randomizing words" << endl << endl << "Your choose: (Y or n)" << endl;
   cin >> choose_display;                                                                                       //variable for randomizing
   cout << endl;

   bool choose_display_Y = false;
    //Conditions for program running
    if (choose_display == 'Y')
    {
        choose_display_Y = true;
    }
    else if (choose_display == 'n')
    {
       choose_display_Y = false;
    }
    else
    {
        cout<<"Uncategorized randomizing!";
        exit(0);
    }



    //Function for random number (time value download)
    srand(time(NULL));

    //Function for count lines in file and change it for amount questions (for service main loop)
   how_much = how_much_quest(choose_file);                                                                 //how_much - amount of questions




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
      if (choose_display_Y==true)
      {
      p[i].quest_nr=array_recent[i];
      }
      if (choose_display_Y==false)
      {
      p[i].quest_nr=i+1;
      }
      if (choose_file==1)    //1 - by line
      {
      p[i].loadbyline();
      }
      if (choose_file==2)    //2 - by word
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
