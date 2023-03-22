// Copyright 2022 UNN-IASR
#include "Automata.h"
#include <iostream>
#include <string>

int main() {
  std::string menu[] = { "Espresso", "Capuccino", "Latte",
                        "Americano", "Raf", "Hot chocolate", "Cocoa"};
  int prices[] = {70, 140, 140, 130, 190, 160, 140};
  Automata automat = Automata(menu, prices);
  automat.on();
  automat.coin(140);
  automat.choice(2);
  automat.cancel();
  automat.coin(160);
  automat.choice(5);
  automat.check();
  automat.cook();
  automat.finish();
  automat.off();
}
