#include <iostream>
#include <string>

using namespace std;

string removeOccurrences(string s, string part){
    bool loop = true;

    while(loop){
        size_t found = s.find(part);
        if (found != string::npos){
            s.erase(found, part.length());
        } else {
            loop = false;
        }
    }

    return s;
}


int main()
{
    string s = "daabcbaabcbc";
    string part = "abc";
    cout << "Resultado: " << removeOccurrences(s, part);
    return 0;
}