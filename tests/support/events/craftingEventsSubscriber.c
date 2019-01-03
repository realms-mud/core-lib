//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private mapping Events = ([]);

/////////////////////////////////////////////////////////////////////////////
public mapping events()
{
    return Events;
}

/////////////////////////////////////////////////////////////////////////////
public void clearEvents()
{
    Events = ([]);
}

/////////////////////////////////////////////////////////////////////////////
public void onCraftingStarted(object caller, string data)
{
    Events["onCraftingStarted"] = data;
}

/////////////////////////////////////////////////////////////////////////////
public void onCraftingCompleted(object caller, string data)
{
    Events["onCraftingCompleted"] = data;
}

/////////////////////////////////////////////////////////////////////////////
public void onCraftingAborted(object caller)
{
    Events["onCraftingAborted"] = 1;
}
