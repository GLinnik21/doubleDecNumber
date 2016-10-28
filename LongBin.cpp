//
//  LongBin.cpp
//  Dop*Task1
//
//  Created by Глеб Линник on 27.10.16.
//  Copyright © 2016 Linkin Industris. All rights reserved.
//

#include "LongBin.hpp"

LongBin::LongBin() {}
LongBin::LongBin(deque<short> d): binDeque(d){}

LongBin LongBin::operator+(LongBin add) {
    
    deque<short> biggerDeque, smallerDeque;
    
    if (binDeque.size() > add.binDeque.size()) {
        biggerDeque = binDeque;
        smallerDeque = add.binDeque;
    } else {
        biggerDeque = add.binDeque;
        smallerDeque = binDeque;
    }
    
    for (short i = smallerDeque.size() - 1, j = biggerDeque.size() - 1; i >= 0; i--, j--) {
        biggerDeque[j] += smallerDeque[i];
    }
    
    for (int i = (int)biggerDeque.size() - 1; i >= 0; i--) {
        if (biggerDeque[i] > 1) {
            if (i == 0) {biggerDeque.push_front(0); i++;}
            biggerDeque[i - 1] += 1;
            biggerDeque[i] -= 2;
        }
    }
    
    LongBin brandNew(biggerDeque);
    
    return brandNew;
}

void LongBin::operator+=(LongBin add) {
    //this -> binString += add.binString;
}
