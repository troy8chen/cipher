//
// Created by Troy Chen on 11/11/21.
//
#include "CaesarCipher.h"
#include <iostream>
#include <sstream>
#include <stdexcept>

using namespace std;

/**
 * Initialize the random shift number from getShift method
 *
 */
CaesarCipher::CaesarCipher() {
    shift = getShift();
}

/**
 * Copy constructor
 *
 * @param c CaesarCipher Object
 */
CaesarCipher::CaesarCipher(const CaesarCipher &c) {
    shift = c.shift;
}

/**
 * Encrypt string input
 *
 * @param s input string
 * @return encrypted string
 *
 */
string CaesarCipher::encrypt(string s) {
    return encryptDecrypt(s, true);
}

/**
 * Decrypt encrypted string
 *
 * @param s encrypted string
 * @return original string before encryption
 */
string CaesarCipher::decrypt(string s) {
    return encryptDecrypt(s, false);
}

/**
 * Overload the assignment operator by replacing the shift value to existing object
 *
 * @param c CaesarCipher object
 * @return CaesarCipher object that has been replaced
 */
CaesarCipher &CaesarCipher::operator=(const CaesarCipher &c){
    // Replace the shift value from left-hand side to right-hand side,
    // which is the CaesarCipher object we passed in (&c in parameter)
    if (this == &c){
        return *this;
    }
    shift = c.shift;
    return *this;
}

/**
 * Overload addition operator
 *
 * @param c CaesarCipher object
 * @return CaesarCipher object after addition
 */
CaesarCipher CaesarCipher::operator+(const CaesarCipher &c) {
    // declare a CaesarCipher object as the outcome after addition of two CaesarCipher objects
    CaesarCipher temp;
    // Give the definition to addition operator. Shift value of the outcome is the shift value from left-hand side
    // plus the shift value from the right-hand side.
    // The range of shift value assigned by the getShift function is from 1 to MAX_SHIFT (we defined it in the header)
    // if the shift value from temp (call it sum) is greater than MAX_SHIFT, we will use sum - MAX_SHIFT as shift value
    temp.shift = shift + c.shift;
    if(temp.shift > MAX_SHIFT){
        temp.shift -=MAX_SHIFT;
        return temp;
    }
    return temp;
}

/**
 * Overload equality operator
 *
 * @param c CaesarCipher object
 * @return true/false
 */
bool CaesarCipher::operator==(const CaesarCipher &c) {
    // Return true if &c has same memory address on the left-hand side
    if (this == &c) {
        return true;
    }
    // Return true if &c has same shift value on the left-hand side
    else if (shift == c.shift){
        return true;
    }
    return false;
}

/**
 * Overload less than operator
 * @param c CaesarCipher object
 * @return true/false
 */
bool CaesarCipher::operator<(const CaesarCipher &c) {
    // If the shift value from the left-hand side is less than the right-hand side, return true
    if (shift < c.shift){
        return true;
    }
    return false;
}

/**
 * Overload greater than operator
 *
 * @param c CaesarCipher object
 * @return true/false
 */
bool CaesarCipher::operator>(const CaesarCipher &c) {
    //If the shift value from the left-hand side is greater than the right-hand side, return true
    if (shift > c.shift){
        return true;
    }
    return false;
}

/**
 * Overload postfix operator
 *
 * @return A reference to the CaesarCipher object with the incremented shift field value.
 */
CaesarCipher &CaesarCipher::operator++() {
    // Rest the shift value to 1 if the shift value reaches MAX_SHIFT that we defined in header
    if(shift == MAX_SHIFT){
        shift = 1;
    }
    // increment shift value
    else{
        shift++;
    }
    return *this;
}

/**
 * Overload prefix operator, parameter int is a unused dummy variable to represent shift value for this operator
 *
 * @return A CaesarCipher object with the shift field value prior to incrementation.
 */
CaesarCipher CaesarCipher::operator++(int) {
    // Declare a CaesarCipher object temp points to the shift value prior the increment
    CaesarCipher temp =*this;
    // If the shift value prior (from incrementing) is equal to MAX_SHIFT, rest the shift value to 1
    if(this->shift == MAX_SHIFT){
        this->shift = 1;
    }
    // show shift value prior to this operator
    else{
        ++*this;
    }
    return temp;
}

/**
 * Getter for shift value
 *
 * @return shift value
 */
int CaesarCipher::getShift() {

    int result;
    int low = 1;
    int high = OFFSET_MAX - OFFSET_MIN;

    // initialize the condition for seed
    if (!isSeeded) {
        srand(time(nullptr));
        isSeeded= true;
    }
    // Generate random shift number under constrain from variable low (1) to variable high (94)
    result = rand() % (high - low) + low;
    return result;
}

/**
 * encryptDecrypt method
 *
 * @param s input string
 * @param encrypt true to encrypt, false to decrypt
 * @return encrypted or decrypted string
 */
string CaesarCipher::encryptDecrypt(string s, bool encrypt) {
    stringstream ss;
    int n = s.length();
    // declaring character array
    char char_array[n];
    // copying the contents of the
    // string to char array
    strcpy(char_array, s.c_str());

    for (char c: char_array){
        int index = c, cpos;
        if(!isPositionInRange(index)){
            throw std::invalid_argument("String to be encrypted has unrecognized character "+ to_string(c));
        }

        if (encrypt) {
            cpos = index + shift;
            if (cpos > OFFSET_MAX)
                cpos = OFFSET_MIN + (cpos - OFFSET_MAX);
        } else {
            cpos = index - shift;
            if (cpos < OFFSET_MIN)
                cpos = OFFSET_MAX - (OFFSET_MIN - cpos);
        }
        char p = cpos;
        ss << p;
    }
    return ss.str();
}

/**
 * Checker for position
 *
 * @param index position
 * @return true/false
 */
bool CaesarCipher::isPositionInRange(int index) {
    return index >= OFFSET_MIN && index <= OFFSET_MAX;
}

