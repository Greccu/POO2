class StackPereche: public MultimePereche{

 public:

    StackPereche(int);
    StackPereche(const StackPereche&);
    ~StackPereche();
    Pereche pop();
};

StackPereche::StackPereche(int k = 0):MultimePereche(k){}
StackPereche::StackPereche(const StackPereche& ob):MultimePereche(ob){}
StackPereche::~StackPereche(){}
Pereche StackPereche::pop(){
    return MultimePereche::pop();
}

