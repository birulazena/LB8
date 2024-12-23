#include "func_1_2.h"

#include <iostream>

int check_start_write() {
  int result;

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
      result = std::stoi(check);
      return result;
    } else {
      std::cout << "Неверный ввод\n";
    }
  }
}

int write_hour() {
  int result;
  for (;;) {
    bool isnum = true;
    std::string check;
    std::cin >> check;
    for (auto l : check) {
      if (!isdigit(l)) {
        isnum = false;
        break;
      }
    }
    if (isnum) {
      result = std::stoi(check);
      if (result < 24) {
        return result;
      } else {
        std::cout << "Неверный воод\n";
      }
    } else {
      std::cout << "Неверный ввод\n";
    }
  }
}

int write_min() {
  int result;
  for (;;) {
    bool isnum = true;
    std::string check;
    std::cin >> check;
    for (auto l : check) {
      if (!isdigit(l)) {
        isnum = false;
        break;
      }
    }
    if (isnum) {
      result = std::stoi(check);
      if (result < 60) {
        return result;
      } else {
        std::cout << "Неверный ввод\n";
      }
    } else {
      std::cout << "Неверный ввод\n";
    }
  }
}

void write_char(char* massiw) {
  if (std::cin.peek() == '\n') {
    char check;
    while (true) {
      check = getchar();
      if (check == '\n') {
        break;
      }
    }
  }

  int i = 0;
  for (;;) {
    for (int j = 0; j < 100; j++) {
      massiw[j] = '\0';
    }
    i = 0;
    bool isnum = true;
    char l;
    while ((l = getchar()) != '\n') {
      if (l == '\n') {
        massiw[i] = '\0';
        break;
      }
      if (i == 99 || l == 32) {
        isnum = false;
        while (true) {
          l = getchar();
          if (l == '\n') {
            break;
          }
        }
        break;
      }
      massiw[i] = l;
      i++;
    }
    if (isnum) {
      break;
    } else {
      std::cout << "\nНеверный ввод, попробуй еще раз\n";
    }
  }
}

int write_1_or_2() {
  int result;
  for (;;) {
    bool isnum = true;
    std::string check;
    std::cin >> check;
    for (auto l : check) {
      if (!isdigit(l)) {
        isnum = false;
        break;
      }
    }
    if (isnum) {
      result = std::stoi(check);
      if (result == 1 || result == 2) {
        return result;
      } else {
        std::cout << "Неверный ввод\n";
      }
    } else {
      std::cout << "Неверный ввод\n";
    }
  }
}

int write_1_dash_5() {
  int result;
  for (;;) {
    bool isnum = true;
    std::string check;
    std::cin >> check;
    for (auto l : check) {
      if (!isdigit(l)) {
        isnum = false;
        break;
      }
    }
    if (isnum) {
      result = std::stoi(check);
      if (result < 6 && result > 0) {
        return result;
      } else {
        std::cout << "Неверный ввод\n";
      }
    } else {
      std::cout << "Неверный ввод\n";
    }
  }
}

int write_1_dash_4() {
  int result;
  for (;;) {
    bool isnum = true;
    std::string check;
    std::cin >> check;
    for (auto l : check) {
      if (!isdigit(l)) {
        isnum = false;
        break;
      }
    }
    if (isnum) {
      result = std::stoi(check);
      if (result < 5 && result > 0) {
        return result;
      } else {
        std::cout << "Неверный ввод\n";
      }
    } else {
      std::cout << "Неверный ввод\n";
    }
  }
}

void to_continue() {
  if (std::cin.peek() == '\n') {
    char check;
    while (true) {
      check = getchar();
      if (check == '\n') {
        break;
      }
    }
  }
  std::cin.get();
}
int for_write_number_tabl(int number_of_buses) {
  int result;
  for (;;) {
    bool isnum = true;
    std::string check;
    std::cin >> check;
    for (auto l : check) {
      if (!isdigit(l)) {
        isnum = false;
        break;
      }
    }
    if (isnum) {
      result = std::stoi(check);
      if (result > 0 && result <= number_of_buses) {
        return result;
      } else {
        std::cout << "Неверный ввод (такого рассписаниия нету)\n";
      }
    } else {
      std::cout << "Неверный ввод\n";
    }
  }
}