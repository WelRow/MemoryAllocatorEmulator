#include "CPUScheduler.h"

CPUScheduler::CPUScheduler(vector<int> partitions, int ramSize) {
    this->ram = partitions;
    this->ramSize = ramSize;
}

int CPUScheduler::getRamSize() const {
    return ramSize;
}

int CPUScheduler::firstFit(vector<int> processes) {
    int firstFit;
    bool found;

    for (int i = 0; i < processes.size(); i++) {
        found = false;
        for (int j = 0; j < ram.size(); j++) {
            if (ram[j] >= processes[i]) {
                firstFit = j;
                found = true;
                break;
            }
        }
        if (found == true) {
            ram[firstFit] -= processes[i];
            cout << "Process " << i << " (size " << processes[i] << "): placed in partition "
                 << firstFit << endl;
        } else {
            cout << "Process " << i << " (size " << processes[i] << "): failed, no partition large enough" << endl;
            return -1;
        }
    }

    cout << "All Processes allocated with First Fit policy" << endl;
    return 0;
}