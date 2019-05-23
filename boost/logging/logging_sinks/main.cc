#include <boost/log/core.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sinks/text_file_backend.hpp>
#include <boost/log/sources/record_ostream.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/utility/setup/file.hpp>

namespace logging = boost::log;
namespace src = boost::log::sources;
namespace sinks = boost::log::sinks;
namespace keywords = boost::log::keywords;

void init()
{
  logging::add_file_log(keywords::file_name = "sample_%N.log",
                        keywords::rotation_size = 10 * 1024 * 1024,
                        keywords::time_based_rotation =
                            sinks::file::rotation_at_time_point(0, 0, 0),
                        keywords::format = "[%TimeStamp%]:%Message%"

  );
  logging::core::get()->set_filter(logging::trivial::severity >=
                                   logging::trivial::info);
}

int main()
{
  init();
  logging::add_common_attributes();
  using namespace logging::trivial;
  src::severity_logger<severity_level> lg;

  BOOST_LOG_SEV(lg, trace) << "A trac severity message";
  BOOST_LOG_SEV(lg, debug) << "A debug severity message";
  BOOST_LOG_SEV(lg, info) << "A info severity message";
  BOOST_LOG_SEV(lg, warning) << "A warning severity message";
  BOOST_LOG_SEV(lg, error) << "A error severity message";
  BOOST_LOG_SEV(lg, fatal) << "A fatal severity message";

  return 0;
}