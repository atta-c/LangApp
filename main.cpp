#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include "ang.h"

using namespace std;



int how_much_quest(int x)                       //function of amount return--> x- amount lines:2 = amount of questions
{
   fstream file;
   file.open("questions.txt",ios::in);

   if(file.good()==false)
   {
      cout<<"The file cannot be open!";
      exit(0);
   }

   int actual_nr=0;
   string line;

   while(getline(file,line))
   {
      actual_nr++;
   }
   file.close();

   x = (actual_nr+1)/2;

    return x;
}



int main()
{

    int sum=0;

    Question p[how_much_quest(how_much)];                             //amount of declared class, possible asked questions


   for(int i=0; i<how_much_quest(how_much); i++)                     //i = number of asking questions

   {
      p[i].quest_nr=i+1;
      p[i].load();
      p[i].ask();
      p[i].check();
      sum+=p[i].points;
   }

   cout<<"END PROGRAM! POINTS = "<<sum;

   return 0;
}
