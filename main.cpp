//Student name: Mahsa Fazli 1271287

#include <iostream>
#include <chrono> //For measuring time (start and end points, duration)
#include <cmath> //We don't really need this library in this code but I have added that in case I want to use it!
#include <string> //For std::string and to_string
#include <iomanip> //For setw()

using namespace std;
using namespace chrono;

// Function definitions :
void opLinear(int n) {
    int x;
    for (int i = 0; i < n; ++i)
        x = 1;
}

void opNlogN(int n) {
    int x;
    for (int i = 0; i < n; ++i)
        for (int j = 1; j < n; j *= 2)
            x = 1;
}

void opQuadratic(int n) {
    int x;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            x = 1;
}

void opCubic(int n) {
    int x;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < n; ++k)
                x = 1;
}

// Function for calculating time :
long long measureTime(void (*func)(int), int n) {    //this function takes our other functions as input to measures how long they take to run 
    auto start = high_resolution_clock::now();
    func(n);
    auto end = high_resolution_clock::now();
    return duration_cast<microseconds>(end - start).count();
}

int main() {
    // To Print formatted headers :
    cout << left
        << setw(5) << "i"
        << setw(12) << "opLinear"
        << setw(12) << "opNlogN"
        << setw(18) << "opQuadratic"
        << setw(18) << "opCubic (microseconds)" << endl;
    cout << string(69, '-') << endl;

    // Loop through powers of 2 :
    for (int i = 10; i <= 20; ++i) {
        int n = 1 << i; //1 << i is the same as pow(2, i) or n = 2^i but faster and uses no math library 

        long long linear = measureTime(opLinear, n);
        long long nlogn = measureTime(opNlogN, n);

        string quadratic = "SKIPPED";
        string cubic = "SKIPPED";

        if (i <= 17) {
            quadratic = to_string(measureTime(opQuadratic, n)); // we use to-string to be able to assign the measured time to the variable of type string 
        }                                                       // because since we needed to use the word "skipped" we had to define it as string type

        if (i <= 12) {
            cubic = to_string(measureTime(opCubic, n));         //Same for this
        }

        // To Print output aligned and tidy :
        cout << left
            << setw(5) << i
            << setw(12) << linear
            << setw(12) << nlogn
            << setw(18) << quadratic
            << setw(18) << cubic << endl;
    }

    return 0;
}