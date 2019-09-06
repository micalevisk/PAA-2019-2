#ifndef ANALYTICS_H
#define ANALYTICS_H


typedef struct t_analytics TAnalytics;
typedef void (*ClockHandle)(TAnalytics*);
typedef struct timeval t_clock; // alias

struct t_analytics {
  // clock_t begin, end;
  struct timeval begin, end;
  double timeSpent;
  ClockHandle startClock;
  ClockHandle stopClock;

};

TAnalytics Analytics(void);


#endif
