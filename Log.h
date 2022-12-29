#ifndef __LOG_H__
#define __LOG_H__

#include <vector>

class Log
{ 
private:
    std::vector<bool> up;
    std::vector<bool> down;
    std::vector<bool> right;
    std::vector<bool> left;
public:
    Log(std::vector<std::vector<int>> bw);

};

#endif  // __LOG_H__
