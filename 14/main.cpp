/*
Task:
  This problem was asked by Google.
  The area of a circle is defined as πr^2. Estimate π to 3 decimal places using a Monte Carlo method.
  Hint: The basic equation of a circle is x2 + y2 = r2.

Solution:
    calculate the probability of a random distributed point in a square to be inside a circle.
    recall is calculated based on standart deviation
*/
#include <iostream>
#include <random>

float sigma_single = pow(4 - M_PI, 2) * M_PI_4 + pow(M_PI, 2) * (1 - M_PI_4);

float solve(float precision) {
    std::random_device rd;
    std::mt19937 eng(rd());
    std::uniform_int_distribution<> distr(0, RAND_MAX);

    float x, y, r;
    float qpi = 0, next_qpi = 0, qprecision = precision / 4; // q = quarter of
    int32_t in_circle_count = 0;
    int32_t n = pow(round(sigma_single / precision), 2);

    std::cout << n << ' ';

    for (int32_t i = 1; i < n; ++i) {
        qpi = next_qpi;

        x = 1. * distr(eng) / RAND_MAX;
        y = 1. * distr(eng) / RAND_MAX;

        if (x * x + y * y < 1) {
            in_circle_count++;
        }

        next_qpi = 1. * in_circle_count / i;
    }

    return next_qpi * 4;
}

int main() {
    std::cout << solve(0.0001) << std::endl;

    return 0;
}