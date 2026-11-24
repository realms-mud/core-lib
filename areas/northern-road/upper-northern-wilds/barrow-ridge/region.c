//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/region.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    asManualRegion();
    setRegionName("Barrow Ridge");
    setRegionType("rural");
    setRegionLevel(7);
    setSettlementChance(-1);
    setDimensions(5, 5);

    setEntryCoordinate(2, 4,
        "/areas/northern-road/upper-northern-wilds/barrow-ridge/approach.c",
        "south", "/areas/northern-road/upper-northern-wilds/24x0.c");
    setCoordinate(2, 3,
        "/areas/northern-road/upper-northern-wilds/barrow-ridge/mound-ring.c",
        "room");
    setCoordinate(1, 3,
        "/areas/northern-road/upper-northern-wilds/barrow-ridge/"
        "sealed-mound.c", "room");
    setCoordinate(2, 2,
        "/areas/northern-road/upper-northern-wilds/barrow-ridge/"
        "north-mound.c", "room");
    setCoordinate(3, 3,
        "/areas/northern-road/upper-northern-wilds/barrow-ridge/"
        "opened-mound.c", "room");
}
