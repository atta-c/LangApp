#include <iostream>

using namespace std;

class Question
{
   public:

   string word;
   int quest_nr;
   string correct;
   string answer;
   int points;

   void load();
   void ask();
   void check();
};

