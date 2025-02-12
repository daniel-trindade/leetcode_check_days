#include <iostream>
#include <string>

using namespace std;

string clearDigits(string s){
    string temp = s;
    int n = temp.length();
    
    for(int i = 0; i < n; i++){
        if (isdigit(temp[i])){
            temp.erase(i-1, 2);
            n = temp.length();
            i = 0;
        }
    }
    return temp;
}

int main()
{
    string s = "cb34";
    cout << "Resultado: " << clearDigits(s);
    return 0;
}