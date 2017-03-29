//
//  missingI2C.cpp
//  
//
//  Created by William Boyd on 3/29/17.
//
//

#include "missingI2C.h"

long readI2CHex(int howMany) {
    
    char data[howMany];
    
    for (int i = 0; i < howMany; i++) {
        
            //read the character off the bus
        char newChar = Wire.read();
        
            //and append
        data[i] = newChar;
        
    }
    
        //add the null 0
    data[howMany] = '\0';
    
        /* Convert */
        // TODO: Investigate this-
        // For some reason, reading in a
        // String object or a char array
        // feeding that directly into the
        // strol fcn causes strtol to return
        // 0, even if the string is the
        // correct value. This should always
        // work, since the data will never
        // me larger than 2 digits long
    
    String conversion = "";
    conversion += data[3];
    conversion += data[4];
    
        //convert
    long convertedValue = strtol(conversion.c_str(), NULL, 16);
    
        //and return
    return convertedValue;
    
    
    
}
