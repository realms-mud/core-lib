//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseContainer.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("fake light");
    addDescriptionTemplate("a light");
    addDescriptionTemplate("a state-changed light", "some state");
    addAlias("light");
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs void testAddSourceOfLight(int magnitude, string state, string period, string season)
{
    return addSourceOfLight(magnitude, state, period, season);
}
