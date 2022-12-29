#include "SMOIndex.h"

SMOIndex::SMOIndex(std::vector<std::vector<std::vector<int>>> positions, int j)
{
    for (int i = 0; i < positions.size(); i++)
    {
        std::vector<std::vector<int>> matrix = positions[i];
        std::vector<std::vector<int>> bw(j);
        i++;
        for (int k = 0; k < j; k++)
        {
            for (int x = 0; x < positions[i].size(); x++)
            {
                for (int y = 0; y < positions[i].size(); y++)
                {
                    if (positions[i][x][y] != 0)
                    {
                        if (x == positions[i - 1][x][y] + 1)
                        {

                        }
                        else if (positions[i][x][y] == positions[i - 1][x][y] + 1)
                        {

                        }
                        else if (positions[i][x][y] == positions[i - 1][x][y] + 1)
                        {

                        }
                    }
                }
            }
            i++;
        }
    }
}