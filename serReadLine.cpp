#include <Arduino.h>
#include "serReadLine.h"


int readLineBufferFill = 0; 
int readLineLength = 0;
char readLineBuffer[READ_LINE_BUF_SIZE] = { 0 };
bool readLineLoop (char c) {
    
    if ( (c == '\n') || (c == '\r')  ) {
        readLineBuffer[(readLineLength=readLineBufferFill)]=(char) 0;
        readLineBufferFill=0;
        return true;
    } else {
        if  (
              ( 
                  (readLineBuffer[readLineBufferFill]!='\r') || 
                  (readLineBuffer[readLineBufferFill]!='\r') 
              ) &&  
        
               (readLineBufferFill<READ_LINE_BUF_SIZE)
            ) {
            readLineBufferFill++;
        }
    }
    return false;
}

bool readLine () {
    while (Serial.available()) {
        char c = readLineBuffer[readLineBufferFill] = (char)Serial.read();
        if (readLineLoop(c)) return true;
    }
    return false;
}

