
#ifndef SOLUTION_H
#define SOLUTION_H

#include "node.h"
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>

using namespace std;
namespace sol752
{

  class Solution
  {
  private:
  public:
    int openLock(vector<string> &deadends, string target);
  };
}
#endif