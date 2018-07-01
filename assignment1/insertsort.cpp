/*************************************************
** Name: Harshvardhan Singh
** OSUID: 932539479
**
*************************************************/

#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

void insertion_sort (vector<int> *data) {
  for (int i = 1;i<(*data).size();i++) {
    for(int j = 0;j<i;j++){
      if((*data)[i] < (*data)[j]) {
        int temp = (*data)[i];
        (*data)[i] = (*data)[j];
        (*data)[j] = temp;
      }
    }
  }
  for (int i = 0; i < (*data).size(); i++) {
    cout << (*data)[i] << " ";
  }
  cout << endl;
  (*data).clear();
}


int main () {

  vector<int> data;
  ifstream myfile;
  ofstream output_file;
  myfile.open("data.txt");
  output_file.open("insert.out");
  
  string line;
  // getline (myfile,line);
  // cout << line << endl;
  while(!myfile.eof()) {
    // getline(myfile, line);
    int a;
    myfile >> a;
    for (int i=0;i<a;i++) {
      int b;
      myfile >> b;
      data.push_back(b);
    }
    clock_t start, stop;
    start = clock();
      insertion_sort(&data);
    stop = clock();

    cout << a << " elements take " << left << setw(5) << (stop - start)/(CLOCKS_PER_SEC/1000) << "miliseconds to sort" << endl;
    // output_file << data.s
  }

  // for (int i = 0; i<data.size(); i++) {
  //   cout << data[i] << endl;
  // }

  // cout << endl << data.size() << endl << endl;

  // insertion_sort (&data);

}
