#include "func_2.h"

#include <string.h>

#include <fstream>
#include <iostream>

#include "func_1.h"
#include "struct.h"
#define ASCII_COLOR_YELLOW "\e[0;33m"
#define ASCII_RESET "\e[0m"

void up_size_massiw(reference*& massiw, int& first_size) {
  int size_plas_one = first_size + 1;
  reference* new_massiw = new reference[size_plas_one];
  for (int i = 0; i < first_size; i++) {
    strcpy(new_massiw[i].bus_number, massiw[i].bus_number);
    strcpy(new_massiw[i].bus_type, massiw[i].bus_type);
    strcpy(new_massiw[i].end_point, massiw[i].end_point);
    new_massiw[i].start_time_hour = massiw[i].start_time_hour;
    new_massiw[i].start_time_min = massiw[i].start_time_min;
    new_massiw[i].UN.finish_time_hour = massiw[i].UN.finish_time_hour;
    new_massiw[i].finish_time_min = massiw[i].finish_time_min;
  }

  delete[] massiw;
  massiw = new_massiw;
  first_size = size_plas_one;
}
void view_content(reference* massiw_BD, int number_of_buses) {
  for (int i = 0; i < number_of_buses; i++) {
    std::cout << "\nЛист №" << i + 1 << '\n';
    std::cout << "Номер автобуса: " << massiw_BD[i].bus_number;
    std::cout << "\tТип автобуса: " << massiw_BD[i].bus_type;
    std::cout << "\tКонечная точка: " << massiw_BD[i].end_point;
    std::cout << "\nВремя отправления: " << massiw_BD[i].start_time_hour
              << " ч. " << massiw_BD[i].start_time_min << " мин.";
    std::cout << "\tВремя прибытия: " << massiw_BD[i].UN.finish_time_hour
              << " ч. " << massiw_BD[i].finish_time_min << " мин.\n\n";
  }
}

void delete_zero_cell(reference*& massiw, int couter) {
  reference* new_massiw = new reference[couter];
  for (int i = 0; i < couter; i++) {
    strcpy(new_massiw[i].bus_number, massiw[i].bus_number);
    strcpy(new_massiw[i].bus_type, massiw[i].bus_type);
    strcpy(new_massiw[i].end_point, massiw[i].end_point);
    new_massiw[i].start_time_hour = massiw[i].start_time_hour;
    new_massiw[i].start_time_min = massiw[i].start_time_min;
    new_massiw[i].UN.finish_time_hour = massiw[i].UN.finish_time_hour;
    new_massiw[i].finish_time_min = massiw[i].finish_time_min;
  }
  delete[] massiw;
  massiw = new_massiw;
}

void scan_tabl_element(reference* massiw_BD, int number_of_buses) {
  std::cout << "\nВведите 1 - искать по номеру автобуса\n";
  std::cout << "Введите 2 - искать по типу автобуса\n";
  std::cout << "Введите 3 - искать по конечной точку\n";
  std::cout << "Введиет 4 - искать по времени отправления\n";
  std::cout << "Введите 5 - искать по времени прибытия\n";
  int scan = write_1_dash_5();
  bool check_progress = false;
  system("clear");
  if (scan == 1) {
    std::cout << "Введите номер автобуса, который нужно найти\n";
    std::string number_bus_for_scan;
    std::cin >> number_bus_for_scan;
    system("clear");
    for (int i = 0; i < number_of_buses; i++) {
      if (massiw_BD[i].bus_number == number_bus_for_scan) {
        check_progress = true;
        std::cout << "\nЛист №" << i + 1 << '\n';
        std::cout << "Номер автобуса: " << massiw_BD[i].bus_number;
        std::cout << "\tТип автобуса: " << massiw_BD[i].bus_type;
        std::cout << "\tКонечная точка: " << massiw_BD[i].end_point;
        std::cout << "\nВремя отправления: " << massiw_BD[i].start_time_hour
                  << " часов " << massiw_BD[i].start_time_min << " мин.";
        std::cout << "\tВремя прибытия: " << massiw_BD[i].UN.finish_time_hour
                  << " часов " << massiw_BD[i].finish_time_min << " мин.\n\n";
      }
    }
    if (check_progress == false) {
      std::cout << "\nНичего не найдено...\n";
    }
  } else if (scan == 2) {
    std::cout << "Введите тип автобуса, который нужно найти\n";
    std::string bus_tupe_for_scan;
    std::cin >> bus_tupe_for_scan;
    system("clear");
    for (int i = 0; i < number_of_buses; i++) {
      if (massiw_BD[i].bus_type == bus_tupe_for_scan) {
        check_progress = true;
        std::cout << "\nЛист №" << i + 1 << '\n';
        std::cout << "Номер автобуса: " << massiw_BD[i].bus_number;
        std::cout << "\tТип автобуса: " << massiw_BD[i].bus_type;
        std::cout << "\tКонечная точка: " << massiw_BD[i].end_point;
        std::cout << "\nВремя отправления: " << massiw_BD[i].start_time_hour
                  << " часов " << massiw_BD[i].start_time_min << " мин.";
        std::cout << "\tВремя прибытия: " << massiw_BD[i].UN.finish_time_hour
                  << " часов " << massiw_BD[i].finish_time_min << " минут\n\n";
      }
    }
    if (check_progress == false) {
      std::cout << "\nНичего не найдено...\n";
    }
  } else if (scan == 3) {
    std::cout << "Введите конечную точку, которую нужно найти\n";
    std::string end_point_for_scan;
    std::cin >> end_point_for_scan;
    system("clear");
    for (int i = 0; i < number_of_buses; i++) {
      if (massiw_BD[i].end_point == end_point_for_scan) {
        check_progress = true;
        std::cout << "\nЛист №" << i + 1 << '\n';
        std::cout << "Номер автобуса: " << massiw_BD[i].bus_number;
        std::cout << "\tТип автобуса: " << massiw_BD[i].bus_type;
        std::cout << "\tКонечная точка: " << massiw_BD[i].end_point;
        std::cout << "\nВремя отправления: " << massiw_BD[i].start_time_hour
                  << " часов " << massiw_BD[i].start_time_min << " мин.";
        std::cout << "\tВремя прибытия: " << massiw_BD[i].UN.finish_time_hour
                  << " часов " << massiw_BD[i].finish_time_min << " минут\n\n";
      }
    }
    if (check_progress == false) {
      std::cout << "\nНичего не найдено...\n";
    }
  } else if (scan == 4) {
    std::cout << "Введите время отправления, которое нужно найти\nЧасы: ";
    int start_hout_for_scan = write_hour();
    std::cout << "Минуты: ";
    int start_min_for_scan = write_min();
    std::cout << '\n';
    system("clear");
    for (int i = 0; i < number_of_buses; i++) {
      if (massiw_BD[i].start_time_hour == start_hout_for_scan &&
          massiw_BD[i].start_time_min == start_min_for_scan) {
        check_progress = true;
        std::cout << "\nЛист №" << i + 1 << '\n';
        std::cout << "Номер автобуса: " << massiw_BD[i].bus_number;
        std::cout << "\tТип автобуса: " << massiw_BD[i].bus_type;
        std::cout << "\tКонечная точка: " << massiw_BD[i].end_point;
        std::cout << "\nВремя отправления: " << massiw_BD[i].start_time_hour
                  << " часов " << massiw_BD[i].start_time_min << " мин.";
        std::cout << "\tВремя прибытия: " << massiw_BD[i].UN.finish_time_hour
                  << " часов " << massiw_BD[i].finish_time_min << " минут\n\n";
      }
    }
    if (check_progress == false) {
      std::cout << "\nНичего не найдено...\n";
    }
  } else if (scan == 5) {
    std::cout << "Введите время прибытия, которое нужно найти\nЧасы: ";
    int finish_hour_for_scan = write_hour();
    std::cout << "Минуты: ";
    int finish_min_for_scan = write_min();
    system("clear");
    for (int i = 0; i < number_of_buses; i++) {
      if (massiw_BD[i].UN.finish_time_hour == finish_hour_for_scan &&
          massiw_BD[i].finish_time_min == finish_min_for_scan) {
        check_progress = true;
        std::cout << "\nЛист №" << i + 1 << '\n';
        std::cout << "Номер автобуса: " << massiw_BD[i].bus_number;
        std::cout << "\tТип автобуса: " << massiw_BD[i].bus_type;
        std::cout << "\tКонечная точка: " << massiw_BD[i].end_point;
        std::cout << "\nВремя отправления: " << massiw_BD[i].start_time_hour
                  << " часов " << massiw_BD[i].start_time_min << " мин.";
        std::cout << "\tВремя прибытия: " << massiw_BD[i].UN.finish_time_hour
                  << " часов " << massiw_BD[i].finish_time_min << " минут\n\n";
      }
    }
    if (check_progress == false) {
      std::cout << "\nНичего не найдено...\n";
    }
  }
}

void changing_values(reference* massiw_BD, int number_of_buses) {
  std::cout << "Показать, какие рассписания у вас есть?(1 - да; 2 - нет)\n";
  int yes_no_for_check = write_1_or_2();
  system("clear");
  if (yes_no_for_check == 1) {
    view_content(massiw_BD, number_of_buses);
  }
  std::cout << "\nВведите 1 - изменить номер автобуса\n";
  std::cout << "Введите 2 - изменить тип автобуса\n";
  std::cout << "Введите 3 - изменить конечную точку\n";
  std::cout << "Введите 4 - изменить время отправления\n";
  std::cout << "Введите 5 - изменить время прибытия\n";
  int number_for_changes = write_1_dash_5();
  system("clear");

  if (number_for_changes == 1) {
    std::cout
        << "Выберите номер рассписания, в котором нужно сделать изменения\n";
    int check_number_tabl = for_write_number_tabl(number_of_buses);
    system("clear");
    std::cout << "Введите новый номер автобуса\n";

    write_char(massiw_BD[check_number_tabl - 1].bus_number);
    system("clear");

    std::ofstream file("lol.bin", std::ios::binary);
    file.seekp((sizeof(massiw_BD[0]) * check_number_tabl - 1));
    file.write((char*)&massiw_BD[check_number_tabl - 1].bus_number,
               sizeof(massiw_BD[check_number_tabl - 1].bus_number));
    file.close();

  } else if (number_for_changes == 2) {
    std::cout
        << "Выберите номер рассписания, в котором нужно сделать изменения\n";
    int check_number_tabl = for_write_number_tabl(number_of_buses);
    system("clear");
    std::cout << "Введите новый тип автобуса\n";
    write_char(massiw_BD[check_number_tabl - 1].bus_type);
    system("clear");

    std::ofstream file("lol.bin", std::ios::binary);
    file.seekp(((sizeof(massiw_BD[0]) * check_number_tabl - 1) + 100));
    file.write((char*)&massiw_BD[check_number_tabl - 1].bus_type,
               sizeof(massiw_BD[check_number_tabl - 1].bus_type));
    file.close();
  } else if (number_for_changes == 3) {
    std::cout
        << "Выберите номер рассписания, в котором нужно сделать изменения\n";
    int check_number_tabl = for_write_number_tabl(number_of_buses);
    system("clear");
    std::cout << "Введите новую конечную точку\n";
    write_char(massiw_BD[check_number_tabl - 1].end_point);
    system("clear");

    std::ofstream file("lol.bin", std::ios::binary);
    file.seekp(((sizeof(massiw_BD[0]) * check_number_tabl - 1) + 200));
    file.write((char*)&massiw_BD[check_number_tabl - 1].end_point,
               sizeof(massiw_BD[check_number_tabl - 1].end_point));
    file.close();
  } else if (number_for_changes == 4) {
    std::cout
        << "Выберите номер рассписания, в котором нужно сделать изменения\n";
    int check_number_tabl = for_write_number_tabl(number_of_buses);
    system("clear");
    std::cout << "Введите новое время отправления\nЧасы: ";
    massiw_BD[check_number_tabl - 1].start_time_hour = write_hour();

    std::ofstream file("lol.bin", std::ios::binary);
    file.seekp(((sizeof(massiw_BD[0]) * check_number_tabl - 1) + 300));
    file.write((char*)&massiw_BD[check_number_tabl - 1].start_time_hour,
               sizeof(massiw_BD[check_number_tabl - 1].start_time_hour));

    std::cout << "\nМинуты: ";
    massiw_BD[check_number_tabl - 1].start_time_min = write_min();
    system("clear");

    file.seekp(
        ((sizeof(massiw_BD[0]) * check_number_tabl - 1) + 300 + sizeof(int)));
    file.write((char*)&massiw_BD[check_number_tabl - 1].start_time_min,
               sizeof(massiw_BD[check_number_tabl - 1].start_time_min));
    file.close();

  } else if (number_for_changes == 5) {
    std::cout
        << "Выберите номер рассписания, в котором нужно сделать изменения\n";
    int check_number_tabl = for_write_number_tabl(number_of_buses);
    system("clear");
    std::cout << "Введите новое время прибытия\nЧасы: ";
    massiw_BD[check_number_tabl - 1].UN.finish_time_hour = write_hour();

    std::ofstream file("lol.bin", std::ios::binary);
    file.seekp(((sizeof(massiw_BD[0]) * check_number_tabl - 1) + 300 +
                (sizeof(int) * 2)));
    file.write((char*)&massiw_BD[check_number_tabl - 1].UN.finish_time_hour,
               sizeof(massiw_BD[check_number_tabl - 1].UN.finish_time_hour));

    std::cout << "\nМинуты: ";
    massiw_BD[check_number_tabl - 1].finish_time_min = write_min();
    system("clear");

    file.seekp(((sizeof(massiw_BD[0]) * check_number_tabl - 1) + 300 +
                (sizeof(int) * 3)));
    file.write((char*)&massiw_BD[check_number_tabl - 1].finish_time_min,
               sizeof(massiw_BD[check_number_tabl - 1].finish_time_min));
    file.close();
  }
}

void my_selection_sort(reference* massiw_BD, int number_of_buses) {
  int max = 0;
  int check_1 = 0;
  int check_2 = 0;
  reference buf_massiw;

  for (int i = 0; i < number_of_buses; i++) {
    max = i;

    for (int j = i + 1; j < number_of_buses; j++) {
      check_1 = 60 * massiw_BD[max].UN.finish_time_hour +
                massiw_BD[max].finish_time_min;
      check_2 =
          60 * massiw_BD[j].UN.finish_time_hour + massiw_BD[j].finish_time_min;
      if (check_2 > check_1) {
        max = j;
      }
    }

    if (i != max) {
      buf_massiw = massiw_BD[i];
      massiw_BD[i] = massiw_BD[max];
      massiw_BD[max] = buf_massiw;
    }
  }
}

void write_in_file(reference* massiw_BD, int number_of_buses) {
  std::ofstream file("lol.bin", std::ios::binary);

  for (int i = 0; i < number_of_buses; i++) {
    file.write((char*)&massiw_BD[i], sizeof(massiw_BD[i]));
  }

  file.close();
}

void write_massiw(reference* massiw_BD, int number_of_buses, int start) {
  int yes_no_wrt = 3;
  for (int i = start; i < number_of_buses; i++) {
    std::cout << ASCII_COLOR_YELLOW "\nЛист №" << i + 1 << "\n" << ASCII_RESET;
    std::cout << ASCII_COLOR_YELLOW
        "\nЗаполнить номер автобуса значением из другого "
        "расписания?(1 - да; 2 - нет)\n"
              << ASCII_RESET;
    yes_no_wrt = write_1_or_2();

    if (yes_no_wrt == 1) {
      std::cout
          << "Выберите номер расписания, из которого скопировать значение\n";
      int number_tabl = for_write_number_tabl(number_of_buses - 1);
      strcpy(massiw_BD[i].bus_number, massiw_BD[number_tabl - 1].bus_number);
    } else {
      std::cout << ASCII_COLOR_YELLOW "\nВведите номер автобуса\n"
                << ASCII_RESET;
      write_char(massiw_BD[i].bus_number);
    }

    std::cout << ASCII_COLOR_YELLOW
        "\nЗаполнить тип автобуса изначением из другого расписания?(1 "
        "- да; 2 - нет)\n"
              << ASCII_RESET;
    yes_no_wrt = write_1_or_2();

    if (yes_no_wrt == 1) {
      std::cout
          << "Выберите номер расписания, из которого скопировать значение\n";
      int number_tabl = for_write_number_tabl(number_of_buses - 1);
      strcpy(massiw_BD[i].bus_type, massiw_BD[number_tabl - 1].bus_type);
    } else {
      std::cout << ASCII_COLOR_YELLOW "\nВведите тип автобуса\n" << ASCII_RESET;
      write_char(massiw_BD[i].bus_type);
    }

    std::cout << ASCII_COLOR_YELLOW
        "\nЗаполнить конечную точку значением из другого "
        "расписания?(1 - да; 2 - нет)\n"
              << ASCII_RESET;
    yes_no_wrt = write_1_or_2();

    if (yes_no_wrt == 1) {
      std::cout
          << "Выберите номер расписания, из которого скопировать значение\n";
      int number_tabl = for_write_number_tabl(number_of_buses);
      strcpy(massiw_BD[i].end_point, massiw_BD[number_tabl - 1].end_point);
    } else {
      std::cout << ASCII_COLOR_YELLOW "\nВведите конечную точку\n"
                << ASCII_RESET;
      write_char(massiw_BD[i].end_point);
    }

    std::cout << ASCII_COLOR_YELLOW
        "\nЗаполнить время отправления значением из другого "
        "расписания?(1 - да; 2 - нет)\n"
              << ASCII_RESET;
    yes_no_wrt = write_1_or_2();

    if (yes_no_wrt == 1) {
      std::cout
          << "Выберите номер расписания, из которого скопировать значение\n";
      int number_tabl = for_write_number_tabl(number_of_buses - 1);
      massiw_BD[i].start_time_hour = massiw_BD[number_tabl - 1].start_time_hour;
      massiw_BD[i].start_time_min = massiw_BD[number_tabl - 1].start_time_min;
    } else {
      std::cout << ASCII_COLOR_YELLOW "\nВведите время отправления\nЧасы "
                << ASCII_RESET;
      massiw_BD[i].start_time_hour = write_hour();
      std::cout << ASCII_COLOR_YELLOW "Минуты " << ASCII_RESET;
      massiw_BD[i].start_time_min = write_min();
    }

    std::cout << ASCII_COLOR_YELLOW
        "\nЗаполнить время прибытия значением из другого "
        "расписания?(1 - да; 2 - нет)\n"
              << ASCII_RESET;
    yes_no_wrt = write_1_or_2();

    if (yes_no_wrt == 1) {
      std::cout
          << "Выберите номер расписания, из которого скопировать значение\n";
      int number_tabl = for_write_number_tabl(number_of_buses - 1);
      massiw_BD[i].UN.finish_time_hour =
          massiw_BD[number_tabl - 1].UN.finish_time_hour;
      massiw_BD[i].finish_time_min = massiw_BD[number_tabl - 1].finish_time_min;
    } else {
      std::cout << ASCII_COLOR_YELLOW "\nВведите время прибытия\nЧасы "
                << ASCII_RESET;
      massiw_BD[i].UN.finish_time_hour = write_hour();
      std::cout << ASCII_COLOR_YELLOW "Минуты " << ASCII_RESET;
      massiw_BD[i].finish_time_min = write_min();
    }
  }
  std::ofstream file("lol.bin", std::ios::binary | std::ios::app);

  file.write((char*)&massiw_BD[number_of_buses - 1],
             sizeof(massiw_BD[number_of_buses - 1]));
  file.close();
}