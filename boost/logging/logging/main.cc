#include <boost/log/trivial.hpp>

int main()
{
  BOOST_LOG_TRIVIAL(trace) << "A trac severity message";
  BOOST_LOG_TRIVIAL(debug) << "A debug severity message";
  BOOST_LOG_TRIVIAL(info) << "A info severity message";
  BOOST_LOG_TRIVIAL(warning) << "A warning severity message";
  BOOST_LOG_TRIVIAL(error) << "A error severity message";
  BOOST_LOG_TRIVIAL(fatal) << "A fatal severity message";

  return 0;
}
