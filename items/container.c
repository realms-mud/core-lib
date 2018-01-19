//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, Realms MUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/item.c";

/////////////////////////////////////////////////////////////////////////////
public int isContainer()
{
    return 1;
}

/////////////////////////////////////////////////////////////////////////////
public int canGet(object target)
{
    return 1;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mixed query(string element)
{
    mixed ret = 0;
    switch(element)
    {
        case "type":
        {
            ret = "container";
            break;
        }
        default:
        {
            ret = "item"::query(element);
        }
    }

    return ret;
}