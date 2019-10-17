#include <iostream>
#include <vector>

int water=0;
using namespace std;
// exmaple : 
vector<int> elev{2,1,0,2,0,4,0,2,1,0,2,3,4};
vector<int> peaks;

bool checkForpeaks()
{
    int l=0;
    int t=0;
    peaks.clear();
    if (elev[0]>elev[1])
    {
        peaks.push_back(0);
        t++;
    }
    for (int i =1; i<elev.size()-1;i++)
    {

        if (elev[i-1]<elev[i] && elev[i]>elev[i+1])
        {
            peaks.push_back(i);
            t++;
        }

    }
    if (elev[elev.size()-2]<elev[elev.size()-1])
    {

        peaks.push_back(elev.size()-1);
        t++;
    }

    return bool (t>1);
}
void  addWater()
{
    for (int i=0;i<peaks.size()-1;i++)
    {
        int level;
        level=min (elev[peaks[i]],elev[peaks[i+1]]);
        for (int k=peaks[i]+1;k<peaks[i+1];k++)
        {
            water+=level-elev[k];
            elev[k]=level;

        }

    }
}


int main()
{
    //input()

    while(checkForpeaks()==true)
    {

        addWater();


    }
    cout<<water;
    return 0;
}
