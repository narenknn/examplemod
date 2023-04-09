#include <string>
#include <random>
#include <iostream>

#include "nlohmann/json.hpp"
#include "sa/genmain.h"
#include "sa/main.h"

extern std::string
genmain(std::string s_config);

extern std::string
checkmain(std::string s_config, std::string ques, std::string ans);

void
run(const std::string conf)
{
  /* should be a json */
  for (auto i=1; i; i--) {
    auto confj = nlohmann::json::parse(conf);
    std::string ret1 = genmain(conf);
    std::cout << "question: " << ret1 << std::endl;
    // std::string ret2 = checkmain(conf, ret1, "{\"ans\": [[null,null,null,null],[null,null,null,null],[\"\",\"1\",\"3\",\"6\"]]}");
    // std::cout << "result: " << ret2 << std::endl;
  }
}

int
main(int argc, char **argv)
{
  run(R"(
  {
    "class": "Class-3",
    "chapter": "Ch-0",
    "id": "A-2",
    "enabled": true,
    "title": "Even or odd: arithmetic rules",
    "ask": "Identify result of arithmetic operation is even or odd",
    "controller": "MathsU1::XYZ-SelectsEvenodd",
    "model": "",
    "view": "BtnChoiceViewTest",
    "qtypes": [
      "yesno-arithmetic"
    ],
    "op_types": [
      "+",
      "-"
    ],
    "min_digits": 1,
    "max_digits": 2
  }
  )");

  return 0;
}
