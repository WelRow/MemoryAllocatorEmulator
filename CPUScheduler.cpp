#include "CPUScheduler.h"

CPUScheduler::CPUScheduler(vector<int> partitions, int ramSize) {
    this->ram = partitions;
    this->ramSize = ramSize;
}

int CPUScheduler::getRamSize() const {
    return ramSize;
}

int CPUScheduler::bestFit(vector<int> processes) {
    int bestBlock;
    int diff;
    int tempDiff;
    bool found;

    for (int i = 0; i < processes.size(); ++i) {
        bestBlock = -1;
        diff = -1;
        tempDiff = 0;
        found = false;

        for (int j = 0; j < this->ram.size(); ++j) {
            tempDiff = this->ram.at(j) - processes.at(i);

            if (tempDiff < 0) {
                continue;
            }

            else if (diff == -1 || tempDiff < diff) {
                diff = tempDiff;
                bestBlock = j;
                found = true;
                continue;
            }  
        }

        // if the process cant find any partition to fit into
        if (found == false) {
            cout << "This process with size " << processes.at(i) << " has no space for it in ram." << endl;
            return -1;
        }

        // places process in partition
        this->ram.at(bestBlock) -= processes.at(i);
        cout << i << "th process is allocated to partition " << bestBlock << "!"<< endl; 
    }

    cout << "Stored all processes in ram!" << endl;
    return 1;
}