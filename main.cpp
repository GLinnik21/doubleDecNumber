//
//  main.cpp
//  Dop*Task1
//
//  Created by Глеб Линник on 27.10.16.
//  Copyright © 2016 Linkin Industris. All rights reserved.
//

#include <iostream>
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
    LongBin(const char*);
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

int main() {
    LongBin Ak[1000], Bk[1000], Ck[1000],c=1111101000;
    int ABki = 0, Cki = 8, answer = 7, k, m = 0;

    Ck[0] = 0;
    Ck[1] = 1;
    Ck[2] = 1010;
    Ck[3] = 1011;
    Ck[4] = 1100100;
    Ck[5] = 1100101;
    Ck[6] = 1101110;
    Ck[7] = 1101111;
    
    int number, i;
    
    cout << "Enter n:";
    cin >> number;
    
    clock_t tStart = clock();
    for (k = 4; answer < number; k++) {
        for (i = 0; i < Cki; i++) {
            if (Ck[i].getBin().size() >= k) {
                if (Ck[i].getKBit(k) == 0) {
                    Ak[ABki] = Ck[i];
                    Bk[ABki] = Ak[ABki] + c;
                    answer++;
                    ABki++;
                }
            } else {
                Ak[ABki] = Ck[i];
                Bk[ABki] = Ak[ABki] + c;
                answer++;
                ABki++;
            }
        }
        for (i = 0; i < ABki; i++) {
            Ck[i] = Ak[i];
            Ck[i+ABki]=Bk[i];
        }
        m = ABki;
        Cki = 2 * ABki;
        ABki = 0;
        //Devision by 10
        c = (c << 3) + (c << 1);
    }
    
    cout <<  Bk[m - 1 - (answer - number)].getDec() << endl;
    cout << "Execution time: " << (double)(clock() - tStart)/CLOCKS_PER_SEC << "s" << endl;
    return 0;
}

LongBin::LongBin() {}
LongBin::LongBin(deque<short> d): binDeque(d){}
LongBin::LongBin(string s) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != '0' && s[i] != '1') {
            throw "Initialization with wrong number! Constructor accepts only base2";
        }
        binDeque.push_back((short)(s[i] == '0' ? 0 : 1));
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
