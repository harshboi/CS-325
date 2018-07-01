
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

int main () {
  clock_t start, stop;
  start = clock();
    for(int i=0; i<10000000;i++){
        cout << i << endl;
    }
  stop = clock();   

  cout << "fsdfsd" << left << setw(5) << (stop - start)/(CLOCKS_PER_SEC/1000) << " ";

}