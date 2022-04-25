#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <algorithm>
#include <iterator>
#include <unordered_map>
#include <set>
#include <cstring>
using namespace sol752;
using namespace std;

/*takeways
  - use BFS
  - given a combination you can make 8 possible moves
    with each digit the choice of moving fordward or
    backward
  - so in BFS term, for each combination it has 8
    neighbors to visit at the next level

*/

int Solution::openLock(vector<string> &deadends, string target)
{
  auto blocks = unordered_set<string>(deadends.begin(), deadends.end());
  auto s = string("0000");
  if (blocks.count(s))
    return -1;
  if (s == target)
    return 0;
  auto q = queue<string>();
  q.push(s);
  auto visited = unordered_set<string>{s};
  auto step = 0;

  while (!q.empty())
  {
    step++; // make one more move to the next level
    auto size = (int)q.size();
    /* for each node at this level
       find its neighbors that
       are not a dead-end or visited
    */
    for (auto i = 0; i < size; i++)
    {
      auto c = q.front();
      q.pop();
      /* given a combination you have 8 choices
         to choose from for your next move
         - 4 digits each can move forward
           or backward
      */
      for (auto j = 0; j < 4; j++)
        for (auto k = -1; k <= 1; k += 2)
        {
          auto next = c;
          /*next move for digit j */
          next[j] = '0' + (c[j] - '0' + k + 10) % 10;
          if (next == target)
            return step;
          if (blocks.count(next) || visited.count(next))
            continue;
          q.push(next);
          visited.insert(next);
        }
    }
  }

  return -1;
}