/*
Name Javier Chavez
email jchavez589@cnm.edu
oct 31,2012
*/
#ifndef _TIMER_H_
#define _TIMER_H_

#include <sys/time.h>



class Timer
{

public:
    Timer();                                               

    void   start();                   
    void   stop();                    
    double getElapsedTime();          


private:
    double startTime;
    double endTime;
    bool    stopped;

    timeval beginTiming;
    timeval endTiming;

};

#endif
