#include "Log.h"


Log::Log(std::vector<std::vector<int>> bw)
{
    for (int i = 0; i < bw.size(); i++)
    {
        this->right[i] = 0;
        this->up[i] = 0;
        this->down[i] = 0;
        this->left[i] = 0;

        if (bw[i][0] == 1)
        {
            this->right[i] = 1; 
        }
        else if (bw[i][0] == -1)
        {
            this->left[i] = 1;
        }
        else if (bw[i][1] == 1)
        {
            this->down[i] = 1;
        }
        else
        {
            this->up[i] = 1;
        }
    }

    
}