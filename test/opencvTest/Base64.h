#include <string>

std::string base64_encode(unsigned const char* str, unsigned int len);
std::string base64_decode(std::string const& s);

std::string UrlEncode(const std::string& str);
