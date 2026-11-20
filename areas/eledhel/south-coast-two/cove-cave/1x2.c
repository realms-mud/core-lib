//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/cave.c");
    setShortDescription("A dry shelf overlooks a tide-fed pool");
    addDecorator("cave south-east passage");
    addFeature("/lib/environment/features/landforms/crag.c");
    addExit("south", "/areas/eledhel/south-coast-two/cove-cave/1x3.c");
    addExit("east", "/areas/eledhel/south-coast-two/cove-cave/2x2.c");
    addRandomCreature(({ "outlaw", "bat" }));
}
