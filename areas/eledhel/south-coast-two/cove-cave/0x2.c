//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/cave.c");
    setShortDescription("The cave mouth above Lantern Cove");
    addDecorator("cave south-west passage");
    addFeature("/lib/environment/features/landforms/crag.c");
    addExit("west", "/areas/eledhel/south-coast-two/18x3.c");
    addExit("south", "/areas/eledhel/south-coast-two/cove-cave/0x3.c");
}
