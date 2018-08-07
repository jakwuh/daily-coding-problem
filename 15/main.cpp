/*
  Task:
    Given a stream of elements too large to store in memory, pick a random element from the stream with uniform probability.
*/
#include <iostream>
#include <vector>
#include <random>

typedef int32_t value_t;
typedef std::vector<value_t> vector_t;

value_t solve(vector_t::iterator left, vector_t::iterator end)
{
    if (left == end)
    {
        throw std::range_error("empty array");
    }

    int64_t count = 0;
    value_t random_n, value;
    std::mt19937 range;
    range.seed(std::random_device()());

    while (left != end)
    {
        count++;
        std::uniform_int_distribution<std::mt19937::result_type> generator(1, count);
        value = generator(range) < count ? value : *left;
        left++;
    }

    return value;
}

int main()
{
    vector_t v = {0, 1, 2, 3, 4, 5};
    vector_t counters = {0, 0, 0, 0, 0, 0};

    for (int i = 0; i < 10000; ++i)
    {
        auto value = solve(v.begin(), v.end());
        counters[value]++;
    }

    for (auto counter : counters) {
        std::cout << counter << ' ';
    }
}
