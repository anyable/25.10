#include <iostream>
bool isPyth(unsigned a, unsigned b, unsigned c){
  bool p = (a*a == b*b + c*c);
  p = p || (b*b == c*c + a*a);
  p = p || (c*c == a*a + b*b);
  return p; 
}
int main()
{
  using u_t = unsigned;
  u_t a, c, b;
  std::cin >> c >> b;
  size_t count = 0;
  while (std::cin >> a){
    count += isPyth(a, b, c) ? 1 : 0;
    c = b;
    b = a;
  }


  if (std::cin.eof()){
    std::cout << count << "/n";
  }
  else if (std::cin.fail()){
    std::cerr << "error\n";
    return 1; 
  }
}
