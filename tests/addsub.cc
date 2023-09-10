#include <string>
#include <iostream>
#include <random>
#include <gtest/gtest.h>

#include "nlohmann/json.hpp"
#include "top/genmain.h"
#include "top/main.h"
#include "addsub.h"

void
mathsc3_c2_sc6_t1(nlohmann::json& confj, nlohmann::json& retj, bool debug)
{
}
TEST_F_WRAP(R"(
  {
    "class": "Class-3",
    "chapter": "Ch-0",
    "id": "A-2",
    "enabled": true,
    "title": "Even or odd: arithmetic rules",
    "ask": "Identify result of arithmetic operation is even or odd",
    "controller": "MathsU1AddSub::XYZ-SelectsEvenodd",
    "view": "",
    "test": "BtnChoiceViewTest",
    "qtypes": [
      "yesno-arithmetic"
    ],
    "op_types": [
      "+",
      "-"
    ],
    "min_digits": 1,
    "max_digits": 2,
    "ans_optional": false
  }
)", XyzController1YesNoTest, mathsc3_c2_sc6_t1);
