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
     string Version;
     ProcessorType Type;
     double Speed;
public:
     IProcessor(){}


     string GetterProcessor()
     {
         string speed = to_string(Speed);
         string type = to_string(Type);
         return  "Processor for " + Version + ". It`s speed = " + speed + "; Type = " + type;
     }

     void SetterProcessor(string version, ProcessorType type, double speed)
     {
         Version = version;
         Type = type;
         Speed = speed;
     }

     virtual ~IProcessor(){}

 };
class IntelProcessor:public IProcessor
{
public:
    IntelProcessor(){}
    ~IntelProcessor(){}
};

class AMDProcessor:public IProcessor
{
public:
    AMDProcessor(){}
    ~AMDProcessor(){}
};



#endif // IPROCESSOR_H
