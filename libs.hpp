#ifndef HEADER_MAIN_DEFINED
#define HEADER_MAIN_DEFINED


#include <cstddef>
#include <utility>
#include <type_traits>
#include <limits>
#include <memory>
#include <initializer_list>
#include <functional>
#include <string>
#include <string_view>
#include <optional>
#include <variant>
#include <vector>
#include <map>
#include <sstream>
#include <iostream>
#include <fstream>


using std::byte;
using std::forward;
using std::decay_t;
using std::remove_reference;
using std::numeric_limits;
using std::unique_ptr;
using std::initializer_list;
using std::function;
using std::string;
using std::string_view;
using std::stringstream;
using std::optional;
using std::nullopt;
using std::variant;
using std::holds_alternative;
using std::visit;
using std::vector;
using std::map;
using std::ios_base;
using std::istream;
using std::ostream;
using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;


using namespace std::string_literals;


#include "ex.hpp"


#endif // HEADER_MAIN_DEFINED