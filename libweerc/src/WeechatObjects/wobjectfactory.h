// vim: ts=4 sw=4 expandtab

#ifndef WOBJECTFACTORY_H
#define WOBJECTFACTORY_H

#include <QString>

#include "wobject.h"

class WObjectFactory
{
public:
    static WObjectPtr fromTypeString(const QString &str);
    static WObjectPtr fromType(WObject::ObjectType type);
};

#endif // WOBJECTFACTORY_H
