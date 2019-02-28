//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/item.c";

/////////////////////////////////////////////////////////////////////////////
public nomask mixed query(string element)
{
    mixed ret = 0;
    switch(element)
    {
        case "type":
        {
            ret = "treasure";
            break;
        }
        case "low light description":
        {
            ret = "The silhouette of an object";
            break;
        }
        case "dim light description":
        {
            ret = "An object that it is too dark to identify";
            break;
        }
        default:
        {
            ret = "item"::query(element);
        }
    }

    return ret;
}
