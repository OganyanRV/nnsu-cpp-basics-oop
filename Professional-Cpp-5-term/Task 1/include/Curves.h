//
// Created by OgRob on 27.09.2020.
//
#include <stdexcept>

#ifndef TASK_1_CURVES_H
#define TASK_1_CURVES_H
enum type {
  undefined=0,
  circle,
  ellipse,
};

struct point {
    double x;
    double y;
};
const double pi = 3.141592653589;

class Curves {

protected:

  point center; // Центр фигуры
  type figure_type; // Признак фигуры

public:

  Curves() = default;
  virtual ~Curves() = default;
  virtual double Square() const = 0;
  type Getfigure_type() const {
      return figure_type;
  };

};

#endif // TASK_1_CURVES_H
