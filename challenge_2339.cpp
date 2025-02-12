#include <iostream>
#include <map>

using namespace std;

int main(){

    map <int, int> nums;

    
    void change(int index, int number) {
        nums[index] = number;
    }
    
    int find(int number) {
        for(const auto& pair : nums){
            if(pair.second == number){
                return pair.first;
            }
        }

        return -1;

    }

}


/*
class NumberContainers {
private: 
    std::map<int, int> nums;
public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        nums[index] = number;
    }
    
    int find(int number) {
        for(const auto& pair : nums){
            if(pair.second == number){
                return pair.first;
            }
        }

        return -1;

    }

};
*/