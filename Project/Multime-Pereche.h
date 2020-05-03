#include <iostream>
using namespace std;


class MultimePereche{

protected:

    int n;
    int capacity;  //capacitatea maxima a multimii
    Pereche *v;

public:

    MultimePereche(int);
    MultimePereche(const MultimePereche&);
    virtual ~MultimePereche();
    int get_n();
    int get_capacity();
    Pereche get_element(int); //returneaza perechea de pe pozitia i, by default ultima pozitie
    void add(Pereche p);
    virtual Pereche pop();
    friend ostream &operator <<(ostream &o, const MultimePereche&);
    friend istream &operator >>(istream &i, MultimePereche&);
    const MultimePereche &operator =(const MultimePereche&);

};

MultimePereche::MultimePereche(int k=0){

    if(k < 0){
        throw "Exception - invalid lenght";
    }

    n = 0;
    capacity = k;

    if(k > 0){
        v = new Pereche[k];
    }
    else{
        v = nullptr;
    }
}

MultimePereche::MultimePereche(const MultimePereche &ob){

    this -> capacity = ob.capacity;
    this -> n = ob.n;

    if(n > 0){
        this -> v = new Pereche[capacity];

        for(int i = 0; i < n; i++){
            this -> v[i] = ob.v[i];
        }

    }
    else{
        this -> v = nullptr;
    }

}

MultimePereche::~MultimePereche(){

    if(capacity > 0){
        delete[] v;
    }

}

int MultimePereche::get_n(){
    return n;
}

int MultimePereche::get_capacity(){
    return capacity;
}

Pereche MultimePereche::get_element(int i){
    if(i >= n || i<-1*n){
        throw "Exception - index out of range";
    }

    return v[(i<0)?n+i:i];   /// in cazul in care i<0 se foloseste abordarea din python (-1=ultimul element)

}

void MultimePereche::add(Pereche p){
    n++;
    if(n > capacity){
        capacity++;
        Pereche *aux = new Pereche[n];
        for(int i = 0; i<n-1; i++){
            aux[i] = v[i];
        }
        aux[n - 1] = p;

        delete[] v;

        v=aux;
    }
    else{
        v[n-1] = p;
    }

}

Pereche MultimePereche::pop(){

    if(n <= 0){
        throw "Exception - Underflow";
    }

    n--;
    return v[n];
}

ostream &operator <<(ostream &os, const MultimePereche &ob){
    if(ob.n<=0){
        os<<"Empty ";
        return os;
    }

    os<<"{"<<ob.v[0];
    for(int i=1; i<ob.n; i++){
        os<<", "<<ob.v[i];
    }
    os<<"}";
    return os;
}

istream &operator >>(istream &is, MultimePereche &ob){

    try{
        int m;
        if(&is==&cin)
            cout<<"n=";
        is>>m;

        if(m < 0)
            throw "Exception - negative lenght";

        Pereche p;
        int i;
        for(i = 0; i < ob.n; i++){
            if(&is==&cin)
                cout<<"Elementul "<<i<<" - introduceti numerele pe 2 randuri\n";
            is>>p;
            ob.v[i] = p;
        }
        for(;i < m; i++){
            if(&is==&cin)
                cout<<"Elementul "<<i<<" - introduceti numerele pe 2 randuri\n";
            is>>p;
            ob.add(p);
        }

        ob.n = m;
        ob.capacity = (m > ob.capacity)?m:ob.capacity;
    }
    catch(const char *eroare){
        throw eroare;
    }

    return is;


}

const MultimePereche& MultimePereche::operator =(const MultimePereche &ob){

    this -> n = ob.n;
    this -> capacity = ob.capacity;
    if(n > 0){

        v = new Pereche[ob.capacity];

        for(int i = 0; i < ob.n; i++){
            this -> v[i] = ob.v[i];
        }
    }

    else{
        this -> v = nullptr;
    }

    return *this;
}

