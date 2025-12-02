//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

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