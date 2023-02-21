//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#include "/lib/include/itemFormatters.h"

/////////////////////////////////////////////////////////////////////////////
public nomask varargs string decorate(string text, string textClass, string type, string configuration)
{
    string ret = 0;
    if (sizeof(regexp(({ textClass }), "\x1b", 1)))
    {
        ret = textClass;
    }
    else if (member(decorators, type) && member(decorators[type], textClass) &&
        member(decorators[type][textClass], configuration))
    {
        ret = decorators[type][textClass][configuration];
    }

    ret = ret ? (ret + text + "\x1b[0m") : text;
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string divider(string configuration, string charset)
{
    string ret = 0;
    if (member(decorators["dividers"], configuration))
    {
        ret = decorators["dividers"][configuration];
    }

    string lineDivider = "";
    if (charset == "screen reader")
    {
        lineDivider = sprintf("%78s\n", "");
    }
    else
    {
        lineDivider = "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n";
    }

    ret = ret ? (ret + lineDivider + "\x1b[0m") : lineDivider;
    return ret;
}
