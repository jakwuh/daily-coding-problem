/*
Task:
  Given an integer k and a string s, find the length of the longest substring that contains at most k distinct characters.
  For example, given s = "abcba" and k = 2, the longest substring with k distinct characters is "bcb".

Solution:
  n for limited alphabet (e.g. english letters only) (replace map with an array)
  n log n for unlimited alphabet

  I will code for unlimited alphabet
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <set>
#include <map>

std::string solve(std::string text, int64_t k)
{
  std::map<char, int32_t> counters;
  auto left = text.begin();
  auto current = left;
  auto current_size = 1;
  auto end = text.end();

  int32_t best_size = 0;
  auto best_start = left;
  auto best_end = left;

  while (current != end)
  {
      auto ch = *current;
      auto it = counters.find(ch);

      if (it == counters.end()) {
        counters.emplace(ch, 1);
      } else {
          it->second += 1;
      }

      while (counters.size() > k) {
          auto ch = *left;
          auto it = counters.find(ch);
          it->second -= 1;

          if (it->second == 0) {
              counters.erase(it);
          }

          left += 1;
          current_size -= 1;
      }

        if (current_size > best_size) {
            best_size = current_size;
            best_start = left;
            best_end = current + 1;
        }

        current += 1;
        current_size += 1;
  }

  return std::string(best_start, best_end);
}

int main()
{
  int64_t k;
  std::string text;
  std::ifstream in("in.txt");
  std::ofstream out("out.txt");
  std::string line;

  while (std::getline(in, line))
  {
    std::istringstream stream(line);
    stream >> k;
    stream >> text;
    out << solve(text, k) << std::endl;
  }
}