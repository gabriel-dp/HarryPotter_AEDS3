#ifndef TIME_H
#define TIME_H

typedef long double Time;

Time formatTime(long int, long int);
Time getRealTime();
Time getCpuTime();
void printElapsedTime(Time, Time);

#endif