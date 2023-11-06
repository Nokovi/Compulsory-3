#pragma once
#include <ctime>


/// <summary>
/// modified asctime function that has a prettier yyyy.mm.dd formatting and no newline
/// </summary>
/// <returns>result</returns>
char* asctime_modified()
{

    time_t rawtime;
    struct tm* timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    static char result[26];
    sprintf(result, "%4d/%.2d/%.2d %.2d:%.2d:%.2d",
        1900 + timeinfo->tm_year, timeinfo->tm_mon+1, timeinfo->tm_mday, timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
    return result;
}
