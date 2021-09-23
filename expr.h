#pragma once

struct Expr {
  enum Type {
    Add,
    Sub,
    Mul,
    Div
  };
  
  Type type;
  int left;
  int right;
  int result;
  bool successed;
  
  Expr();
  
  std::string ToString() const;
  
  bool operator == (Expr const& e) const;
  
  static Expr MakeExprWithRandom();
};
