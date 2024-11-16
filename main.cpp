#include<string>
#include<iostream>
#include<fstream>
#include<vector>
#include "Textfreader.h"
#include "PointPotential.h"

using namespace std;

 

int main(){
    cout<<"hrjani"<<endl;
    TextfileReader inp_file;
    // double a = -123.001;
    // cout<<a;
    
    inp_file.TextTovector("input.txt");
    cout<<(inp_file.data.size())<<endl;
    std::vector<std::vector<std::string>> inp_data = inp_file.data;
    // cout<<"-"<<(inp_data.size())<<"-";
    // cout<<(inp_file.data[0].size())<<endl; 
    int fa = std::stoi(inp_data[0][2]);
    int sa = std::stoi(inp_data[1][2]);
    std :: string fname = inp_data[2][2];
    int step = std::stoi(inp_data[3][2]);
   
    
    
    

    //storing charge in amber library;
    TextfileReader amberlib;
    amberlib.TextToMap("amber_library.inp");
    cout<<(amberlib.mp.size())<<endl;
    cout<<amberlib.mp["ALA N"]<<endl;
    

    //generating point charge list => index,charge,x-crd,y-crd,z-crd
    TextfileReader Pdb_file;
    cout<<fname<<endl;
    Pdb_file.TextTovector(fname);
    Pdb_file.mp = amberlib.mp;
    Pdb_file.ptchlistgen();
    cout<<Pdb_file.data.size()<<endl;
    cout<<Pdb_file.ptchlist.size()<<endl;
    

    // for(auto it:Pdb_file.ptchlist){ //for printing point charge
    //     for(auto i:it){
    //         cout<<i<<" ";
    //     }
    //     cout<<endl;
    // }
    

    // printing coorginate of first atom and second atom 
    cout<<"Crd of first atom"<<Pdb_file.ptchlist[fa-1][2]<<"  "<<Pdb_file.ptchlist[fa-1][3]<<"  "<<Pdb_file.ptchlist[fa-1][4]<<endl;
    cout<<"Crd of second atom"<<Pdb_file.ptchlist[sa-1][2]<<"  "<<Pdb_file.ptchlist[sa-1][3]<<"  "<<Pdb_file.ptchlist[sa-1][4]<<endl;
    
    //calculating potential for system

    std::string root_fname = "";
    for(auto it:fname){
        if(it=='.')break;
        else root_fname.push_back(it);
    }
    cout<<root_fname<<endl;
    double x1 = Pdb_file.ptchlist[fa-1][2];
    double x2 = Pdb_file.ptchlist[sa-1][2];
    double y1 = Pdb_file.ptchlist[fa-1][3];
    double y2 = Pdb_file.ptchlist[sa-1][3];
    double z1 = Pdb_file.ptchlist[fa-1][4];
    double z2 = Pdb_file.ptchlist[sa-1][4];

    PointPotential sys1(step,x1,y1,z1,x2,y2,z2,root_fname);
    sys1.Potentialdiff(Pdb_file.ptchlist);






    return 0;
}
