#ifndef BATALLAS_H
#define BATALLAS_H

#include "Monstruo.h"

class Batalla {
public:
    static void enfrenta(const Monstruo& m1, const Monstruo& m2, char tipo);
};

#endif
