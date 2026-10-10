#ifndef CPU_SCHEDULER
#define CPU_SCHEDULER
using namespace std;

#include <vector>
#include <iostream>

class CPUScheduler {
public:
    CPUScheduler(vector<int> partitions, int ramSize);

    int bestFit(vector<int> processes);
    int worstFit(vector<int> processes);
    int firstFit(vector<int> processes);
    int nextFit(vector<int> processes);

    int getRamSize() const;
    // show ram getter

private:
    vector<int> ram;
    int ramSize;
};

#endif