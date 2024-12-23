#include <string.h>

#include <fstream>
#include <iostream>

#include "func_1_2.h"
#include "func_2_2.h"
#include "struct.h"

int main() {
  for (;;) {
    std::cout << "Введите количество расписаний движений поездов\n";
    int number_of_trains = check_start_write();

    trains* massiw_BD = new trains[number_of_trains];

    int yes_no;
    int couter = 0;
    for (int i = 0; i < number_of_trains; i++) {
      system("clear");
      couter++;
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
      massiw_BD[i].free_seats = check_start_write();
      std::cout << "\nПродолжить ввод(1 - да;2 - нет)\n";
      yes_no = write_1_or_2();
      if (yes_no == 2) {
        delete_zero_cell(massiw_BD, couter);
        number_of_trains = couter;
        break;
      }
    }

    write_in_file(massiw_BD, number_of_trains);

    for (;;) {
      system("clear");
      std::cout << "Введите 1 - добавить расписание\n";
      std::cout << "Введите 2 - удалить расписание\n";
      std::cout << "Введите 3 - изменить расписание\n";
      std::cout << "Введите 4 - посмотреть расписания\n";
      std::cout << "Введиет 5 - выйти из меню\n";
      int number_for_meniu = write_1_dash_5();

      if (number_for_meniu == 1) {
        system("clear");
        int start = number_of_trains;
        up_size_massiw(massiw_BD, number_of_trains);
        write_massiw(massiw_BD, number_of_trains, start);
        std::cout << "\nНажмите Enter чтобы продолжить\n";
        to_continue();
        continue;
      } else if (number_for_meniu == 2) {
        system("clear");
        delete_field(massiw_BD, number_of_trains);
        std::cout << "\nНажмите Enter чтобы продолжить\n";
        to_continue();
        continue;
      } else if (number_for_meniu == 3) {
        system("clear");
        changing_values(massiw_BD, number_of_trains);
        std::cout << "\nНажмите Enter чтобы продолжить\n";
        to_continue();
        continue;
      } else if (number_for_meniu == 4) {
        system("clear");
        view_content(massiw_BD, number_of_trains);
        std::cout << "\nНажмите Enter чтобы продолжить\n";
        to_continue();
        continue;
      } else if (number_for_meniu == 5) {
        system("clear");
        break;
      }
    }

    write_in_file(massiw_BD, number_of_trains);

    std::cout << "Теперь вы стали Оргкомитетом международной конференции, и "
                 "вам надо\n";
    std::cout << "зарезервировать места до нужного вам города на определенный "
                 "день недели\n";
    std::cout << "с временем отправления не позднее нужного вам\n";
    std::cout << "\nНажмите Enter чтобы продолжить\n";
    to_continue();
    system("clear");

    std::cout << "Введите количество мест, которые вам надо зарезервировать\n";
    int check_seats = check_start_write();
    std::cout << "\nВведите пункт назначения\n";
    std::string check_end;
    std::cin >> check_end;
    std::cout << "\nВведите день отправки поезда\n";
    std::string check_day;
    std::cin >> check_day;
    std::cout << "\nВведите время, до которого должно быть отправление "
                 "поезда\nЧасы: ";
    int check_hour = write_hour();
    std::cout << "\nМинуты: ";
    int check_min = write_min();

    std::cout << "\nНажмите Enter чтобы продолжить\n";
    to_continue();
    system("clear");

    std::cout << "Поиск:\n";
    std::cout << "Места: " << check_seats;
    std::cout << "\nПункт назначения: " << check_end;
    std::cout << "\nДень отправки: " << check_day;
    std::cout << "\nВремя: " << check_hour << "ч. " << check_min << "мин.\n";

    bool check_progress = false;
    for (int i = 0; i < number_of_trains; i++) {
      if (massiw_BD[i].free_seats >= check_seats &&
          massiw_BD[i].end_point == check_end &&
          massiw_BD[i].day_week == check_day) {
        if (massiw_BD[i].start_hour < check_hour) {
          check_progress = true;
          std::cout << "\nПоезд №" << massiw_BD[i].number_train;
          std::cout << "\nВремя отправления: " << massiw_BD[i].start_hour
                    << "ч. " << massiw_BD[i].UN.start_min << "мин.\n";
        }
        if (massiw_BD[i].start_hour == check_hour) {
          if (massiw_BD[i].UN.start_min < check_min) {
            check_progress = true;
            std::cout << "\nПоезд №" << massiw_BD[i].number_train;
            std::cout << "\nВремя отправления: " << massiw_BD[i].start_hour
                      << "ч. " << massiw_BD[i].UN.start_min << "мин.\n\n";
          }
        }
      }
    }

    if (check_progress == false) {
      std::cout
          << "\n\nПростите, мы не можем выполнить ваш заказ, таких поездов "
             "нету...\n\n";
    }

    delete[] massiw_BD;

    std::cout << "\nНажмите Enter чтобы продолжить\n";
    to_continue();
    system("clear");

    std::cout << "Запустить программу еще раз(1 - да; 2 - нет)\n";
    int number_for_restart = write_1_or_2();
    system("clear");

    if (number_for_restart == 2) {
      break;
    }
  }

  return 0;
}