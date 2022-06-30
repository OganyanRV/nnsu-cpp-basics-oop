//
// Created by OgRob on 27.09.2020.
//
#include "Curves.h"
#include "Circle.h"
#include "Ellipse.h"
#include "vector"
#include <exception>
#include <memory>
#include <random>
#include <algorithm>
#include <iostream>

#ifndef TASK_1_CURVES_CONTAINER_H
#define TASK_1_CURVES_CONTAINER_H

class Curves_Container {

private:

  std::vector<std::shared_ptr<Curves>> container;

  class Random { // Класс для генерации случайных double от 0.0 до 100.0

  public:

    static double Next() {
      static Random rand = Random();
      return rand.dist_(rand.gen_);
    }

  private:

     Random() {
      std::random_device device;
      gen_ = std::mt19937(device());
      dist_ = std::uniform_real_distribution<>(0.0, 100.0);
    }

    std::mt19937 gen_;
    std::uniform_real_distribution<double> dist_;
  };

public:

    Curves_Container() = default;

    Curves_Container(size_t size) {
        container.clear();
        container.resize(size);
    }

  std::shared_ptr<Curves> RandomGenerate() { // Случайный объект
    double center_x = Random::Next ();
    double center_y = Random::Next ();
    if (Random::Next() < 50.0) {
      double radius = Random::Next();
      Circle object(center_x, center_y, radius);
      return std::make_shared<Circle>(object);
    }
    else {
      double semiaxis_x = Random::Next();
      double semiaxis_y = Random::Next();
      Ellipse object(center_x, center_y, semiaxis_x, semiaxis_y);
      return std::make_shared<Ellipse>(object);
    }
  };

  void RandomFill(std::size_t size) { // Заполнение контейнера случайными объектами
    for (std::size_t i=0; i<size; ++i) {
      container.push_back(RandomGenerate());
    }
  }

  double CalculateArea(type object_type = undefined) const { // Подсчет площади по признаку object_type
    double area = 0.0;
    for (std::size_t i=0; i < container.size(); ++i) {
        if (object_type == undefined) {
            area+=container[i]->Square();
            continue;
        }
        if (container[i]->Getfigure_type() == object_type) {
          area += container[i]->Square();
        }
    }
    return area;
  }

  static bool Comparator(std::shared_ptr<Curves>& left, std::shared_ptr<Curves>& right) { // Вспомогательная функция для сортировки
      return left->Square() < right->Square();
  }

  void Sort() { // Сортировка с помощью встроенной функции sort и вспомогательной реализованной Comparator
        std::sort(container.begin(), container.end(), Comparator);
  }

  void Print_container() { // Вывод контейнера для наглядности
      for (std::size_t i = 0; i < container.size(); ++i) {
          std::string info;
          if (container[i]->Getfigure_type() == ellipse) info = "Ellipse";
          else info = "Circle";
          std::cout<<info<<" "<<container[i]->Square()<<"\n";
      }
  }

};

#endif // TASK_1_CURVES_CONTAINER_H
