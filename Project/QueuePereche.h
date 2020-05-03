class QueuePereche: public MultimePereche{
public:
    QueuePereche(int);
    QueuePereche(const QueuePereche&);
    ~QueuePereche();
    Pereche pop();
};

QueuePereche::QueuePereche(int k = 0):MultimePereche(k){}
QueuePereche::QueuePereche(const QueuePereche& ob):MultimePereche(ob){}
QueuePereche::~QueuePereche(){}
Pereche QueuePereche::pop(){
    if(n == 0)
        throw "Exception - Underflow";
    v++;
    n--;
    capacity--;
    return v[-1];
}
