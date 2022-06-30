#include "include/Curves_Container.h"
#include <iostream>


int main() {
  std::cout.fixed;
  std::cout.precision(13);
  std::cout<<"Enter size of the container:"<<"\n";
  int size=0;
  do {
    std::cin>>size;
  } while (size<=0);
  std::cout<<"\n";

  Curves_Container cur_container;
  cur_container.RandomFill(size);
  std::cout<<"The container after being random filled: " <<"\n";
  cur_container.Print_container();
  cur_container.Sort();
  std::cout<<"The container after being sorted: " <<"\n";
  cur_container.Print_container();

  std::cout<<"The sum of all areas of the ellipses: "<<"\n";
  std::cout<<cur_container.CalculateArea(ellipse)<<"\n";
  std::cout<<"The sum of all areas of the circles: "<<"\n";
  std::cout<<cur_container.CalculateArea(circle)<<"\n";
  std::cout<<"The sum of all areas: "<<"\n";
  std::cout<<cur_container.CalculateArea()<<"\n";

  return 0;
}