#include "CPUScheduler.h"

CPUScheduler::CPUScheduler(vector<int> partitions, int ramSize) {
    this->ram = partitions;
    this->ramSize = ramSize;
}

int CPUScheduler::getRamSize() const {
    return ramSize;
}

int CPUScheduler::worstFit(vector <int> processes) {
    // Implement worst fit algorithm here
    return 0; // Placeholder return value
}