//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/cave.c");
    setShortDescription("A bent passage descends from the shore");
    addDecorator("cave north-east passage");
    addFeature("/lib/environment/features/landforms/crag.c");
    addExit("north", "/areas/eledhel/south-coast-two/cove-cave/0x2.c");
    addExit("east", "/areas/eledhel/south-coast-two/cove-cave/1x3.c");
}
