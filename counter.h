#ifndef COUNTER_H
#define COUNTER_H


class Counter
{
private:
    int counter;
public:
    Counter(int _counter);
    void set_counter(int _counter);
    int get_counter();
};

#endif // COUNTER_H
