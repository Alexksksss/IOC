#ifndef IPROCESSOR_H
#define IPROCESSOR_H

#include <iostream>
using namespace std;
enum ProcessorType
{
    x86 = 86,
    x64 = 64
};

class IProcessor
{
public:
    IProcessor(){}

    void SetterProcessor(string version, ProcessorType type, double speed)
    {
        Version = version;
        Type = type;
        Speed = speed;
    }
    void GetterProcessor()
    {
        cout << "Processor for "<<Version<<". It`s speed = "<<Speed<<"; Type = Type"<<endl;
    }
    virtual ~IProcessor(){}

private://protected?
    string Version;
    ProcessorType Type;
    double Speed;
};






//class IntelProcessor
//{

//public:
//    IntelProcessor(????){????}



//    string GetProcessorInfo()
//    {
//        return "Processor for" + Version + Speed + Type;
//    }

//};

#endif // IPROCESSOR_H
