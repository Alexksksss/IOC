#include <QCoreApplication>
#include "ioc.h"
#include "computer.h"
#include "iprocessor.h"
#include <iostream>
using namespace std;


int IOCContainer::s_nextTypeId = 1;

int main()
{
    IOCContainer injector;

        //------Example #1----------------
    // Регистрируем IProcessor с классом Intel, т.о. каждый раз запрашивая Iprocessor получаем объект Intel.
    injector.RegisterInstance<IProcessor, IntelProcessor>();
    injector.GetObject<IProcessor>()->SetterProcessor("Intel",x64,2.1);
    Computer computerIntel(injector.GetObject<IProcessor>().get());
    cout<<computerIntel.GetProcessor()<<endl;

    //------Example #2----------------
    // Регистрируем IProcessor с классом AMD, т.о. каждый раз запрашивая Iprocessor получаем объект Amd;
    injector.RegisterInstance<IProcessor, AMDProcessor>();
    injector.GetObject<IProcessor>()->SetterProcessor("AMD",x86,4.2);
    Computer computerAMD(injector.GetObject<IProcessor>().get());
    cout<<computerAMD.GetProcessor()<<endl;

        return 0;

}
