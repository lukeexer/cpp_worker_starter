#include <string>

#include <slog/slog.h>

using namespace std;

int main(int, char*[])
{
    string greeting = "Hello"; 

    SLog::init(SLogSeverity::INFO);
    SLog::log_debug(greeting);
    SLog::log_info(greeting);
    SLog::log_warning(greeting);
    SLog::log_error(greeting);

    return 0;
}