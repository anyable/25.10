#include <iostream>
#include <limits>

using u_t = unsigned;
u_t max_u() {
  using namespace std;
  using u_limit = numeric_limits< u_t >;
  return u_limit::max();
}

u_t add(u_t a, u_t b) {
  if (a > max_u() - b) {
    return 0;
  }
  return a + b;
}

bool isAddErr(u_t s, u_t a, u_t b) {
  return !s && (a || b);
}



bool isPyth(unsigned a, unsigned b, unsigned c){
  bool t = isAddErr(add(b*b, b*b), b, c);
  t = t && isAddErr(add(a*a, b*b), a, b);
  t = t && isAddErr(add(c*c, a*a), c, a);
  if (!t){
    return 0;
  }
  bool p = (a*a == b*b + c*c);
  p = p || (b*b == c*c + a*a);
  p = p || (c*c == a*a + b*b);
  return p; 
}

int main()
{
  u_t a, c, b;
  std::cin >> c >> b;
  size_t count = 0;
  while (std::cin >> a){
    u_t Pyth = isPyth(a, b, c) ? 1 : 0;
    if (isAddErr(add(count, Pyth), count, Pyth)){
      count += Pyth;
      c = b;
      b = a;
    }
    
  }


  if (std::cin.eof()){
    std::cout << count << "\n";
  }
  else if (std::cin.fail()){
    std::cerr << "error\n";
    return 1; 
  }


  
}
