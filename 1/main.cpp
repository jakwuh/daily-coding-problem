/*
Task:
  Given a list of numbers and a number k, return whether any two numbers from the list add up to k.
  For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.
  Bonus: Can you do this in one pass?

Solution:
  n log n
*/
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <set>

bool solve(std::vector<int64_t> numbers, int64_t k)
{
  std::set<int64_t> pairs;

  for (auto number : numbers)
  {
    if (pairs.find(k - number) != pairs.end())
    {
      return true;
    }
    else
    {
      pairs.insert(number);
    }
  }

  return false;
}

int main()
{
  int64_t number, k;
  std::ifstream in("in.txt");
  std::ofstream out("out.txt");
  std::string line;

  while (std::getline(in, line))
  {
    std::vector<int64_t> numbers;
    std::istringstream stream(line);
    while (stream >> number)
    {
      numbers.push_back(number);
    }

    k = numbers.back();
    numbers.pop_back();

    out << (solve(numbers, k) ? "true" : "false") << std::endl;
  }
}