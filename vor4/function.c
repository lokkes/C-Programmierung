#include <stdio.h>
#include <stdlib.h>

#include "functions.h"
    
    
    double PowInt(int x, int y){

        double result = 1;
        for(int i = 1; i<= y; i++) {
            result*=x;
        }
        return result;
        
    }