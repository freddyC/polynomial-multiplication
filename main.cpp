
#include "tools.h"
#include <random>
#include <iostream>

std::vector<double> simple (std::vector<double> p, std::vector<double> q);
std::vector<double> fourMult (std::vector<double> p, std::vector<double> q);
std::vector<double> threeMult (std::vector<double> p, std::vector<double> q);

const int N = 20;
const int VALUE_MIN = 0;
const int VALUE_MAX = 100;

int main() {
  std::vector<double> p(N);
  std::vector<double> q(N);

  std::random_device rd;
  std::uniform_int_distribution<int> dist(VALUE_MIN, VALUE_MAX);
  
  std::generate(p.begin(), p.end(), [&] () {
    return dist(rd);
  });

  std::generate(q.begin(), q.end(), [&] () {
    return dist(rd);
  });

  std::cout << p[0] << ' ' << p[1] << std::endl;
  std::cout << q[0] << ' ' << q[1] << std::endl;

  auto simple_res     = funcEval([=] () {
    simple(p, q);
  });
  auto fourMult_res   = funcEval([=] () {
    fourMult(p, q);
  });
  auto threeMult_res  = funcEval([=] () {
    threeMult(p, q);
  });

  std::cout << "\nsimple = " << simple_res.first << "\nfourMult = " << fourMult_res.first << "\nthreeMult = " << threeMult_res.first << std::endl;

  return 0;
}

std::vector<double> simple (std::vector<double> p, std::vector<double> q) {
  std::vector<double> result ((2 * N) - 1, 0);
  for (int i = 0; i < p.size(); ++i) {
    for (int j = 0; j < q.size(); ++j) {
      result[i + j] += p[i] * q[j];
    }
  }
  return result;
}

std::vector<double> fourMult (std::vector<double> p, std::vector<double> q) {
  std::vector<double> result ((2 * N) - 1);

  return result;
}

std::vector<double> threeMult (std::vector<double> p, std::vector<double> q) {
  std::vector<double> result ((2 * N) - 1);

  return result;
}

