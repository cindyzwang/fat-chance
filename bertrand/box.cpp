#include <stdlib.h>
#include <iostream>
#include "box.h"

Box::Box(bool coin1, bool coin2) {
    Box::coin1 = coin1;
    Box::coin2 = coin2;
    Box::picked1 = false;
    Box::picked2 = false;
}

bool Box::pick_coin(void) {
    if (!Box::picked1 && !Box::picked2) {
        bool heads = rand() % 2;
        if (heads) {
            Box::picked1 = true;
            return Box::coin1;
        } else {
            Box::picked2 = true;
            return Box::coin2;
        }
    } else {
        if (Box::picked1) {
            Box::picked2 = true;
            return Box::coin2;
        } else {
            Box::picked1 = true;
            return Box::coin1;
        }
    }
}