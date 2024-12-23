#include "func_2_2.h"

#include <string.h>

#include <fstream>
#include <iostream>

#include "func_1_2.h"
#include "struct.h"

void delete_zero_cell(trains*& massiw, int couter) {
  trains* new_massiw = new trains[couter];
  for (int i = 0; i < couter; i++) {
    new_massiw[i].number_train = massiw[i].number_train;
    strcpy(new_massiw[i].day_week, massiw[i].day_week);
    strcpy(new_massiw[i].end_point, massiw[i].end_point);
    new_massiw[i].start_hour = massiw[i].start_hour;
    new_massiw[i].UN.start_min = massiw[i].UN.start_min;
    new_massiw[i].free_seats = massiw[i].free_seats;
  }
  delete[] massiw;
  massiw = new_massiw;
}

void up_size_massiw(trains*& massiw, int& first_size) {
  int size_plas_one = first_size + 1;
  trains* new_massiw = new trains[size_plas_one];
  for (int i = 0; i < first_size; i++) {
    new_massiw[i].number_train = massiw[i].number_train;
    strcpy(new_massiw[i].day_week, massiw[i].day_week);
    strcpy(new_massiw[i].end_point, massiw[i].end_point);
    new_massiw[i].start_hour = massiw[i].start_hour;
    new_massiw[i].UN.start_min = massiw[i].UN.start_min;
    new_massiw[i].free_seats = massiw[i].free_seats;
  }

  delete[] massiw;
  massiw = new_massiw;
  first_size = size_plas_one;
}

void write_massiw(trains* massiw_BD, int number_of_trains, int start) {
  for (int i = start; i < number_of_trains; i++) {
    system("clear");
    massiw_BD[i].number_train = i + 1;
    std::cout << "\nПоезд №" << massiw_BD[i].number_train << "\n\n";
    std::cout << "Введите день недели отправки поезда\n";
    write_char(massiw_BD[i].day_week);
    std::cout << "\nВведите пункт назначения поезда\n";
    write_char(massiw_BD[i].end_point);
    std::cout << "\nВведите время отправления\nЧасы: ";
    massiw_BD[i].start_hour = write_hour();
    std::cout << "Минуты: ";
    massiw_BD[i].UN.start_min = write_min();
    std::cout << "\nВведите количество свободных мест\n";
    std::cin >> massiw_BD[i].free_seats;
  }
  std::ofstream file("file.txt", std::ios::app);
  file << massiw_BD[number_of_trains - 1].number_train << '\n';
  file << massiw_BD[number_of_trains - 1].day_week << '\n';
  file << massiw_BD[number_of_trains - 1].end_point << '\n';
  file << massiw_BD[number_of_trains - 1].start_hour << ':'
       << massiw_BD[number_of_trains - 1].UN.start_min << '\n';
  file << massiw_BD[number_of_trains - 1].free_seats << '\n' << '\n';
  file.close();
}

void delete_field(trains*& massiw_BD, int& number_of_trains) {
  if (number_of_trains > 1) {
    system("clear");
    std::cout << "Введите номер расписания, которое хотите удалить\n";
    int number_table = for_write_number_tabl(number_of_trains);
    int new_size = number_of_trains - 1;
    trains* new_massiw = new trains[new_size];
    int index = 0;
    for (int i = 0; i < number_of_trains; i++) {
      if (i == number_table - 1) {
        continue;
      }
      new_massiw[index].number_train = massiw_BD[i].number_train;
      strcpy(new_massiw[index].day_week, massiw_BD[i].day_week);
      strcpy(new_massiw[index].end_point, massiw_BD[i].end_point);
      new_massiw[index].start_hour = massiw_BD[i].start_hour;
      new_massiw[index].UN.start_min = massiw_BD[i].UN.start_min;
      new_massiw[index].free_seats = massiw_BD[i].free_seats;
      index++;
    }

    delete[] massiw_BD;
    massiw_BD = new_massiw;
    number_of_trains = new_size;
  } else {
    std::cout << "У вас и так одно расписание, его удалить нельзя\n";
  }
}

void view_content(trains* massiw_BD, int number_of_buses) {
  for (int i = 0; i < number_of_buses; i++) {
    std::cout << "\nПоезд № " << massiw_BD[i].number_train << '\n';
    std::cout << "День отправки поезда: " << massiw_BD[i].day_week;
    std::cout << "\nПункт назначения: " << massiw_BD[i].end_point;
    std::cout << "\nВремя отправления: " << massiw_BD[i].start_hour << "ч. "
              << massiw_BD[i].UN.start_min << "мин.";
    std::cout << "\nКоличество свободных мест: " << massiw_BD[i].free_seats
              << "\n\n";
  }
}

void changing_values(trains* massiw_BD, int number_of_trains) {
  std::cout << "Показать, какие рассписания у вас есть?(1 - да; 2 - нет)\n";
  int yes_no_for_check = write_1_or_2();
  system("clear");
  if (yes_no_for_check == 1) {
    view_content(massiw_BD, number_of_trains);
  }
  std::cout << "Введите 1 - изменить день отправки поезда\n";
  std::cout << "Введите 2 - изменить пункт назначения\n";
  std::cout << "Введите 3 - изменить время отправления\n";
  std::cout << "Введите 4 - изменить количество свободных мест\n";
  int number_for_changes = write_1_dash_4();
  system("clear");

  if (number_for_changes == 1) {
    std::cout
        << "Выберите номер рассписания, в котором нужно сделать изменения\n";
    int check_number_tabl = for_write_number_tabl(number_of_trains);
    system("clear");
    std::cout << "Введите новый день отправки\n";

    write_char(massiw_BD[check_number_tabl - 1].day_week);
    system("clear");

  } else if (number_for_changes == 2) {
    std::cout
        << "Выберите номер рассписания, в котором нужно сделать изменения\n";
    int check_number_tabl = for_write_number_tabl(number_of_trains);
    system("clear");
    std::cout << "Введите новый пункт назначения\n";
    write_char(massiw_BD[check_number_tabl - 1].end_point);
    system("clear");

  } else if (number_for_changes == 3) {
    std::cout
        << "Выберите номер рассписания, в котором нужно сделать изменения\n";
    int check_number_tabl = for_write_number_tabl(number_of_trains);
    system("clear");
    std::cout << "Введите новое время отправления\nЧасы: ";
    massiw_BD[check_number_tabl - 1].start_hour = write_hour();
    std::cout << "\nМинуты: ";
    massiw_BD[check_number_tabl - 1].UN.start_min = write_min();
    system("clear");

  } else if (number_for_changes == 4) {
    std::cout
        << "Выберите номер рассписания, в котором нужно сделать изменения\n";
    int check_number_tabl = for_write_number_tabl(number_of_trains);
    system("clear");
    std::cout << "Введите новое количество свободных мест\n";
    massiw_BD[check_number_tabl - 1].free_seats = check_start_write();
    system("clear");
  }
}

void write_in_file(trains* massiw_BD, int number_of_trains) {
  std::ofstream file;
  file.open("file.txt");

  for (int i = 0; i < number_of_trains; i++) {
    file << massiw_BD[i].number_train << '\n';
    file << massiw_BD[i].day_week << '\n';
    file << massiw_BD[i].end_point << '\n';
    file << massiw_BD[i].start_hour << ':' << massiw_BD[i].UN.start_min << '\n';
    file << massiw_BD[i].free_seats << '\n' << '\n';
  }

  file.close();
}