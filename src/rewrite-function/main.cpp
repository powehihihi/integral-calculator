#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

int main(int argc, char * argv[]) {
  if (argc==1) {
    std::cout << "You forgot to provide formula!" << std::endl;
    return -1;
  }
  if (argc>2)
    std::cout << "Usage: a b (eps) F(x)" << std::endl;

  std::ostringstream file_buf;
  std::ifstream in_file ("../src/integral/function.cpp");
  file_buf << in_file.rdbuf();
  in_file.close();
  std::string str = file_buf.str();
  
  std::string s_ret = "return ";

  size_t start = str.find(s_ret);
  size_t end = str.find(";", start);
  str.replace(start, end-start, s_ret.append(argv[1]));
  
  std::ofstream out_file("../src/integral/function.cpp");
  out_file << str;
  
  return 0;
}
