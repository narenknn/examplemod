#include <string>
#include <iostream>
#include <random>
#include <gtest/gtest.h>

#include "nlohmann/json.hpp"
#include "top/genmain.h"
#include "top/main.h"
#include "xyz.h"

void
mathsc3c2sc6t1(nlohmann::json& confj, nlohmann::json& retj, bool debug)
{
}
TEST_F_WRAP(R"(
  {
    "class": "Class-3",
    "chapter": "Ch-2",
    "id": "C-6",
    "enabled": true,
    "title": "Add three or more numbers up to two digits each",
    "ask": "",
    "controller": "Maths::Addition-ThreeOrMoreMissing",
    "model": "SubjectsMultiinputs",
    "num_vars": 2,
    "op_types": [
      "+"
    ],
    "is_missing_digits": false,
    "is_missing_inputs": false,
    "min_digits": 1,
    "max_digits": 2
  }
)", AdditionTest, mathsc3c2sc6t1);
