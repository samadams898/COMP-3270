#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// function declarations
int algorithm1(vector<int> &X);
int algorithm2(vector<int> &X);
int algorithm3(vector<int> &X, int L, int U);
int algorithm4(vector<int> &X);

// global variables

// main method
int main() {
    // this link is where this solution was from
    // https://stackoverflow.com/questions/40945378/reading-a-comma-separated-file-into-an-integer-array
    ifstream inputFile ("phw_input.txt");

    vector<int> numbers;
    string number_as_string;

    while (getline(inputFile, number_as_string, ',')) {
        numbers.push_back(stoi(number_as_string));
    }

    cout << "n : " << numbers.size() << "\n";
    for (auto&& number : numbers) {
        cout << number << "\n";
    }
}

// function/algorithm definitions
// each algorithm is a solution to MSCS

// #1
int algorithm1(vector<int> &X) {
    int maxSoFar = 0;
    int P = 0;
    int Q = X.size();
    for (int L = P; L < Q; L++) {
        for (int U = L; U < Q; U++) {
            int sum = 0;
            for (int I = L; I <= U; I++) {
                sum = sum + X[I]; 
                // sum now contains the sum of X[L...U]
            }
            maxSoFar = max(maxSoFar, sum);
        }
    }
    return maxSoFar;
}

// #2
int algorithm2(vector<int> &X) {
    int maxSoFar = 0;
    int P = 0;
    int Q = X.size();
    for (int L = P; L <= Q; L++) {
        int sum = 0;
        for (int U = L; U < Q; U++) {
           sum = sum + X[U];
           // sum now contains the sum of X[L...U]
           maxSoFar = max(maxSoFar, sum);
        }
    }
    return maxSoFar;
}

// alg 3
int algorithm3(vector<int> &X, int L, int U) {
	if (L > U) {
		return 0; /* zero element vector */
	}
	if (L == U) {

		return max(0, X[L]);

	}
	int M = (L + U) / 2;  /* A is X[L..M], B is X[M+1..U] */
	int sum = 0;
	int	maxToLeft = 0;

	for (int I = M; I >= L; I--) {
		sum = sum + X[I];
		maxToLeft = max(maxToLeft, sum);
	}
	/* Find max crossing to right */
	sum = 0;
	int maxToRight = 0;
	for (int I = M + 1; I <= U; I++) {
		sum = sum + X[I];
		maxToRight = max(maxToRight, sum);
	}
	int maxCrossing = maxToLeft + maxToRight;

	int maxInA = algorithm3(X, L, M);
	int maxInB = algorithm3(X, M + 1, U);

    int finalMax = max(max(maxCrossing, maxInA), maxInB);
	return finalMax;
}

// alg 4	
int algorithm4(vector<int> &X) {
	int maxSoFar = 0;
	int maxEndingHere = 0;
	
	int P = 0;
	int Q = X.size();
	for (int I = P; I < Q; I++) {
		maxEndingHere = max(0, maxEndingHere + X[I]);
		maxSoFar = max(maxSoFar, maxEndingHere);
	}
	return maxSoFar;
}
