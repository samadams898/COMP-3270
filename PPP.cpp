#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// function declarations
int algorithm1(vector<int>& X);
int algorithm2(vector<int>& X);
int algorithm3(vector<int>& X, int L, int U);
int algorithm4(vector<int>& X);

// reading/writing/checking file functions

bool check_file(string);
vector<int> read_file(string);  // i want this to read the file and also store the integers into the vector as well
void writefile(vector<int>& X, int outputArray_size, string file);
string file = "phw_input.txt";

// main method
int main() {
    check_file(file);

    vector<int> readArray = read_file(file);
    for (int i : readArray) {
        cout << i << "\n";
    }
    cout <<"algorithm 1: " << algorithm1(readArray) << "\n";

    cout << "algorithm 2: " << algorithm2(readArray) << "\n";
    
    cout << "algorithm 3: " << algorithm3(readArray, 0, readArray.size() - 1) << "\n";

    cout << "algorithm 4: " << algorithm4(readArray) << "\n";

    vector<vector<int>> cumshot;

    for (int i = 0; i < 19; i++) {
        vector<int> column;

        for (int j = 0; j < (i + 2) * 5; j++) {
            column.push_back(rand() % 100 + 1);

        }
        cumshot.push_back(column);
    }


}

// function/algorithm definitions
// each algorithm is a solution to MSCS

// T(n) = 
int algorithm1(vector<int>& X) {
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
int algorithm2(vector<int>& X) {
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
int algorithm3(vector<int>& X, int L, int U) {
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
int algorithm4(vector<int>& X) {
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

// helper functions

bool check_file(string file) {
    ifstream stream;

    stream.open(file.c_str());
    if (stream.fail()) {
        cout << "Input file opening failed." << endl;
    }
    stream.close();

    return true;
}

vector<int> read_file(string fileIn) {
   // int i = 0;
    ifstream stream;
    vector<int> X;
    int index;
    stream.open(fileIn);
    string number_as_string;
    while (getline(stream, number_as_string, ',')) {
        X.push_back(stoi(number_as_string));
    }
    /**for (vector<int>::iterator it = X.begin(); it != X.end(); ++it) {
        cout << ' ' << *it;
        cout << '\n';
    } **/
    return X;
}

// alt solution
// this link is where this solution was from
    // https://stackoverflow.com/questions/40945378/reading-a-comma-separated-file-into-an-integer-array
    // ifstream inputFile ("phw_input.txt");

    //vector<int> numbers;
    //string number_as_string;

    //while (getline(inputFile, number_as_string, ',')) {
        //numbers.push_back(stoi(number_as_string));
    //}

    //cout << "n : " << numbers.size() << "\n";
    //for (auto&& number : numbers) {
        //cout << number << "\n";
    //}

void writefile(vector<int>& X, int outputArray_size, string file) {
    ofstream outstream;
    string output_filename;
    cout << "Enter the output file name: ";
    cin >> output_filename;

    outstream.open((char*)output_filename.c_str());
    for (int i = 0; i < outputArray_size; i++) {
        outstream << X[i] << "\n";
    }
    outstream.close();

    cout << "*** Please check the new file - "
        << output_filename << " ***\n"
        << "*** Goodbye. ***";
}
