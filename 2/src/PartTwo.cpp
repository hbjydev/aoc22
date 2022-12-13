#include "../lib/RPS.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <tuple>

using namespace std;

const int you = 2;
const int them = 1;
const int draw = 0;

int main() {
  vector<tuple<char, char>> instructions;
  vector<tuple<int, int>> scores;

  string line;
  ifstream InputData("data/input.txt");

  while (getline(InputData, line)) {
    auto inst = make_tuple(line[0], line[2]);
    instructions.push_back(inst);
  }

  for (int i = 0; i < instructions.size(); i++) {
    tuple<char, char> current = instructions[i];
    char play = get<0>(current);
    char need = get<1>(current);

    auto next = rps::Parser::whatNow(play, need);
    auto score = rps::Parser::score(play, next);
    scores.push_back(score);
  }

  int youTotal = 0;
  for (int i = 0; i < scores.size(); i++) {
    int youCurrent = get<1>(scores[i]);
    youTotal += youCurrent;
  }

  cout << youTotal << endl;
}
