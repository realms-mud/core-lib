//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/region.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setRegionName("Upper Northern Wilds");
    setRegionType("rural");
    setRegionLevel(7);
    setSettlementChance(-1);
    setDimensions(25, 9);

    setEntryCoordinate(0, 4,
        "/areas/northern-road/upper-northern-wilds/0x0.c", "south",
        "/areas/northern-road/lower-northern-wilds/24x8.c");

    setCoordinate(1, 4,
        "/areas/northern-road/upper-northern-wilds/1x0.c", "road");
    setCoordinate(2, 4,
        "/areas/northern-road/upper-northern-wilds/2x0.c", "road");
    setCoordinate(3, 4,
        "/areas/northern-road/upper-northern-wilds/3x0.c", "road");
    setCoordinate(4, 4,
        "/areas/northern-road/upper-northern-wilds/4x0.c", "road");
    setCoordinate(5, 4,
        "/areas/northern-road/upper-northern-wilds/5x0.c", "road");
    setCoordinate(6, 4,
        "/areas/northern-road/upper-northern-wilds/6x0.c", "road");
    setCoordinate(7, 4,
        "/areas/northern-road/upper-northern-wilds/7x0.c", "road");
    setCoordinate(8, 4,
        "/areas/northern-road/upper-northern-wilds/8x0.c", "road");
    setCoordinate(9, 4,
        "/areas/northern-road/upper-northern-wilds/9x0.c", "road");
    setCoordinate(10, 4,
        "/areas/northern-road/upper-northern-wilds/10x0.c", "road");
    setCoordinate(11, 4,
        "/areas/northern-road/upper-northern-wilds/11x0.c", "road");
    setCoordinate(12, 4,
        "/areas/northern-road/upper-northern-wilds/12x0.c", "road");
    setCoordinate(13, 4,
        "/areas/northern-road/upper-northern-wilds/13x0.c", "road");
    setCoordinate(14, 4,
        "/areas/northern-road/upper-northern-wilds/14x0.c", "road");
    setCoordinate(15, 4,
        "/areas/northern-road/upper-northern-wilds/15x0.c", "road");
    setCoordinate(16, 4,
        "/areas/northern-road/upper-northern-wilds/16x0.c", "road");
    setCoordinate(17, 4,
        "/areas/northern-road/upper-northern-wilds/17x0.c", "road");
    setCoordinate(18, 4,
        "/areas/northern-road/upper-northern-wilds/18x0.c", "road");
    setCoordinate(19, 4,
        "/areas/northern-road/upper-northern-wilds/19x0.c", "road");
    setCoordinate(20, 4,
        "/areas/northern-road/upper-northern-wilds/20x0.c", "road");
    setCoordinate(21, 4,
        "/areas/northern-road/upper-northern-wilds/21x0.c", "road");
    setCoordinate(22, 4,
        "/areas/northern-road/upper-northern-wilds/22x0.c", "road");
    setCoordinate(23, 4,
        "/areas/northern-road/upper-northern-wilds/23x0.c", "road");
    setCoordinate(24, 4,
        "/areas/northern-road/upper-northern-wilds/24x0.c", "road");

    setCoordinate(5, 3,
        "/areas/northern-road/upper-northern-wilds/hollow-mill/yard.c",
        "room");
    setCoordinate(5, 2,
        "/areas/northern-road/upper-northern-wilds/hollow-mill/grain-store.c",
        "room");
    setCoordinate(6, 3,
        "/areas/northern-road/upper-northern-wilds/hollow-mill/wheelhouse.c",
        "room");
    setCoordinate(6, 2,
        "/areas/northern-road/upper-northern-wilds/hollow-mill/wheel-room.c",
        "room");
    setCoordinate(7, 2,
        "/areas/northern-road/upper-northern-wilds/inland/ridge-path.c",
        "path");
    setCoordinate(8, 2,
        "/areas/northern-road/upper-northern-wilds/inland/fir-shelf.c",
        "path");
    setCoordinate(8, 3,
        "/areas/northern-road/upper-northern-wilds/inland/wrecked-coach.c",
        "room");
    setCoordinate(9, 2,
        "/areas/northern-road/upper-northern-wilds/inland/wind-saddle.c",
        "path");
    setCoordinate(10, 2,
        "/areas/northern-road/upper-northern-wilds/inland/low-track.c",
        "path");
    setCoordinate(11, 2,
        "/areas/northern-road/upper-northern-wilds/inland/return-track.c",
        "path");
    setCoordinate(11, 3,
        "/areas/northern-road/upper-northern-wilds/inland/return-slope.c",
        "path");

    setCoordinate(12, 5,
        "/areas/northern-road/upper-northern-wilds/bridge/north-bank.c",
        "room");
    setCoordinate(13, 5,
        "/areas/northern-road/upper-northern-wilds/bridge/broken-span.c",
        "room");
    setCoordinate(12, 6,
        "/areas/northern-road/upper-northern-wilds/bridge/ford.c",
        "path");
    setCoordinate(13, 6,
        "/areas/northern-road/upper-northern-wilds/bridge/east-bank.c",
        "path");

    setCoordinate(15, 5,
        "/areas/northern-road/upper-northern-wilds/fishery/landing.c",
        "room");
    setCoordinate(16, 5,
        "/areas/northern-road/upper-northern-wilds/fishery/net-yard.c",
        "room");
    setCoordinate(17, 5,
        "/areas/northern-road/upper-northern-wilds/fishery/boat-shed.c",
        "room");
    setCoordinate(15, 6,
        "/areas/northern-road/upper-northern-wilds/fishery/tide-cave.c",
        "room");
    setCoordinate(16, 6,
        "/areas/northern-road/upper-northern-wilds/fishery/smokehouse.c",
        "room");
    setCoordinate(17, 6,
        "/areas/northern-road/upper-northern-wilds/fishery/ebb-rocks.c",
        "room");
}
