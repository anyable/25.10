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
    using std::overflow_error;
    throw 
      overflow_error("add");
  }
  return a + b;
}

u_t multi(u_t a) {
  if (a > max_u() / a) {
    using std::overflow_error;
    throw 
      overflow_error("multy");
  }
  return a * a;
}

bool isPyth(unsigned a, unsigned b, unsigned c){
  u_t aa = multi(a);
  u_t bb = multi(b);
  u_t cc = multi(c);
  bool p = (aa == add(bb, cc));
  p = p || (bb == add(cc, aa));
  p = p || (cc == add(aa, bb));
  return p; 
}
int main()
{
  u_t a, b, c;
  std::cin >> c >> b;
  size_t count = 0;
  try{
  while (std::cin >> a){
    u_t Pyth = isPyth(a, b, c) ? 1 : 0;
    count = add(count, Pyth);
    c = b;
    b = a;
  }
  } catch(...){
    std::cerr << "error too match\n";
    return 2;
  }
  if (std::cin.eof()){
    std::cout << count << "\n";
  }
  else if (std::cin.fail()){
    std::cerr << "error\n";
    return 1; 
  }
}
