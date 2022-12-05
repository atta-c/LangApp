#include <iostream>
#include "ang.h"
#include <fstream>
#include <cstdlib>

using namespace std;



void Question::load()
{
   fstream file;
   file.open("questions.txt",ios::in);

   if(file.good()==false)
   {
      cout<<"The file cannot be open!";
      exit(0);
   }

   int nr_of_line=(quest_nr-1)*2+1;
   int actual_nr=1;
   string line;

   while(getline(file,line))
   {
      if(actual_nr==nr_of_line) word=line;
      if(actual_nr==nr_of_line+1) correct=line;
      actual_nr++;
   }

   file.close();

}

void Question::ask()
{
   cout<<"Translate the: "<<quest_nr<<". "<<word<<endl;
   cout<<endl<<"Your answer: ";
   cin>>answer;
}

void Question::check()
{
   if(answer==correct)
   {
      points=1;
      cout<<"!CORRECT!"<<endl<<endl;
      cout<<"------------------------"<<endl;
   }
   else
    {
        points=0;
        cout<<"The answer is WRONG!"<<endl<<endl;
              cout<<"------------------------"<<endl;
    }
}

