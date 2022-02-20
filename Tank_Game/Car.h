#ifndef CAR_H_INCLUDED
#define CAR_H_INCLUDED

using namespace std;

class Car{
  private:
    int NumberOfCar, Distance_Car , Time_Car ;

  public:

     int  Coeff_Car[100];
     void getCoefficientOfCar(int*,int , int);
     void setTime    (double);
     void setDistance(double);
     void setNumberOfCar(int);
     double  getTime    ();
     double  getDistance();
     int  getNumberOfCar();
     int  EquationOfCar_Distance(double,int,int[]);
     int  EquationOfCar_Velocity(double,int,int[]);

};



#endif // CAR_H_INCLUDED
