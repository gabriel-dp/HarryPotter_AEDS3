#include "../include/time.h"

#include <stdio.h>
#include <sys/resource.h>
#include <sys/time.h>

// Join time in seconds and microseconds into a long double variable
Time formatTime(long int sec, long int usec) {
    Time totalTime = sec + ((Time)usec / 1000000.0L);
    return totalTime;
}

// Returns real time in that moment
Time getRealTime() {
    struct timeval now;
    gettimeofday(&now, NULL);
    return formatTime(now.tv_sec, now.tv_usec);
}

// Returns CPU time in that moment
Time getCpuTime() {
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    return formatTime(usage.ru_utime.tv_sec, usage.ru_utime.tv_usec);
}

// Prints the difference between start to end
void printElapsedTime(Time startTime, Time endTime) {
    Time elapsedTime = endTime - startTime;
    printf("Elapsed time: %Lf\n", elapsedTime);
}