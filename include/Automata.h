#pragma once
#include <string>

enum States {
  OFF, WAIT, ACCEPT, CHECK, COOK
};
class Automata {
 private:
  States state;
  int cash;
  std::string* menu;
  int* prices;
  int num_choice;
 public:
  void on();
  void off();
  void coin(int money);
  void getMenu();
  void choice(int num);
  void check();
  void cancel();
  void cook();
  void finish();
  std::string getState();
  Automata(std::string menu[], int prices[]);
};
