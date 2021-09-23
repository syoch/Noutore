#include "common.h"
#include "utils.h"
#include "expr.h"

Expr::Expr()
  :   type(Add),
    left(0),
    right(0),
    result(0),
    successed(false)
{
}

std::string Expr::ToString() const {
  auto op = ((char const* []){
    " + ",
    " - ",
    " * ",
    " / "
  })[static_cast<int>(this->type)];
  
  return std::to_string(left) + op + std::to_string(right);
}

bool Expr::operator == (Expr const& e) const {
  return type == e.type && left == e.left && right == e.right;
}

Expr Expr::MakeExprWithRandom() {
  Expr expr;
  expr.type = static_cast<Expr::Type>(randrange(0, 4));
  
  while( 1 ) {
    expr.left = randrange(1, 10);
    expr.right = randrange(1, 10);
    
    expr.result = [] (Expr const& e) -> int {
      switch( e.type ) {
        case Expr::Add:
          return e.left + e.right;
        
        case Expr::Sub:
          return e.left - e.right;
        
        case Expr::Mul:
          return e.left * e.right;
        
        case Expr::Div:
          return e.left / e.right;
      }
    } (expr);
    
    if( expr.type == Expr::Div ) {
      if( expr.left % expr.right != 0 )
        continue;
      
      if( expr.left < expr.right )
        continue;
    }
    
    if( expr.result < 0 || expr.result > 10 )
      continue;
  
    break;
  }
  
  return expr;
}