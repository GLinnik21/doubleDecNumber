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
public:
    LongBin();
    LongBin(deque<short>);
    friend void setString(LongBin& ,string);
    friend string getString(LongBin&);
    LongBin operator+(LongBin);
    void operator+=(LongBin);
};

#endif /* LongBin_hpp */
