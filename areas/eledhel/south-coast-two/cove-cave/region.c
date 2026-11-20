//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/region.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setRegionName("southern headland cove");
    setRegionType("cave");
    setRegionLevel(6);
    setDimensions(5, 5);
    setEntryCoordinate(0, 2,
        "/areas/eledhel/south-coast-two/cove-cave/0x2.c", "west",
        "/areas/eledhel/south-coast-two/18x3.c");

    setCoordinate(0, 2,
        "/areas/eledhel/south-coast-two/cove-cave/0x2.c", "entry");
    setCoordinate(0, 3,
        "/areas/eledhel/south-coast-two/cove-cave/0x3.c", "path");
    setCoordinate(1, 3,
        "/areas/eledhel/south-coast-two/cove-cave/1x3.c", "path");
    setCoordinate(1, 2,
        "/areas/eledhel/south-coast-two/cove-cave/1x2.c", "room");
    setCoordinate(2, 2,
        "/areas/eledhel/south-coast-two/cove-cave/2x2.c", "room");
}
