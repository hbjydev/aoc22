#include <iostream>
#include "../lib/ParseData.h"

using namespace std;

int main() {
  struct ElfLib::data data = ElfLib::Parser::read();

  int highest = 0;
  int highestCal = 0;

  for (int i = 0; i < data.totals.size(); i++) {
    int current = data.totals[i];

    if (current > highestCal) {
      highestCal = current;
      highest = i + 1;
    }
  }

  cout << "the elf with the most calories is "
    << highest
    << " with "
    << highestCal
    << " calories."
    << endl;
};
