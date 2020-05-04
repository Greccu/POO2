#include <iostream>
#include <string.h>
#include "Pereche.h"
#include "Multime-Pereche.h"
#include "StackPereche.h"
#include "QueuePereche.h"
#include "Stack.h"

using namespace std;

void func(int a=7,char b='a'){
cout<<a<<" "<<b<<"\n";}


int main()
{
    /*
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

    Stack st;
    cout<<"Created stack\n";
    st.add(7,2);
    st.add(2,3);
    st.add(2,3);
    st.add(2,3);
    st.add(2,3);
    st.add(7,3);
    st.add(2,1);
    st.pop();
    cout<<st;
    */

    try{
        MultimePereche m(-1);
    }
    catch(const char* eroare){
        cout<<eroare<<"\n";
    }

    try{
        MultimePereche n(7);
        n.add(7,2);
        n.add(2,3);
        cout<<n.get_element(-3);
    }
    catch(const char* eroare){
        cout<<eroare<<"\n";
    }

    try{
        MultimePereche p(10);
        p.pop();
    }
    catch(const char* eroare){
        cout<<eroare<<"\n";
    }
    return 0;
}
