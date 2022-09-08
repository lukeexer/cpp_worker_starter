#include <string>

#include <slog.h>

using namespace std;

int main(int, char*[])
{
    string greeting = "Hello"; 

    SLog slog;
    slog.init(SLogSeverity::INFO);
    slog.log_debug(greeting);
    slog.log_info(greeting);
    slog.log_warning(greeting);
    slog.log_error(greeting);

    return 0;
}