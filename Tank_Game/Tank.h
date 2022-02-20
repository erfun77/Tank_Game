#ifndef TANK_H_INCLUDED
#define TANK_H_INCLUDED
#include<string>
#include<iostream>

using namespace std;
class Tank{
private:
    int Tank_x1,Tank_x2,Tank_x3,Tank_x4,Time,Distance;
    string CoT;
public:
     void getCoefficientOfTank(int*,int);
     void setTime    (double);
     void setDistance(double);
     void setTank_x1 (int);
     void setTank_x2 (double);
     void setTank_x3 (int);
     void setTank_x4 (int);
     double  getTime    ();
     double  getDistance();
     int  getTank_x1 ();
     double  getTank_x2 ();
     int  getTank_x3 ();
     int  getTank_x4 ();
     int  EquationOfTank_Distance(double,int,int[]);
     int  EquationOfTank_Velocity(double,int,int[]);

};



#endif // TANK_H_INCLUDED
