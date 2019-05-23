#include <boost/log/core.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/trivial.hpp>

namespace logging = boost::log;

void init()
{
  logging::core::get()->set_filter(logging::trivial::severity >=
                                   logging::trivial::info);
}

int main()
{
  init();

  BOOST_LOG_TRIVIAL(trace) << "A trac severity message";
  BOOST_LOG_TRIVIAL(debug) << "A debug severity message";
  BOOST_LOG_TRIVIAL(info) << "A info severity message";
  BOOST_LOG_TRIVIAL(warning) << "A warning severity message";
  BOOST_LOG_TRIVIAL(error) << "A error severity message";
  BOOST_LOG_TRIVIAL(fatal) << "A fatal severity message";

  return 0;
}