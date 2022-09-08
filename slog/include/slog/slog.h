#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sinks/text_file_backend.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/sources/record_ostream.hpp>
#include <string>

namespace logging = boost::log;
namespace src = boost::log::sources;
namespace sinks = boost::log::sinks;
namespace keywords = boost::log::keywords;

using namespace std;
using namespace logging::trivial;

enum SLogSeverity {
    DEBUG = 0,
    INFO = 1,
    WARNING = 2,
    ERROR = 3    
};

class SLog {
    public:
        static void init(SLogSeverity severity);
        static void log_debug(string msg);
        static void log_info(string msg);
        static void log_warning(string msg);
        static void log_error(string msg);
};

