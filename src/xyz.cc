#include <random>
#include <sstream>
#include "nlohmann/json.hpp"
#ifdef SABUILD
#include "sa/genmain.h"
#else
# ifdef WASMBUILD
  #include "src/genmain.h"
# else
  #include "top/genmain.h"
# endif
#endif
#include "xyz.h"

namespace MathsU1 {

  class SelectsEvenodd : public Controller {
  public:
    void gen(nlohmann::json& ret, std::shared_ptr<RandGenerator> rand, nlohmann::json& config);
    void check(nlohmann::json& ret, nlohmann::json& config, nlohmann::json& question, nlohmann::json& ans);
  };

}

MathsU1::XYZ::XYZ():
  ::GenMod(__CLASS_NAME__)
{
  controllers.emplace("SelectsEvenodd", std::make_unique<SelectsEvenodd>());
}

void
MathsU1::SelectsEvenodd::gen(nlohmann::json& ret, std::shared_ptr<RandGenerator> rand, nlohmann::json& config)
{
  /* choose op */
  std::string op;
  do {
    auto i = rand->get() % config["op_types"].size();
    op = config["op_types"][i].get<std::string>();
  } while (false);

  auto min_digits = config["min_digits"].get<uint32_t>();
  auto max_digits = config["max_digits"].get<uint32_t>();

  auto _op1 = rand->get_digits(min_digits, max_digits);
  auto _op2 = rand->get_digits(min_digits, max_digits);
  auto op1 = (_op1 > _op2) ? _op1 : _op2;
  auto op2 = (op1 == _op1) ? _op2 : _op1;
  auto op1IsEven = (op1 & 1) ? false : true;
  auto op2IsEven = (op2 & 1) ? false : true;
  bool resultIsEven = false;
  
  /* compute result */
  if (op == "+") {
    resultIsEven = (op1IsEven == op2IsEven) ? true : false;
  } else if (op == "-") {
    resultIsEven = (op1IsEven == op2IsEven) ? true : false;
  }

  /* populate ret with the question */
  ret["text"] = std::to_string(op1) + op + std::to_string(op2);
  ret["btnchoice"] = nlohmann::json::array();
  ret["btnchoice"].push_back("Even");
  ret["btnchoice"].push_back("Odd");
  ret["correct_ans"] = nlohmann::json::array();
  ret["correct_ans"].push_back(resultIsEven ? 0 : 1);
}

void
MathsU1::SelectsEvenodd::check(nlohmann::json& ret, nlohmann::json& config, nlohmann::json& question, nlohmann::json& ans)
{
  ret["result"] = false;

  /* check if the user has entered correct answer by inspecting ans
     if any check fails, simply return
   */
  if (true) return; /* cause a failure */

  /* all checks passed... */
  ret["result"] = true;
}

/* create object */
namespace MathsU1 {
  XYZ xyz{};
}
