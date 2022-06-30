//  Copyright by Oganyan Robert

#include <stdlib.h>
#include <cstring>
#include <string>
#include <cmath>

#include "../include/RPolNotation.h"

RPolNotation::RPolNotation(char *form) {
  formula = form;
  size = 0;
  if (form != nullptr) {
    size = strlen(form);
  }
}

RPolNotation::~RPolNotation() {
  if (formula != nullptr) {
    delete[] formula;
  }
}

RPolNotation::RPolNotation(const RPolNotation& rpn) {
  size = rpn.size;
  if (rpn.formula != nullptr) {
    for (std::size_t i = 0; i < size; ++i) {
      formula[i] = rpn.formula[i];
    }
  }
}
//  Перевод в постфиксную форму
Token * RPolNotation::Postfix(int& curidx) {
  curidx = 0;
  int formulaidx = 0;
  Token *ans = new Token[size];
  TStack<Token> st(size);
  //  Берем элемент
  Token cur = Next(formulaidx);
  while (cur.type != Token::kEnd) {
    //  Если это число, то
    if (cur.type == Token::kNumber) {
      ans[curidx] = cur;
      curidx++;
      cur = Next(formulaidx);
      continue;
    }
    if (st.IsEmpty() || cur.symbol == '(') {
      st.Push(cur);
      cur = Next(formulaidx);
      continue;
    }
    if (cur.symbol == ')') {
      //  Выплевываем до скобки
      while (st.Top().symbol != '(') {
        ans[curidx] = st.Pop();
        curidx++;
      }
      st.Pop();
      cur = Next(formulaidx);
      continue;
    }
    //  Если текующий приоритет выше, то кладем
    if (cur.prior > st.Top().prior) {
      st.Push(cur);
      cur = Next(formulaidx);
      continue;
    }

    //  Иначе выплевываем до конца, внутренней скобки или до меньшего приоритета
    while (!st.IsEmpty() && st.Top().symbol
                != '(' && st.Top().prior >= cur.prior) {
      ans[curidx] = st.Pop();
      curidx++;
    }
    st.Push(cur);
    cur = Next(formulaidx);
  }
  // Остаток
  while (!st.IsEmpty()) {
    ans[curidx] = st.Pop();
    curidx++;
  }
  return ans;
}

Token RPolNotation::Next(int& ind) {
  char cur = formula[ind];
  // Если это конец строки
  if (cur == 0) {
    return Token(Token::Type::kEnd);
  }
  // Если это знак
  if (cur < '0' || cur > '9') {
    Token token(Token::Type::kSymbol, cur);
    ++ind;
    return token;
  }
  Token token(Token::Type::kNumber);
  // алгоритм чтоб узнать какое число и вернуть его
  double num;
  int begin = ind;
  while ((formula[ind] >= '0' && formula[ind] <= '9')
                    || (formula[ind] == '.')) {
    ind++;
  }
  char *number = new char[ind - begin + 1];
  strncpy(number, formula + begin, ind - begin + 1);
  number[ind - begin] = '\0';
  num = atof(number);
  delete[] number;
  token.number = num;
  return token;
}

double RPolNotation::Calculate() {
  int n = 0;
  auto str = Postfix(n);
  TStack<double> st(n);
  int i = 0;
  while (i < n) {
    Token cur = str[i++];
    //  Число кладем в стэк
    if (cur.type == Token::kNumber) {
      st.Push(cur.number);
      continue;
    }
    if (st.GetTop() < 2) {
      //  Случай для начала строки с минусом, например -5
      if (st.GetTop() == 1) {
        if (cur.symbol == '-') {
          int new_val = st.Pop();
          st.Push(-1*new_val);
          continue;
        }
      }
      throw std::runtime_error("Wrong Postfix Formula");
    }
    auto op_fi = st.Pop();
    auto op_se = st.Pop();
    double res = 0.0;
    bool fl = true;
    switch (cur.symbol) {
      case '-':
        // Случай для -(- чтобы оно давало +
        if (str[i].type == Token::kSymbol && str[i].symbol == '-') {
          op_fi = op_fi * -1;
          fl = false;
          st.Push(op_se);
          st.Push(op_fi);
        } else {
          res = op_se - op_fi;
        }
        break;

      case '+':
        res = op_fi + op_se;
        break;

      case '*':
        res = op_fi * op_se;
        break;

      case '/':
        res = op_se / op_fi;
        break;

      default:
        throw std::runtime_error("Wrong Postfix Formula");
    }

    if (fl) {
      st.Push(res);
    }
  }
  if (st.GetTop() != 1) {
    throw std::runtime_error("Wrong Postfix Formula");
  }
  delete[] str;
  return st.Pop();
}

//  Не работает из-за неправильного форматирования (1.000000)
std::string RPolNotation::Convert(const Token* str, const int& size) {
  std::string new_str;
  std::size_t i = 0;
  while (i < size) {
    if (str[i].type == Token::kSymbol) {
      new_str += str[i].symbol;
      new_str += ' ';
      ++i;
      continue;
    }
    auto num = str[i].number;
    if (num == std::floor(num)) {
      int new_num = num;
      new_str += std::to_string(num);
      new_str += ' ';
      ++i;
      continue;
    }
    new_str += std::to_string(num);
    new_str += ' ';
    ++i;
  }
  return new_str;
}
