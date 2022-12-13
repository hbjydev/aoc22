#include "RPS.h"
#include <tuple>
#include <iostream>

using namespace std;

namespace rps {
  int Parser::value(char in) {
    if (in == TRock     || in == YRock    ) return Rock;
    if (in == TPaper    || in == YPaper   ) return Paper;
    if (in == TScissors || in == YScissors) return Scissors;
    return 0;
  };

  tuple<int, int> Parser::score(char them, char you) {
    int themScore = Parser::value(them);
    int youScore = Parser::value(you);

    bool draw = themScore == youScore;

    bool theyWin = (
      (themScore == Rock     && youScore == Scissors) ||
      (themScore == Paper    && youScore == Rock) ||
      (themScore == Scissors && youScore == Paper)
    );

    if (draw) {
      themScore += 3;
      youScore += 3;
    } else if (theyWin) {
      themScore += 6;
    } else {
      youScore += 6;
    }

    return make_tuple(themScore, youScore);
  }
}
