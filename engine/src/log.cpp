#include <oola.h>
#include <stdarg.h>

using namespace Oola;

void Log::Info(const char *fmt, ...)
{
    va_list list;
    va_start(list, fmt);

    printf("[INFO] ");
    vprintf(fmt, list);
    putchar('\n');

    va_end(list);
}

void Log::Warn(const char *fmt, ...)
{
    va_list list;
    va_start(list, fmt);

    printf("[WARN] ");
    vprintf(fmt, list);
    putchar('\n');

    va_end(list);
}

void Log::Error(const char *fmt, ...)
{
    va_list list;
    va_start(list, fmt);

    printf("[ERROR] ");
    vprintf(fmt, list);
    putchar('\n');

    va_end(list);
}

void Log::Fatal(const char *fmt, ...)
{
    va_list list;
    va_start(list, fmt);

    printf("[FATAL ERROR] ");
    vprintf(fmt, list);
    putchar('\n');

    va_end(list);

    abort();
}