#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol752;

/*
Input: deadends = ["0201","0101","0102","1212","2002"], target = "0202"
Output: 6
Explanation:
A sequence of valid moves would be "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202".
Note that a sequence like "0000" -> "0001" -> "0002" -> "0102" -> "0202" would be invalid,
because the wheels of the lock become stuck after the display becomes the dead end "0102".
*/

tuple<vector<string>, string, int>
testFixture1()
{
  auto dns = vector<string>{"0201", "0101", "0102", "1212", "2002"};

  return make_tuple(dns, "0202", 6);
}

/*
Input: deadends = ["8888"], target = "0009"
Output: 1
Explanation:
We can turn the last wheel in reverse to move from "0000" -> "0009".
*/
tuple<vector<string>, string, int>
testFixture2()
{
  auto dns = vector<string>{"8888"};

  return make_tuple(dns, "0009", 1);
}

/*
Input: deadends = ["8887","8889","8878","8898","8788","8988","7888","9888"],
target = "8888"
Output: -1
Explanation:
We can't reach the target without getting stuck.
*/

tuple<vector<string>, string, int>
testFixture3()
{
  auto dns = vector<string>{"8887", "8889", "8878",
                            "8898", "8788", "8988", "7888", "9888"};

  return make_tuple(dns, "8888", -1);
}

/*
Input: deadends = ["0000"], target = "8888"
Output: -1
*/

tuple<vector<string>, string, int>
testFixture4()
{
  auto dns = vector<string>{"0000"};

  return make_tuple(dns, "8888", -1);
}

void test1()
{
  auto f = testFixture1();
  cout << "Expect to see " << to_string(get<2>(f)) << endl;
  Solution sol;
  cout << sol.openLock(get<0>(f), get<1>(f)) << endl;
}

void test2()
{
  auto f = testFixture2();
  cout << "Expect to see " << to_string(get<2>(f)) << endl;
  Solution sol;
  cout << sol.openLock(get<0>(f), get<1>(f)) << endl;
}

void test3()
{
  auto f = testFixture3();
  cout << "Expect to see " << to_string(get<2>(f)) << endl;
  Solution sol;
  cout << sol.openLock(get<0>(f), get<1>(f)) << endl;
}

void test4()
{
  auto f = testFixture4();
  cout << "Expect to see " << to_string(get<2>(f)) << endl;
  Solution sol;
  cout << sol.openLock(get<0>(f), get<1>(f)) << endl;
}

main()
{
  test1();
  test2();
  test3();
  test4();
  return 0;
}