//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/pier.c");
    setShortDescription("The eastern quay is busy with small coastal boats");
    addDecorator("sandy shore");
    addItem("/lib/environment/items/marine/pier.c");
    addExit("west", "/areas/anor/12x6.c");
    addExit("east", "/areas/anor/14x6.c");
}
