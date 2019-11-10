
#define READ_LINE_BUF_SIZE 100

extern int readLineBufferFill ; 
extern int readLineLength;
extern char readLineBuffer[READ_LINE_BUF_SIZE];
extern bool readLine ();
extern bool readLineLoop (char c);
