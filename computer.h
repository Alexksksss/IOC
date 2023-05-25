#ifndef COMPUTER_H
#define COMPUTER_H

#include <iostream>
#include <iprocessor.h>

class Computer
{
    IProcessor* Processor;
public:
    Computer(IProcessor* processor)
        {
            Processor = processor;
        }
        void SetProcessor(IProcessor* processor)
        {
            Processor = processor;
        }
        void PrintingInfo()
        {
            Processor->GetterProcessor();
        }

};

#endif // COMPUTER_H
