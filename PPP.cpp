/* FILE NAME: project3_petrillo_mrp0066.cpp
 * Author: Mattea Petrillo
 * Compile: g++.exe (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0
 * run: ./project3_petrillo_mrp0066
 * 
 * Sources:
 * Project3 Template
 * COMP 2210 notes for sorting references
 * Ch.4 Slides for iostream
 * 
 */ 
#include <iostream>
#include <fstream>
#include <cstdlib> 
#include <string>

using namespace std;

const int MAX_SIZE = 100;

/* function to check if valid file */
bool check_file(string);

/* function to read file */
int read_file(int inputArray[], ifstream& inStream);

/* function to merge two sorted arrays */
int merge(int inputArray[], int inputArray1_size, int inputArray2[], int inputArray2_size, int outputArray[]);

/* function to write the output array to a new file */
void writefile(int outputArray[], int outputArray_size, string file);

ifstream stream;
int iArray1[MAX_SIZE];
int iArray1_size;
int iArray2[MAX_SIZE];
int iArray2_size;
    
string filename;
string filename2;
string file;

int outputArray[MAX_SIZE];
int outputArray_size;
    
int main() {

    cout << "*** Welcome to Brian's sorting program\n";

    // Check, read, and create an array for data in 2nd file
    cout << "Enter the first input file name: ";
    cin >> filename;
    
    // if valid file open stream, else exits program with warning
    if (check_file(filename) == true) {
        stream.open(filename.c_str());
    }
    iArray1_size = read_file(iArray1, stream);
    stream.close();

    // spits out the ints stored from first file
    cout << "The list of " << iArray1_size << " numbers in file " << filename << " is:\n";
    for (int i = 0; i <= iArray1_size; i++) {
        cout << iArray1[i] << endl;
    }
    cout << endl;

    // Check, read, and create an array for data in 2nd file
    cout << "Enter the second input file name: ";
	cin >> filename2;

    // if valid file open stream, else exits program with warning
    if (check_file(filename2) == true) {
        stream.open(filename2.c_str());
    }
    iArray2_size = read_file(iArray2, stream);
    stream.close();

    // spits out the ints stored from first file
    cout << "The list of " << iArray2_size << " numbers in file " << filename2 << " is:\n";
    for (int i = 0; i <= iArray2_size; i++) {
        cout << iArray2[i] << endl;
    }
    cout << endl;

    // merging
    outputArray_size = merge(iArray1, iArray1_size, iArray2, iArray2_size, outputArray);
    cout << "The sorted list of " << outputArray_size << " numbers is: ";
	for (int i = 0; i < outputArray_size; i++) {
		cout << outputArray[i] << " ";
	}
	cout << endl;

    // Write to new file
	writefile(outputArray, outputArray_size, file);
    return 0;
}

bool check_file(string file) {
    ifstream stream;
    
    stream.open(file.c_str());
    if (stream.fail()) {
        cout << "Input file opening failed." << endl;
    }
    stream.close();

    return true;
}

int read_file(int inputArray[], ifstream& inStream) {
    int index = 0;

    inStream >> inputArray[index];
    while (!inStream.eof()) {
        index++;
        inStream >> inputArray[index];
    }
    return index;
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

int merge(int inputArray[], int inputArray1_size, int inputArray2[], int inputArray2_size, int outputArray[]) {
    int i = 0; // represents counter for iArray1
    int j = 0; // represents counter for iArray2
    int size = 0;
    while (i < inputArray1_size && j < inputArray2_size) {
        if (inputArray[i] < inputArray2[j]) {
            outputArray[size] = inputArray[i];
            i++;
            size++;
        }
        else if (inputArray[i] > inputArray2[j]) { 
            outputArray[size] = inputArray2[j];
            j++;
            size++;
        }
        else if (inputArray[i] == inputArray2[j]) {
            outputArray[size] = inputArray[i];
            i++;
            outputArray[size++] = inputArray2[j];
            j++;
            size+=2;
        }
    }

    while (i < inputArray1_size) {
        outputArray[size] = inputArray[i];
        i++;
        size++;
    }
    while (j < inputArray2_size) {
        outputArray[size] = inputArray2[j];
        j++;
        size++;
    }
    return size;
}


void writefile(int outputArray[], int outputArray_size, string file) {
	ofstream outstream;
    string output_filename;
    cout << "Enter the output file name: ";
    cin >> output_filename;

    outstream.open((char*)output_filename.c_str());
    for (int i = 0; i < outputArray_size; i++) {
        outstream << outputArray[i] << "\n";
    }
    outstream.close();

    cout << "*** Please check the new file - " 
         << output_filename << " ***\n"
         << "*** Goodbye. ***";
}

