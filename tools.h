/* Fred Christensen  1-12-2013

A function that computes the standard deviation of elements in any container
A function that computes the average (mean) of elements in any container
A function that times the processing of another function
A function that repeatedly invokes another function, and returns the average and standard deviation of the time taken.
*/

#ifndef TOOLS_H
#define TOOLS_H

#include <numeric>
#include <ctime>
#include <algorithm>
#include <vector>
#include <math.h>
#include <utility>

// -------Average-----------

  template <typename InputIterator>
  double average (InputIterator c)
  {
    double total = (double)std::accumulate(c.begin(),c.end(),0);
    return total/(double)c.size();
  }

// ------Standard Deviation--------
  template <typename InputIterator>
  double deviation (InputIterator c)
  {
    double av = average(c);
    typedef typename InputIterator::value_type myType;
    std::vector<myType> av_list;

    std::for_each(c.begin(), c.end(), 
      [&](myType current)
      {
        auto e = current - av;
        auto r = e * e;
        av_list.push_back (r);
      }
    );
    
    av = (double)std::accumulate(av_list.begin(),av_list.end(),0);
    av = av / (av_list.size() - 1);
    av = sqrt(av);
    return av;
  }

// ----------Calculate time------------
  template <typename functor>
  clock_t funcTime (functor f)
  {
    auto start = clock();
    f();
    auto stop = clock();
    return stop-start;
  }

// ----------Function Time Average & Deviation------------
// ----------returns pair <average, deviation>------------
  template <typename functor>
  std::pair<double, double> funcEval (functor f, int timesCalled = 25) // if nove value give
  {
    std::vector<clock_t> c;
    c.resize(timesCalled);
    
    std::generate (c.begin(), c.end(), 
      [&] () { return funcTime(f);}
    );
    
    double av = average (c);
    double dev = deviation (c);
    std::pair <double, double> result (av, dev);
    return result;
  }

#endif