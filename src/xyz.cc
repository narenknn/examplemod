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
#include "addition.h"

void
Maths::check_multiarray(nlohmann::json& ret, nlohmann::json& config, nlohmann::json& q, nlohmann::json& ans)
{
  ret["result"] = true;
  for(auto i = q["correct_ans"].size(); i; i--) {
    for(auto j = q["correct_ans"][i-1].size(); j; j--) {
      if (! q["correct_ans"][i-1][j-1].is_null())
        if (q["correct_ans"][i-1][j-1].get<std::string>() != ans["ans"][i-1][j-1].get<std::string>())
          ret["result"] = false;
    }
  }
}

namespace Maths {

  class ThreeOrMoreMissing : public Controller {
  public:
    void gen(nlohmann::json& ret, std::shared_ptr<RandGenerator> rand, nlohmann::json& config);
    void check(nlohmann::json& ret, nlohmann::json& config, nlohmann::json& question, nlohmann::json& ans) { return check_multiarray(ret, config, question, ans); }
  };

  class MultiplicationSentenceForNumberLines : public Controller {
  public:
    void gen(nlohmann::json& ret, std::shared_ptr<RandGenerator> rand, nlohmann::json& config);
    void check(nlohmann::json& ret, nlohmann::json& config, nlohmann::json& question, nlohmann::json& ans) { return check_multiarray(ret, config, question, ans); }
  };

  class ArraysModelMultiplication : public Controller {
  public:
    void gen(nlohmann::json& ret, std::shared_ptr<RandGenerator> rand, nlohmann::json& config);
    void check(nlohmann::json& ret, nlohmann::json& config, nlohmann::json& question, nlohmann::json& ans);
  };

  class CountEqual : public Controller {
  public:
    void gen(nlohmann::json& ret, std::shared_ptr<RandGenerator> rand, nlohmann::json& config);
    void check(nlohmann::json& ret, nlohmann::json& config, nlohmann::json& question, nlohmann::json& ans) { return check_multiarray(ret, config, question, ans); }
  };

  class IdentifyExprMseg : public Controller {
  public:
    void gen(nlohmann::json& ret, std::shared_ptr<RandGenerator> rand, nlohmann::json& config);
    void check(nlohmann::json& ret, nlohmann::json& config, nlohmann::json& question, nlohmann::json& ans) { return check_multiarray(ret, config, question, ans); }
  };

  class Tables : public Controller {
  public:
    void gen(nlohmann::json& ret, std::shared_ptr<RandGenerator> rand, nlohmann::json& config);
    void check(nlohmann::json& ret, nlohmann::json& config, nlohmann::json& question, nlohmann::json& ans) { return check_multiarray(ret, config, question, ans); }
  };

  class AdditionPatternIncreasingPlacevalues : public Controller {
  public:
    void gen(nlohmann::json& ret, std::shared_ptr<RandGenerator> rand, nlohmann::json& config);
    void check(nlohmann::json& ret, nlohmann::json& config, nlohmann::json& question, nlohmann::json& ans) { return check_multiarray(ret, config, question, ans); }
  };

  class DragGroup : public Controller {
  public:
    void gen(nlohmann::json& ret, std::shared_ptr<RandGenerator> rand, nlohmann::json& config);
    void check(nlohmann::json& ret, nlohmann::json& config, nlohmann::json& question, nlohmann::json& ans) { return check_multiarray(ret, config, question, ans); }
  };

}

Maths::Addition::Addition():
  GenMod(__CLASS_NAME__)
{
  controllers.emplace("ThreeOrMoreMissing", std::make_unique<ThreeOrMoreMissing>());
  controllers.emplace("MultiplicationSentenceForNumberLines", std::make_unique<MultiplicationSentenceForNumberLines>());
  controllers.emplace("ArraysModelMultiplication", std::make_unique<ArraysModelMultiplication>());
  controllers.emplace("CountEqual", std::make_unique<CountEqual>());
  controllers.emplace("IdentifyExprMseg", std::make_unique<IdentifyExprMseg>());
  controllers.emplace("Tables", std::make_unique<Tables>());
  controllers.emplace("AdditionPatternIncreasingPlacevalues", std::make_unique<AdditionPatternIncreasingPlacevalues>());
  controllers.emplace("DragGroup", std::make_unique<DragGroup>());
}

void
Maths::ThreeOrMoreMissing::gen(nlohmann::json& ret, std::shared_ptr<RandGenerator> rand, nlohmann::json& config)
{
  bool is_missing_digits = config["is_missing_digits"].get<bool>();
  bool is_missing_inputs = config["is_missing_inputs"].get<bool>();
  is_missing_digits = false, is_missing_inputs = false;

  /* choose op */
  std::string op;
  do {
    auto i = rand->get() % config["op_types"].size();
    op = config["op_types"][i].get<std::string>();
  } while (false);

  /* static conf */
  ret["text"] = std::string("Complete the <b>") + ((op == "+") ? "Addition" : (("*" == op) ? "Multiplication" : "Subtraction")) + "</b> table:";
  ret["inboxwidth"] = "50px";

  /* first generate the values */
  auto num_vars = config.contains("num_vars") ?
    config["num_vars"].get<uint32_t>() : rand->get_range(3, 6);
  auto vars = std::vector<uint32_t>();
  auto svars = std::vector<std::string>();
  auto min_digits = config["min_digits"].get<uint32_t>();
  auto max_digits = config["max_digits"].get<uint32_t>();
  auto cols = 0;
  uint32_t ca = 0, cm = 1;
  for (auto i=0; i<num_vars-1; i++) {
    vars.emplace_back(rand->get_digits(min_digits, max_digits));
    ca += vars.back();
    cm *= vars.back();
    svars.emplace_back(std::to_string(vars[i]));
    cols = svars[i].length() > cols ? svars[i].length() : cols;
  }
  do {
    auto d = rand->get_digits(min_digits, max_digits);
    if (op == "+") {
      vars.emplace_back(d);
      ca += d;
      svars.emplace_back(std::to_string(d));
      cols = svars.back().length() > cols ? svars.back().length() : cols;
    } else if (op == "*") {
      vars.emplace_back(d);
      ca = cm * d;
      svars.emplace_back(std::to_string(d));
      cols = svars.back().length() > cols ? svars.back().length() : cols;
    } else /* op == "-" */ {
      vars.insert(vars.begin(), d+ca);
      svars.insert(svars.begin(), std::to_string(d+ca));
      cols = svars[0].length() > cols ? svars[0].length() : cols;
      ca = d;
    }
  } while (false);
  auto sca = std::to_string(ca);
  cols = sca.length() > cols ? sca.length() : cols;
  cols++;

  /* first push null to all locations */
  ret["th"] = nlohmann::json::array();
  ret["htabledata"] = nlohmann::json::array();
  ret["correct_ans"] = nlohmann::json::array();
  for (auto j = 0; j<cols; j++) {
    ret["th"][j] = nullptr;
  }
  const uint32_t user_input_row = rand->get_range(0, num_vars);
  for (auto i=0; i<=num_vars; i++) {
    ret["htabledata"].push_back(nlohmann::json::array());
    ret["correct_ans"].push_back(nlohmann::json::array());
    for (auto j=0; j<cols; j++) {
      bool is_user_input = is_missing_digits ? ((0 == j) ? true : rand->get()&1) : true;
      ret["htabledata"][i][j] =
        (is_user_input && (i >= num_vars)) ? "_" :
        ((!is_user_input) && (i >= num_vars)) ?
        ((j < (cols-sca.length())) ? "" : sca.substr(sca.length()+j-cols, 1)) :
        (j < (cols-svars[i].length())) ?
        ( (i != 0) && (0 == j) ? op : "" ) :
        svars[i].substr(svars[i].length()+j-cols, 1);
      if (is_missing_inputs) {
        if (user_input_row == i) {
          ret["htabledata"][i][j] = "_";
          ret["correct_ans"][i][j] = ((cols-j) > sca.length()) ? "" : sca.substr(sca.length()+j-cols, 1);
        } else {
          ret["htabledata"][i][j] = (i >= num_vars);
          ret["correct_ans"][i][j] = nullptr;
        }
      } else if (i < svars.size()) {
        ret["correct_ans"][i][j] = nullptr;
      } else {
        if (is_user_input)
          ret["correct_ans"][i][j] = ((cols-j) > sca.length()) ? "" : sca.substr(sca.length()+j-cols, 1);
        else
          ret["correct_ans"][i][j] = "";
      }
    }
  }
}

void
Maths::MultiplicationSentenceForNumberLines::gen(nlohmann::json& ret, std::shared_ptr<RandGenerator> rand, nlohmann::json& config)
{
  /* choose op */
  std::string op;
  do {
    auto i = rand->get() % config["op_types"].size();
    op = config["op_types"][i].get<std::string>();
  } while (false);
  bool add_from0 {op == "add-from0"};

  /* */
  auto min_digits = config["min_digits"].get<uint32_t>();
  auto max_digits = config["max_digits"].get<uint32_t>();

  auto op1 = rand->get_digits(min_digits, max_digits) + 1; /* distance */
  auto op2 = rand->get_digits(min_digits, max_digits) + 1; /* num-seq */
  auto op3 = op2;
  auto start = add_from0 ? 0 : rand->get_digits(min_digits, max_digits);
  op3 = ((op3+10)/10)*10 + 1; /* make is to next 10 */

  /* question */
  auto op1_blank = (rand->get() & 1) ? true : false;
  auto ans_blank = (rand->get() & 1) ? true : false;
  ret["text"] = "Complete the multiplication sentence that describes the model:";
  ret["multiinput"] = nlohmann::json::array();
  ret["multiinput"][0] = nlohmann::json::array();
  ret["correct_ans"] = nlohmann::json::array();
  ret["correct_ans"][0] = nlohmann::json::array();
  ret["multiinput"][0].push_back(op1_blank ? "_" : std::to_string(op1));
  if (op1_blank) ret["correct_ans"][0].push_back(std::to_string(op1));
  else ret["correct_ans"][0].push_back(nullptr);
  ret["multiinput"][0].push_back(" &times; ");
  ret["correct_ans"][0].push_back(nullptr);
  ret["multiinput"][0].push_back(op1_blank ? std::to_string(op2) : "_");
  if (!op1_blank) ret["correct_ans"][0].push_back(std::to_string(op2));
  else ret["correct_ans"][0].push_back(nullptr);
  ret["multiinput"][0].push_back(" = ");
  ret["correct_ans"][0].push_back(nullptr);
  ret["multiinput"][0].push_back(ans_blank ? "_" : std::to_string(op1*op2));
  if (ans_blank) ret["correct_ans"][0].push_back(std::to_string(op1*op2));
  else ret["correct_ans"][0].push_back(nullptr);

  /* fill others */
  ret["status_answer"] = "null";
  ret["controller"] = "SiteMathSimpleSequence";
  ret["datastr"] = nlohmann::json::object();
  ret["datastr"]["height"] = 100;
  ret["datastr"]["width"] = 450;

  /* make the sequence */
  ret["datastr"]["sequences"] = nlohmann::json::array();
  ret["datastr"]["sequences"].push_back(nlohmann::json::object());
  ret["datastr"]["sequences"][0]["values"] = nlohmann::json::array();
  ret["datastr"]["sequences"][0]["arcs"] = nlohmann::json::array();
  do {
    auto i = rand->get() % Genmain::htmlColors.size();
    ret["datastr"]["sequences"][0]["color"] = Genmain::htmlColors[i];
  } while (false);
  for (auto i3=0; i3<op3; i3++) {
    ret["datastr"]["sequences"][0]["values"].push_back(i3*op1);
    ret["datastr"]["sequences"][0]["arcs"].push_back(bool((i3>=0) && ((i3*op1)<(op1*op2))));
  }
}

void
Maths::ArraysModelMultiplication::gen(nlohmann::json& ret, std::shared_ptr<RandGenerator> rand, nlohmann::json& config)
{
  /* init */
  auto min_digits = config["min_digits"].get<uint32_t>();
  auto max_digits = config["max_digits"].get<uint32_t>();

  auto op1 = rand->get_digits(min_digits, max_digits) + 1; /* no 0's */
  auto op2 = rand->get_digits(min_digits, max_digits) + 1; /* no 0's */
  auto ans = op1 * op2;

  ret["text"] = "Make rectangular array of squares to model : <b> " + std::to_string(op1) + " &times; " + std::to_string(op2) + " = " + std::to_string(ans) + " </b>";
  ret["datastr"] = nlohmann::json::object();
  ret["datastr"]["size"] = 15;
  ret["status_answer"] = nlohmann::json::array();
  for (auto i=15; i; i--)
    for (auto j=15; j; j--)
      ret["status_answer"].push_back(bool((i<=op1) && (j<=op2)));
  ret["op1"] = op1;
  ret["op2"] = op2;
  ret["ans"] = ans;
  ret["controller"] = "SiteMathArraySelect";
}

void
Maths::ArraysModelMultiplication::check(nlohmann::json& ret, nlohmann::json& config, nlohmann::json& question, nlohmann::json& ans)
{
  uint32_t nsel{0};
  uint32_t low_x{15}, low_y{15}, high_x{0}, high_y{0};
  ret["result"] = false;

  /* first count should be equal */
  if (!ans.is_array()) return;
  if (ans.size() != 15*15) return;
  for (uint32_t i=0; i<ans.size(); i++) {
    auto &v = ans[i];
    if (!v.is_boolean()) return;
    if (v.get<bool>()) {
      uint32_t x{i/15}, y{i%15};
      if (x < low_x) low_x = x;
      if (y < low_y) low_y = y;
      if (x > high_x) high_x = x;
      if (y > high_y) high_y = y;
      nsel++;
    }
  }
  if (nsel != question["ans"].get<uint32_t>()) return;

  /* check for rectangle */
  auto op1{question["op1"].get<uint32_t>()}, op2{question["op2"].get<uint32_t>()};
  op1--, op2--;
  if (((low_x + op1) != high_x) && ((low_x + op2) != high_x)) return;
  if (((low_y + op1) != high_y) && ((low_y + op2) != high_y)) return;

  /* all checks passed... */
  ret["result"] = true;
}

void
Maths::CountEqual::gen(nlohmann::json& ret, std::shared_ptr<RandGenerator> rand, nlohmann::json& config)
{
  std::string fcol, bkcol, symbol;
  const std::string is {config["is"].get<std::string>()};

  /* choose op */
  std::string op;
  do {
    auto i = rand->get() % config["op_types"].size();
    op = config["op_types"][i].get<std::string>();
  } while (false);

  /* init */
  auto min_digits = config["min_digits"].get<uint32_t>();
  auto max_digits = config["max_digits"].get<uint32_t>();
  do {
    auto i = rand->get() % Genmain::htmlColors.size();
    fcol = Genmain::htmlColors[i];
  } while (false);
  do {
    auto i = rand->get() % Genmain::htmlBackgroundColors.size();
    bkcol = Genmain::htmlBackgroundColors[i];
  } while (false);
  do {
    auto i = rand->get() % Genmain::symbols.size();
    symbol = Genmain::symbols[i];
  } while (false);

  /* */
  ret["text"] = "Fill blanks to describe the model:";
  ret["draw_symbols"] = nlohmann::json::array();

  /* generate the test */
  auto op1 = rand->get_digits(min_digits, max_digits) + 1; /* no 0's */
  auto op2 = rand->get_digits(min_digits, max_digits) + 1;
  auto ans = op1 * op2;
  for (auto i=op2; i; i--) {
    auto o = nlohmann::json::object();
    o["rows"] = nlohmann::json::array();
    o["height"] = 100;
    o["width"] = 400;
    o["box"] = true;
    o["cols"] = 3;
    o["box_color"] = bkcol;
    o["rows"].push_back(nlohmann::json::object
                        ({
                          {"symbol", symbol},
                          {"num", op1},
                          {"color", fcol},
                        })
                        );
    ret["draw_symbols"].push_back(o);
  }
  auto op1_blank = (rand->get() & 1) ? true : false;
  auto op2_blank = (rand->get() & 1) ? true : false;
  auto ans_blank = ((!op1_blank) && (!op2_blank)) ? true :
    (rand->get() & 1) ? true : false;

  /* */
  ret["multiinput"] = nlohmann::json::array();
  ret["correct_ans"] = nlohmann::json::array();
  ret["multiinput"][0] = nlohmann::json::array();
  ret["correct_ans"][0] = nlohmann::json::array();
  if (is == "CountEqualGroups") {
    ret["multiinput"][1] = nlohmann::json::array();
    ret["correct_ans"][1] = nlohmann::json::array();
    if (op1_blank || op2_blank) {
      ret["multiinput"][0].push_back("There are ");
      ret["correct_ans"][0].push_back(nullptr);
      if (op1_blank) {
        ret["multiinput"][0].push_back("_");
        ret["correct_ans"][0].push_back(std::to_string(op1));
      } else {
        ret["multiinput"][0].push_back("<b>"+std::to_string(op1)+"</b>");
        ret["correct_ans"][0].push_back(nullptr);
      }
      ret["multiinput"][0].push_back(" groups of ");
      ret["correct_ans"][0].push_back(nullptr);
      if (op2_blank) {
        ret["multiinput"][0].push_back("_");
        ret["correct_ans"][0].push_back(std::to_string(op2));
      } else {
        ret["multiinput"][0].push_back("<b>"+std::to_string(op2)+"</b>");
        ret["correct_ans"][0].push_back(nullptr);
      }
      ret["multiinput"][0].push_back(" symbols.");
      ret["correct_ans"][0].push_back(nullptr);
    } else {
      ret["multiinput"][0].push_back("There are " + std::to_string(op1) + " groups of " + std::to_string(op2) + " symbols.");
      ret["correct_ans"][0].push_back(nullptr);
    }
    if (ans_blank) {
      ret["multiinput"][1].push_back("There are ");
      ret["multiinput"][1].push_back("_");
      ret["multiinput"][1].push_back(" symbols in all.");
      ret["correct_ans"][1].push_back(nullptr);
      ret["correct_ans"][1].push_back(std::to_string(ans));
      ret["correct_ans"][1].push_back(nullptr);
    } else {
      ret["multiinput"][1].push_back("There are " + std::to_string(ans) + " symbols in all.");
      ret["correct_ans"][1].push_back(nullptr);
    }
  } else {
    auto idx = 0;
    if (is == "relate-addition-multiplication") {
      auto s = std::string{};
      for (auto i=op2; i; i--) {
        s += std::to_string(op1);
        if (i > 1)
          s += " + ";
      }
      s += " = ";
      ret["multiinput"][idx][0] = s;
      ret["multiinput"][idx][1] = "_";
      ret["correct_ans"][idx][0] = nullptr;
      ret["correct_ans"][idx][1] = std::to_string(ans);
      idx ++;
      ret["multiinput"][idx] = nlohmann::json::array();
      ret["correct_ans"][idx] = nlohmann::json::array();
    }
    if (op1_blank) {
      ret["multiinput"][idx].push_back("_");
      ret["correct_ans"][idx].push_back(std::to_string(op1));
    } else {
      ret["multiinput"][idx].push_back(std::to_string(op1));
      ret["correct_ans"][idx].push_back(nullptr);
    }
    ret["multiinput"][idx].push_back(" &times; ");
    ret["correct_ans"][idx].push_back(nullptr);
    if (op2_blank) {
      ret["multiinput"][idx].push_back("_");
      ret["correct_ans"][idx].push_back(std::to_string(op2));
    } else {
      ret["multiinput"][idx].push_back(std::to_string(op2));
      ret["correct_ans"][idx].push_back(nullptr);
    }
    ret["multiinput"][idx].push_back(" = ");
    ret["correct_ans"][idx].push_back(nullptr);
    if (ans_blank) {
      ret["multiinput"][idx].push_back("_");
      ret["correct_ans"][idx].push_back(std::to_string(ans));
    } else {
      ret["multiinput"][idx].push_back(std::to_string(ans));
      ret["correct_ans"][idx].push_back(nullptr);
    }
  }
}

void
Maths::IdentifyExprMseg::gen(nlohmann::json& ret, std::shared_ptr<RandGenerator> rand, nlohmann::json& config)
{
  std::string fcol, bkcol, symbol;
  const std::string is {config["is"].get<std::string>()};
  auto mefa = "multiplication-expr-for-arrays" == is;
  auto write_mefa = "write-multiplication-expr-for-arrays" == is;

  /* choose op */
  std::string op;
  do {
    auto i = rand->get() % config["op_types"].size();
    op = config["op_types"][i].get<std::string>();
  } while (false);

  /* init */
  auto min_digits = config["min_digits"].get<uint32_t>();
  auto max_digits = config["max_digits"].get<uint32_t>();
  do {
    auto i = rand->get() % Genmain::htmlColors.size();
    fcol = Genmain::htmlColors[i];
  } while (false);
  do {
    auto i = rand->get() % Genmain::htmlBackgroundColors.size();
    bkcol = Genmain::htmlBackgroundColors[i];
  } while (false);
  do {
    auto i = rand->get() % Genmain::symbols.size();
    symbol = Genmain::symbols[i];
  } while (false);

  /* */
  ret["text"] = "Fill blanks to describe the model:";
  ret["draw_symbols"] = nlohmann::json::array();

  /* generate the test */
  auto op1 = rand->get_digits(min_digits, max_digits) + 1; /* no 0's */
  auto op2 = rand->get_digits(min_digits, max_digits) + 1;
  auto ans = op1 * op2;
  for (auto i=op1; i; i--) {
    auto o = nlohmann::json::object();
    o["rows"] = nlohmann::json::array();
    o["height"] = 100;
    o["width"] = 400;
    o["box"] = ! (mefa || write_mefa);
    o["cols"] = (mefa || write_mefa) ? 12 : 3;
    o["box_color"] = bkcol;
    o["rows"].push_back(nlohmann::json::object
                        ({
                          {"symbol", symbol},
                          {"num", op2},
                          {"color", fcol},
                        })
                        );
    ret["draw_symbols"].push_back(o);
  }

  /* */
  if (write_mefa) {
    auto op1_blank = (rand->get() & 1) ? true : false;
    auto op2_blank = (rand->get() & 1) ? true : false;
    auto ans_blank = ((!op1_blank) && (!op2_blank)) ? true :
      (rand->get() & 1) ? true : false;
    ret["multiinput"] = nlohmann::json::array();
    ret["multiinput"][0] = nlohmann::json::array();
    ret["correct_ans"] = nlohmann::json::array();
    ret["correct_ans"][0] = nlohmann::json::array();
    ret["multiinput"][0][0] = op1_blank ? "_" : std::to_string(op1);
    op1_blank ?
      ret["correct_ans"][0][0] = std::to_string(op1) : ret["correct_ans"][0][0] = nullptr;
    ret["multiinput"][0][1] = " &times; ";
    ret["correct_ans"][0][1] = nullptr;
    ret["multiinput"][0][2] = op2_blank ? "_" : std::to_string(op2);
    op2_blank ?
      ret["correct_ans"][0][2] = std::to_string(op2) : ret["correct_ans"][0][2] = nullptr;
    ret["multiinput"][0][3] = " = ";
    ret["correct_ans"][0][3] = nullptr;
    ret["multiinput"][0][4] = ans_blank ? "_" : std::to_string(ans);
    ans_blank ?
      ret["correct_ans"][0][4] = std::to_string(ans) : ret["correct_ans"][0][4] = nullptr;
  } else { /* mefa & (!mefa && !write_mefa)*/
    ret["btnchoice"] = nlohmann::json::array();
    ret["correct_ans"] = nlohmann::json::array();
    ret["btnchoice"].push_back(std::to_string(op1-1) + " &times; " + std::to_string(op2));
    ret["btnchoice"].push_back(std::to_string(op1) + " &times; " + std::to_string(op2-1));
    ret["btnchoice"].push_back(std::to_string(op1-1) + " &times; " + std::to_string(op2+1));
    ret["btnchoice"].push_back(std::to_string(op1+1) + " &times; " + std::to_string(op2-1));
    ret["btnchoice"].push_back(std::to_string(op1) + " &times; " + std::to_string(op2+1));
    ret["btnchoice"].push_back(std::to_string(op1+1) + " &times; " + std::to_string(op2));
    std::shuffle(std::begin(ret["btnchoice"]), std::end(ret["btnchoice"]), rand->rng);

    /* select ans loc */
    auto ans_idx = rand->get() % ret["btnchoice"].size();
    ret["btnchoice"][ans_idx] = std::to_string(op1) + " &times; " + std::to_string(op2);
    ret["correct_ans"].push_back(ans_idx);
  }
}

void
Maths::Tables::gen(nlohmann::json& ret, std::shared_ptr<RandGenerator> rand, nlohmann::json& config)
{
  const std::string is{config["is"].get<std::string>()};

  /* choose op */
  std::string op;
  do {
    auto i = rand->get() % config["op_types"].size();
    op = config["op_types"][i].get<std::string>();
  } while (false);

  /* config */
  uint32_t tfor;
  do {
    auto i = rand->get() % config["table_for"].size();
    tfor = config["table_for"][i].get<uint32_t>();
  } while (false);
  uint32_t tmax = config["table_maxin"].get<uint32_t>();

  /* */
  auto op1 = rand->get_range(0, tmax);
  auto ans = (op == "*") ? op1 * tfor :
    (op == "/") ? op1 * tfor :
    (op == "+") ? op1 + tfor : op1 - tfor;
  if (op == "/") {
    auto t = op1;
    op1 = ans;
    ans = t;
  }

  /* */
  auto truefalse_yesno = (rand->get() & 1) ? true : false;
  auto truefalse_yesno_truefalse = (rand->get() & 1) ? true : false;
  if (is == "tables") {
    ret["text"] = "Compute: ";
    ret["multiinput"] = nlohmann::json::array();
    ret["multiinput"][0] = nlohmann::json::array();
    /* business logic */
    ret["multiinput"][0][0] = "_";
    ret["multiinput"][0][1] = std::string((op == "*") ? "&times;" : ((op == "/") ? "&div;" : op)) +
      " " + std::to_string(tfor) + " = " + std::to_string(ans);
    /* business logic: end */
    ret["correct_ans"] = nlohmann::json::array();
    ret["correct_ans"][0] = nlohmann::json::array();
    ret["correct_ans"][0][0] = std::to_string(op1);
    ret["correct_ans"][0][1] = nullptr;
  } else if ((is == "tables-truefalse") && truefalse_yesno) {
    ret["btnchoice"] = nlohmann::json::array();
    ret["correct_ans"] = nlohmann::json::array();
    if (truefalse_yesno_truefalse) {
      ret["text"] = "Is number sentence true or false : <b>" + std::to_string(op1) +
        " &times; " + std::to_string(tfor) + " = " + std::to_string(ans) + "</b>";
      auto o = (rand->get() & 1) ? true : false;
      if (o) {
        ret["btnchoice"].push_back("true");
        ret["btnchoice"].push_back("false");
        ret["correct_ans"].push_back(0);
      } else {
        ret["btnchoice"].push_back("false");
        ret["btnchoice"].push_back("true");
        ret["correct_ans"].push_back(1);
      }
    } else {
      ret["text"] = "Is number sentence true or false : <b>" + std::to_string(op1) +
        " &times; " + std::to_string(tfor) + " = " + std::to_string(ans-2) + "</b>";
      auto o = (rand->get() & 1) ? true : false;
      if (o) {
        ret["btnchoice"].push_back("true");
        ret["btnchoice"].push_back("false");
        ret["correct_ans"].push_back(1);
      } else {
        ret["btnchoice"].push_back("false");
        ret["btnchoice"].push_back("true");
        ret["correct_ans"].push_back(0);
      }
    }
  } else if (is == "tables-truefalse") {
    ret["text"] = std::string("Select <b>all sentences</b> those are <b>") + (truefalse_yesno_truefalse?"true":"false") + "</b>";
    ret["btnchoice"] = nlohmann::json::array();
    ret["correct_ans"] = nlohmann::json::array();
    for (uint32_t i=0; i<6; i++) {
      op1 = rand->get_range(0, tmax);
      ans = op1 * tfor;
      auto o = rand->get() & 7;
      if (o == 0)
        ret["btnchoice"].push_back(std::to_string(op1-1) + " &times; " + std::to_string(tfor) + " = " + std::to_string(ans));
      else if (o == 1)
        ret["btnchoice"].push_back(std::to_string(op1) + " &times; " + std::to_string(tfor-1) + " = " + std::to_string(ans));
      else if (o == 2)
        ret["btnchoice"].push_back(std::to_string(op1) + " &times; " + std::to_string(tfor+1) + " = " + std::to_string(ans));
      else if (o == 3)
        ret["btnchoice"].push_back(std::to_string(op1+1) + " &times; " + std::to_string(tfor) + " = " + std::to_string(ans));
      else if (o == 4)
        ret["btnchoice"].push_back(std::to_string(op1+1) + " &times; " + std::to_string(tfor-1) + " = " + std::to_string(ans));
      else if (o == 5)
        ret["btnchoice"].push_back(std::to_string(op1-1) + " &times; " + std::to_string(tfor+1) + " = " + std::to_string(ans));
      else { /* true case probability: 3/8 */
        ret["btnchoice"].push_back(std::to_string(op1) + " &times; " + std::to_string(tfor) + " = " + std::to_string(ans));
      }
      if (truefalse_yesno_truefalse && (o > 5))
        ret["correct_ans"].push_back(i);
      else if ((!truefalse_yesno_truefalse) && (o <= 5))
        ret["correct_ans"].push_back(i);
    }
  } else if (is == "tables-sorting") {
    /* FIXME */
  }
}


void
Maths::AdditionPatternIncreasingPlacevalues::gen(nlohmann::json& ret, std::shared_ptr<RandGenerator> rand, nlohmann::json& config)
{
  /* choose op */
  std::string op;
  do {
    auto i = rand->get() % config["op_types"].size();
    op = config["op_types"][i].get<std::string>();
  } while (false);

  /* static conf */
  ret["text"] = std::string("Complete the <b>") + ((op == "+") ? "Addition" : "Subtraction") + "</b> pattern table over increasing place values:";
  ret["no-outlines"] = true;

  auto min_digits = config["min_digits"].get<uint32_t>();
  auto max_digits = config["max_digits"].get<uint32_t>();
  std::vector<uint32_t> vars;
  auto num_vars = config.contains("num_vars") ? config["num_vars"].get<uint32_t>() : 2;
  auto num_steps = config.contains("num_steps") ? config["num_steps"].get<uint32_t>() : 3;

  /* get all vars */
  uint32_t res = 0;
  for (auto i=0; i<num_vars-1; i++) {
    vars.emplace_back(rand->get_digits(min_digits, max_digits));
    res += vars.back();
  }
  do {
    auto d = rand->get_digits(min_digits, max_digits);
    if (op == "+") {
      res += d;
      vars.emplace_back(d);
    } else /* op == "-" */ {
      vars.insert(vars.begin(), d + res);
      res = d;
    }
  } while (false);

  /* init */
  auto is_q_res = (rand->get() & 1) ? true : false;
  is_q_res = false;
  ret["th"] = nlohmann::json::array({nullptr, nullptr});
  ret["htabledata"] = nlohmann::json::array();
  ret["correct_ans"] = nlohmann::json::array();

  /* generate  */
  std::ostringstream sout;
  uint32_t mult = 1;
  if (is_q_res) {
    for (auto step=0; step<num_steps; step++, mult *= 10) {
      sout.str(std::string());
      for (auto var=0; var<num_vars; var++) {
        sout << std::dec << (vars[var]*mult) << " " << ((var < (num_vars-1)) ? op : "=") << " ";
      }
      ret["htabledata"].push_back(nlohmann::json::array());
      ret["htabledata"].back().push_back(sout.str());
      ret["htabledata"].back().push_back("_");
      ret["correct_ans"].push_back(nlohmann::json::array());
      ret["correct_ans"].back().push_back(nullptr);
      ret["correct_ans"].back().push_back(std::to_string(res*mult));
    }
  } else {
    ret["th"].push_back(nullptr);
    for (auto step=0; step<num_steps; step++, mult *= 10) {
      sout.str(std::string());
      for (auto var=0; var<num_vars-1; var++) {
        sout << std::dec << (vars[var]*mult) << " " << op << " ";
      }
      ret["htabledata"].push_back(nlohmann::json::array());
      ret["htabledata"].back().push_back(sout.str());
      ret["htabledata"].back().push_back("_");
      sout.str(std::string()); sout << "= " << (res*mult);
      ret["htabledata"].back().push_back(sout.str());
      ret["correct_ans"].push_back(nlohmann::json::array());
      ret["correct_ans"].back().push_back(nullptr);
      ret["correct_ans"].back().push_back(std::to_string(vars.back()*mult));
      ret["correct_ans"].back().push_back(nullptr);
    }
  }

  ret["maxlength"] = max_digits*2;
}

/*
 * this.question = {
 text: 'this is trial dragngroup, pls answer...',
 dragngroup: [
 { text: 'pull from',
 values: [
 "John", "Joao", "Jean", "Gerard", "Juan", "Edgard", "Johnson",
 ]
 },
 { text: 'group 0', values: ['a'] },
 { text: 'group 1', values: ['b'] },
 { text: 'group 2', values: ['c'] },
 ],
 correct_ans: [
 { values: [
 "John", "Joao", "Jean", "Gerard", "Juan", "Edgard", "Johnson",
 ]
 },
 { values: ['a'] },
 { values: ['b'] },
 { values: ['c'] },
 ],
 };

*/
void
Maths::DragGroup::gen(nlohmann::json& ret, std::shared_ptr<RandGenerator> rand, nlohmann::json& config)
{ /* FIXME: Incomplete */
  /* choose op */
  std::string op;
  do {
    auto i = rand->get() % config["op_types"].size();
    op = config["op_types"][i].get<std::string>();
  } while (false);

  // ret["text"] = "my question";
  // ret["dragngroup"] =
}

/* create global object */
namespace {
  Maths::Addition a{};
}
