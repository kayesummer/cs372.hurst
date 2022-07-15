// RecurFactorial.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <chrono>
long fibonacci(unsigned n) {
    if (n < 2) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

long ifibonacci(unsigned n) {
    int f0 = 1;
    int f1 = 1;
    int fibtotal = 1;
    for (unsigned i = 1; i <= n; ++i) {
        fibtotal = f0 + f1;
        f0 = f1;
        f1 = fibtotal;
    }
    return fibtotal;
}

int main() {
    // Start by going recursive
    std::cout << "Recursive" << std::endl;
    for (int n = 1; n <= 42; ++n) {
        auto start = std::chrono::steady_clock::now();
        long lf = fibonacci(n);
        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - start;
        std::cout << "f(" << n << ") = " << lf;
        std::cout << " with elapsed time: " << elapsed_seconds.count() << "s\n";
    }

    // Now iterative
    std::cout << "Iterative " << std::endl;
    for (int n = 1; n <= 42; ++n) {
        auto start = std::chrono::steady_clock::now();
        long lf = ifibonacci(n);
        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - start;
        std::cout << "f(" << n << ") = " << lf; 
        std::cout << " with elapsed time: " << elapsed_seconds.count() << "s\n";
    }
}