#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <time.h>
#include "ang.h"

using namespace std;

int main()
{

    //Declaration variables
    int sum=0;

    //Declaration main program class
    Control a;
    a.which_file();
    a.asking_about_randomizing();

    //Function for count lines in file and change it for amount questions (for service main loop)
    a.how_much = how_much_quest(a.choose_file);                                 //how_much - amount of questions


    //Array for random numbers of questions
    int array_recent[a.how_much];
    //Array = 0
    for (int i=0; i<=a.how_much; i++)
    {
    array_recent[i]=0;
    }
    //Main loop for random questions
    for (int i=0; i<a.how_much; i++)
    {
    array_recent[i] = new_rdm_nb(a.how_much, array_recent);
    }

   //Declaration useable classes
   Question p[a.how_much];

   //Main program loop
    for(int i=0; i<a.how_much; i++)                                                                //i = number of asking questions
    {
        if (a.choose_display == 'Y') p[i].quest_nr=array_recent[i];
        if (a.choose_display == 'n') p[i].quest_nr=i+1;
        if (a.choose_file==1) p[i].loadbyline();
        if (a.choose_file==2) p[i].loadbyword();
        p[i].ask();
        p[i].check();
        sum+=p[i].points;
    }

   cout<<"END PROGRAM! POINTS = "<<sum;

   return 0;
}
