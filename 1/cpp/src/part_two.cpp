#include <vector>
#include <iostream>
#include <bits/stdc++.h>
#include "../lib/ParseData.h"

using namespace std;

int main() {
  struct ElfLib::data data = ElfLib::Parser::read();

  vector<int> totals = data.totals;

  sort(totals.begin(), totals.end(), greater<int>());

  int amount = totals[0] + totals[1] + totals[2];

  cout << amount << endl;
}
