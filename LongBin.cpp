//
//  LongBin.cpp
//  Dop*Task1
//
//  Created by Глеб Линник on 27.10.16.
//  Copyright © 2016 Linkin Industris. All rights reserved.
//

#include "LongBin.h"

LongBin::LongBin() {}
LongBin::LongBin(deque<short> d): binDeque(d){}
LongBin::LongBin(string s) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != '0' && s[i] != '1') {
            throw "Initialization with wrong number! Constructor accepts only base2";
        }
        binDeque.push_back(s[i] == '0' ? 0 : 1);
    }
}
LongBin::LongBin(const char* s) {
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] != '0' && s[i] != '1') {
            throw "Initialization with wrong number! Constructor accepts only base2";
        }
        binDeque.push_back(s[i] == '0' ? 0 : 1);
    }
}
LongBin::LongBin(int i) {
    do {
        int digit = i % 10;
        if (digit != 0 && digit != 1) {
            throw "Initialization with wrong number! Constructor accepts only base2";
        }
        binDeque.push_front(digit);
        i /= 10;
    } while (i > 0);
}

LongBin LongBin::operator+(const LongBin& add) {
    LongBin brandNew = adding(binDeque, add.binDeque, 2);
    return brandNew;
}

void LongBin::operator+=(const LongBin& add) {
    binDeque = adding(binDeque, add.binDeque, 2);
}

LongBin LongBin::operator+(const int add) {
    int tempInt = add;
    deque<short> tempDeque;
    do {
        int digit = add % 10;
        if (digit != 0 && digit != 1) {
            throw "Initialization with wrong number! Constructor accepts only base2";
        }
        tempInt /= 10;
        tempDeque.push_front(digit);
    } while (add > 0);
    LongBin brandNew = adding(binDeque, tempDeque, 2);
    return brandNew;
}

void LongBin::operator+=(const int add) {
    int tempInt = add;
    deque<short> tempDeque;
    do {
        int digit = add % 10;
        if (digit != 0 && digit != 1) {
            throw "Initialization with wrong number! Constructor accepts only base2";
        }
        tempInt /= 10;
        tempDeque.push_front(digit);
    } while (add > 0);
    binDeque = adding(binDeque, tempDeque, 2);
}

LongBin LongBin::operator<<(int shift) {
    LongBin brandNew = *this;
    while (shift > 0) {
        brandNew.binDeque.push_back(0);
        shift--;
    }
    return brandNew;
}

LongBin LongBin::operator>>(int shift) {
    LongBin brandNew = *this;
    binDeque.erase(brandNew.binDeque.end() - shift, brandNew.binDeque.end());
    return brandNew;
}

deque<short> LongBin::adding(deque<short>& a, const deque<short>& b, int base) {
    deque<short> biggerDeque, smallerDeque;
    
    //Find longer number
    if (a.size() > b.size()) {
        biggerDeque = a;
        smallerDeque = b;
    } else {
        biggerDeque = b;
        smallerDeque = a;
    }
    
    //Adding by decimal bit
    for (int i = (int)smallerDeque.size() - 1, j = (int)biggerDeque.size() - 1; i >= 0; i--, j--) {
        biggerDeque[j] += smallerDeque[i];
    }
    
    //Perebroska
    for (int i = (int)biggerDeque.size() - 1; i >= 0; i--) {
        if (biggerDeque[i] > (base - 1)) {
            if (i == 0) {biggerDeque.push_front(0); i++;}
            biggerDeque[i - 1] += 1;
            biggerDeque[i] -= base;
        }
    }
    
    return biggerDeque;
}

int LongBin::getKBit(int k) {
    return binDeque[(int)binDeque.size() - k];
}

string LongBin::getBin() {
    string str;
    for (int i = 0; i < binDeque.size(); i++) {
        str.push_back((char)('0' + binDeque[i]));
    }
    return str;
}

string LongBin::getDec() {
    decDeque = {0};
    deque<short> powerDeque = {1};
    for (int i = (int)binDeque.size() - 1; i >= 0; i--) {
        if (binDeque[i]) {
            decDeque = adding(decDeque, powerDeque, 10);
        }
        powerDeque = adding(powerDeque, powerDeque, 10);
    }
    string decString;
    for (int i = 0; i < decDeque.size(); i++) {
        decString += (char)((short)'0' + decDeque[i]);
    }
    return decString;
}


