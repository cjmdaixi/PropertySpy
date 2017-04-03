#include "PropertySpy.h"
#include <QMetaProperty>
#include <QMetaMethod>
#include <QtDebug>

PropertySpy::PropertySpy(QObject *parent) : QObject(parent)
{
}

void PropertySpy::spy(QObject *object)
{
    auto slotIndex = metaObject()->indexOfSlot("onPropertyChanged()");
    if(slotIndex == -1){
        qDebug()<<"The index of onPropertyChanged is invalid!";
        return;
    }
    auto slotMethod = metaObject()->method(slotIndex);
    if(!slotMethod.isValid()){
        qDebug()<<"cannot find onPropertyChanged!";
        return;
    }
    for(auto i = 0; i != object->metaObject()->propertyCount(); ++i){
        auto prop = object->metaObject()->property(i);
        auto sig = prop.notifySignal();
        if(!sig.isValid()) continue;
        connect(object, sig, this, slotMethod);
    }
}

void PropertySpy::onPropertyChanged()
{
    auto senderObj = sender();
    auto signalIndex = senderSignalIndex();
    for(auto i = 0; i != senderObj->metaObject()->propertyCount(); ++i){
        auto prop = senderObj->metaObject()->property(i);
        if(prop.notifySignalIndex() == signalIndex){
            qDebug()<<prop.name()<<prop.read(senderObj);
        }
    }
}
