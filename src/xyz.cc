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

namespace Maths {

  class XYZController1 : public Controller {
  public:
    void gen(nlohmann::json& ret, std::shared_ptr<RandGenerator> rand, nlohmann::json& config);
    void check(nlohmann::json& ret, nlohmann::json& config, nlohmann::json& question, nlohmann::json& ans);
  };

}

Maths::XYZ::XYZ():
  GenMod(__CLASS_NAME__)
{
  controllers.emplace("XYZController1", std::make_unique<XYZController1>());
}

void
Maths::XYZController1::gen(nlohmann::json& ret, std::shared_ptr<RandGenerator> rand, nlohmann::json& config)
{
  /* populate ret with the question */
  ret["text"] = std::string("Complete the <b>Given") + "</b> table:";
  ret["inboxwidth"] = "50px";
}

void
Maths::XYZController1::check(nlohmann::json& ret, nlohmann::json& config, nlohmann::json& question, nlohmann::json& ans)
{
  ret["result"] = false;

  /* check if the user has entered correct answer by inspecting ans
     if any check fails, simply return
   */

  /* all checks passed... */
  ret["result"] = true;
}

/* create global object */
namespace {
  Maths::XYZ xyz{};
}
