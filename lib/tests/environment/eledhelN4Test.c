//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/tests/environment/eledhelCountrysideTest.c";

void Init()
{
    selectTestMethods(({
        "NorthernN4RoadHasThePlannedScale",
        "NorthernN4BoundariesAreReciprocal",
        "NorthernN4RoadShowsWorkingCountryside",
        "NorthernN4RegionIsAuthored",
        "NorthernN4EncountersStayAtOpeningLevels"
    }));
}

void Setup()
{
    Region = 0;
    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player.Name("bob");
    Player.addCommands();
    Player.colorConfiguration("none");
    Harvested = ({});
    Spawned = ({});
}

void NorthernN4RoadHasThePlannedScale()
{
    object region = clone_object("/areas/northern-road/belathon-eolach/region.c");

    ExpectEq(128, shortestRoomPathInRegion(region,
        "/areas/northern-road/belathon-eolach/0x0.c",
        "/areas/northern-road/belathon-eolach/24x8.c"));
    ExpectEq(25, region->xDimension());
    ExpectEq(9, region->yDimension());

    int rooms = 0;
    for (int x = 0; x < region->xDimension(); x++)
    {
        for (int y = 0; y < region->yDimension(); y++)
        {
            mapping coordinate = region->coordinateToMapping(x, y);
            if (mappingp(coordinate) && coordinate["is placed"])
            {
                rooms++;
            }
        }
    }
    ExpectEq(129, rooms);
    destruct(region);
}

void NorthernN4BoundariesAreReciprocal()
{
    object n3 = load_object("/areas/northern-road/northern-manor/24x8.c");
    object n4Start = load_object("/areas/northern-road/belathon-eolach/0x0.c");
    object n4End = load_object("/areas/northern-road/belathon-eolach/24x8.c");
    object n5 = load_object("/areas/northern-road/hrondil-approaches/0x0.c");
    object belathonRoad = load_object(
        "/areas/northern-road/belathon-eolach/23x8.c");
    object belathon = load_object(
        "/areas/eledhel/estates/belathon/approach/0x0.c");
    object eolachRoad = load_object(
        "/areas/northern-road/belathon-eolach/5x4.c");
    object eolach = load_object(
        "/areas/eledhel/estates/eolach/approach/0x0.c");

    ExpectEq("/areas/northern-road/belathon-eolach/0x0.c",
        n3->getExitDirections()["default"]["north"]);
    ExpectEq("/areas/northern-road/northern-manor/24x8.c",
        n4Start->getExitDirections()["default"]["south"]);
    ExpectEq("/areas/northern-road/belathon-eolach/24x8.c",
        n5->getExitDirections()["default"]["south"]);
    ExpectEq("/areas/northern-road/hrondil-approaches/0x0.c",
        n4End->getExitDirections()["default"]["north"]);
    ExpectEq("/areas/eledhel/estates/belathon/approach/0x0.c",
        belathonRoad->getExitDirections()["default"]["north"]);
    ExpectEq("/areas/northern-road/belathon-eolach/23x8.c",
        belathon->getExitDirections()["default"]["south"]);
    ExpectEq("/areas/eledhel/estates/eolach/approach/0x0.c",
        eolachRoad->getExitDirections()["default"]["north"]);
    ExpectEq("/areas/northern-road/belathon-eolach/5x4.c",
        eolach->getExitDirections()["default"]["south"]);
}

void NorthernN4RoadShowsWorkingCountryside()
{
    object region = clone_object("/areas/northern-road/belathon-eolach/region.c");
    mapping farm = region->getEnvironment("4x4")->buildRoomSnapshot();
    mapping eolachTurnoff = region->getEnvironment("5x4")->
        buildRoomSnapshot();
    mapping belathonTurnoff = region->getEnvironment("23x8")->
        buildRoomSnapshot();
    mapping northernRoad = region->getEnvironment("24x8")->
        buildRoomSnapshot();

    ExpectTrue(sizeof(filter(farm["features"],
        (: $1["name"] == "field drain" :))) > 0,
        "4x4 tenant field drainage");
    ExpectTrue(sizeof(filter(farm["items"],
        (: $1["name"] == "stone pile" :))) > 0,
        "4x4 stone cartage");
    ExpectTrue(sizeof(filter(eolachTurnoff["items"],
        (: $1["name"] == "signpost" :))) > 0,
        "5x4 Eolach directions");
    ExpectTrue(sizeof(filter(eolachTurnoff["features"],
        (: $1["name"] == "managed ash coppice" :))) > 0,
        "5x4 managed bowwood");
    ExpectTrue(sizeof(filter(belathonTurnoff["items"],
        (: $1["name"] == "crate of fish" :))) > 0,
        "23x8 coastal freight");
    ExpectTrue(sizeof(filter(belathonTurnoff["items"],
        (: $1["name"] == "fishing net" :))) > 0,
        "23x8 fishing gear");
    ExpectTrue(sizeof(filter(northernRoad["items"],
        (: $1["name"] == "milestone" :))) > 0,
        "24x8 northbound milestone");

    destruct(region);
}

void NorthernN4RegionIsAuthored()
{
    validateAuthoredRegions(({ "/areas/northern-road/belathon-eolach/region.c" }));
}

void NorthernN4EncountersStayAtOpeningLevels()
{
    object region = clone_object("/areas/northern-road/belathon-eolach/region.c");
    object room = region->getEnvironment("11x2");
    move_object(Player, room);
    int count = 0;

    foreach (object encounter in all_inventory(room))
    {
        if (encounter != Player)
        {
            ExpectTrue(encounter->effectiveLevel() >= 1 &&
                encounter->effectiveLevel() <= 4);
            ExpectTrue(member(inherit_list(encounter),
                "/lib/realizations/monster.c") >= 0);
            count++;
            Spawned += ({ encounter });
        }
    }
    ExpectTrue(count >= 1 && count <= 3);
    destruct(region);
}
