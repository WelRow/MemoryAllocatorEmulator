#include "CPUScheduler.h"
#include <iostream>

CPUScheduler::CPUScheduler(vector<int> partitions, int ramSize)
{
    this->ram = partitions;
    this->ramSize = ramSize;
}

int CPUScheduler::getRamSize() const
{
    return ramSize;
}

int CPUScheduler::worstFit(vector<int> processes)
{

    int worstBlock;
    int tempDiff;
    int diff;
    bool found;


    for (int i = 0; i < processes.size(); i++) {

        worstBlock = -1;
        diff = -1;
        found = false;

        for (int j = 0; j < ram.size(); j++) {

            tempDiff = ram[j] - processes[i];

            if (tempDiff < 0) {
                continue;
            }

            if (tempDiff > diff) {
                worstBlock = j;
                diff = tempDiff;
                found = true;
            }
        }

            if (found) {
                ram[worstBlock] -= processes[i];
                cout << "Process " << i + 1 << " allocated to partition " << worstBlock + 1 << "." << endl;
            }
        else {
            cout << "Process " << i + 1 << " cannot be allocated." << endl;
            return 0;
        }

    }

    cout << "All Processes allocated with Worst Fit policy." << endl;
    return 1;
}