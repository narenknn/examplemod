#include <string>
#include <iostream>
#include <random>
#include <gtest/gtest.h>

#include "nlohmann/json.hpp"
#include "top/genmain.h"
#include "top/main.h"
#include "addition.h"

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

void
mathsc3c2sc8t1(nlohmann::json& confj, nlohmann::json& retj, bool debug)
{
}
TEST_F_WRAP(R"(
  {
    "class": "Class-3",
    "chapter": "Ch-2",
    "id": "C-8",
    "enabled": true,
    "title": "Addition patterns over increasing place values",
    "ask": "",
    "controller": "Maths::Addition-AdditionPatternIncreasingPlacevalues",
    "model": "SubjectsMultiinputs",
    "num_vars": 2,
    "num_steps": 3,
    "op_types": [
      "+"
    ],
    "min_digits": 1,
    "max_digits": 2
  }
)", AdditionTest, mathsc3c2sc8t1);

//void
//mathsc3c2sc9t1(nlohmann::json& confj, nlohmann::json& retj, bool debug)
//{
//}
//TEST_F_WRAP(R"(
//  {
//    "class": "Class-3",
//    "chapter": "Ch-2",
//    "id": "C-9",
//    "enabled": true,
//    "title": "Addition: fill in the missing digits",
//    "ask": "",
//    "controller": "Maths::Addition-ThreeOrMoreMissing",
//    "model": "SubjectsMultiinputs",
//    "num_vars": 4,
//    "op_types": [
//      "+"
//    ],
//    "is_missing_digits": true,
//    "is_missing_inputs": false,
//    "min_digits": 1,
//    "max_digits": 2
//  }
//)", AdditionTest, mathsc3c2sc9t1);

void
mathsc3c3sd6t1(nlohmann::json& confj, nlohmann::json& retj, bool debug)
{
}
TEST_F_WRAP(R"(
  {
    "class": "Class-3",
    "chapter": "Ch-3",
    "id": "D-6",
    "enabled": true,
    "title": "Subtraction patterns over increasing place values",
    "ask": "",
    "controller": "Maths::Addition-AdditionPatternIncreasingPlacevalues",
    "model": "SubjectsMultiinputs",
    "num_vars": 2,
    "num_steps": 3,
    "op_types": [
      "-"
    ],
    "min_digits": 1,
    "max_digits": 2,
    "no_negatives": true
  }
)", AdditionTest, mathsc3c3sd6t1);

//void
//mathsc3c3sd7t1(nlohmann::json& confj, nlohmann::json& retj, bool debug)
//{
//}
//TEST_F_WRAP(R"(
//  {
//    "class": "Class-3",
//    "chapter": "Ch-3",
//    "id": "D-7",
//    "enabled": true,
//    "title": "Subtraction: fill in the missing digits",
//    "ask": "",
//    "controller": "Maths::Addition-ThreeOrMoreMissing",
//    "model": "SubjectsMultiinputs",
//    "num_vars": 4,
//    "op_types": [
//      "-"
//    ],
//    "is_missing_digits": true,
//    "is_missing_inputs": false,
//    "min_digits": 1,
//    "max_digits": 2,
//    "no_negatives": true
//  }
//)", AdditionTest, mathsc3c3sd7t1);

void
mathsc3c4se1t1(nlohmann::json& confj, nlohmann::json& retj, bool debug)
{
}
TEST_F_WRAP(R"(
  {
    "class": "Class-3",
    "chapter": "Ch-4",
    "id": "E-1",
    "enabled": true,
    "title": "Count equal groups",
    "ask": "",
    "controller": "Maths::Addition-CountEqual",
    "model": "SubjectsMultiinputs",
    "op_types": [
      "*"
    ],
    "is": "CountEqualGroups",
    "min_digits": 1,
    "max_digits": 1
  }
)", AdditionMultiInputsTest, mathsc3c4se1t1);

void
mathsc3c4se2t1(nlohmann::json& confj, nlohmann::json& retj, bool debug)
{
}
TEST_F_WRAP(R"(
  {
    "class": "Class-3",
    "chapter": "Ch-4",
    "id": "E-2",
    "enabled": true,
    "title": "Identify multiplication expressions for equal groups",
    "ask": "",
    "controller": "Maths::Addition-IdentifyExprMseg",
    "model": "SubjectsMultiinputs",
    "op_types": [
      "*"
    ],
    "is": "multiplication-sentences-equal-groups",
    "min_digits": 1,
    "max_digits": 1
  }
)", AdditionBtnChoiceTest, mathsc3c4se2t1);

void
mathsc3c4se3t1(nlohmann::json& confj, nlohmann::json& retj, bool debug)
{
}
TEST_F_WRAP(R"(
  {
    "class": "Class-3",
    "chapter": "Ch-4",
    "id": "E-3",
    "enabled": true,
    "title": "Write multiplication sentences for equal groups",
    "ask": "",
    "controller": "Maths::Addition-CountEqual",
    "model": "SubjectsMultiinputs",
    "op_types": [
      "*"
    ],
    "is": "write-multiplication-sentences",
    "min_digits": 1,
    "max_digits": 1
  }
)", AdditionMultiInputsTest, mathsc3c4se3t1);

void
mathsc3c4se4t1(nlohmann::json& confj, nlohmann::json& retj, bool debug)
{
}
TEST_F_WRAP(R"(
  {
    "class": "Class-3",
    "chapter": "Ch-4",
    "id": "E-4",
    "enabled": true,
    "title": "Relate addition and multiplication for equal groups",
    "ask": "",
    "controller": "Maths::Addition-CountEqual",
    "model": "SubjectsMultiinputs",
    "op_types": [
      "*"
    ],
    "is": "relate-addition-multiplication",
    "min_digits": 1,
    "max_digits": 1
  }
)", AdditionMultiInputsTest, mathsc3c4se4t1);

void
mathsc3c4se5t1(nlohmann::json& confj, nlohmann::json& retj, bool debug)
{
}
TEST_F_WRAP(R"(
  {
    "class": "Class-3",
    "chapter": "Ch-4",
    "id": "E-5",
    "enabled": true,
    "title": "Identify multiplication expressions for arrays",
    "ask": "",
    "controller": "Maths::Addition-IdentifyExprMseg",
    "model": "SubjectsMultiinputs",
    "op_types": [
      "*"
    ],
    "is": "multiplication-expr-for-arrays",
    "min_digits": 1,
    "max_digits": 2
  }
)", AdditionBtnChoiceTest, mathsc3c4se5t1);

void
mathsc3c4se6t1(nlohmann::json& confj, nlohmann::json& retj, bool debug)
{
}
TEST_F_WRAP(R"(
  {
    "class": "Class-3",
    "chapter": "Ch-4",
    "id": "E-6",
    "enabled": true,
    "title": "Write multiplication sentences for arrays",
    "ask": "",
    "controller": "Maths::Addition-IdentifyExprMseg",
    "model": "SubjectsMultiinputs",
    "op_types": [
      "*"
    ],
    "is": "write-multiplication-expr-for-arrays",
    "min_digits": 1,
    "max_digits": 2
  }
)", AdditionMultiInputsTest, mathsc3c4se6t1);

void
mathsc3c4se7t1(nlohmann::json& confj, nlohmann::json& retj, bool debug)
{
}
TEST_F_WRAP(R"(
  {
    "class": "Class-3",
    "chapter": "Ch-4",
    "id": "E-7",
    "enabled": true,
    "title": "Make arrays to model multiplication",
    "ask": "",
    "controller": "Maths::Addition-ArraysModelMultiplication",
    "model": "SubjectsMultiinputs",
    "is": "arrays-model-multiplication",
    "op_types": [
      "*"
    ],
    "min_digits": 1,
    "max_digits": 1
  }
)", AdditionArraySelectTest, mathsc3c4se7t1);

void
mathsc3c4se8t1(nlohmann::json& confj, nlohmann::json& retj, bool debug)
{
}
TEST_F_WRAP(R"(
  {
    "class": "Class-3",
    "chapter": "Ch-4",
    "id": "E-8",
    "enabled": true,
    "title": "Write multiplication sentences for number lines",
    "ask": "",
    "controller": "Maths::Addition-MultiplicationSentenceForNumberLines",
    "model": "SubjectsMultiinputs",
    "is": "multiplication-sentence-number-lines",
    "op_types": [
      "add-from0"
    ],
    "min_digits": 1,
    "max_digits": 1
  }
)", AdditionMultiInputsTest, mathsc3c4se8t1);

void
mathsc3c5sf1t1(nlohmann::json& confj, nlohmann::json& retj, bool debug)
{
}
TEST_F_WRAP(R"(
  {
    "class": "Class-3",
    "chapter": "Ch-5",
    "id": "F-1",
    "enabled": true,
    "title": "Multiply by 0",
    "ask": "",
    "controller": "Maths::Addition-Tables",
    "model": "SubjectsMultiinputs",
    "is": "tables",
    "op_types": [
      "*"
    ],
    "table_for": [
      0
    ],
    "table_maxin": 10
  }
)", AdditionMultiInputsTest, mathsc3c5sf1t1);

void
mathsc3c5sf2t1(nlohmann::json& confj, nlohmann::json& retj, bool debug)
{
}
TEST_F_WRAP(R"(
  {
    "class": "Class-3",
    "chapter": "Ch-5",
    "id": "F-2",
    "enabled": true,
    "title": "Multiply by 1",
    "ask": "",
    "controller": "Maths::Addition-Tables",
    "model": "SubjectsMultiinputs",
    "is": "tables",
    "op_types": [
      "*"
    ],
    "table_for": [
      1
    ],
    "table_maxin": 10
  }
)", AdditionMultiInputsTest, mathsc3c5sf2t1);

void
mathsc3c5sf3t1(nlohmann::json& confj, nlohmann::json& retj, bool debug)
{
}
TEST_F_WRAP(R"(
  {
    "class": "Class-3",
    "chapter": "Ch-5",
    "id": "F-3",
    "enabled": true,
    "title": "Multiply by 2",
    "ask": "",
    "controller": "Maths::Addition-Tables",
    "model": "SubjectsMultiinputs",
    "is": "tables",
    "op_types": [
      "*"
    ],
    "table_for": [
      2
    ],
    "table_maxin": 10
  }
)", AdditionMultiInputsTest, mathsc3c5sf3t1);

void
mathsc3c5sf4t1(nlohmann::json& confj, nlohmann::json& retj, bool debug)
{
}
TEST_F_WRAP(R"(
  {
    "class": "Class-3",
    "chapter": "Ch-5",
    "id": "F-4",
    "enabled": true,
    "title": "Multiply by 3",
    "ask": "",
    "controller": "Maths::Addition-Tables",
    "model": "SubjectsMultiinputs",
    "is": "tables",
    "op_types": [
      "*"
    ],
    "table_for": [
      3
    ],
    "table_maxin": 10
  }
)", AdditionMultiInputsTest, mathsc3c5sf4t1);

void
mathsc3c5sf5t1(nlohmann::json& confj, nlohmann::json& retj, bool debug)
{
}
TEST_F_WRAP(R"(
  {
    "class": "Class-3",
    "chapter": "Ch-5",
    "id": "F-5",
    "enabled": true,
    "title": "Multiply by 4",
    "ask": "",
    "controller": "Maths::Addition-Tables",
    "model": "SubjectsMultiinputs",
    "is": "tables",
    "op_types": [
      "*"
    ],
    "table_for": [
      4
    ],
    "table_maxin": 10
  }
)", AdditionMultiInputsTest, mathsc3c5sf5t1);

void
mathsc3c5sf6t1(nlohmann::json& confj, nlohmann::json& retj, bool debug)
{
}
TEST_F_WRAP(R"(
  {
    "class": "Class-3",
    "chapter": "Ch-5",
    "id": "F-6",
    "enabled": true,
    "title": "Multiply by 5",
    "ask": "",
    "controller": "Maths::Addition-Tables",
    "model": "SubjectsMultiinputs",
    "is": "tables",
    "op_types": [
      "*"
    ],
    "table_for": [
      5
    ],
    "table_maxin": 10
  }
)", AdditionMultiInputsTest, mathsc3c5sf6t1);

void
mathsc3c5sf7t1(nlohmann::json& confj, nlohmann::json& retj, bool debug)
{
}
TEST_F_WRAP(R"(
  {
    "class": "Class-3",
    "chapter": "Ch-5",
    "id": "F-7",
    "enabled": true,
    "title": "Multiply by 6",
    "ask": "",
    "controller": "Maths::Addition-Tables",
    "model": "SubjectsMultiinputs",
    "is": "tables",
    "op_types": [
      "*"
    ],
    "table_for": [
      6
    ],
    "table_maxin": 10
  }
)", AdditionMultiInputsTest, mathsc3c5sf7t1);

void
mathsc3c5sf8t1(nlohmann::json& confj, nlohmann::json& retj, bool debug)
{
}
TEST_F_WRAP(R"(
  {
    "class": "Class-3",
    "chapter": "Ch-5",
    "id": "F-8",
    "enabled": true,
    "title": "Multiply by 7",
    "ask": "",
    "controller": "Maths::Addition-Tables",
    "model": "SubjectsMultiinputs",
    "is": "tables",
    "op_types": [
      "*"
    ],
    "table_for": [
      7
    ],
    "table_maxin": 10
  }
)", AdditionMultiInputsTest, mathsc3c5sf8t1);

void
mathsc3c5sf9t1(nlohmann::json& confj, nlohmann::json& retj, bool debug)
{
}
TEST_F_WRAP(R"(
  {
    "class": "Class-3",
    "chapter": "Ch-5",
    "id": "F-9",
    "enabled": true,
    "title": "Multiply by 8",
    "ask": "",
    "controller": "Maths::Addition-Tables",
    "model": "SubjectsMultiinputs",
    "is": "tables",
    "op_types": [
      "*"
    ],
    "table_for": [
      8
    ],
    "table_maxin": 10
  }
)", AdditionMultiInputsTest, mathsc3c5sf9t1);

void
mathsc3c5sf10t1(nlohmann::json& confj, nlohmann::json& retj, bool debug)
{
}
TEST_F_WRAP(R"(
  {
    "class": "Class-3",
    "chapter": "Ch-5",
    "id": "F-10",
    "enabled": true,
    "title": "Multiply by 9",
    "ask": "",
    "controller": "Maths::Addition-Tables",
    "model": "SubjectsMultiinputs",
    "is": "tables",
    "op_types": [
      "*"
    ],
    "table_for": [
      9
    ],
    "table_maxin": 10
  }
)", AdditionMultiInputsTest, mathsc3c5sf10t1);

void
mathsc3c5sf11t1(nlohmann::json& confj, nlohmann::json& retj, bool debug)
{
}
TEST_F_WRAP(R"(
  {
    "class": "Class-3",
    "chapter": "Ch-5",
    "id": "F-11",
    "enabled": true,
    "title": "Multiply by 10",
    "ask": "",
    "controller": "Maths::Addition-Tables",
    "model": "SubjectsMultiinputs",
    "is": "tables",
    "op_types": [
      "*"
    ],
    "table_for": [
      10
    ],
    "table_maxin": 10
  }
)", AdditionMultiInputsTest, mathsc3c5sf11t1);

void
mathsc3c6sg1t1(nlohmann::json& confj, nlohmann::json& retj, bool debug)
{
}
TEST_F_WRAP(R"(
  {
    "class": "Class-3",
    "chapter": "Ch-6",
    "id": "G-1",
    "enabled": true,
    "title": "Multiplication tables for 2, 3, 4, 5, 10",
    "ask": "",
    "controller": "Maths::Addition-Tables",
    "model": "SubjectsMultiinputs",
    "is": "tables",
    "op_types": [
      "*"
    ],
    "table_for": [
      2,
      3,
      4,
      5,
      10
    ],
    "table_maxin": 10
  }
)", AdditionMultiInputsTest, mathsc3c6sg1t1);

void
mathsc3c6sg2t1(nlohmann::json& confj, nlohmann::json& retj, bool debug)
{
}
TEST_F_WRAP(R"(
  {
    "class": "Class-3",
    "chapter": "Ch-6",
    "id": "G-2",
    "enabled": true,
    "title": "Multiplication facts for 2, 3, 4, 5, 10: true or false?",
    "ask": "",
    "controller": "Maths::Addition-Tables",
    "model": "SubjectsMultiinputs",
    "is": "tables-truefalse",
    "op_types": [
      "*"
    ],
    "table_for": [
      2,
      3,
      4,
      5,
      10
    ],
    "table_maxin": 10
  }
)", AdditionBtnChoiceTest, mathsc3c6sg2t1);

void
mathsc3c6sg4t1(nlohmann::json& confj, nlohmann::json& retj, bool debug)
{
}
TEST_F_WRAP(R"(
  {
    "class": "Class-3",
    "chapter": "Ch-6",
    "id": "G-4",
    "enabled": true,
    "title": "Multiplication tables for 6, 7, 8, 9",
    "ask": "",
    "controller": "Maths::Addition-Tables",
    "model": "SubjectsMultiinputs",
    "is": "tables",
    "op_types": [
                 "*"
                 ],
    "table_for": [
                  6,
                  7,
                  8,
                  9
                  ],
    "table_maxin": 10
  }
)", AdditionMultiInputsTest, mathsc3c6sg4t1);

void
mathsc3c6sg5t1(nlohmann::json& confj, nlohmann::json& retj, bool debug)
{
}
TEST_F_WRAP(R"(
  {
    "class": "Class-3",
    "chapter": "Ch-6",
    "id": "G-5",
    "enabled": true,
    "title": "Multiplication facts for 6, 7, 8, 9: true or false?",
    "ask": "",
    "controller": "Maths::Addition-Tables",
    "model": "SubjectsMultiinputs",
    "is": "tables-truefalse",
    "op_types": [
                 "*"
                 ],
    "table_for": [
                  6,
                  7,
                  8,
                  9
                  ],
    "table_maxin": 10
  }
)", AdditionBtnChoiceTest, mathsc3c6sg5t1);

void
mathsc3c6sg7t1(nlohmann::json& confj, nlohmann::json& retj, bool debug)
{
}
TEST_F_WRAP(R"(
  {
    "class": "Class-3",
    "chapter": "Ch-6",
    "id": "G-7",
    "enabled": true,
    "title": "Multiplication tables up to 10",
    "ask": "",
    "controller": "Maths::Addition-Tables",
    "model": "SubjectsMultiinputs",
    "is": "tables",
    "op_types": [
      "*"
    ],
    "table_for": [
      1,
      2,
      3,
      4,
      5,
      6,
      7,
      8,
      9,
      10
    ],
    "table_maxin": 10
  }
)", AdditionMultiInputsTest, mathsc3c6sg7t1);

void
mathsc3c6sg8t1(nlohmann::json& confj, nlohmann::json& retj, bool debug)
{
}
TEST_F_WRAP(R"(
  {
    "class": "Class-3",
    "chapter": "Ch-6",
    "id": "G-8",
    "enabled": true,
    "title": "Multiplication facts up to 10: true or false?",
    "ask": "",
    "controller": "Maths::Addition-Tables",
    "model": "SubjectsMultiinputs",
    "is": "tables-truefalse",
    "op_types": [
      "*"
    ],
    "table_for": [
      1,
      2,
      3,
      4,
      5,
      6,
      7,
      8,
      9,
      10
    ],
    "table_maxin": 10
  }
)", AdditionBtnChoiceTest, mathsc3c6sg8t1);

//void
//mathsc3c6sg11t1(nlohmann::json& confj, nlohmann::json& retj, bool debug)
//{
//}
//TEST_F_WRAP(R"(
//  {
//    "class": "Class-3",
//    "chapter": "Ch-6",
//    "id": "G-11",
//    "enabled": true,
//    "title": "Multiplication facts up to 10: find the missing factor",
//    "ask": "",
//    "controller": "Maths::Addition-ThreeOrMoreMissing",
//    "model": "SubjectsMultiinputs",
//    "num_vars": 4,
//    "op_types": [
//      "*"
//    ],
//    "is_missing_digits": true,
//    "is_missing_inputs": false,
//    "min_digits": 1,
//    "max_digits": 1
//  }
//)", AdditionTest, mathsc3c6sg11t1);

void
mathsc3c9j1t1(nlohmann::json& confj, nlohmann::json& retj, bool debug)
{
}
TEST_F_WRAP(R"(
  {
    "class": "Class-3",
    "chapter": "Ch-9",
    "id": "J-1",
    "enabled": true,
    "title": "Divide by 1",
    "ask": "",
    "controller": "Maths::Addition-Tables",
    "model": "SubjectsMultiinputs",
    "is": "tables",
    "op_types": [
      "/"
    ],
    "table_for": [
      1
    ],
    "table_maxin": 10
  }
)", AdditionMultiInputsTest, mathsc3c9j1t1);

void
mathsc3c9j2t1(nlohmann::json& confj, nlohmann::json& retj, bool debug)
{
}
TEST_F_WRAP(R"(
  {
    "class": "Class-3",
    "chapter": "Ch-9",
    "id": "J-2",
    "enabled": true,
    "title": "Divide by 2",
    "ask": "",
    "controller": "Maths::Addition-Tables",
    "model": "SubjectsMultiinputs",
    "is": "tables",
    "op_types": [
      "/"
    ],
    "table_for": [
      2
    ],
    "table_maxin": 10
  }
)", AdditionMultiInputsTest, mathsc3c9j2t1);

void
mathsc3c9j3t1(nlohmann::json& confj, nlohmann::json& retj, bool debug)
{
}
TEST_F_WRAP(R"(
  {
    "class": "Class-3",
    "chapter": "Ch-9",
    "id": "J-3",
    "enabled": true,
    "title": "Divide by 3",
    "ask": "",
    "controller": "Maths::Addition-Tables",
    "model": "SubjectsMultiinputs",
    "is": "tables",
    "op_types": [
      "/"
    ],
    "table_for": [
      3
    ],
    "table_maxin": 10
  }
)", AdditionMultiInputsTest, mathsc3c9j3t1);

void
mathsc3c9j4t1(nlohmann::json& confj, nlohmann::json& retj, bool debug)
{
}
TEST_F_WRAP(R"(
  {
    "class": "Class-3",
    "chapter": "Ch-9",
    "id": "J-4",
    "enabled": true,
    "title": "Divide by 4",
    "ask": "",
    "controller": "Maths::Addition-Tables",
    "model": "SubjectsMultiinputs",
    "is": "tables",
    "op_types": [
      "/"
    ],
    "table_for": [
      4
    ],
    "table_maxin": 10
  }
)", AdditionMultiInputsTest, mathsc3c9j4t1);

void
mathsc3c9j5t1(nlohmann::json& confj, nlohmann::json& retj, bool debug)
{
}
TEST_F_WRAP(R"(
  {
    "class": "Class-3",
    "chapter": "Ch-9",
    "id": "J-5",
    "enabled": true,
    "title": "Divide by 5",
    "ask": "",
    "controller": "Maths::Addition-Tables",
    "model": "SubjectsMultiinputs",
    "is": "tables",
    "op_types": [
      "/"
    ],
    "table_for": [
      5
    ],
    "table_maxin": 10
  }
)", AdditionMultiInputsTest, mathsc3c9j5t1);

void
mathsc3c9j6t1(nlohmann::json& confj, nlohmann::json& retj, bool debug)
{
}
TEST_F_WRAP(R"(
  {
    "class": "Class-3",
    "chapter": "Ch-9",
    "id": "J-6",
    "enabled": true,
    "title": "Divide by 6",
    "ask": "",
    "controller": "Maths::Addition-Tables",
    "model": "SubjectsMultiinputs",
    "is": "tables",
    "op_types": [
      "/"
    ],
    "table_for": [
      6
    ],
    "table_maxin": 10
  }
)", AdditionMultiInputsTest, mathsc3c9j6t1);

void
mathsc3c9j7t1(nlohmann::json& confj, nlohmann::json& retj, bool debug)
{
}
TEST_F_WRAP(R"(
  {
    "class": "Class-3",
    "chapter": "Ch-9",
    "id": "J-7",
    "enabled": true,
    "title": "Divide by 7",
    "ask": "",
    "controller": "Maths::Addition-Tables",
    "model": "SubjectsMultiinputs",
    "is": "tables",
    "op_types": [
      "/"
    ],
    "table_for": [
      7
    ],
    "table_maxin": 10
  }
)", AdditionMultiInputsTest, mathsc3c9j7t1);

void
mathsc3c9j8t1(nlohmann::json& confj, nlohmann::json& retj, bool debug)
{
}
TEST_F_WRAP(R"(
  {
    "class": "Class-3",
    "chapter": "Ch-9",
    "id": "J-8",
    "enabled": true,
    "title": "Divide by 8",
    "ask": "",
    "controller": "Maths::Addition-Tables",
    "model": "SubjectsMultiinputs",
    "is": "tables",
    "op_types": [
      "/"
    ],
    "table_for": [
      8
    ],
    "table_maxin": 10
  }
)", AdditionMultiInputsTest, mathsc3c9j8t1);

void
mathsc3c9j9t1(nlohmann::json& confj, nlohmann::json& retj, bool debug)
{
}
TEST_F_WRAP(R"(
  {
    "class": "Class-3",
    "chapter": "Ch-9",
    "id": "J-9",
    "enabled": true,
    "title": "Divide by 9",
    "ask": "",
    "controller": "Maths::Addition-Tables",
    "model": "SubjectsMultiinputs",
    "is": "tables",
    "op_types": [
      "/"
    ],
    "table_for": [
      9
    ],
    "table_maxin": 10
  }
)", AdditionMultiInputsTest, mathsc3c9j9t1);

void
mathsc3c9j10t1(nlohmann::json& confj, nlohmann::json& retj, bool debug)
{
}
TEST_F_WRAP(R"(
  {
    "class": "Class-3",
    "chapter": "Ch-9",
    "id": "J-10",
    "enabled": true,
    "title": "Divide by 10",
    "ask": "",
    "controller": "Maths::Addition-Tables",
    "model": "SubjectsMultiinputs",
    "is": "tables",
    "op_types": [
      "/"
    ],
    "table_for": [
      10
    ],
    "table_maxin": 10
  }
)", AdditionMultiInputsTest, mathsc3c9j10t1);
