#include <string>
#include <random>
#include <iostream>
#include <time.h>

#include "nlohmann/json.hpp"
#include "sa/genmain.h"
#include "sa/main.h"

extern std::string
genmain(std::string s_config);

extern std::string
checkmain(std::string s_config, std::string ques, std::string ans);

void
run(const std::string conf, uint32_t count=1, uint32_t seed=time(NULL))
{
  /* should be a json */
  for (auto ui=0; ui<count; ui++, seed++) {
    auto confj = nlohmann::json::parse(conf);
    confj["seed"] = seed;
    std::string ret1 = genmain(confj.dump());
    std::cout << ui << ": question(" << confj["seed"].get<uint32_t>() << ")" << ret1 << std::endl;
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
    "controller": "MathsU1AddSub::XYZ-SelectsEvenodd",
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
  )", 10, 1);

  return 0;
}
