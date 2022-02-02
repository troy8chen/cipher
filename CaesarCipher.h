//
// Created by Troy Chen on 11/11/21.
//

#ifndef CHENY30_HW6_CAESARCIPHER_H
#define CHENY30_HW6_CAESARCIPHER_H

#include <string>
using namespace std;

class CaesarCipher {
public:
    static bool isSeeded; //a false-safe to ensure seed value can be randomized when encryptDecrypt has invoked
    CaesarCipher();
    CaesarCipher(const CaesarCipher &);
    string encrypt(string);
    string decrypt(string);
    CaesarCipher& operator = (const CaesarCipher &);
    CaesarCipher operator + (const CaesarCipher &);
    bool operator == (const CaesarCipher &);
    bool operator < (const CaesarCipher &);
    bool operator > (const CaesarCipher &);
    CaesarCipher& operator ++ ();
    CaesarCipher operator ++ (int);
    ~CaesarCipher(){};
private:
    int shift;
    const int OFFSET_MIN = 32;
    const int OFFSET_MAX = 126;
    const int MAX_SHIFT = OFFSET_MAX - OFFSET_MIN; //gives maximum shift value returned by the getShift function
    int getShift();
    string encryptDecrypt(string, bool encrypt);
    bool isPositionInRange(int);
};

#endif //CHENY30_HW6_CAESARCIPHER_H
