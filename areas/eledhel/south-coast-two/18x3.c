//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/rocky-shoreline.c");
    setShortDescription("A low cave mouth opens above the tide line");
    addDecorator("rocky shore");
    addFeature("/lib/environment/features/landforms/crag.c", "east");
    addExit("west", "/areas/eledhel/south-coast-two/17x3.c");
    addExit("east", "/areas/eledhel/south-coast-two/cove-cave/0x2.c");
}
