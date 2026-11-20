//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/bedroom.c");
    addDecorator("keep interior floor");
    setShortDescription("A guest sleeping room");
    addItem("/lib/environment/items/furniture/bed.c", "north");
    addItem("/lib/environment/items/furniture/dresser.c", "west");
    addExit("east", "/areas/evenholt/manor/1x2.c");
}
