//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/cave.c");
    setShortDescription("A narrow gallery passes between wet stone walls");
    addDecorator("cave north-west passage");
    addFeature("/lib/environment/features/landforms/crag.c");
    addExit("west", "/areas/eledhel/south-coast-two/cove-cave/0x3.c");
    addExit("north", "/areas/eledhel/south-coast-two/cove-cave/1x2.c");
}
