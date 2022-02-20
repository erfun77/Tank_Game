#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <dos.h>
#include<iostream>
#include<cmath>
#include<string>
#include<cstdlib>
#include<time.h>
#include"Obstacle.h"
#include"Tank.h"
#include"Car.h"
#include"Bullet.h"
using namespace std;

void Bullet::getCoeffOfBullet(int *Coeff , int n,int bull_n){
    cout<<"For "<< bull_n +1 <<" th bullet : "<<endl;

    for(int i = 0 ; i < n ; i ++ )
        {
        cout<< "your ("<<i<<") Coefficient is : ";
        cin>>Coeff[i];
         }
}
int Bullet::EquationOfBullet_Distance(double t , int n , int Coeff[]){
int sum = 0;

        for(int counter = 0 ; counter < n ; counter++)
            sum += Coeff[counter]*pow(t,double(counter+1));

    return sum;
}

/*****************************************TANK**************************************************/
void    Tank :: setTime    (double t){Time = t;}
void    Tank :: setDistance(double d){Distance = d;}
void    Tank :: setTank_x1 (int x){Tank_x1 = x;}
void    Tank :: setTank_x2 (double x){Tank_x2 = x;}
void    Tank :: setTank_x3 (int x){Tank_x3= x;}
void    Tank :: setTank_x4 (int x){Tank_x4 = x;}
double  Tank :: getTank_x2 (){return Tank_x2;}
double  Tank :: getTime    (){return Time;}
double  Tank :: getDistance(){return Distance;}
int     Tank :: getTank_x1 (){return Tank_x1;}
int     Tank :: getTank_x3 (){return Tank_x3;}
int     Tank :: getTank_x4 (){return Tank_x4;}

void Tank::getCoefficientOfTank(int *Coeff,int n)
{

        for(int i = 0 ; i < n ; i ++ )
        {
          cout<< "your ("<<i<<") Coefficient is : ";
          cin>>Coeff[i];
         }
}
int Tank::EquationOfTank_Distance( double t , int n ,int Coeff[])
{
        int sum = 0;

        for(int counter = 0 ; counter < n ; counter++)
            sum += Coeff[counter]*pow(t,double(counter));

    return sum;
}
int Tank::EquationOfTank_Velocity(double t , int n ,int Coeff[])
{
        int sum = 0;

        for(int counter = 1 ; counter < n ; counter++)
            sum += (counter*Coeff[counter])*(pow(t,double(counter))/counter);

    return (sum);
}
/*******************************************Obstacle****************************************************/
void Obstacle::setObs_x(int x){
    obs_x = x;
    }
int Obstacle::getObs_x(){return obs_x;}
/**********************************************Car*******************************************************/
void    Car :: setTime       (double t) {Time_Car = t;}
void    Car :: setDistance   (double d) {Distance_Car = d;}
void    Car :: setNumberOfCar(int n ){NumberOfCar = n;}
double  Car :: getTime       (      ){return Time_Car;}
double  Car :: getDistance   (      ){return Distance_Car;}
int     Car :: getNumberOfCar(      ){return NumberOfCar;}

void Car::getCoefficientOfCar(int *Coeff,int n ,int car_n)
{
        cout<<"For "<< car_n +1 <<" th Car : "<<endl;
        for(int i = 0 ; i < n ; i ++ )
        {
          cout<< "your ("<<i<<") Coefficient is : ";
          cin>>Coeff[i];
         }
}
int Car::EquationOfCar_Distance( double t , int n ,int Coeff_Car[])
{
        int sum = 0;

        for(int counter = 0 ; counter < n ; counter++)
            sum += Coeff_Car[counter]*pow(t,double(counter));

    return sum;
}
int Car::EquationOfCar_Velocity(double t , int n ,int Coeff_Car[])
{
        int sum = 0;

        for(int counter = 1 ; counter < n ; counter++)
            sum += (counter*Coeff_Car[counter])*(pow(t,double(counter))/counter);

    return (sum);
}


/********************************************************************************************************/
int main() {
    int gd = DETECT, gm;
    double i;
    int maxx;
    int n1,n2,eq1,color,obs_n,destroy,car_n,car_destroyed = 0;
    cout<<"Which one Of This Do You Want To Use ?\n"<<"1-Distance Equation\n"<<"2-Velocity Equation "<<endl;
    cin>>eq1;
    cout<<"Enter The Color Of Tank ( 1-BL UE 2-GREEN 3-CYAN 4-RED ): ";
    cin>>color;
    cout<<"Enter The Number Of Coefficient (For Tank) : " ;
    cin>>n1;
    int Coeff_Tank[n1];
    cout<<"Enter The Number Of Coefficient (For Car) : " ;
    cin>>n2;
    cout<<"Enter Number Of Cars : ";
    cin>>car_n;
    cout<<"Enter The Number Of Obstacles : ";
    cin>>obs_n;
    cout<<"Enter Destroy Number : ";
    cin>>destroy;

    int obs_x[obs_n];
    Obstacle O;
    Bullet B[50];
    int Car_des[20];
    Car c[car_n];
    Tank T;
    T.getCoefficientOfTank(Coeff_Tank,n1);
     for(int j = 0 ; j < car_n ; j++)
    {
        c[j].getCoefficientOfCar(c[j].Coeff_Car,n2,j);
    }
     for(int j = 0 ; j < 10 ; j++)
    {
        B[j].getCoeffOfBullet(B[j].Coeff_Bullet,1,j);
    }
    for(int k = 0 ; k < obs_n ; k ++ )
    {
        cout<<"Enter Obstacle "<< k+1 <<" (x) : ";
        cin>>obs_x[k];
        O.setObs_x(obs_x[k]);
    }

    for(int i = 0 ; i < 20 ; i++ )
        Car_des[i] = 0;


    initgraph(&gd, &gm, "X:\\TC\\BGI");
    maxx = getmaxx();
    /**************************************************DISTANCE_EQ******************************************************/
    if(eq1 == 1){
        for (i = 0 ; i < maxx-150; i = i + 0.1)
            {
        cleardevice();
        setcolor(YELLOW);
        line(0 , 250 , maxx , 250);
        setfillstyle(1,color);


         /*-------------------------------------------TANK---------------------------------------------------------*/
            T.setTank_x2( 40+  T.EquationOfTank_Distance(i,n1,Coeff_Tank));
            bar( T.EquationOfTank_Distance(i,n1,Coeff_Tank)     , 235 , 40 +  T.EquationOfTank_Distance(i,n1,Coeff_Tank)  , 248 );
            setfillstyle(1,color);
            bar(10+ T.EquationOfTank_Distance(i,n1,Coeff_Tank)  , 220 , 30 +  T.EquationOfTank_Distance(i,n1,Coeff_Tank)  , 250 );
            setcolor(GREEN);
            line(30+ T.EquationOfTank_Distance(i,n1,Coeff_Tank) , 227 , 55 +  T.EquationOfTank_Distance(i,n1,Coeff_Tank)  , 227 );
            setfillstyle(1,DARKGRAY);
            setcolor(DARKGRAY);
            fillellipse(T.EquationOfTank_Distance(i,n1,Coeff_Tank)+5 ,250,3,3);
            fillellipse(T.EquationOfTank_Distance(i,n1,Coeff_Tank)+15,250,3,3);
            fillellipse(T.EquationOfTank_Distance(i,n1,Coeff_Tank)+25,250,3,3);
            fillellipse(T.EquationOfTank_Distance(i,n1,Coeff_Tank)+35,250,3,3);
         /*-------------------------------------------Car-----------------------------------------------------------*/
        for(int z = 0 ; z < car_n ; z++)
         {
            srand(time(NULL));
            int color = rand()%15 + 1;
            setfillstyle(1,color);
            bar((maxx-c[z].EquationOfCar_Distance(i,n2,c[z].Coeff_Car))    , 235 , ((maxx-40)-c[z].EquationOfCar_Distance(i,n2,c[z].Coeff_Car)) , 247);
            bar((maxx-10-c[z].EquationOfCar_Distance(i,n2,c[z].Coeff_Car)) , 226 , ((maxx-30)-c[z].EquationOfCar_Distance(i,n2,c[z].Coeff_Car)) , 247);
            setfillstyle(1,BROWN);
            setcolor(BROWN);
            fillellipse((maxx-10)-c[z].EquationOfCar_Distance(i,n2,c[z].Coeff_Car),250,3,3);
            fillellipse((maxx-30)-c[z].EquationOfCar_Distance(i,n2,c[z].Coeff_Car),250,3,3);
          }
          /*----------------------------------------------------Bullet-----------------------------------------------------*/

          for(int q = 0 ; q < 10 ; q++)
          {

              setcolor(RED);
              line(55 +  T.EquationOfTank_Distance(i,n1,Coeff_Tank) +B[q].EquationOfBullet_Distance(i,1,B[q].Coeff_Bullet) ,227 ,
                   58 +  T.EquationOfTank_Distance(i,n1,Coeff_Tank) +B[q].EquationOfBullet_Distance(i,1,B[q].Coeff_Bullet) ,227 );
          }

          /*----------------------------------------------------------------------------------------------------------------*/
            for(int k = 0 ; k < obs_n ; k++)
        {
            setfillstyle(1,WHITE);
            bar(obs_x[k] , 200,obs_x[k]+10 , 250);
        }

          if(55+ T.EquationOfTank_Distance(i,n1,Coeff_Tank) > obs_x[destroy-1])
            {
            T.setTime(i);
            T.setDistance(T.getTank_x2());
            break;
            }
             for(int z = 0 ; z < car_n ; z++)
        {
            if(40+ T.EquationOfTank_Distance(i,n1,Coeff_Tank) > (maxx-40)-c[z].EquationOfCar_Distance(i,n2,c[z].Coeff_Car) &&
               40+ T.EquationOfTank_Distance(i,n1,Coeff_Tank) < (maxx-c[z].EquationOfCar_Distance(i,n2,c[z].Coeff_Car)))
            {
                Car_des[z]++;
                c[z].setTime(i);
                c[z].setDistance((maxx-40)-c[z].EquationOfCar_Distance(i,n2,c[z].Coeff_Car) - maxx);

            }
            if(40 + T.EquationOfTank_Distance(i,n1,Coeff_Tank) >(maxx-40)-c[z].EquationOfCar_Distance(i,n2,c[z].Coeff_Car) ){
                setfillstyle(4,LIGHTBLUE);
                bar((maxx-c[z].EquationOfCar_Distance(i,n2,c[z].Coeff_Car))    , 235 , ((maxx-40)-c[z].EquationOfCar_Distance(i,n2,c[z].Coeff_Car)) , 250);
                bar((maxx-10-c[z].EquationOfCar_Distance(i,n2,c[z].Coeff_Car)) , 226 , ((maxx-30)-c[z].EquationOfCar_Distance(i,n2,c[z].Coeff_Car)) , 247);
            }
         }
        delay(100);
        }
 }
        /*************************************************VELOCITY_EQ*************************************************************/
        else if (eq1 == 2){
            for (i = 0; i < maxx-150; i = i + 0.1){
            cleardevice();
            setcolor(YELLOW);
            line(0 , 250 , maxx , 250);
            setfillstyle(1,color);
           /*---------------------------------------------TANK-----------------------------------------------------------------*/
            T.setTank_x2( 40+  T.EquationOfTank_Velocity(i,n1,Coeff_Tank));
            bar( T.EquationOfTank_Velocity(i,n1,Coeff_Tank)     , 235 , 40 +  T.EquationOfTank_Velocity(i,n1,Coeff_Tank)  , 248 );
            setfillstyle(1,color);
            bar(10+ T.EquationOfTank_Velocity(i,n1,Coeff_Tank)  , 220 , 30 +  T.EquationOfTank_Velocity(i,n1,Coeff_Tank)  , 250 );
            setcolor(GREEN);
            line(30+ T.EquationOfTank_Velocity(i,n1,Coeff_Tank) , 227 , 55 +  T.EquationOfTank_Velocity(i,n1,Coeff_Tank)  , 227 );
            setfillstyle(1,DARKGRAY);
            setcolor(DARKGRAY);
            fillellipse(T.EquationOfTank_Velocity(i,n1,Coeff_Tank)+5 ,250,3,3);
            fillellipse(T.EquationOfTank_Velocity(i,n1,Coeff_Tank)+15,250,3,3);
            fillellipse(T.EquationOfTank_Velocity(i,n1,Coeff_Tank)+25,250,3,3);
            fillellipse(T.EquationOfTank_Velocity(i,n1,Coeff_Tank)+35,250,3,3);
        /*------------------------------------------------Car-------------------------------------------------------------------*/
        for(int z = 0 ; z < car_n ; z++)
         {
            srand(time(NULL));
            int color = rand()%15 + 1;
            setfillstyle(1,color);
            bar((maxx-c[z].EquationOfCar_Velocity(i,n2,c[z].Coeff_Car))    , 235 , ((maxx-40)-c[z].EquationOfCar_Velocity(i,n2,c[z].Coeff_Car)) , 247);
            bar((maxx-10-c[z].EquationOfCar_Velocity(i,n2,c[z].Coeff_Car)) , 226 , ((maxx-30)-c[z].EquationOfCar_Velocity(i,n2,c[z].Coeff_Car)) , 247);
            setfillstyle(1,BROWN);
            setcolor(BROWN);
            fillellipse((maxx-10)-c[z].EquationOfCar_Velocity(i,n2,c[z].Coeff_Car),250,3,3);
            fillellipse((maxx-30)-c[z].EquationOfCar_Velocity(i,n2,c[z].Coeff_Car),250,3,3);
          }
          /*----------------------------------------------------Bullet-----------------------------------------------------*/

          for(int q = 0 ; q < 10 ; q++)

          {
              setcolor(RED);
              line(55 +  T.EquationOfTank_Velocity(i,n1,Coeff_Tank)+B[q].EquationOfBullet_Distance  (i,1,B[q].Coeff_Bullet) , 227 ,
                   56 +  T.EquationOfTank_Velocity(i,n1,Coeff_Tank)+B[q].EquationOfBullet_Distance(i,1,B[q].Coeff_Bullet) ,227 );

          }

          /*----------------------------------------------------------------------------------------------------------------*/

        for(int k = 0 ; k < obs_n ; k++)
        {
            setfillstyle(1,WHITE);
            bar(obs_x[k] , 200,obs_x[k]+10 , 250);
        }
        if(55+ T.EquationOfTank_Velocity(i,n1,Coeff_Tank) > obs_x[destroy-1])
            {
            T.setTime(i);
            T.setDistance(T.getTank_x2());
            break;
            }
            for(int z = 0 ; z < car_n ; z++)
        {
            if(40+ T.EquationOfTank_Velocity(i,n1,Coeff_Tank) > (maxx-40)-c[z].EquationOfCar_Velocity(i,n2,c[z].Coeff_Car) &&
               40+ T.EquationOfTank_Velocity(i,n1,Coeff_Tank) < (maxx-c[z].EquationOfCar_Velocity(i,n2,c[z].Coeff_Car)))
            {
                Car_des[z]++;
                c[z].setTime(i);
                c[z].setDistance((maxx-40)-c[z].EquationOfCar_Velocity(i,n2,c[z].Coeff_Car) - maxx);
                setfillstyle(4,LIGHTBLUE);
                bar((maxx-c[z].EquationOfCar_Velocity(i,n2,c[z].Coeff_Car))     , 235 , ((maxx-40)-c[z].EquationOfCar_Velocity(i,n2,c[z].Coeff_Car)) , 250);
                bar((maxx-10-c[z].EquationOfCar_Velocity (i,n2,c[z].Coeff_Car)) , 226 , ((maxx-30)-c[z].EquationOfCar_Velocity(i,n2,c[z].Coeff_Car)) , 247);
            }
            if(40+ T.EquationOfTank_Velocity(i,n1,Coeff_Tank) > (maxx-40)-c[z].EquationOfCar_Velocity(i,n2,c[z].Coeff_Car)){
                 setfillstyle(4,LIGHTBLUE);
                 bar((maxx-c[z].EquationOfCar_Velocity(i,n2,c[z].Coeff_Car))     , 235 , ((maxx-40)-c[z].EquationOfCar_Velocity(i,n2,c[z].Coeff_Car)) , 250);
                 bar((maxx-10-c[z].EquationOfCar_Velocity (i,n2,c[z].Coeff_Car)) , 226 , ((maxx-30)-c[z].EquationOfCar_Velocity(i,n2,c[z].Coeff_Car)) , 247);
            }
         }
            delay(100);
        }
}


    for(int i = 0 ; i < 20 ; i++)
      {
        if(Car_des[i] != 0)
            car_destroyed++;
      }

        cout<<endl<<"Period Of Time: " <<T.getTime()<<" seconds"<<endl<<"The Distance Traveled By The Tank: "<<T.getDistance()<<" meter"<<endl;
        cout<<"The Cars Have Been Destroyed : "<<car_destroyed<<endl;
        cout<<"The Cars Have Been Safe : "     <<car_n-car_destroyed<<endl;
    for(int z = 0 ; z < car_destroyed ; z++)
      {
        cout<<z+1<<" th Car's Period Of Time : "<<c[z].getTime()<<endl;
        cout<<z+1<<" th Car's Distance : "      <<-1*c[z].getDistance()<<endl;
      }

    getch();
    closegraph();
    return 0;
}
