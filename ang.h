#include <iostream>

using namespace std;

int how_much_quest(int);    //function of (program control) amount return--> x- amount lines:2 = amount of questions -->


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

