//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
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