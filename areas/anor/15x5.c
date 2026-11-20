//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/pier.c");
    setShortDescription("A narrow landing faces the harbor entrance");
    addDecorator("sandy shore");
    addItem("/lib/environment/items/marine/mooring-post.c");
    addExit("south", "/areas/anor/15x6.c");
}
