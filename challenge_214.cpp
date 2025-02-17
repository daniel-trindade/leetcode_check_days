#include <iostream>
#include <algorithm>

using namespace std;

string shortestPalindrome(string s) {
    int n = s.size();
    string rev = s;
    reverse(rev.begin(), rev.end());
    for(int i = 0; i < n; i++){
        if(s.substr(0, n-i) == rev.substr(i)){
            return rev.substr(0, i) + s;
        }
    }
    return "";
}

int main(){
  string s = "abcd";
  cout << shortestPalindrome(s) << endl;
  return 0;
}