#include "ParseData.h"
#include <fstream>
#include <string>
#include <vector>

using namespace std;

namespace ElfLib
{
  struct data Parser::read() {
    vector<vector<int>> nums;
    vector<int> totals;

    vector<int> currentElf;
    string line;
    ifstream LinesFile("data/part2.txt");

    while (getline (LinesFile, line)) {
      if (line.length() > 0) {
        int num = stoi(line);
        currentElf.push_back(num);
      } else {
        nums.push_back(currentElf);
        currentElf.clear();
      }
    }
    nums.push_back(currentElf);

    LinesFile.close();

    for (int i = 0; i < nums.size(); i++) {
      vector<int> elf = nums[i];
      int total = 0;
      for (int i = 0; i < elf.size(); i++) {
        int current = elf[i];
        total = total + current;
      }

      totals.push_back(total);
    }
    
    struct data memdata;
    memdata.totals = totals;

    return memdata;
  }
}
