//
//  LongBin.cpp
//  Dop*Task1
//
//  Created by Глеб Линник on 27.10.16.
//  Copyright © 2016 Linkin Industris. All rights reserved.
//

#include "LongBin.h"

LongBin::LongBin() {}
LongBin::LongBin(vector<short> d): binDeque(d){}
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
        binDeque.insert(binDeque.begin(), digit);
        i /= 10;
    } while (i > 0);
}

LongBin LongBin::operator+(const LongBin& add) {
    LongBin brandNew = adding(binDeque, add.binDeque);
    return brandNew;
}

void LongBin::operator+=(const LongBin& add) {
    binDeque = adding(binDeque, add.binDeque);
}

LongBin LongBin::operator+(int add) {
    vector<short> tempDeque;
    do {
        int digit = add % 10;
        if (digit != 0 && digit != 1) {
            throw "Initialization with wrong number! Constructor accepts only base2";
        }
        add /= 10;
        tempDeque.insert(tempDeque.begin(), digit);
    } while (add > 0);
    LongBin brandNew = adding(binDeque, tempDeque);
    return brandNew;
}

void LongBin::operator+=(int add) {
    vector<short> tempDeque;
    do {
        int digit = add % 10;
        if (digit != 0 && digit != 1) {
            throw "Initialization with wrong number! Constructor accepts only base2";
        }
        add /= 10;
        tempDeque.insert(tempDeque.begin(), digit);
    } while (add > 0);
    binDeque = adding(binDeque, tempDeque);
}

void LongBin::operator<<(int shift) {
    while (shift > 0) {
        binDeque.push_back(0);
        shift--;
    }
}

void LongBin::operator>>(int shift) {
    binDeque.erase(binDeque.end() - shift, binDeque.end());
}

vector<short> LongBin::adding(vector<short>& a, const vector<short>& b) {
    vector<short> biggerDeque, smallerDeque;
    
    if (a.size() > b.size()) {
        biggerDeque = a;
        smallerDeque = b;
    } else {
        biggerDeque = b;
        smallerDeque = a;
    }

    for (int i = (int)smallerDeque.size() - 1, j = (int)biggerDeque.size() - 1; i >= 0; i--, j--) {
        biggerDeque[j] += smallerDeque[i];
    }
    
    for (int i = (int)biggerDeque.size() - 1; i >= 0; i--) {
        if (biggerDeque[i] > 1) {
            if (i == 0) {biggerDeque.insert(biggerDeque.begin(), 0); i++;}
            biggerDeque[i - 1] += 1;
            biggerDeque[i] -= 2;
        }
    }
    
    return biggerDeque;
}

string LongBin::getBin() {
    string str;
    for (int i = 0; i < binDeque.size(); i++) {
        str.push_back((char)('0' + binDeque[i]));
    }
    return str;
}

unsigned long long int LongBin::getDec() {
    char str[binDeque.size()];
    for (int i = 0; i < binDeque.size(); i++) {
        str[i] = ((char)('0' + binDeque[i]));
    }
    return strtoull(str ,NULL ,2);
}


