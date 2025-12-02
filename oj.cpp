#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int convert(int n){
    int result=0;
    if(n<8) return n;
    convert(n/8);
    cout<<n%8;
}

int main() {
    
    return 0;
}