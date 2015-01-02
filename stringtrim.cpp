#include <algorithm>
#include <functional>
#include <cctype>
#include <locale>

static inline std::string &ltrim(std::string &s)
{
	s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
	
}