#include "CPUScheduler.h"

CPUScheduler::CPUScheduler(vector<int> partitions, int ramSize) {
    this->ram = partitions;
    this->ramSize = ramSize;
}

int CPUScheduler::getRamSize() const {
    return ramSize;
}