class Stack{

private:
    QueuePereche q1, q2;
public:
    Stack(int);
    Stack(const Stack&);
    ~Stack();
    int get_n();
    int get_capacity();
    Pereche get_element(int);
    void add(Pereche);
    void add(int,int);
    Pereche pop();
    friend ostream &operator <<(ostream&, const Stack&);
    friend istream &operator >>(istream&, Stack&);
    const Stack &operator =(const Stack&);
};


Stack::Stack(int k=0):q1(k),q2(k){}

Stack::Stack(const Stack &ob){

    this -> q1 = ob.q1;
    this -> q2 = ob.q2;
}

Stack::~Stack(){

    delete &q1;
    delete &q2;

}

int Stack::get_n(){
    return q1.get_n();
}

int Stack::get_capacity(){
    return q1.get_capacity();
}

Pereche Stack::get_element(int i){
    return q1.get_element(i);
}

void Stack::add(Pereche p){
    q1.add(p);
}

void Stack::add(int a=0, int b=0){
    cout<<"Adding element "<<a<<" "<<b<<"\n";
    q1.add(a,b);
}

Pereche Stack::pop(){
    if(q1.get_n()==0)
        throw "Exception - Underflow";

    while(q1.get_n() > 1){
        q2.add(q1.pop());
    }
    Pereche paux = q1.pop();
    QueuePereche aux;
    aux = q1;
    q1 = q2;
    q2 = aux;
    return paux;
}

ostream &operator <<(ostream &os, const Stack &ob){
    os<<ob.q1;
    return os;
}

istream &operator >>(istream &is, Stack &ob){
    is>>ob.q1;
    return is;
}

