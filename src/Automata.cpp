#include "Automata.h"
#include <iostream>
#include <string>

Automata::Automata(std::string menu[], int prices[]) {
  cash = 0;
  num_choice = -1;
  this->menu = menu;
  this->prices = prices;
  state = OFF;
}

std::string Automata::getState() {
  std::string CurrentState;
  switch (state) {
    case OFF:
      CurrentState = "OFF";
      break;
    case WAIT:
      CurrentState = "WAIT";
      break;
    case ACCEPT:
      CurrentState = "ACCEPT";
      break;
    case CHECK:
      CurrentState = "CHECK";
      break;
    case COOK:
      CurrentState = "COOK";
      break;
  }
  return CurrentState;
}

void Automata::on() {
  if (state == OFF) {
    state = WAIT;
    std::cout << "Coffee machine is ready to work" << std::endl;
    getMenu();
  }
}

void Automata::off() {
  if (state == WAIT) {
    std::cout << "\nCoffee machine off" << std::endl;
    state = OFF;
  }
}

void Automata::coin(int money) {
  if (state == WAIT or state == ACCEPT) {
    state = ACCEPT;
    std::cout << "\n\tDeposit money" << std::endl;
    cash += money;
    std::cout << "Deposit: " << money << std::endl;
    std::cout << "Total: " << cash << std::endl;
  }
}

void Automata::getMenu() {
  std::cout << "\tMenu" << std::endl;
  for (int i = 0; i < size(*menu) - 1; i++) {
    std::cout << i << ". " << menu[i] << " - " << prices[i] << " RUB" << std::endl;
  }
}

void Automata::choice(int num) {
  if (state == ACCEPT) {
    std::cout << "\nYour choice is " << menu[num] << std::endl;
    num_choice = num;
    state = CHECK;
  }
}

void Automata::check() {
  if (state == CHECK || state == ACCEPT) {
    if (prices[num_choice] <= cash) {
      state = COOK;
      std::cout << "\nEnough money" << std::endl;
    } else {
      std::cout << "\nNot enough money. Add or cancel" << std::endl;
      state = ACCEPT;
    }
  }
}

void Automata::cancel() {
  if (state == ACCEPT || state == CHECK) {
    std::cout << "\nCancel..." << std::endl;
    state = WAIT;
    cash = 0;
    num_choice = -1;
  }
}

void Automata::cook() {
  if (state == COOK) {
    state = COOK;
    std::cout << "\nYour drink will be ready soon..." << std::endl;
    std::cout << "\nYour drink is ready!" << std::endl;
  }
}

void Automata::finish() {
  if (state == COOK) {
    state = WAIT;
    num_choice = -1;
    cash = 0;
  }
}
