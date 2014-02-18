polynomial-multiplication
=========================

Project for multiplying polynomials

### The Assignment:

*  Implement three algorithms for solving the polynomial multiplication algorithm:

Given two polynomials P and Q each represented as an array of doubles where P[i] is the coefficient of x to the power i in polynomial P.
Return the polynomial that is the product of P and Q called PQ.
Note that if P and Q are of order n-1 (the highest power of x is n-1) they will have n coefficients and PQ will have 2n-1 coefficients.
*  Here are the three algorithms you are to implement:

Simple school-book algorithm using two nested for loops.
Simple divide and conquer recursive algorithm that generates four subproblems
More complex divide and conquer algorithm that generates three subproblems
*  Once you have verified that your algorithms all produce the same correct answer then perform an empirical study for a large set of random problems. For each problem, a polynomial will be a one dimensional array of n random doubles within the range of -1.0 to +1.0. Your study will loop from n = 32 to as large as possible, doubling the problem size each time (so n is always a power of 2). For each problem size generate a set of random problems of size n, and measure the time each algorithm takes to solve the same set of problems. Generate enough random problems so that the lines on the graph connecting the times is linear (on the log/log plot). Note that the lower efficiency algorithms may not be able to solve the largest of problem sizes.

*  Generate a single log/log graph where x is the problem size and y is the time to solve the problem set.

*  Your graphs should be clearly captioned with the axis labeled. I recommend using gnuplot or some other professional quality graphing software. Whatever you use, you must have the correct log-log graph.

*  Write a brief (4-6 sentence) technical explanation of the behavior of the algorithms derived from the graphs. Specifically, what is the cause of the offset between algorithms (a) and (b) above? Record the crossing points of the algorithms (where one algorithm becomes faster than the other). What is the reason for this?

*  Calculate the exact slopes of the lines for all three algorithms. According to theoretical analysis, the first two should have a slope of exactly 2 and the third algorithm should have a slope of 1.585. How close is your empirical study to the expected result?

*  The 40 points will be awarded as follows: 30 points fully working program that correctly implements all three algorithms; 5 points for the empirical studies and line fitting; 5 points for the correct graphs and correct technical explanation of the behavior.

*  Submit your graphs and report, data files containing your raw data and your commented code along with instructions to run the code.

