#include "field.h"

/** @file field.c
 *  @brief You will modify this file and implement six functions
 *  @details Your implementation of the functions defined in field.h.
 *  You may add other function if you find it helpful. Added function
 *  should be declared <b>static</b> to indicate they are only used
 *  within this file. For example, methods you write may need a mask value.
 *  You might write a method to compute mask for you and use it wherever
 *  it is needed as oposed to just puting the code in line.
 * <p>
 * @author <b>Your name</b> goes here
 */

/** @todo Implement in field.c based on documentation contained in field.h */
int getBit(int value, int position) {
        return (value >> position) & 1;
}

/** @todo Implement in field.c based on documentation contained in field.h */
int setBit(int value, int position) {
        value |=  (1 << position);
        return value;
}

/** @todo Implement in field.c based on documentation contained in field.h */
int clearBit(int value, int position) {
        return value ^ ~(1 << position);
}

/** @todo Implement in field.c based on documentation contained in field.h */
int getField(int value, int hi, int lo, int isSigned) {
        // Create mask of only 1s from lo to hi
        int mask = (1 << (hi - lo + 1)) - 1;
        int extracted = (value >> lo) & mask;
        
        // extracted & (1 << (hi - lo)) implied when it equals 1(or when the leading bit is set)
        if (isSigned && getBit(extracted, hi))
                extracted = setBit(extracted, 31);

        return extracted;
}

/** @todo Implement in field.c based on documentation contained in field.h */
int setField(int oldValue, int hi, int lo, int newValue) {
        int mask = ((1 << (hi - lo + 1)) - 1) << lo;
        /*
        int tmp = getField(oldValue, hi, lo, 0);
        int newField = getField(newValue, hi, lo, 0);
        */

        oldValue = oldValue &  ~mask;
        newValue = (newValue << lo);
        
        return oldValue | newValue;
}

/** @todo Implement in field.c based on documentation contained in field.h */
int fieldFits(int value, int width, int isSigned) {
        return 0;
}
