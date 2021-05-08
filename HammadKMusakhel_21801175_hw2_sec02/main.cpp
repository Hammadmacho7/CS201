#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <math.h>
using namespace std;



//for  random addition of number elements into array;
void createList( int input[], int size){
    srand(time(NULL));
    for( size_t i = 0; i < size; ++i){
        input[i] = (rand()%size) + 1;
    }
}

int main() {

    long int size = 50000;
    int* check = new int[size];
    int* check_2 = new int[size];
    int n;
    const int k = 1000;
    double duration;
    int repeat;


    //add random numbers
    //an array of random numbers according to the size included, 1 - size;
     n = size;
     createList(check, size); //random numbers inside now check list
     clock_t startTime = clock();
     for ( int i = 0; i < 10; i++) {
         solution1(check, n, k, check_2);
     }
     duration = double(1000 * double(clock() - double(startTime)) / CLOCKS_PER_SEC);
     duration = duration/10; //taking average of the time
     cout << "For n = " << size << ", Execution for Algorithm 1 took " << duration << " milliseconds." << endl;
     cout << endl;

     delete [] check;
     delete[] check_2;

    check = new int[size];
    check_2 = new int[size];
    createList(check, size);
    clock_t startTime2 = clock();
    //for ( int i = 0; i < 10; i++) {
        solution2(check, n, k, check_2); //I took averages for every 7 readings for solution 2
   // }
    duration = double(1000 * double(clock() - double(startTime2)) / CLOCKS_PER_SEC);
    //duration = duration/10; //taking average of the time
    cout << "For n = " << size << ", Execution for Algorithm 2 took " << duration << " milliseconds." << endl;
    cout << endl;

    delete [] check;
    delete[] check_2;

    check = new int[size];
    check_2 = new int[size];
    createList(check, size);
    clock_t startTime3 = clock();
    for ( int i = 0; i < 10; i++) {
        solution3(check, n, k, check_2);
    }
    duration = double(1000 * double(clock() - double(startTime3)) / CLOCKS_PER_SEC);
    duration = duration/10; //taking average of the time
    cout << "For n = " << size << ", Execution for Algorithm 3 took " << duration << " milliseconds." << endl;
    cout << endl;

    delete [] check;
    delete [] check_2;

    return 0;
}