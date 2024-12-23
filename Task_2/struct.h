#pragma once

struct Trains {
  int number_train;
  char day_week[100];
  char end_point[100];
  int start_hour;
  union UN {
    int start_min;
  } UN;
  int free_seats;
};

typedef struct Trains trains;