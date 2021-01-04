//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/items/modifierObject.c";

/////////////////////////////////////////////////////////////////////////////
public void onRegisterItem()
{
    // The test needs to catch these exceptions. It was the most elegant way I
    // could derive to test events.
    raise_error("event handler: onRegisterItem called");
}

/////////////////////////////////////////////////////////////////////////////
public void onUnregisterItem()
{
    raise_error("event handler: onUnregisterItem called");
}
