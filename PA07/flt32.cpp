#include "field.h"
#include "flt32.h"

/** @file flt32.c
 *  @brief You will modify this file and implement nine functions
 *  @details Your implementation of the functions defined in flt32.h.
 *  You may add other function if you find it helpful. Added function
 *  should be declared <b>static</b> to indicate they are only used
 *  within this file.
 *  <p>
 *  @author <b>Your name</b> goes here
 */

/** @todo Implement in flt32.c based on documentation contained in flt32.h */
int flt32_get_sign(flt32 x) {
        return getField(x, 31, 31, 0); /* implement this */
}

/** @todo Implement in flt32.c based on documentation contained in flt32.h */
int flt32_get_exp(flt32 x) {
        return getField(x, 30, 23, 0);
}

/** @todo Implement in flt32.c based on documentation contained in flt32.h */
int flt32_get_val(flt32 x) {
        return (setBit(getField(x, 23, 0, 0), 23));
}

/** @todo Implement in flt32.c based on documentation contained in flt32.h */
void flt32_get_all(flt32 x, int* sign, int*exp, int* val) {
        //Assign each to a pointer given in the arguments.
        //This one is already done for you. No need to edit this.
        *sign=flt32_get_sign(x);
        *exp=flt32_get_exp(x);
        *val=flt32_get_val(x);
}

/** @todo Implement in flt32.c based on documentation contained in flt32.h */
int flt32_left_most_1(int value) {
        for (int i = 31; i >= 0; i--)
                if (getBit(value, i))
                        return i;
                
        return -1;  
}

/** @todo Implement in flt32.c based on documentation contained in flt32.h */
flt32 flt32_abs(flt32 x) { 
        return x & 0x7FFFFFFF;
}

/** @todo Implement in flt32.c based on documentation contained in flt32.h */
flt32 flt32_negate(flt32 x) {
        return x ^ 0x80000000;
}

void swap(int* x, int *y) {
        int tmp = *y;
        *y = *x;
        *x = tmp;
}

/** @todo Implement in flt32.c based on documentation contained in flt32.h */
flt32 flt32_add (flt32 x, flt32 y) {
        int exp_x = flt32_get_exp(x);

        int exp_y = flt32_get_exp(y);

        if (exp_x > exp_y) {
                swap(&exp_x, &exp_y);
        }

        int sign_x = flt32_get_sign(x);
        int val_x = flt32_get_val(x);
 
        int sign_y = flt32_get_sign(y); 
        int val_y = flt32_get_val(y);
        
        int exp_diff = exp_y - exp_x;
        val_x  = val_x >> exp_diff;
        if (sign_x)
                val_x = ~val_x + 1;
        if (sign_y)
                val_y = ~val_y + 1;

        

        int result_val = val_x + val_y;
        if (result_val < 0)
                result_val = ~result_val + 1;

        int result_exp = exp_x;

        if (result_val & (1 << 24)) {
                result_val = result_val >> 1;
                result_exp = result_exp + 1;
        }
        int result_sign = sign_x;
        return (result_sign << 31) | (result_exp << 23) | (result_val & 0x7FFFFF);
}

/** @todo Implement in flt32.c based on documentation contained in flt32.h */
flt32 flt32_sub (flt32 x, flt32 y) {
        return flt32_add(x, ~y + 1);
}

