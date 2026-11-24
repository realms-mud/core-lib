//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/region.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    asManualRegion();
    setRegionName("Phaedra Frontier Outpost");
    setRegionType("rural");
    setRegionLevel(7);
    setSettlementChance(-1);
    setDimensions(5, 5);

    setEntryCoordinate(2, 4,
        "/areas/northern-road/upper-northern-wilds/phaedra-outpost/"
        "courtyard.c", "south",
        "/areas/northern-road/upper-northern-wilds/0x0.c");
    setCoordinate(2, 3,
        "/areas/northern-road/upper-northern-wilds/phaedra-outpost/"
        "gatehouse.c", "room");
    setCoordinate(3, 4,
        "/areas/northern-road/upper-northern-wilds/phaedra-outpost/"
        "drill-yard.c", "room");
    setCoordinate(3, 3,
        "/areas/northern-road/upper-northern-wilds/phaedra-outpost/"
        "lookout.c", "room");
}
