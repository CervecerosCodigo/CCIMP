#ifndef OBSERVERTEST_H
#define OBSERVERTEST_H

#include <QString>

class observertest
{
public:
    observertest();
    ~observertest();

    virtual void action_performed(QString str) = 0;
};

#endif // OBSERVERTEST_H
