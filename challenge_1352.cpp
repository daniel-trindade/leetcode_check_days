#include <iostream>
#include <string>
#include <vector>

using namespace std;

class ProductOfNumbers {
  private:
    vector<int> nums;
  public:
    ProductOfNumbers() {
      cout << "Constructor" << endl;
    }
    
    void add(int num) {
      this->nums.push_back(num);
      cout << "Adding " << num << endl;
    }
    
    int getProduct(int k) {
      int product = 1;
      int n = this->nums.size();
      for(int i = n-1; i >= n-k; i--){
        product *= this->nums[i];
      }
      cout << "Produto = " << product << endl;
      return product;
    }
  

};

int main(){
  ProductOfNumbers productOfNumbers;

  productOfNumbers.add(7);
  productOfNumbers.getProduct(1);     
  productOfNumbers.getProduct(1);  
  productOfNumbers.add(4);       
  productOfNumbers.add(5); 
  productOfNumbers.getProduct(3);       
  productOfNumbers.add(4);  
  productOfNumbers.getProduct(4);     
  productOfNumbers.add(3);        
  productOfNumbers.getProduct(4); 
  productOfNumbers.add(8);  
  productOfNumbers.getProduct(1); 
  productOfNumbers.getProduct(6);
  productOfNumbers.add(2);        
  productOfNumbers.getProduct(3); 
}