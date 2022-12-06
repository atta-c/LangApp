#include <iostream>
#include "ang.h"
#include <fstream>
#include <cstdlib>
#include <time.h>

using namespace std;



void Question::loadbyline()
{
   fstream file;
   file.open("questionsbyline.txt",ios::in);

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


void Question::loadbyword()
{
   fstream file;
   file.open("questionsbyword.txt",ios::in);

   if(file.good()==false)
   {
      cout<<"The file cannot be open!";
      exit(0);
   }

   string word_read;
   int nr_of_word=(quest_nr-1)*2+1;
   int actual_nr=1;
   while(file >> word_read)
   {
      if(actual_nr==nr_of_word) word=word_read;
      if(actual_nr==nr_of_word+1) correct=word_read;
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

int how_much_quest(int y)                       //function of (program control) amount return--> x - amount lines:2 = amount of questions // y - chosen read file mode
{

   fstream file;
   int actual_nr=0, x;
   string line, word_read;

   if(file.good()==false)
   {
      cout<<"The file cannot be open!";
      exit(0);
   }

   if (y==1)
   {
        file.open("questionsbyline.txt",ios::in);
        while(getline(file,line))                       //function for read line by line
        {
        actual_nr++;
        }
   }
   else if (y==2)
   {
        file.open("questionsbyword.txt",ios::in);
        while(file >> word_read)                        //function for read word by word
        {
        actual_nr++;
        }
   }

   file.close();

   x = (actual_nr+1)/2;

    return x;
}

int new_rdm_nb(int x, int y[])
{
    int how_much = x;
    int random_number;
    srand(time(NULL));
    random_number = rand()%how_much+1;

    for (int i=0; i<how_much; i++)
    {
        if(random_number==y[i])
        {
        random_number = rand()%how_much+1;
        i=-1;
        }
    }

   return random_number;
}
