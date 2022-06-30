  //  Copyright by Oganyan Robert


#ifndef  STACK_AND_RPN_INCLUDE_TOKEN_H_
#define  STACK_AND_RPN_INCLUDE_TOKEN_H_

  struct Token {
    enum Type {
      kNumber,
      kSymbol,
      kEnd,
    };
    double number;
    char symbol;
    Type type;
    int prior;
    //  По умолчанию
    Token() : number(0), symbol(0), type(kEnd), prior(-1) {
    }
    //  Приоритет для Токена-знака
    Token(Type t, char c) : number(0), symbol(c), type(t) {
      switch (c) {
        case '(':prior = -1;
          break;

        case '+':prior = 1;
          break;

        case '-':prior = 1;
          break;

        case '*':prior = 2;
          break;

        case '/':prior = 2;
          break;

        default:prior = -1;
          break;
      }
    }

    explicit Token(Type t) : number(0), symbol(0), type(t), prior(-1) {
    }
  };

#endif  //  STACK_AND_RPN_INCLUDE_TOKEN_H_
