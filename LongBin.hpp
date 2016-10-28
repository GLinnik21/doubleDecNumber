//
//  LongBin.hpp
//  Dop*Task1
//
//  Created by Глеб Линник on 27.10.16.
//  Copyright © 2016 Linkin Industris. All rights reserved.
//

#ifndef LongBin_hpp
#define LongBin_hpp

#include <stdio.h>
#include <string>
#include <deque>

using namespace std;

class LongBin {
private:
    deque<short> binDeque;
    deque<short> adding(deque<short>&, const deque<short>&);
public:
    LongBin();
    LongBin(deque<short>);
    LongBin(string);
    LongBin(int);
    
    
    LongBin operator+(const LongBin&);
    void operator+=(const LongBin&);
    void operator>>(int);
    void operator<<(int);

friend string getString(LongBin&);
};

#endif /* LongBin_hpp */
