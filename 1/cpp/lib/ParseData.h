#pragma once
#include <vector>

using namespace std;

namespace ElfLib
{
  struct data {
    vector<int> totals;
  };

  class Parser
  {
  public:
    static struct data read();
  };
};
