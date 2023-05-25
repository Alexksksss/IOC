#include <QCoreApplication>
#include "ioc.h"
#include "computer.h"
#include "iprocessor.h"
#include <iostream>
using namespace std;


int IOCContainer::s_nextTypeId = 1;

int main()
{
    //------Example #1----------------
    //Injector injector;
    IOCContainer injector;

    // Регистрируем IHello с классом Hello, т.о. каждый раз запрашивая IHell получаем объект Hello.
    injector.RegisterInstance<IProcessor, AMD>();
    auto helloInstance = injector.GetObject<IHello>();
    helloInstance->hello();
    injector.RegisterInstance<IHello, Privet>();

    //Здесь, после регистрации получим объект Privet
    helloInstance = injector.GetObject<IHello>();
    helloInstance->hello();

    //------Example #2----------------

    gContainer.RegisterInstance<IAmAThing, TheThing>();
    gContainer.RegisterFactory<IAmTheOtherThing, TheOtherThing, IAmAThing>();

    gContainer.GetObject<IAmAThing>()->TestThis();
    gContainer.GetObject<IAmTheOtherThing>()->TheOtherTest();

    //Опять запршиваем объект,после последней регистрации получим объект Privet
    helloInstance = injector.GetObject<IHello>();
    helloInstance->hello();
    return 0;
}
