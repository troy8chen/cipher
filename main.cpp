// This program demonstrates the CaesarCipher class'
// Big 4 operations and overloaded operators
#include "CaesarCipher.h"
#include <string>
#include <iostream>
using namespace std;

bool CaesarCipher::isSeeded = false;

void print (CaesarCipher &c){
    string encrypt = c.encrypt("Hello, World! ");
    cout << "Encrypted: " << encrypt << endl;
    string decrypt = c.decrypt(encrypt);
    cout << "Decrypted: " << decrypt << endl;
}

int main() {

    cout << "\ntest constructor : cc" << endl;
    CaesarCipher cc;
    print(cc);

    cout << "\ntest constructor : cc2" << endl;
    CaesarCipher cc2;
    print(cc2);

    cout << "\n*** testing copy constructor and overloaded assignment ***" << endl;
    cout << "test copy constructor : cc3(cc2)" << endl;
    CaesarCipher cc3 = cc2;
    print(cc3);

    cout << "\ntest overloaded assignment operator : cc2 = cc" << endl;
    cc2 = cc;
    print(cc2);

    cout << "\n*** printing cc, cc2, and cc3 ***" << endl;
    cout << "test constructor : cc" << endl;
    print(cc);
    cout << "\ntest constructor : cc3" << endl;
    print(cc2);
    cout << "\ntest constructor : cc3" << endl;
    print(cc3);


    cout << "\n*** testing comparators ***" << endl;
    cout << "cc == c3 is " << boolalpha << (cc == cc3);
    cout << "\ncc < c3 is " << boolalpha << (cc < cc3);
    cout << "\ncc > c3 is " << boolalpha << (cc > cc3);

    cout << "\n\n*** testing add ***" << endl;
    cout << "cc2 = cc + cc3" << endl;
    cc2 = cc + cc3;
    print(cc2);

    cout << "\n*** testing increment ***" << endl;
    cout << "test increment (postfix) : cc4 = cc++" << endl;
    CaesarCipher cc4;
    cc4 = cc++;
    print(cc);
    cout << "\nresult of cc4 after postfix" << endl;
    print(cc4);
    cout << "\ntest increment (prefix) : cc4 = ++cc" << endl;
    cc4 = ++cc;
    print(cc);
    cout << "\nresult of cc4 after prefix" << endl;
    print(cc4);

    cout << "\ntest increment (postfix) : cc4 = cc2++" << endl;
    cc4 = cc2++;
    print(cc2);
    cout << "\nresult of cc4 after postfix" << endl;
    print(cc4);
    cout << "\ntest increment (prefix) : cc4 = ++cc2" << endl;
    cc4 = ++cc2;
    print(cc2);
    cout << "\nresult of cc4 after prefix" << endl;
    print(cc4);

    cout << "\ntest increment (postfix) : cc4 = cc3++" << endl;
    cc4 = cc3++;
    print(cc3);
    cout << "\nresult of cc4 after postfix" << endl;
    print(cc4);
    cout << "\ntest increment (prefix) : cc4 = ++cc3" << endl;
    cc4 = ++cc3;
    print(cc3);
    cout << "\nresult of cc4 after prefix" << endl;
    print(cc4);

    cout << "\n----------------------------" << endl;

    cout << "\n*** testing list ***" << endl;

    cout << "test list : add cc, cc2, cc3" << endl;
    CaesarCipher cipher[3] = {cc, cc2, cc3};

    cout << "\ntest print list[0] : " << endl;
    print(cc);
    cout << "\ntest print list[1] : " << endl;
    print(cc2);
    cout << "\ntest print list[2] : " << endl;
    print(cc3);

    return 0;
}