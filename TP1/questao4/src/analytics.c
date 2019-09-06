#include <time.h>
#include <sys/time.h>
#include "analytics.h"

static void startClock(TAnalytics* data) {
  gettimeofday(&(data->begin), NULL);
}

static void stopClock(TAnalytics* data) {
  gettimeofday(&(data->end), NULL);

  t_clock begin = data->begin;
  t_clock end = data->end;
  data->timeSpent = (
    (double) (end.tv_usec - begin.tv_usec) / 1000000 +
    (double) (end.tv_sec - begin.tv_sec)
  );
}

TAnalytics Analytics(void) {
  TAnalytics stats;
  // stats.begin = stats.end
  stats.timeSpent = 0L;
  stats.startClock = &startClock;
  stats.stopClock = &stopClock;
  return stats;
}
