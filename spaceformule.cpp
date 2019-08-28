#include "spaceformule.h"

namespace FSpace {

double JulianDate(int year, int month, int day, int hour, int minute, int second) {
    int a = (14 - month) / 12;
    int Y = year + 4800 - a;
    int M = month + 12 * a - 3;
    int JDN = day + (153 * M + 2) / 5 + 365 * Y+ Y / 4 - Y / 100 + Y / 400 -32045;
    double JD = JDN + (hour - 12)/24.0 + minute/1440.0 + second/86400.0;
    return JD;
}

double SiderialTime(int year, int month, int day, int hour, int minute, int second){
    int d = (int)(JulianDate(year, month, day, hour, minute, second) - 2451544.5);
    double t = d / 36525.0;
    double S_G_0 = 24110.584841 + 8640184.812866 * t + 0.093104 * pow(t, 2.) - 6.2e-6 * pow(t, 3.);
    return S_G_0;
}

TVector intoGSK(TVector R)
{
     long double RE=6371.3;
     TVector X(3);
     X[0]=(RE)*cos(R[1])*cos(R[0]);
     X[1]=(RE)*cos(R[1])*sin(R[0]);
     X[2]=(RE)*sin(R[1]);
     return X;
}

TMatrix intoA(double Fi,double S)
{
    TMatrix A(3,3);
    A(0,0)=-sin(Fi)*cos(S);
    A(0,1)=-sin(Fi)*sin(S);
    A(0,2)=cos(Fi);
    A(1,0)=cos(Fi)*cos(S);
    A(1,1)=cos(Fi)*sin(S);
    A(1,2)=-sin(Fi);
    A(2,0)=-sin(S);
    A(2,1)=cos(S);
    A(2,2)=0;
    return A;
}

TMatrix intoA2(long double theta,long double i,long double u)
{
    TMatrix A(3,3);
    A(0,0)=cos(u)*cos(theta)-sin(u)*sin(theta)*cos(i);
    A(0,1)=-sin(u)*cos(theta)-cos(u)*sin(theta)*cos(i);
    A(0,2)=sin(i)*sin(theta);
    A(1,0)=cos(u)*sin(theta)+sin(u)*cos(theta)*cos(i);
    A(1,1)=-sin(u)*sin(theta)+cos(u)*cos(theta)*cos(i);
    A(1,2)=-sin(i)*cos(theta);
    A(2,0)=sin(u)*sin(i);
    A(2,1)=cos(u)*sin(i);
    A(2,2)=cos(i);
    return A;
}

TVector intoGeo(const TVector & R)
{
   TVector G(3);
   G[0]=R[2]*cos(R[1])*cos(R[0]);
   G[1]=R[2]*cos(R[1])*sin(R[0]);
   G[2]=R[2]*sin(R[1]);
   return G;
}

TVector intoSphere(const TVector & R)
{
   TVector G(3);
   G[0]=atan2(R[1],R[0]);//y/x
   G[1]=atan2(R[2],sqrt(R[0]*R[0]+R[1]*R[1]));// z/(x^2+y^2)
   G[2]=sqrt(R[0]*R[0]+R[1]*R[1]+R[2]*R[2]);// ro=x^2+y^2+z^2
   return G;
}

}
