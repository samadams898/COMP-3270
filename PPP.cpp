#include <iostream>
#include <vector>
using namespace std;

// function declarations
int algorithm1(vector<int> X);
int algorithm2(vector<int> X);

// global variables

// main method
int main() {
    std::cout << "something";
}

// function/algorithm definitions
// each algorithm is a solution to MSCS

// #1
int algorithm1(vector<int> X) {
    int maxSoFar = 0;
    for () {
        for () {
            int sum = 0;
            for () {
                sum = sum + 1; // replace 1 with X[1], idk man??
                // sum now contains the sum of X[L...U]
            }
            maxSoFar = max(maxSoFar, sum);
        }
    }
    return maxSoFar;
}

// #2
int algorithm2(vector<int> X) {
    int maxSoFar = 0;
    for () {
        int sum = 0;
        for () {
           sum = sum + 1; // replace 1 with X[U], idk man??
           // sum now contains the sum of X[L...U]
        }
        maxSoFar = max(maxSoFar, sum);
    }
    return maxSoFar;
}
