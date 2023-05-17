#ifndef TIME_H
#define TIME_H

typedef long double Time;

Time getRealTime();
Time getCpuTime();
Time formatTime(long int, long int);
void printElapsedTime(char*, Time, Time);

#endif