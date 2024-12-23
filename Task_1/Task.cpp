#include <cstring>
#include <fstream>
#include <iostream>

#include "func_1.h"
#include "func_2.h"

#define ASCII_COLOR_YELLOW "\e[0;33m"
#define ASCII_RESET "\e[0m"

int main() {
  for (;;) {
    std::cout << "Введите количество рассписаний движений автобусов: \n";
    int number_of_buses = check_start_write();
    system("clear");

    reference* massiw_BD = new reference[number_of_buses];

    int couter = 0;
    int yes_no_wrt = 3;
    for (int i = 0; i < number_of_buses; i++) {
      couter++;
      std::cout << ASCII_COLOR_YELLOW "\nЛист №" << i + 1 << "\n"
                << ASCII_RESET;
      if (i > 0) {
        std::cout << ASCII_COLOR_YELLOW
            "\nЗаполнить номер автобуса значением из другого "
            "расписания?(1 - да; 2 - нет)\n"
                  << ASCII_RESET;
        yes_no_wrt = write_1_or_2();
      }
      if (yes_no_wrt == 1) {
        std::cout
            << "Выберите номер расписания, из которого скопировать значение\n";
        int number_tabl = for_write_number_tabl(couter - 1);
        strcpy(massiw_BD[i].bus_number, massiw_BD[number_tabl - 1].bus_number);
      } else {
        std::cout << ASCII_COLOR_YELLOW "\nВведите номер автобуса\n"
                  << ASCII_RESET;
        write_char(massiw_BD[i].bus_number);
      }

      if (i > 0) {
        std::cout << ASCII_COLOR_YELLOW
            "\nЗаполнить тип автобуса изначением из другого расписания?(1 "
            "- да; 2 - нет)\n"
                  << ASCII_RESET;
        yes_no_wrt = write_1_or_2();
      }
      if (yes_no_wrt == 1) {
        std::cout
            << "Выберите номер расписания, из которого скопировать значение\n";
        int number_tabl = for_write_number_tabl(couter - 1);
        strcpy(massiw_BD[i].bus_type, massiw_BD[number_tabl - 1].bus_type);
      } else {
        std::cout << ASCII_COLOR_YELLOW "\nВведите тип автобуса\n"
                  << ASCII_RESET;
        write_char(massiw_BD[i].bus_type);
      }

      if (i > 0) {
        std::cout << ASCII_COLOR_YELLOW
            "\nЗаполнить конечную точку значением из другого "
            "расписания?(1 - да; 2 - нет)\n"
                  << ASCII_RESET;
        yes_no_wrt = write_1_or_2();
      }
      if (yes_no_wrt == 1) {
        std::cout
            << "Выберите номер расписания, из которого скопировать значение\n";
        int number_tabl = for_write_number_tabl(couter - 1);
        strcpy(massiw_BD[i].end_point, massiw_BD[number_tabl - 1].end_point);
      } else {
        std::cout << ASCII_COLOR_YELLOW "\nВведите конечную точку\n"
                  << ASCII_RESET;
        write_char(massiw_BD[i].end_point);
      }

      if (i > 0) {
        std::cout << ASCII_COLOR_YELLOW
            "\nЗаполнить время отправления значением из другого "
            "расписания?(1 - да; 2 - нет)\n"
                  << ASCII_RESET;
        yes_no_wrt = write_1_or_2();
      }
      if (yes_no_wrt == 1) {
        std::cout
            << "Выберите номер расписания, из которого скопировать значение\n";
        int number_tabl = for_write_number_tabl(couter - 1);
        massiw_BD[i].start_time_hour =
            massiw_BD[number_tabl - 1].start_time_hour;
        massiw_BD[i].start_time_min = massiw_BD[number_tabl - 1].start_time_min;
      } else {
        std::cout << ASCII_COLOR_YELLOW "\nВведите время отправления\nЧасы "
                  << ASCII_RESET;
        massiw_BD[i].start_time_hour = write_hour();
        std::cout << ASCII_COLOR_YELLOW "Минуты " << ASCII_RESET;
        massiw_BD[i].start_time_min = write_min();
      }

      if (i > 0) {
        std::cout << ASCII_COLOR_YELLOW
            "\nЗаполнить время прибытия значением из другого "
            "расписания?(1 - да; 2 - нет)\n"
                  << ASCII_RESET;
        yes_no_wrt = write_1_or_2();
      }
      if (yes_no_wrt == 1) {
        std::cout
            << "Выберите номер расписания, из которого скопировать значение\n";
        int number_tabl = for_write_number_tabl(couter - 1);
        massiw_BD[i].UN.finish_time_hour =
            massiw_BD[number_tabl - 1].UN.finish_time_hour;
        massiw_BD[i].finish_time_min =
            massiw_BD[number_tabl - 1].finish_time_min;
      } else {
        std::cout << ASCII_COLOR_YELLOW "\nВведите время прибытия\nЧасы "
                  << ASCII_RESET;
        massiw_BD[i].UN.finish_time_hour = write_hour();
        std::cout << ASCII_COLOR_YELLOW "Минуты " << ASCII_RESET;
        massiw_BD[i].finish_time_min = write_min();
      }

      if (i < number_of_buses - 1) {
        std::cout << "\nХотите продолжить ввод?(1 - да; 2 - нет)\n";
        int yes_no = write_1_or_2();
        if (yes_no == 1) {
          continue;
          ;
        } else {
          delete_zero_cell(massiw_BD, couter);
          number_of_buses = couter;
          break;
        }
      }
      if (i == number_of_buses - 1) {
        std::cout << "\nВы уже ввели заданное количество "
                     "расписаний.\nХотите ввести еще?(1 - да; 2 - нет)\n";
        int yes_no = write_1_or_2();
        if (yes_no == 1) {
          up_size_massiw(massiw_BD, number_of_buses);
        } else {
          break;
        }
      }
    }
    write_in_file(massiw_BD, number_of_buses);

    system("clear");

    // меню
    for (;;) {
      system("clear");
      std::cout << "Введите 1 - посмотреть расписания\n";
      std::cout << "Введите 2 - дополнить рассписание\n";
      std::cout << "Введите 3 - найти расписание по элементу\n";
      std::cout << "Введите 4 - изменить что-то в рассписании\n";
      std::cout
          << "Введите 5 - отсортировать по времени прибытия(по убыванию)\n";
      std::cout << "Введите 6 - выйти из меню\n";

      int number_for_meniu;
      for (;;) {
        std::string check;
        std::cin >> check;
        bool isnum = true;
        for (auto l : check) {
          if (!isdigit(l)) {
            isnum = false;
            break;
          }
        }
        if (isnum) {
          number_for_meniu = std::stoi(check);
          if (number_for_meniu > 0 && number_for_meniu <= 6) {
            break;
          } else {
            std::cout << "Неверный ввод\n";
          }
        } else {
          std::cout << "Неверный ввод\n";
        }
      }
      system("clear");
      if (number_for_meniu == 1) {
        view_content(massiw_BD, number_of_buses);
        std::cout << "\nНажмите Enter чтобы продолжить\n";
        to_continue();
        continue;
      } else if (number_for_meniu == 2) {
        system("clear");
        int start = number_of_buses;
        up_size_massiw(massiw_BD, number_of_buses);
        write_massiw(massiw_BD, number_of_buses, start);
        std::cout << "\nНажмите Enter чтобы продолжить\n";
        to_continue();
        continue;
      } else if (number_for_meniu == 3) {
        system("clear");
        int yes_no = 1;
        while (yes_no == 1) {
          scan_tabl_element(massiw_BD, number_of_buses);
          std::cout << "\nХотите найти еще что-нибудь(1 - да; 2 - нет)\n";
          yes_no = write_1_or_2();
          system("clear");
        }
        std::cout << "\nНажмите Enter чтобы продолжить\n";
        to_continue();
        continue;
      } else if (number_for_meniu == 4) {
        system("clear");
        int yes_no = 1;
        while (yes_no == 1) {
          changing_values(massiw_BD, number_of_buses);
          std::cout << "Хотите изменить что-нибудь еще?(1 - да; 2 - нет)\n";
          yes_no = write_1_or_2();
          system("clear");
        }
        std::cout << "\nНажмите Enter чтобы продолжить\n";
        to_continue();
        continue;
      } else if (number_for_meniu == 5) {
        system("clear");
        my_selection_sort(massiw_BD, number_of_buses);
        std::cout << "Расписания успешно отсортированы\n";
        std::cout << "\nНажмите Enter чтобы продолжить\n";
        to_continue();
        continue;
      } else if (number_for_meniu == 6) {
        system("clear");
        break;
      }
    }

    std::cout
        << "Чтобы найти расписание, которым можно воспользоваться,\n"
           "чтобы приехать в пункт назначения раньше заданного времени\n\n";
    std::cout << "\nВведите пункт назначения:\n";
    std::string check_end_point;
    std::cin >> check_end_point;
    std::cout << "\nВведите время прибытия\nЧасы:";
    int check_hour = write_hour();
    std::cout << "\nМинуты:";
    int check_min = write_min();

    system("clear");

    std::cout << "Поиск: " << check_end_point << "\t" << check_hour << ":"
              << check_min << "\n\n";

    bool check_progress = false;
    for (int i = 0; i < number_of_buses; i++) {
      if (massiw_BD[i].end_point == check_end_point) {
        if (massiw_BD[i].UN.finish_time_hour == check_hour) {
          if (massiw_BD[i].finish_time_min < check_min) {
            check_progress = true;
            std::cout << "\nЛист №" << i + 1 << '\n';
            std::cout << "Номер автобуса: " << massiw_BD[i].bus_number;
            std::cout << "\tТип автобуса: " << massiw_BD[i].bus_type;
            std::cout << "\tКонечная точка: " << massiw_BD[i].end_point;
            std::cout << "\nВремя отправления: " << massiw_BD[i].start_time_hour
                      << " часов " << massiw_BD[i].start_time_min << " мин.";
            std::cout << "\tВремя прибытия: "
                      << massiw_BD[i].UN.finish_time_hour << " часов "
                      << massiw_BD[i].finish_time_min << " мин.\n\n";
          }
        } else if (massiw_BD[i].UN.finish_time_hour > check_hour) {
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
      if ((i == number_of_buses - 1) && check_progress == false) {
        system("clear");
        std::cout << "Таких расписаний нету...\n\n";
      }
    }

    std::cout << "\nНажмите Enter чтобы продолжить\n";
    to_continue();
    system("clear");

    delete[] massiw_BD;

    std::cout << "Запустить программу еще раз(1 - да; 2 - нет)\n";
    int number_for_restart = write_1_or_2();
    system("clear");

    if (number_for_restart == 2) {
      break;
    }
  }

  return 0;
}