#include "slog.h"

void SLog::init(SLogSeverity severity) {
    logging::add_file_log
    (
        keywords::file_name = "system_%Y%m%d.log",
        keywords::open_mode = std::ios_base::app|std::ios_base::out,
        keywords::time_based_rotation = sinks::file::rotation_at_time_point(0, 0, 0),
        keywords::format = "%TimeStamp% %Severity% %Message%",
        keywords::auto_flush = true
    );

    int selected_severity = logging::trivial::info;

    switch(severity) {
        case SLogSeverity::DEBUG:
            selected_severity = logging::trivial::debug;
            break;
        case SLogSeverity::INFO:
            selected_severity = logging::trivial::info;
            break;
        case SLogSeverity::WARNING:
            selected_severity = logging::trivial::warning;
            break;
        case SLogSeverity::ERROR:
            selected_severity = logging::trivial::error;
            break;
        default:
            selected_severity = logging::trivial::info;
            break;
    }

    logging::core::get()-> set_filter
    (
        logging::trivial::severity >= selected_severity
    );

    logging::add_common_attributes();
}

void SLog::log_debug(string msg) {
    src::severity_logger<severity_level> lg;

    BOOST_LOG_SEV(lg, debug) << msg;
}

void SLog::log_info(string msg) {
    src::severity_logger<severity_level> lg;

    BOOST_LOG_SEV(lg, info) << msg;
}

void SLog::log_warning(string msg) {
    src::severity_logger<severity_level> lg;

    BOOST_LOG_SEV(lg, warning) << msg;
}

void SLog::log_error(string msg) {
    src::severity_logger<severity_level> lg;

    BOOST_LOG_SEV(lg, error) << msg;
}

// int main(int, char*[])
// {
//     string greeting = "Hello"; 

//     SLog slog;
//     slog.init(SLogSeverity::INFO);
//     slog.log_debug(greeting);
//     slog.log_info(greeting);
//     slog.log_warning(greeting);
//     slog.log_error(greeting);

//     return 0;
// }