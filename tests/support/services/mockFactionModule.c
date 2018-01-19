//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, Realms MUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/core/thing";

private int useFaction = 0;

/////////////////////////////////////////////////////////////////////////////
public void ToggleMockFaction()
{
    useFaction = !useFaction;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int memberOfFaction(string faction)
{
    return useFaction;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string *Factions()
{
    return ({});
}
