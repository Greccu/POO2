#include <iostream>
#include <string.h>
#include "Pereche.h"
#include "Multime-Pereche.h"
#include "StackPereche.h"
#include "QueuePereche.h"
using namespace std;

void func(int a=7,char b='a'){
cout<<a<<" "<<b<<"\n";}


int main()
{

    MultimePereche m(7);
    Pereche p;
    p.set(7,9);
    m.add(p);
    p.set(2,3);cout<<p;
    m.add(p);
    p.set(1,2);cout<<p;
    m.add(p);
    cout<<endl<<m<<endl;
    m.pop();
    cout<<m<<endl;
    StackPereche s(7);
    s.add(p);
    s.add(p);
    s.pop();
    cout<<s;
    MultimePereche* array[10];
    for(int i=0; i<7; i++){
        Pereche ob(i,i+1);
        Pereche ob2(i+1,i+2);
        Pereche ob3(i+2,i+3);
        if(i%3==0)
            array[i] = new MultimePereche[3];
        if(i%3==1)
            array[i] = new StackPereche[3];
        if(i%3==2)
            array[i] = new QueuePereche[3];
        array[i] -> add(ob);
        array[i] -> add(ob2);
        array[i] -> add(ob3);
    }
    cout<<endl;
    for(int i=0; i<7; i++){
        cout<<typeid(*array[i]).name()<<" "<<*array[i]<<"\n";
    }
    MultimePereche test(7);
    cin>>test;
    cout<<test;

    return 0;
}
