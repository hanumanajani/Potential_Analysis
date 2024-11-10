#include<string>
#include<iostream>
#include<fstream>
#include<vector>
#include "Textfreader.h"
using namespace std;

 

int main(){
    TextfileReader T;
    T.TextTovector("input.txt");
    cout<<(T.data.size());
    for(auto it:T.data){
        for(auto i:it){
            cout<<i<<"--";
        }
        cout<<'\n';
    }

    return 0;
}
