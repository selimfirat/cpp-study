/**
* Author: Selim Fırat Yılmaz 21502736
*/

#include <iostream>
#include <ctime>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <chrono>
#include <cmath>

using namespace std;

double runAndGetDuration(long long i, bool isRecursive);
int recursiveFibonacci(int n);
long long linearFibonacci(long long n);

int main(int argc, char const *argv[]) {

    std::ofstream dataRec("data_rec.txt");

    for (int i = 30; i <= 55; i += 1) {

        double recRT = runAndGetDuration(i, true); // for recursiveFibonacci

        dataRec << i << "\t" << recRT <<"\n";
    }

    //double recRT = runAndGetDuration(55, true); // for recursiveFibonacci
    //dataRec << 55 << "\t" << recRT <<"\n";

    dataRec.close();
/*
    std::ofstream dataLinear("data_linear.txt");

    for (long long i = 100000; i <= 100000000; i += 5*pow(10, ((int)log10(i) - 1))) {
        double linearRT = runAndGetDuration(i, false); // for linearFibonacci

        dataLinear << i << "\t" << linearRT <<"\n";
    }

    dataLinear.close();
*/
    return 0;
}

double runAndGetDuration(long long n, bool isRecursive) {
    double duration;
    clock_t startTime = clock();

    if (isRecursive)
      recursiveFibonacci(n);
    else
      linearFibonacci(n);

      duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

      cout << "input " << n << " " << duration << endl;
      return duration;
}

int recursiveFibonacci(int n) {
    if (n <= 2)
        return 1;

    return recursiveFibonacci(n - 1) + recursiveFibonacci(n - 2);
}

long long linearFibonacci(long long n) {

    int previous = 1; // initially fib(1)
    int current = 1; // initially fib(2)
    int next = 1; // result when n is 1 or 2

    // compute next Fibonacci values when n >= 3
    for (int i = 3; i <= n; ++i) {
        next = current + previous; // fib(i)

		previous = current; 	// get ready for the
		current = next;		// next iteration
}

	return next;
}
