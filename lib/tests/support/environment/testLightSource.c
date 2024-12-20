//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseContainer.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("fake light");
    addDescriptionTemplate("an extinguished light");
    addDescriptionTemplate("a state-changed light", "some state");
    addAlias("light");
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs void testAddSourceOfLight(int magnitude, string state, string period, string season)
{
    return addSourceOfLight(magnitude, state, period, season);
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs void testAddActiveSourceOfLight(int magnitude, 
    string template, int activeByDefault, string state)
{
    return addActiveSourceOfLight(magnitude, template, activeByDefault, state);
}
