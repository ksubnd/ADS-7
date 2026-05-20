// Copyright 2022 NNTU-CS
#include <iostream>
#include "train.h"

int main() {
  Train train;
  int count = 60; // кол-во вагонов

  while (count--)
    train.addCar(false);

  std::cout << train.getLength() << std::endl;
  std::cout << train.getOpCount() << std::endl;
  return 0;

  int size[] = { 500, 800, 1000,1500, 2000,4000, 5000,6000,8000,10000,25000,30000,40000,50000,60000,120000,150000, 200000,250000,300000 };
  for (int i = 0; size[i]; i++) {
    clock_t begin1, end1, begin2, end2, begin3, end3;
    clock_t t1, t2, t3;

    int j = size[i];

    Train train1;
    while (j--)
      train1.addCar(false);
    begin1 = clock();
    int count1L = train1.getLength();
    int count1C = train1.getOpCount();
    end1 = clock();
    j = size[i];

    Train train2;
    while (j--)
      train2.addCar(true);
    begin2 = clock();
    int count2L = train2.getLength();
    int count2C = train2.getOpCount();
    end2 = clock();
    j = size[i];

    Train train3;
    while (j--) {
      if (j % 2 == 0)
        train3.addCar(true);
      else
        train3.addCar(false);
    }
    begin3 = clock();
    int count3L = train3.getLength();
    int count3C = train3.getOpCount();
    end3 = clock();
    t1 = end1 - begin1;
    t2 = end2 - begin2;
    t3 = end3 - begin3;
    std::cout << t1 << " " << t2 << " " << t3 << std::endl;
  }
}
