//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, Realms MUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#include "/lib/include/itemFormatters.h"

/////////////////////////////////////////////////////////////////////////////
public varargs string buildBanner(string type, string area)
{
    string ret = sprintf(Red, "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n");
    string banner = sprintf("+ %s%s +", capitalize(type), area ? " " + capitalize(area) : "");

    int startingPoint = 47 - (sizeof(banner) / 2);

    for (int i = startingPoint; i < (startingPoint + sizeof(banner)); i++)
    {
        ret[i] = banner[i - startingPoint];
    }
    return ret;
}
