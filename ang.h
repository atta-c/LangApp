#include <iostream>

using namespace std;

int how_much_quest(int);    //function of (program control)
int new_rdm_nb(int, int []);         //return a sum of all quests


class Question
{
   public:

   string word;             //downloaded from file - actual word for translate
   int quest_nr;            //actual number of question
   string correct;          //downloaded from file - actual correct word
   string answer;           //the user respond
   int points;              //amount points of correct answers

   void loadbyline();
   void loadbyword();
   void ask();
   void check();
};

class Control
{
public:

    int choose_file;            //which file to read
    int how_much;               //how many lines OR how many words included in the file
    //int array_recent[];
    int random_number;
    char choose_display;        //variable for ON/OFF randomizing questions


    void which_file();
    void asking_about_randomizing();

};
