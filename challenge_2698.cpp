#include <iostream>
#include <string>
#include <vector>

using namespace std;

int punishmentNumber(int n) {
  std::vector<int> a = {1, 9, 10, 36, 45, 55, 82, 91, 99, 100, 235, 297, 369, 370, 
                        379, 414, 657, 675, 703, 756, 792, 909, 918, 945, 964, 
                        990, 991, 999, 1000};

  int prod = 0;
  for (int value : a) {
      if (value <= n) {
          prod += value * value;
      } else {
          break;
      }
  }
  return prod;
}

int main(){

    int n;
    cin >> n;
    cout << punishmentNumber(n) << endl;

  return 0;
}