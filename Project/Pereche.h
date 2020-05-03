#include <iostream>
using namespace std;

/// Definirea clasei Pereche

class Pereche{
private:

    int x, y;

public:

    Pereche(int a, int b);
    Pereche(const Pereche & ob);
    ~Pereche();
    void set(int a=0, int b=0);
    void set_x(int a=0);
    void set_y(int b=0);
    int get_x();
    int get_y();

    friend ostream &operator <<(ostream &os, const Pereche &ob);
    friend istream &operator >>(istream &is, Pereche &ob);
    Pereche &operator =(const Pereche &ob);
    friend Pereche operator +(const Pereche &ob1, const Pereche &ob2);
    friend Pereche operator -(const Pereche &ob1, const Pereche &ob2);
    friend bool operator ==(const Pereche &ob1, const Pereche &ob2);
};

/// Metode clasa Pereche

Pereche::Pereche(int a = 0, int b = 0){

    x = a;
    y = b;
    //cout<<"Contstructor 1 "<<x<<" "<<y;

}

Pereche::Pereche(const Pereche &ob){

    this -> x = ob.x;
    this -> y = ob.y;
    //cout<<"Contstructor 2 "<<x<<" "<<y;
}

Pereche::~Pereche(){
    //cout<<"Obiect distrus";
}

void Pereche::set(int a, int b){

    x=a;
    y=b;

}

void Pereche::set_x(int a){

    x=a;

}

void Pereche::set_y(int b){

    y=b;

}

int Pereche::get_x(){

    return x;

}

int Pereche::get_y(){

    return y;

}

ostream &operator <<(ostream &os, const Pereche &ob){

    os<<"("<<ob.x<<", "<<ob.y<<")";
    return os;
}

istream &operator >>(istream &is, Pereche &ob){

    is>>ob.x>>ob.y;
    return is;

}

Pereche& Pereche::operator =(const Pereche &ob){

    this -> x = ob.x;
    this -> y = ob.y;
    return *this;
}

bool operator ==(const Pereche &ob1, const Pereche &ob2){

    if((ob1.x == ob2.x && ob1.y == ob2.y) || (ob1.x == ob2.y && ob1.y == ob2.x))
        return true;
    else
        return false;

}

Pereche operator +(const Pereche &ob1, const Pereche &ob2){

    Pereche ob;
    ob.set(ob1.x + ob2.x, ob1.y + ob2.y);
    return ob;

}

Pereche operator -(const Pereche &ob1, const Pereche &ob2){

    Pereche ob;
    ob.set(ob1.x - ob2.x, ob1.y - ob2.y);
    return ob;

}
