#include "Textfreader.h"
#include<fstream>

// custom function for secondary use 
std::vector<std::string> split_string(std::string s){
    std::vector<std::string> ans;
    std::string a;
     int n = s.length();
     for(int i=0;i<n;i++){
        if(s[i]=='\n'){
            if(a.length()){
                ans.push_back(a);
                a = "";
               
            }
            break;

        }
        else if(s[i]==' '){
            if(i>=1 &&s[i-1]!=' '){
                ans.push_back(a);
                a = "";
            }
            continue;
        }
        else a.push_back(s[i]);
     }
     return ans;
}

TextfileReader :: TextfileReader(){
    file_name = "";
    std::vector<std::vector<std::string> > data1;
    data = data1;
    std::map<std::string,float>mp1;
    mp= mp1;
    int length = 0;
    // file_name = "";
    // data = std::vector<std::vector<std::string> >();
    // mp = std::map<std::string, float>();
    // length = 0;
}



void TextfileReader::TextTovector(std::string filename){
    std::ifstream ifs;
    ifs.open(filename,std::ios_base::in);
    std::vector<std::string> data;
    std::string s = "";
    while(ifs.good()){
        char a = ifs.get();
        if(a=='\n'){
            data.push_back(s);
            s="";
        }
        else {
            s.push_back(a);
        }
    }
    if(s.length())data.push_back(s);
    for(int i=0;i<data.size();i++){
        std::vector<std::string> v;
        v = split_string(data[i]);
        this->data.push_back(v);
    }

   


}
TextfileReader::TextfileReader(){
    std::cout<<"constructer called";
}
TextfileReader::~TextfileReader(){
    std::cout<<"destructer called";
}
void TextfileReader::TextToMap(std::string filename){
    // map function for charge amber library 
    return ;
}
int TextfileReader::lengthfind(std::vector<std::vector<std::string> > data){
    // length of text file 
    return 0;
}





 