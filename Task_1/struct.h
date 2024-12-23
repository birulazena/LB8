#pragma once
struct information_desk {
  char bus_number[100];
  char bus_type[100];
  char end_point[100];
  int start_time_hour;
  int start_time_min;
  union UN {
    int finish_time_hour;
  } UN;
  int finish_time_min;
};

typedef struct information_desk reference;