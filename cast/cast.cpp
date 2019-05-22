//
// Created by egl on 5/22/19.
//

#include "cast.h"
using namespace cast;

void g(Radio& r)
{
    Receiver* prec = &r;// Receiver is an ordinary base of Radio
    Radio* prsc1 = static_cast<Radio*>(prec); // OK, unchecked
    Radio* prdc1 = dynamic_cast<Radio*>(prec);// OK, run-time checked

    Transmitter* pt = &r;
    Radio* prsc2 = static_cast<Radio*>(pt);
    Radio* prdc2 = dynamic_cast<Radio*>(pt);


    Storable* ps = &r;// Storable is a virtual base of Radio
    //Radio* prscc = static_cast<Radio*>(ps);// error : cannot cast from virtual base
    Radio* prdc3 = dynamic_cast<Radio*>(ps);// OK, run-time checked

    Receiver * prec2 = dynamic_cast<Receiver*>(pt);

   // Receiver * preccsc = static_cast<Receiver*>(pt); //error static_cast can not do cross cast






}

void cast::drive_cast() {
    Radio r;
    g(r);
}
