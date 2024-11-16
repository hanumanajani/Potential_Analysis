


#include<iostream>
using namespace std;

class IntegralPotential{
    double xcrd1;
    double ycrd1;
    double zcrd1;
    double xcrd2;
    double ycrd2;
    double zcrd2;
    int step;
    IntegralPotential(int step,double xcrd1,double ycrd1,double zcrd1,double xcrd2 ,double ycrd2,double zcrd2);
    double Potentialdiff(std::vector<std::vector<double>>ptchlst,std::map<std::string,double>mp);
    std::vector<double> Electric_field_on_pt(std::vector<std::vector<double>>ptchlst,std::map<std::string,double>mp,float x,float y,float z);
    ~IntegralPotential();
    


};

IntegralPotential::IntegralPotential(int step,double xcrd1,double ycrd1,double zcrd1,double xcrd2 ,double ycrd2,double zcrd2){
    this->step=step;
    this->xcrd1=xcrd1;
    this->ycrd1=ycrd1; 
    this->zcrd1=zcrd1;
    this->xcrd2=xcrd2;
    this->ycrd2=ycrd2;
    this->zcrd2=zcrd2;
}

double IntegralPotential::Potentialdiff(std::vector<std::vector<double>>ptchlst,std::map<std::string,double>mp){
    int n = this->step;
    double x1 = this->xcrd1;
    double y1 = this->ycrd1;
    double z1 = this->zcrd1;
    double x2 = this->xcrd2;
    double y2 = this->ycrd2;
    double z2 = this->zcrd2;
    double dx = (x2-x1)/n;
    double dy = (y2-y1)/n;
    double dz = (z2-z1)/n;
    double dr = sqrt(dx*dx+dy*dy+dz*dz);
    double V=0;
    double v1 = 0; //initial potential --- also can be calculated using point potential
    V = v1;
    int m = ptchlist.size();
    double x =x1;
    double y= y1;
    doubl1 z =z1;
    for(int i=0;i<m;i++){
        std::vector<double> EF;
        x+=dx;
        y+=dy;
        z+=dz;
        EF = Electric_field_on_pt(ptchlist,mp,x,y,z);
        //find component on line joining point 1&2;
        // find dv
        double dv = 0.0000001 //assumed 
        V+=dv
        // add v ,x,y,z in text file 

        
    }
    return V;


}

std::vector<double> IntegralPotential :: Electric_field_on_pt(std::vector<std::vector<double>>ptchlst,std::map<std::string,double>mp,float x,float y,float z){
    double efx=0;
    double efy=0;
    double efz=0;
    int n = ptchlst;
    for(int i=0;i<n;i++){
        double charge = ptchlist[i][1];
        double x1= ptchlist[i][2];
        double y1 =ptchlist[i][3];
        double z1 =ptchlist[i][4];
        if(((x1-x)*(x1-x)+(y1-y)*(y1-y)+(z1-z))<0.000000000000000000001){
            continue;
        }
        ///value of k is not addddded
        efx = efx + (k*charge)///------------
        efy = efy+ //------------
        efz = efz+ //------------


        std::vector<double> ans;
        ans.push_back(efx);
        ans.push_back(efy);
        ans.push_back(efz);
        return ans;
    }
}



