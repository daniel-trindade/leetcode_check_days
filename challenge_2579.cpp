#include <iostream>

using namespace std;

long long coloredCells(int n) {

  long long x = 1;

  for(long long i = 1; i<n; i++){
    x+=i*4;
    cout << "Parcial: " << x << endl;
  }

  return x;
}


int main(){

  long long res = coloredCells(69690);
  cout << "Resultado: " << res << endl;

}