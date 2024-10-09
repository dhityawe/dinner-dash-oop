// Observer.h
#ifndef OBSERVER_H
#define OBSERVER_H

class Observer {
public:
    virtual void update() = 0; // Fungsi update virtual murni
    virtual ~Observer() {} // Destructor virtual
};

#endif // OBSERVER_H
