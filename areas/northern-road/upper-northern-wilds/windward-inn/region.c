//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/region.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    asManualRegion();
    setRegionName("Windward Inn");
    setRegionType("rural");
    setRegionLevel(5);
    setSettlementChance(-1);
    setDimensions(5, 5);

    setEntryCoordinate(2, 2,
        "/areas/northern-road/upper-northern-wilds/windward-inn/"
        "common-room.c", "east",
        "/areas/northern-road/upper-northern-wilds/0x0.c");
    setCoordinate(1, 2,
        "/areas/northern-road/upper-northern-wilds/windward-inn/loft.c",
        "room");
    setCoordinate(2, 3,
        "/areas/northern-road/upper-northern-wilds/windward-inn/"
        "stable-yard.c", "room");
}
