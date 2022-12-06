#include <iostream>

using namespace std;

int how_much_quest(int);    //function of (program control)
int new_rdm_nb(int, int []);         //return a sum of all quests


class Question
{
   public:

   string word;
   int quest_nr;
   string correct;
   string answer;
   int points;

   void loadbyline();
   void loadbyword();
   void ask();
   void check();
};

