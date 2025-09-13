#ifndef BATALLAS_H
#define BATALLAS_H

#include "Monstruo.h"

class Batalla {
public:
    static Monstruo enfrenta(const Monstruo& m1, const Monstruo& m2, char tipoBatalla);
};

#endif
