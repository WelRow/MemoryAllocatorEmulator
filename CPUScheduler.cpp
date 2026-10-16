#include "CPUScheduler.h"

CPUScheduler::CPUScheduler(vector<int> partitions, int ramSize) {
    this->ram = partitions;
    this->ramSize = ramSize;
}

int CPUScheduler::getRamSize() const {
    return ramSize;
}

int CPUScheduler::nextFit(vector<int> processes) {
    int partitionP = 0;
    int processP = 0;
    int partitionsChecked = 0;

    while (processP != processes.size()) {
        
        if (this->ram.at(partitionP) - processes.at(processP) < 0) {
            if (partitionsChecked == this->ram.size()) {
                break;
            }

            partitionP == this->ram.size() - 1 ? partitionP = 0 : partitionP++;

            partitionsChecked++;
            continue;
        }

        cout << processP << "th process is allocated to partition " << partitionP << "!"<< endl;
        this->ram.at(partitionP++) -= processes.at(processP++);
        partitionsChecked = 0;
    }

    if (processP == processes.size()) {
        cout << "Stored all processes in ram!" << endl;
        return 1;
    }
    
    cout << "This process with size " << processes.at(processP) << " has no space for it in ram." << endl;
    return -1;
    
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