#include <iostream>
#include <cmath>
using namespace std;

struct Point{
	double x;
	double y;
	};


class PolarCoordinates {
	private:
	double R;
	double Fi,Alfa;	
	Point point1,point2;
	public:
	PolarCoordinates(){
		R=0;
		Fi=0;
		Alfa=0;
		point1.x=0;
		point1.y=0;
		point2.x=0;
		point2.y=0;	
		}
	PolarCoordinates(double value_R,double value_Fi,double value_Alfa){
		R=value_R;
		Fi=value_Fi;
		Alfa=value_Alfa;
		}	
	void decart(){
		Fi=3.14/180*Fi;
		point1.x=R*cos(Fi);
		point1.y=R*sin(Fi);
		cout << "X=  ";
		cout << point1.x << endl;
		cout << "Y=  ";
		cout << point1.y << endl;
		}
	void decart_alfa(){
		Alfa=3.14/180*Alfa;
		point2.x=point1.x*cos(Alfa)+point1.y*sin(Alfa);
		point2.y=-point1.x*sin(Alfa)+point1.y*cos(Alfa);
		cout << "X1=  ";
		cout << point2.x << endl;
		cout << "Y1=  ";
		cout << point2.y << endl;
		}	
	
	 Point set(){
		return point1;
		}
	};


int main(){
	double R,Fi,Alfa;
	cout << "Введите координаты в полярной системе координат:R=  ";
	cin >> R;
	cout << "Fi=  ";
	cin >> Fi;
	cout << "Alfa=  ";
	cin >> Alfa;
	
	PolarCoordinates point(R,Fi,Alfa);
	point.decart();
	point.decart_alfa();
	}

