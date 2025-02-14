#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<long long> vectorCopy(const vector<int>& original) {
  return vector<long long>(original.begin(), original.end());
}

int minOperations(vector<int> &nums, int k){

  int count = 0;

  priority_queue<long long, vector<long long>, greater<long long>> minHeap(nums.begin(), nums.end());
  
  while(minHeap.top()<k){
    long long x = minHeap.top();
    minHeap.pop();
    long long y = minHeap.top();
    minHeap.pop();
    minHeap.push(x*2+y);
    count++;
  }
  
  return count;
}

int main(){
  vector<int> nums = {2,11,10,1,3};
  int k = 10;

  cout << minOperations(nums, k) << endl;

  return 0;
}