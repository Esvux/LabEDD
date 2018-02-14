#ifndef JSONREADER_H
#define JSONREADER_H

#include "doublelist.h"
#include "simplelist.h"

class JsonReader
{
public:
    static void fillListFromFile(DoubleList *list, QByteArray json);

};

#endif // JSONREADER_H
