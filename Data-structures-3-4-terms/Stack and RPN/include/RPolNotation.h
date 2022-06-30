//  Copyright by Oganyan Robert

#ifndef  STACK_AND_RPN_INCLUDE_RPOLNOTATION_H_
#define  STACK_AND_RPN_INCLUDE_RPOLNOTATION_H_

#include <string>
#include "../include/Token.h"
#include "../include/TStack.h"


class RPolNotation {
 private:
     char* formula;     // исходная формула
     int size;
 public:
     RPolNotation() = delete;
     explicit RPolNotation(char *form = nullptr);  // конструктор
     RPolNotation(const RPolNotation& rpn);  //  Конструктор копирования
     ~RPolNotation();  //  Деструктор
     // преобразование в постфиксную форму, в n записывается длина новой строки
     Token* Postfix(int& n);
     //  Вспомогательный метод для определения характеристик ячейки массива
     Token Next(int& ind);
     // Перевод Массива токкенов в строку [ Не работает ]
     std::string Convert(const Token* str, const int& size);
     double Calculate();  //  вычисление формулы
};

#endif  // STACK_AND_RPN_INCLUDE_RPOLNOTATION_H_"
