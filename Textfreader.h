
#include<string>
#include<vector>
#include<iostream>
#include<map>
#include<fstream>
using namespace std;



//---------------------------------
// custom function for secondary use 
std::vector<std::string> split_string(std::string s){
    std::vector<std::string> ans;
    std::string a="";
    int n = s.length();
    for(int i=0;i<n;i++){
        if(s[i]=='\n'){
            if(a.length()){
                ans.push_back(a);
                // a = "";
                a.clear();
               
            }
            break;

        }
        else if(s[i]==' '){
            if(i>=1 &&s[i-1]!=' '){
                ans.push_back(a);
                // a = "";
                a.clear();
            }
            continue;
        }
        else a.push_back(s[i]);
     }
     if(a.length()!=0)ans.push_back(a);
     return ans;
}




class TextfileReader{
    public:
      std::string file_name;
      std::vector<std::vector<std::string> > data;
      std::map<std::string,double>mp;
      std::vector<std::vector<double>>ptchlist;
      int length;

      TextfileReader();
      void TextTovector(std::string filename);
      void TextToMap(std::string filename);
      int lengthfind(std::vector<std::vector<std::string> > filename);
      void ptchlistgen();
      ~TextfileReader();     


};
TextfileReader::TextfileReader(){
    std::cout<<"constructer called"<<'\n';
}
TextfileReader::~TextfileReader(){
    std::cout<<"destructer called"<<'\n';
}
 
void TextfileReader:: ptchlistgen(){
      for(int i=0;i<this->data.size();i++){
        if(this->data[i][0]!="ATOM" and this->data[i][0]!="HETATM")continue;
        int a,b,c,x,y,z;
        a=3;
        b=2;
        c=1;
        x=5;
        y=6;
        z=7;

        std::vector<double>vect;
        int ind = std::stoi(this->data[i][c]); //need to convert into int
        double charge = this->mp[this->data[i][a]+" "+this->data[i][b]];
        cout<<"charge"<<this->data[i][a]+" "+this->data[i][b]<<charge<<endl;
        double xcrd = std::stod(this->data[i][x]); // need to convert x,y,z cordinate string to double
        double ycrd = std::stod(this->data[i][y]);
        double zcrd = std::stod(this->data[i][z]);
        vect.push_back(ind);
        vect.push_back(charge);
        vect.push_back(xcrd);
        vect.push_back(ycrd);
        vect.push_back(zcrd);
        this->ptchlist.push_back(vect);
      }
      return;
}

void TextfileReader::TextTovector(std::string filename){
    std::ifstream ifs;
    ifs.open(filename,std::ios_base::in);
    std::vector<std::string> data1;
    std::string s = "";
    cout<<filename;
    while(ifs.good()){
        char a = ifs.get();
        // cout<<a;
        
        if(a=='\n'){
            data1.push_back(s);
            s.clear();
            // s="";
        }
        else {
            s.push_back(a);
        }
    }
    if(s.length())data1.push_back(s);
    // cout<<data1.size()<<endl;
    for(int i=0;i<data1.size();i++){
        std::vector<std::string> v;
        v = split_string(data1[i]);
        this->data.push_back(v);
    }


   


}

// for storing amber library in map for acccess charge 
void TextfileReader :: TextToMap(std::string filename){
    cout<<"Texttomap function................";

    std::ifstream ifs;
    ifs.open(filename,std::ios_base::in);
    std::string s = "";
    std::vector<std::string> data1;
    std::vector<vector<std::string>>vect;
    // cout<<"Texttomap function................";
    while(ifs.good()){
        char a = ifs.get();
        if(a=='\n'){
            data1.push_back(s);
            s="";
        }
        else{
            s.push_back(a);
        }
        
    }
    if(s.length())data1.push_back(s);

    for(int i=0;i<data1.size();i++){
        std::vector<std::string>v;
        v = split_string(data1[i]);
        vect.push_back(v);
    
    }
    // writing amber library in map 
    for(int i=0;i<vect.size();i++){
        if(vect[i].size()>=4){
         double ch =  std::stod(vect[i][3]);
        //  cout<<ch<<endl;
         this->mp[vect[i][0]+" "+vect[i][1]] = ch;
        }
         
        // this->mp[vect[i][0]+" "+vect[i][1]] = ch;
    }
    cout<<"charge of amber library stored in map"<<endl;

    
}
 
// void TextfileReader::TextToMap(std::string filename){
//     // map function for charge amber library 
//     return ;
// }
int TextfileReader::lengthfind(std::vector<std::vector<std::string> > data){
    // length of text file 
    return 0;
}




 




// #endif