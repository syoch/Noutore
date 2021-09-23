#include <algorithm>
#include <iostream>
#include "common.h"
#include "utils.h"
#include "expr.h"

#define clear std::system("clear")

static constexpr int LEVEL_MIN = 1;
static constexpr int LEVEL_MAX = 100;

int main() {
  int level = input_int("input level your like");
  int count = input_int("how many do you solve formula?");
  std::vector<Expr> expr_vec;
  
  srand((unsigned)time(NULL));
  clear;
  
  for( int i = -level; i < count; i++ ) {
    if( expr_vec.size() < count ) {
      Expr expr;
      
      do {
        expr = Expr::MakeExprWithRandom();
      } while( std::count(expr_vec.begin(), expr_vec.end(), expr) );
      
      std::cout
        << i + level + 1 << std::endl
        << expr.ToString() << std::endl;

      expr_vec.emplace_back(expr);
    }
    else {
      level--;
    }
    
    if( expr_vec.size() <= level ) {
      input("press enter...");
      clear;
      continue;
    }
    
    auto num = input_int("input a result of " + (level ? format("before %d last:", level) : "last:"));
    auto& expr = expr_vec[i];

    clear;
    expr.successed = num == expr.result;
    
    if( expr.successed ) {
      std::cout << "great!\n";
    }
    else {
      std::cout << "no.\n";
    }
  }

  int success_count = 0;

  std::cout
    << "\n"
    << "all expressions you solved:\n";

  for( int i = 0; i < expr_vec.size(); i++ ) {
    auto const& expr = expr_vec[i];

    std::cout << format("%3d| ", i + 1) << expr.ToString() << "\t: " << (expr.successed ? "Ok" : "no") << std::endl;
    success_count++;
  }

  std::cout
    << "\n"
    << "You successed to solve " << success_count << " formulas.\n";
}