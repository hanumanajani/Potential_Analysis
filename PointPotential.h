#include<iostream>
#include<fstream>
#include<math.h>

using namespace std;

class PointPotential{
    public:
    std::string fname;
    double xcrd1;
    double ycrd1;
    double zcrd1;
    double xcrd2;
    double ycrd2;
    double zcrd2;
    int step;
    PointPotential(int step,double xcrd1,double ycrd1,double zcrd1,double xcrd2 ,double ycrd2,double zcrd2,std::string fname);
    double Potentialdiff(std::vector<std::vector<double>>ptchlst);  // give potential diff  b/w pt 1&2
    double potential_on_pt(std::vector<std::vector<double>>ptchlst,float x,float y,float z);
    ~PointPotential();
    


};
PointPotential::~PointPotential(){
    cout<<"point potential calculation process ended here"<<endl;
}
PointPotential::PointPotential(int step,double xcrd1,double ycrd1,double zcrd1,double xcrd2 ,double ycrd2,double zcrd2, std::string fname){
    this->fname = fname;
    this->step=step;
    this->xcrd1=xcrd1;
    this->ycrd1=ycrd1; 
    this->zcrd1=zcrd1;
    this->xcrd2=xcrd2;
    this->ycrd2=ycrd2;
    this->zcrd2=zcrd2;
}

double PointPotential::Potentialdiff(std::vector<std::vector<double>>ptchlst){
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
    
    double V=0;
    int m = ptchlst.size();
    double x =x1;
    double y= y1;
    double z =z1;
    std:: string ep_file_name = this->fname + ".ep";
    ofstream fio(ep_file_name,ios::app);
    ofstream fiod(ep_file_name+"d",ios::app);
    ofstream fiov(ep_file_name+"v",ios::app);


    double d =0;
    double dr = sqrt(dx*dx + dy*dy + dz*dz);
    for(int i=0;i<n;i++){
    
 
        V = potential_on_pt(ptchlst,x,y,z);
        
        fio<<d<<"  "<<V<<endl;
        fiod<<d<<endl;
        fiov<<V<<endl;

        d+=dr;
        x+=dx;
        y+=dy;
        z+=dz;
        
        // add v ,x,y,z in text file 


        
    }
    fio.close();
    return V;


}

double PointPotential :: potential_on_pt(std::vector<std::vector<double>>ptchlst,float x,float y,float z){
    
    int n = ptchlst.size();
    double ans = 0;
    for(int i=0;i<n;i++){
        double charge = ptchlst[i][1];
        double x1= ptchlst[i][2];
        double y1 =ptchlst[i][3];
        double z1 =ptchlst[i][4];
        if(((x1-x)*(x1-x)+(y1-y)*(y1-y)+(z1-z))<0.000000000000000000001){
            continue;
        }
        double r = sqrt(((x1-x)*(x1-x)+(y1-y)*(y1-y)+(z1-z)));
        double dv = 14.403523*charge/r;
        ans+=dv;
    
    }
    return ans;
}



