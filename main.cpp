
#include "tools.h"
#include <random>
#include <iostream>
#include <numeric>

std::vector<int> simple (std::vector<int> &p, std::vector<int> &q);
std::vector<int> fourMult (std::vector<int> &p, std::vector<int> &q);
std::vector<int> threeMult (std::vector<int> &p, std::vector<int> &q);

const int VALUE_MIN = -10;
const int VALUE_MAX = 10;

int main() {
  //////////////////////////////////////////////////////
  ////////// TO TEST UNCOMENT THIS CODE ////////////////
  //////////////////////////////////////////////////////
  // int n = 8;

  // std::vector<int> p(n);
  // std::vector<int> q(n);

  // std::random_device rd;
  // std::uniform_int_distribution<int> dist(VALUE_MIN, VALUE_MAX);
  
  // std::generate(p.begin(), p.end(), [&] () {
  //   return dist(rd);
  // });

  // std::generate(q.begin(), q.end(), [&] () {
  //   return dist(rd);
  // });

  // std::cout << "\nP = ";
  // for (int i = 0; i < n; ++i) {
  //   std::cout << p[i] << ' ';
  // }

  // std::cout << "\nQ = ";
  // for (int i = 0; i < n; ++i) {
  //   std::cout << q[i] << ' ';
  // }

  // std::cout << std::endl;

  // // Test it works
  // auto temp_res = simple(p, q);
  // std::cout << "Simple Results: ";
  // std::for_each(temp_res.begin(), temp_res.end(), [] (int val) {
  //   std::cout << val << " ";
  // });

  // temp_res = fourMult(p, q);
  // std::cout << "\nFour Mult-Results: ";
  // std::for_each(temp_res.begin(), temp_res.end(), [] (int val) {
  //   std::cout << val << " ";
  // });

  // temp_res = threeMult(p, q);
  // std::cout << "\nThree Mult-Results: ";
  // std::for_each(temp_res.begin(), temp_res.end(), [] (int val) {
  //   std::cout << val << " ";
  // });

  // std::cout << std::endl;

  //////////////////////////////////////////////////////
  ////////// End uncompent section      ////////////////
  //////////////////////////////////////////////////////


  // imperical tests

  std::vector<int> p;
  std::vector<int> q;

  std::random_device rd;
  std::uniform_int_distribution<int> dist(VALUE_MIN, VALUE_MAX);

  for (int j = 2; j <= 8192; j *= 2) {

    p.resize(j);
    q.resize(j);

    std::generate(p.begin(), p.end(), [&] () {
      return dist(rd);
    });

    std::generate(q.begin(), q.end(), [&] () {
      return dist(rd);
    });


    std::cout << "\n\nFor polynomials of size " << j;

    auto simple_res     = funcEval([&] () {
      for (int i = 0; i < p.size(); ++i) {
        p[i] = dist(rd);
        q[i] = dist(rd);
      }

      simple(p, q);
    });
    auto fourMult_res   = funcEval([&] () {
      for (int i = 0; i < p.size(); ++i) {
        p[i] = dist(rd);
        q[i] = dist(rd);
      }

      fourMult(p, q);
    });
    auto threeMult_res  = funcEval([&] () {
      for (int i = 0; i < p.size(); ++i) {
        p[i] = dist(rd);
        q[i] = dist(rd);
      }

      threeMult(p, q);
    });
  std::cout << "\nsimple = " << simple_res.first << "\nfourMult = " << fourMult_res.first << "\nthreeMult = " << threeMult_res.first << std::endl;
  }

  std::cout << "ALL DONE\n";
  return 0;
}

std::vector<int> simple (std::vector<int> &p, std::vector<int> &q) {
  std::vector<int> result (p.size() + q.size() - 1, 0);
  for (int i = 0; i < p.size(); ++i) {
    for (int j = 0; j < q.size(); ++j) {
      result[i + j] += p[i] * q[j];
    }
  }
  return result;
}

std::vector<int> fourMult (std::vector<int> &p, std::vector<int> &q) {
  if (p.size() == 1 || q.size() == 1) {
    auto res = simple(p,q);
    return res;
  }

  std::vector<int> result (p.size() + q.size() - 1, 0);
  std::vector<int> pLow;
  std::vector<int> pHigh;
  std::vector<int> qLow;
  std::vector<int> qHigh;


// Initialize
  for (int i = 0; i < (p.size() / 2); ++i) {
    pLow.push_back(p[i]);
  }

  for (int i = 0; i < (p.size() - pLow.size()); ++i) {
    pHigh.push_back(p[i + pLow.size()]);
  }

  for (int i = 0; i < (q.size() / 2); ++i) {
    qLow.push_back(q[i]);
  }

  for (int i = 0; i < (q.size() - qLow.size()); ++i) {
    qHigh.push_back(q[i + qLow.size()]);
  }

// Low P * Low Q
  std::vector<int> tempRes;
  tempRes = fourMult(pLow, qLow);
  for (int i = 0; i < tempRes.size(); ++i) {
    result[i] += tempRes[i];
  }

// High P * High Q
  tempRes = fourMult(pHigh, qHigh);
  for (int i = 0; i < tempRes.size(); ++i) {
    result[i + p.size()] += tempRes[i];
  }

// Low P * High Q
  tempRes = fourMult(pLow, qHigh);
  for (int i = 0; i < tempRes.size(); ++i) {
    result[i + (p.size() / 2)] += tempRes[i];
  }

// High P * Low Q
  tempRes = fourMult(pHigh, qLow);
  for (int i = 0; i < tempRes.size(); ++i) {
    result[i + (q.size() / 2)] += tempRes[i];
  }
  return result;
}


std::vector<int> threeMult (std::vector<int> &p, std::vector<int> &q) {
  if (p.size() == 1 || q.size() == 1) {
    auto res = simple(p,q);
    return res;
  }

  std::vector<int> result (p.size() + q.size() - 1, 0);
  std::vector<int> pLow;
  std::vector<int> pHigh;
  std::vector<int> qLow;
  std::vector<int> qHigh;


// Initialize
  for (int i = 0; i < (p.size() / 2); ++i) {
    pLow.push_back(p[i]);
  }

  for (int i = 0; i < (p.size() - pLow.size()); ++i) {
    pHigh.push_back(p[i + pLow.size()]);
  }

  for (int i = 0; i < (q.size() / 2); ++i) {
    qLow.push_back(q[i]);
  }

  for (int i = 0; i < (q.size() - qLow.size()); ++i) {
    qHigh.push_back(q[i + qLow.size()]);
  }

  // Low P * Low Q
  std::vector<int> lowRes, highRes, mixRes, pMix, qMix;
  lowRes = threeMult(pLow, qLow);
  for (int i = 0; i < lowRes.size(); ++i) {
    result[i] += lowRes[i];
  }

  // High P * High Q
  highRes = threeMult(pHigh, qHigh);
  for (int i = 0; i < highRes.size(); ++i) {
    result[i + p.size()] += highRes[i];
  }

  // (pLow + pHigh)
  for(int i = 0; i < pLow.size(); ++i) {
    pMix.push_back(pLow[i] + pHigh[i]);
  }
  if (pHigh.size() > pLow.size()) {
    pMix.push_back(pHigh[pHigh.size() - 1]);
  }

  // (qLow + qHigh)
  for(int i = 0; i < qLow.size(); ++i) {
    qMix.push_back(qLow[i] + qHigh[i]);
  }
  if (qHigh.size() > qLow.size()) {
    qMix.push_back(qHigh[qHigh.size() - 1]);
  }

  // (High P + Low Q)(Low P + High Q)
  mixRes = threeMult(pMix, qMix);
  for (int i = 0; i < mixRes.size(); ++i) {
    result[i + (q.size() / 2)] += mixRes[i];
    result[i + (q.size() / 2)] -= highRes[i];
    result[i + (q.size() / 2)] -= lowRes[i];
  }
  return result;
}

