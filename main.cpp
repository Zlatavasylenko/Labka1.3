//Лабораторна 1-3. 
#include <iostream> 
#include <cmath> 
 
using namespace std; 
 
int whereP(double x, double y, double a); 
void putP(double x, double y); 
void proccesP(double x, double y, double a); 
bool getP(double& x, double& y); 
void aboutA(); 
bool getCont(double& a); 
void proccesCont(double a); 
void putResult(double a, double x, double y, int r, double d); 
double getDouble(); 
double distPC(double x, double y, double a); 
 
int main() 
{ 
 setlocale(LC_CTYPE, "ukr"); 
 aboutA(); 
 double a; 
 if (getCont(a)) 
    { 
        proccesCont(a); 
    } 
cout << "<<<END OF WORK>>>" << endl;
 return 0; 
} 
 
void aboutA() { 
    cout << "Laboratory work 1-1. Point and outline.\nK-14 Vasylenko Zlata\n"; 
} 
double getDouble() { 
    double x, y; 
    while (true) { 
        if (cin >> x) { 
            return x; 
        } 
        else { 
            cin.clear(); 
            cin.sync(); 
        } 
    } 
} 
 
 
bool getCont(double& a) 
{ 
    do { 
        cout << "Input a , a>0:"; 
        a = getDouble(); 
 
    } while (a <= 0); 
    return true; 
} 
 
bool getP(double& x, double& y) { 
    cout << "Enter the coordinates : "; 
    x = getDouble(); 
    y = getDouble(); 
    return true; 
} 
 
void putP(double x, double y) 
{ 
 cout << '(' << x << ';' << y << ')' << endl; 
} 
int whereP(double x, double y, double a) { 
    if ( 
        ((x == a) && (y >= 0 && y <= 2 * a)) || 
        ((y == 2 * a) && (x >= 0 && x <= a)) || 
        ((x == 0) && (y >= a && y <= 2 * a)) || 
        ((x >= 0 && x <= a) && y == (a - x))) { 
        return 0; 
    } 
    else if ( 
        ((x > 0 && x < a) && (y >= a && y <= 2 * a)) || 
        ((x > 0 && x < a) && (y > (a - x) && y < a))) { 
        return -1; 
    } 
    else { 
        return 1; 
    } 
} 
double distPC(double x, double y, double a) 
{ 
 double dist; 
 int r = whereP(x, y, a); 
 if (r == 0) { dist = 0; } 
 else if (r == -1) 
 { 
  double d1, d2, d3, d4; 
  d1 = round(abs(x - a)*100)/100; 
  d2 = round(abs(y - 2 * a)*100)/100; 
  d3 = round(abs(x)*100)/100; 
  d4 = round((abs(x + y - a)) / sqrt(2)*100)/100; 
  dist = min(min(d1, d2), min(d3, d4)); 
 } 
 else 
 { 
  if (y >= a && y <= 2 * a && x <= 0) { 
            return round(abs(x)*100)/100; 
        } 
        else if (y >= 2 * a && x >= 0 && x <= a) { 
            return round(abs(y - 2 * a)*100)/100; 
        } 
        else if (x >= a && y >= 0 && y <= 2 * a) { 
            return round(abs(x - a)*100)/100; 
        } 
        else if(y<0 && x==a){
            return round(abs(y)*100)/100;
        }
        else if (y<a && a<y-x){
          return round(sqrt(pow(a-y,2)+pow(x,2))*100)/100; 
        }
        else if (y<0 && a<x-y){
          return round(sqrt(pow(a-x,2)+pow(y,2))*100)/100; 
        }
         else if (a>y-x && y<a) { 
            return round(abs(x + y - a) / sqrt(2)*100)/100; 
        }  
         else if (y > 2 * a && x < 0) { 
            return  round(pow(pow(x, 2) + pow((y - 2 * a), 2), 1.0 / 2.0)*100)/100; 
        } 
        else if (x > a && y > 2 * a) { 
            return  round(pow(pow(x - a, 2) + pow(y - 2 * a, 2), 1. / 2)*100)/100; 
        } 
        else if (x > a && y < 0) { 
            return  round(pow(pow(x - a, 2) + pow(y, 2), 1.0 / 2.0)*100)/100; 
        } 
        else { 
            return round(pow(pow(x, 2) + pow((y - a), 2), 1.0 / 2.0)*100)/100; 
        } 
    } 
 return dist; 
} 
void proccesP(double x, double y, double a) 
{ 
 int r = whereP(x, y, a); 
 double d = distPC(x, y, a); 
 putResult(a, x, y, r, d); 
} 
 
void proccesCont(double a) 
{ 
 double x, y, x1, y1; 
 getP(x, y); 
 do 
 { 
  proccesP(x, y, a); 
  x1 = x; 
  y1 = y; 
  getP(x, y); 
 } while ((x != x1) or (y != y1)); 
 cout << "<<<END OF POINTS>>>" << endl; 
} 
 
 
 void putResult(double a, double x, double y, int r, double d) 
{ 
 putP(x, y); 
 
    if (r == -1) { cout << "IN_C "; } 
    else if (r == 0) { cout << "ON_C "; } 
    else {cout << "OUT_C ";} 
    cout << a << "\n"; 
 cout << "DISTANCE = "<< d << endl; 
 
}
