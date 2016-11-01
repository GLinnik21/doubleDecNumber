//
//  LongBin.hpp
//  Dop*Task1
//
//  Created by Глеб Линник on 27.10.16.
//  Copyright © 2016 Linkin Industris. All rights reserved.
//

#ifndef LongBin_h
#define LongBin_h

#include <stdio.h>
#include <cstdlib>
#include <string>
#include <cstring>
#include <deque>

using namespace std;

class LongBin {
private:
    deque<short> binDeque;
    deque<short> decDeque = {0};
    deque<short> adding(deque<short>&, const deque<short>&, int);
public:
    LongBin();
    LongBin(deque<short>);
    LongBin(string);
    LongBin(const char* s);
    LongBin(int);
    
    LongBin operator+(const LongBin&);
    void operator+=(const LongBin&);
    
    LongBin operator+(const int);
    void operator+=(const int);
    
    LongBin operator>>(int);
    LongBin operator<<(int);

    int getKBit(int);
    string getDec();
    string getBin();
};

#endif /* LongBin_hpp */
