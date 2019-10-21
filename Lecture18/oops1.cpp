#include <iostream>
using namespace std;

class Car{
    int price;
    public:
    string name;
    int mileage;
    char* color;
    Car(){
    }
    Car(string str, int n, char* c, int p){
        name = str;
        mileage = m;
        color = c;
        price = p;
    }
    Car(string str, int m, cahr*c, int p=100){
        name = str;
        mileage = m;
        color = c;
        price = p;
    }
    void printCar(){
        cout<<"name: "<<name<<endl;
        cout<<"mileage: "<<mileage<<endl;
        cout<<"color: "<<color<<endl;
        cout<<"price: "<<price<<endl;
        cout<<"--------------------------------"<<endl;
    }
    void set_price(int p){
        if(p>0){
            price = p;
        }
    }
    int get_price(){
        return price;
    }
};
int main(){
    Car* A=new Car();
    // A->name = "Car_A";
    // A->mileage = 100;
    // A->color = "Black";
    // A->price = 10;

    cout<<"name: "<<A->name<<endl;
    cout<<"mileage: "<<A->mileage<<endl;
    cout<<"color: "<<A->color<<endl;
    cout<<"price: "<<A->price<<endl;
    Car* B = new Car("Car_B", 200, "Yellow", 20);
    B->printCar();
    Car C;
    C.name = "Car_C";
    C.mileage = 400;
    C.printCar();
    Car D = C;  //copy assignment
    D.printCar();
    Car E(C);
    E.printCar(); //copy constructor
    return 0;
}