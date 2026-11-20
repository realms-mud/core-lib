//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/cave.c");
    addDecorator("cave north-west passage");
    setShortDescription("The flowstone curtain");
    addFeature("/lib/environment/features/landforms/crag.c", "north");
    addExit("west", "/areas/evenholt/limestone-caves/2x2.c");
    addExit("north", "/areas/evenholt/limestone-caves/3x1.c");
}
