
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <iomanip>

using namespace std;

void merge (vector<int> *, int, int, int);


void merge_sort(vector<int> *data, int left_index, int right_index) {


  if (left_index == right_index) {
    return;
  }

  int middle = (left_index + (right_index-left_index)/2);
  // cout << "M " << middle << " Li" << left_index << " Ri" << right_index << endl;
  merge_sort(data, left_index,middle);
  merge_sort(data, middle+1, right_index);    

  merge(data, left_index, middle, right_index);

}

void merge (vector<int> *data, int left_index, int middle, int right_index) {
  
  int size_left = middle-left_index+1;
  int size_right = right_index-middle;

  // cout << "Size_left is " << size_left << endl;
  // cout << "Size_right is " << size_right << endl;;

  int *left_arr = new int [size_left];
  int *right_arr = new int [size_right];


  for (int i=0;i<size_left;i++) {
    left_arr[i] = (*data)[left_index+i];
    // cout << "Left_arr[" << i << "] is " << left_arr[i] << endl;
  }

  for (int i=0;i<size_right;i++) {
    right_arr[i] = (*data)[middle+i+1];
    // cout << "Right_arr[" << i << "] is " << right_arr[i] << endl;
  }
  
  int a = 0;
  int b = 0;
  int c,d = 0;
  c = left_index;

  while (a<size_left && b<size_right) {
    if (left_arr[a] <= right_arr[b]) {
      (*data)[c++] = left_arr[a++];
    }
    else {
      (*data)[c++] = right_arr[b++];
    }
  }

  if (a<size_left) {
      (*data)[c++] = left_arr[a++];
  }

  if (b<size_right) {
      (*data)[c++] = right_arr[b++];
  }

  delete []left_arr;
  delete []right_arr;

}


int main () {
  // int a[] = {3,4,6,2,67,32,1,35};
  srand(time(NULL));
  ifstream myfile;
  ofstream output_file;
  output_file.open("merge.out");
  myfile.open("data.txt");
  // vector<int> data (a,a+sizeof(a)/sizeof(int)); //[3,4,6,2,67,32,1,35];
  int rand_numb;
  vector<int> data;
  while(!myfile.eof()) {
    // getline(myfile, line);
    int a;
    myfile >> a;
    for (int i=0;i<a;i++) {
      int b;
      myfile >> b;
      data.push_back(b);
    }

    // cout << data[0] << endl;
    // cout << data.size() << endl;
    clock_t start, stop;
    start = clock();
      merge_sort(&data, 0, data.size()-1);  
    stop = clock();

    cout << data.size() << " elements take " << left << setw(5) << (stop - start)/(CLOCKS_PER_SEC/1000) << "miliseconds to sort" << endl;
    output_file << data.size() << " elements take " << left << setw(5) << (stop - start)/(CLOCKS_PER_SEC/1000) << "miliseconds to sort" << endl;
    // cout << left << setw(5) << (stop - start)/(CLOCKS_PER_SEC/1000) << " ";
    data.clear();
  }
  // for (int i=0;i<data.size();i++) {
  //   cout << data[i] << " ";
  // }
  cout << endl;
}