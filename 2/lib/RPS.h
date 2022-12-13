#include <tuple>
using namespace std;

namespace rps {
  static const char TRock = 'A';
  static const char TPaper = 'B';
  static const char TScissors = 'C';

  static const char YRock = 'X';
  static const char YPaper = 'Y';
  static const char YScissors = 'Z';

  static const int Rock = 1;
  static const int Paper = 2;
  static const int Scissors = 3;

  class Parser
  {
  public:
    static tuple<int, int> score(char them, char you);
    static int value(char in);
  };
};
