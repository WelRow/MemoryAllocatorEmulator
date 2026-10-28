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

int CPUScheduler::firstFit(vector<int> processes)
{
    int firstFit;
    bool found;

    for (int i = 0; i < processes.size(); i++)
    {
        found = false;
        for (int j = 0; j < ram.size(); j++)
        {
            if (ram[j] >= processes[i])
            {
                firstFit = j;
                found = true;
                break;
            }
        }

        if (found == true)
        {
            ram[firstFit] -= processes[i];
            cout << "Process " << i << " (size " << processes[i] << "): placed in partition "
                 << firstFit << endl;
        }
        else
        {
            cout << "Process " << i << " (size " << processes[i] << "): failed, no partition large enough" << endl;
            return -1;
        }
    }

    cout << "All Processes allocated with First Fit policy" << endl;
    return 0;
}

int CPUScheduler::nextFit(vector<int> processes)
{
    int partitionP = 0;
    int processP = 0;
    int partitionsChecked = 0;

    while (processP != processes.size())
    {

        if (this->ram.at(partitionP) - processes.at(processP) < 0)
        {
            if (partitionsChecked == this->ram.size())
            {
                break;
            }

            partitionP == this->ram.size() - 1 ? partitionP = 0 : partitionP++;

            partitionsChecked++;
            continue;
        }

        cout << processP << "th process is allocated to partition " << partitionP << "!" << endl;
        this->ram.at(partitionP) -= processes.at(processP++);
        partitionP == this->ram.size() - 1 ? partitionP = 0 : partitionP++;
        partitionsChecked = 0;
    }

    if (processP == processes.size())
    {
        cout << "Stored all processes in ram!" << endl;
        return 1;
    }

    cout << "This process with size " << processes.at(processP) << " has no space for it in ram." << endl;
    return -1;
}

int CPUScheduler::bestFit(vector<int> processes)
{
    int bestBlock;
    int diff;
    int tempDiff;
    bool found;

    for (int i = 0; i < processes.size(); ++i)
    {
        bestBlock = -1;
        diff = -1;
        tempDiff = 0;
        found = false;

        for (int j = 0; j < this->ram.size(); ++j)
        {
            tempDiff = this->ram.at(j) - processes.at(i);

            if (tempDiff < 0)
            {
                continue;
            }

            else if (diff == -1 || tempDiff < diff)
            {
                diff = tempDiff;
                bestBlock = j;
                found = true;
                continue;
            }
        }

        // if the process cant find any partition to fit into
        if (found == false)
        {
            cout << "This process with size " << processes.at(i) << " has no space for it in ram." << endl;
            return -1;
        }

        // places process in partition
        this->ram.at(bestBlock) -= processes.at(i);
        cout << i << "th process is allocated to partition " << bestBlock << "!" << endl;
    }

    cout << "Stored all processes in ram!" << endl;
    return 1;
}

int CPUScheduler::worstFit(vector<int> processes)
{
    int worstBlock;
    int tempDiff;
    int diff;
    bool found;
    bool allAllocated = true;

    for (int i = 0; i < processes.size(); i++)
    {
        worstBlock = -1;
        diff = -1;
        found = false;

        for (int j = 0; j < ram.size(); j++)
        {
            tempDiff = ram[j] - processes[i];

            if (tempDiff < 0)
            {
                continue;
            }

            if (tempDiff > diff)
            {
                worstBlock = j;
                diff = tempDiff;
                found = true;
            }
        }

        if (found)
        {
            ram[worstBlock] -= processes[i];
            cout << "Process " << i + 1 << " allocated to partition " << worstBlock + 1 << "." << endl;
        }
        else
        {
            cout << "Process " << i + 1 << " cannot be allocated." << endl;
            allAllocated = false;
        }
    }

    if (allAllocated)
    {
        cout << "All Processes allocated with Worst Fit policy." << endl;
        return 1;
    }

    return 0;
}
