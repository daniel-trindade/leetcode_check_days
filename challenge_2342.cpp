#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm> 

using namespace std;

int digi_sum(int num) {
    int soma = 0;
    while (num > 0) {
        soma += num % 10;
        num /= 10; 
    }
    cout << "Soma: " << soma << endl;
    return soma;
}

int maximumSum(vector<int>& nums) {

    int max_value = 0;
    bool there_is_sum = false;
    map<int, vector<int>> sums_to_nums;

    for(int i=0; i<nums.size(); i++){
        sums_to_nums[digi_sum(nums[i])].push_back(nums[i]);
    }

    for(auto& pair : sums_to_nums){

        if(pair.second.size() > 1){
            there_is_sum = true;
            sort(pair.second.begin(), pair.second.end(), greater<int>());
            int sum = pair.second[0] + pair.second[1]; 
            max_value = max(max_value, sum);
        }
    }

    if(there_is_sum) {
        return max_value;
    }else{
        return -1;
    }
}


int main()
{
    vector<int> nums = {4,6,10,6}; // 9, 7, 9, 4, 7
    cout << maximumSum(nums) << endl;
    return 0;
}