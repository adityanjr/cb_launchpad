#include<iostream>
#include <vector>
using namespace std;

class Car {
	int price;
public :
	string name;
	int milage;
	char* color;
	//default constructor
	Car() {
		color =  new char[10];
	}
	// user defined constructor
	// Car(string str, int m, char* c, int p){
	// 	name = str;
	// 	milage = m;
	// 	color = c;
	// 	price = p;

	// }

	// parameterized constructor
	Car(string str, int m, char* c, int p = 100) {
		name = str;
		milage = m;

		//color = c;
		color =  new char[10];
		strcpy(color, c);
		price = p;

	}

//copy constructor shallow copy

	// Car(Car &X){
	// 	cout<<"out own copy constructor"<<endl;
	// 	name =  X.name;
	// 	milage = X.milage;
	// 	color =  X.color;
	// 	price = X.price;
	// }

//copy constructor deep copy
	Car(Car &X) {
		cout << "out own copy constructor" << endl;
		name =  X.name;
		milage = X.milage;
		color =  new char[10];
		strcpy(color, X.color);
		price = X.price;
	}

	void printCar() {
		cout << "name : " << name << endl;
		cout << "milage : " << milage << endl;
		cout << "color : " << color << endl;
		cout << "price : " << price << endl;
		cout << "=============================================================" << endl;

	}
	//Getters & Setters 
	void set_price(int p) {
		if (p > 0) {
			price = p;
		}
	}

	int get_price() {
		return price;
	}

	//Copy Assignment Operator(Operator Overloading)
	void operator=(Car &X) {
		cout << "our copy assignment operator " << endl;
		name = X.name;
		milage = X.milage;
		//color = X.color;
		color =  new char[10];
		strcpy(color, X.color);
		price = X.price;
	}

};

// void operator<<(ostream& o, Car &X){
// 		o<<X.name<<endl;
// 		o<<X.milage<<endl;
// 		o<<X.color<<endl;
// 		//return o;
// 	}
ostream& operator<<(ostream& o, Car &X) {
	o << X.name << endl;
	o << X.milage << endl;
	o << X.color << endl;
	return o;
}
istream& operator>>(istream& o, Car &X) {
	o >> X.name;
	o >> X.milage;
	o >> X.color;
	return o;
}
int main(int argc, char const *argv[])
{	Car* A = new Car();
	// A->name =  "Car_A";
	// A->milage = 100;
	// A->color = "Black";
	// A->price = 10;
	// cout<<"name : "<<A->name<<endl;
	// cout<<"milage : "<<A->milage<<endl;
	// cout<<"color : "<<A->color<<endl;
	// cout<<"price : "<<A->price<<endl;
	//Car*B =  new Car();
	char c[10] = "Yellow";
	Car* B = new Car("Car_B", 200, c, 20);
	// B->color = "green";
	//  B->color[2] = 'A';
	// B->printCar();
	// string n;
	// cin>>B->name;
	// //B->name=n;
	// B->printCar();
	// Car* C = new Car("Car_C", 300, "Red");
	// C->printCar();
	// Car D;
	// D.name = "Car_D";
	// D.milage = 400;
	// strcpy(D.color, c);
	// D.printCar();
// copy assignment operator "="
	//Car E = D; // calls copy constructor
	// Car E;
	// E = D;
	// E.printCar();
//copy const
	// Car F(D);
	// F.printCar();
	// Car G;
	// G.name = "Car_G";
	// G.milage = 1000;
	// strcpy(G.color, c);
	// cout<<F<<G;
	// Car H;
	// cin>>H;
	// cout<<H;
	// Car I(H);

	// I.color[2] = 'O';

	// cout<<I<<endl;
	// cout<<H<<endl;



	return 0;
}











