//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/pier.c");
    setShortDescription("Salt baskets and fishing nets line the outer quay");
    addDecorator("sandy shore");
    addItem("/lib/environment/items/marine/fishing-net.c");
    addExit("west", "/areas/anor/13x6.c");
    addExit("east", "/areas/anor/15x6.c");
}
