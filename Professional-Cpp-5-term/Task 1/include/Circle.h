//
// Created by OgRob on 27.09.2020.
//

#include "Curves.h"

#ifndef TASK_1_CIRCLE_H
#define TASK_1_CIRCLE_H

class Circle : public Curves {

private:

    double radius; // Радиус фигуры

public:

  Circle(double center_x = 0.0, double center_y = 0.0, double radius_ = 0.0) {
    if (radius_ < 0) {
      throw std::runtime_error("Radius is incorrect");
    }
    center.x = center_x;
    center.y = center_y;
    radius = radius_;
    figure_type = circle;
  };

  ~Circle() override = default;

  double Square() const override {
    return pi * radius * radius;
  };

};

#endif // TASK_1_CIRCLE_H
