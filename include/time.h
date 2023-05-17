#ifndef TIME_H
#define TIME_H

typedef long double Time;

Time getRealTime();
Time getCpuTime();
Time formatTime(long int sec, long int usec);
void printElapsedTime(char* message, Time start, Time end);

#endif