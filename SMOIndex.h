#ifndef __SMO_INDEX__
#define __SMO_INDEX__

#include "K2Tree.h"
#include "Log.h"

class SMOIndex
{
private:
    std::vector<K2Tree> snapshots;
    std::vector<Log> mov_logs;
public:
    SMOIndex(std::vector<std::vector<std::vector<int>>> positions, int j);

};

#endif  // __SMO_INDEX__