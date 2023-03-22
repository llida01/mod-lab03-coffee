// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"

TEST(test1, test_off) {
  std::string menu[] = { "Espresso", "Capuccino", "Latte", 
                        "Americano", "Raf", "Hot chocolate", "Cocoa" };
  int prices[] = {70, 140, 140, 130, 190, 160, 140};
  Automata automat = Automata(menu, prices);
  std::string answer = "OFF";
  automat.on();
  automat.off();
  EXPECT_EQ(automat.getState(), answer);
}

TEST(test2, test_off) {
  std::string menu[] = { "Espresso", "Capuccino", "Latte", 
                        "Americano", "Raf", "Hot chocolate", "Cocoa" };
  int prices[] = { 70, 140, 140, 130, 190, 160, 140 };
  Automata automat = Automata(menu, prices);
  std::string answer = "OFF";
  automat.on();
  automat.coin(100);
  automat.choice(3);
  automat.check();
  automat.cancel();
  automat.off();
  EXPECT_EQ(automat.getState(), answer);
}

TEST(test3, test_off) {
  std::string menu[] = { "Espresso", "Capuccino", "Latte", 
                        "Americano", "Raf", "Hot chocolate", "Cocoa" };
  int prices[] = { 70, 140, 140, 130, 190, 160, 140 };
  Automata automat = Automata(menu, prices);
  std::string answer = "OFF";
  automat.on();
  automat.coin(100);
  automat.choice(5);
  automat.check();
  automat.coin(60);
  automat.cancel();
  automat.coin(100);
  automat.choice(1);
  automat.check();
  automat.coin(40);
  automat.check();
  automat.check();
  automat.finish();
  automat.off();
  EXPECT_EQ(automat.getState(), answer);
}

TEST(test4, test_wait) {
  std::string menu[] = { "Espresso", "Capuccino", "Latte", 
                        "Americano", "Raf", "Hot chocolate", "Cocoa" };
  int prices[] = { 70, 140, 140, 130, 190, 160, 140 };
  Automata automat = Automata(menu, prices);
  std::string answer = "WAIT";
  automat.on();
  EXPECT_EQ(automat.getState(), answer);
}

TEST(test5, test_wait) {
  std::string menu[] = { "Espresso", "Capuccino", "Latte", 
                        "Americano", "Raf", "Hot chocolate", "Cocoa" };
  int prices[] = { 70, 140, 140, 130, 190, 160, 140 };
  Automata automat = Automata(menu, prices);
  std::string answer = "WAIT";
  automat.on();
  automat.coin(100);
  automat.cancel();
  EXPECT_EQ(automat.getState(), answer);
}

TEST(test6, test_wait) {
  std::string menu[] = { "Espresso", "Capuccino", "Latte", 
                        "Americano", "Raf", "Hot chocolate", "Cocoa" };
  int prices[] = { 70, 140, 140, 130, 190, 160, 140 };
  Automata automat = Automata(menu, prices);
  std::string answer = "WAIT";
  automat.on();
  automat.coin(100);
  automat.choice(4);
  automat.cancel();
  EXPECT_EQ(automat.getState(), answer);
}

TEST(test7, test_wait) {
  std::string menu[] = { "Espresso", "Capuccino", "Latte", 
                        "Americano", "Raf", "Hot chocolate", "Cocoa" };
  int prices[] = { 70, 140, 140, 130, 190, 160, 140 };
  Automata automat = Automata(menu, prices);
  std::string answer = "WAIT";
  automat.on();
  automat.coin(130);
  automat.choice(3);
  automat.check();
  automat.cook();
  automat.finish();
  EXPECT_EQ(automat.getState(), answer);
}

TEST(test8, test_accept) {
  std::string menu[] = { "Espresso", "Capuccino", "Latte", 
                        "Americano", "Raf", "Hot chocolate", "Cocoa" };
  int prices[] = { 70, 140, 140, 130, 190, 160, 140 };
  Automata automat = Automata(menu, prices);
  std::string answer = "ACCEPT";
  automat.on();
  automat.coin(100);
  EXPECT_EQ(automat.getState(), answer);
}

TEST(test9, test_accept) {
  std::string menu[] = { "Espresso", "Capuccino", "Latte", 
                        "Americano", "Raf", "Hot chocolate", "Cocoa" };
  int prices[] = { 70, 140, 140, 130, 190, 160, 140 };
  Automata automat = Automata(menu, prices);
  std::string answer = "ACCEPT";
  automat.on();
  automat.coin(100);
  automat.coin(100);
  EXPECT_EQ(automat.getState(), answer);
}

TEST(test10, test_accept) {
  std::string menu[] = { "Espresso", "Capuccino", "Latte", 
                        "Americano", "Raf", "Hot chocolate", "Cocoa" };
  int prices[] = { 70, 140, 140, 130, 190, 160, 140 };
  Automata automat = Automata(menu, prices);
  std::string answer = "ACCEPT";
  automat.on();
  automat.coin(50);
  automat.choice(1);
  automat.check();
  EXPECT_EQ(automat.getState(), answer);
}

TEST(test11, test_accept) {
  std::string menu[] = { "Espresso", "Capuccino", "Latte", 
                        "Americano", "Raf", "Hot chocolate", "Cocoa" };
  int prices[] = { 70, 140, 140, 130, 190, 160, 140 };
  Automata automat = Automata(menu, prices);
  std::string answer = "ACCEPT";
  automat.on();
  automat.coin(100);
  automat.cancel();
  automat.coin(90);
  automat.choice(1);
  automat.check();
  EXPECT_EQ(automat.getState(), answer);
}

TEST(test12, test_check) {
  std::string menu[] = { "Espresso", "Capuccino", "Latte", 
                        "Americano", "Raf", "Hot chocolate", "Cocoa" };
  int prices[] = { 70, 140, 140, 130, 190, 160, 140 };
  Automata automat = Automata(menu, prices);
  std::string answer = "CHECK";
  automat.on();
  automat.coin(70);
  automat.choice(0);
  EXPECT_EQ(automat.getState(), answer);
}

TEST(test13, test_check) {
  std::string menu[] = { "Espresso", "Capuccino", "Latte", 
                        "Americano", "Raf", "Hot chocolate", "Cocoa" };
  int prices[] = { 70, 140, 140, 130, 190, 160, 140 };
  Automata automat = Automata(menu, prices);
  std::string answer = "CHECK";
  automat.on();
  automat.coin(100);
  automat.choice(1);
  automat.cancel();
  automat.coin(140);
  automat.choice(6);
  EXPECT_EQ(automat.getState(), answer);
}

TEST(test14, test_cook) {
  std::string menu[] = { "espresso", "capuccino", "latte", 
                        "americano", "raf", "hot chocolate", "cocoa" };
  int prices[] = { 70, 140, 140, 130, 190, 160, 140 };
  Automata automat = Automata(menu, prices);
  std::string answer = "COOK";
  automat.on();
  automat.coin(100);
  automat.coin(50);
  automat.choice(4);
  automat.check();
  automat.coin(50);
  automat.check();
  automat.cook();
  EXPECT_EQ(automat.getState(), answer);
}
