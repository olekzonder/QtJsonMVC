#include "counter.h"

Counter::Counter(int _counter)
{
    counter = _counter;
}


void Counter::set_counter(int _counter){
    counter = _counter;
}

int Counter::get_counter(){
    return counter;
}
