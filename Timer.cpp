/*
Name Javier Chavez
email jchavez589@cnm.edu
oct 31,2012
*/
#include "Timer.h"
#include <stdlib.h>

Timer::Timer()
{
    beginTiming.tv_sec = beginTiming.tv_usec = 0;
    endTiming.tv_sec = endTiming.tv_usec = 0;


    stopped = false;
    startTime = 0;
    endTime = 0;
}


void Timer::start()
{
    stopped = false;
    gettimeofday(&beginTiming, NULL);

}

void Timer::stop()
{
    stopped = true;
    gettimeofday(&endTiming, NULL);

}

double Timer::getElapsedTime()
{
    timeval stopWatch;
    stopWatch.tv_sec = stopWatch.tv_usec = 0;
    if(!stopped)
    {
        gettimeofday(&stopWatch, NULL);
        double SWend = (stopWatch.tv_sec* 1000000.0) + stopWatch.tv_usec;
        double SWstart = (beginTiming.tv_sec* 1000000.0) + beginTiming.tv_usec;
        return (SWend - SWstart)* 0.000001;
    }


    startTime = (beginTiming.tv_sec * 1000000.0) + beginTiming.tv_usec;
    endTime = (endTiming.tv_sec * 1000000.0) + endTiming.tv_usec;


    return (endTime - startTime)* 0.000001;
}
