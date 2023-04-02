#include <string>
#include <random>
#include <iostream>

#include "nlohmann/json.hpp"
#include "sa/genmain.h"
#include "sa/main.h"
#include "src/addition.h"

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
    "chapter": "Ch-2",
    "id": "C-9",
    "enabled": true,
    "title": "Addition: fill in the missing digits",
    "ask": "",
    "controller": "Maths::Addition-ThreeOrMoreMissing",
    "model": "SubjectsMultiinputs",
    "num_vars": 4,
    "op_types": [
      "+"
    ],
    "is_missing_digits": true,
    "is_missing_inputs": false,
    "min_digits": 1,
    "max_digits": 2
  }
  )");

  return 0;
}
