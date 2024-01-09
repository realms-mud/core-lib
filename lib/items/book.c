//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
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
            ret = "book";
            break;
        }
        case "low light description":
        {
            ret = "The silhouette of a small, rectangular object";
            break;
        }
        case "dim light description":
        {
            ret = "Something that appears to be a book";
            break;
        }
        default:
        {
            ret = item::query(element);
        }
    }

    return ret;
}
