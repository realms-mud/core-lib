//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/tests/environment/eledhelCountrysideTest.c";

void Init()
{
    selectTestMethods(({
        "NorthernN5RoadHasThePlannedScale",
        "NorthernN5BoundariesAreReciprocal",
        "NorthernN5RoadShowsUplandCountry",
        "NorthernN5RegionIsAuthored",
        "NorthernN5EncountersStayAtOpeningLevels",
        "NorthernN5ResidentsArePresent"
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

protected void expectN5ResidentAt(string path, string name)
{
    object room = clone_object(path);
    Harvested += ({ room });
    move_object(Player, room);
    int foundResident = 0;

    foreach (object resident in all_inventory(room))
    {
        if (resident != Player &&
            function_exists("isRealizationOfNpc", resident) &&
            resident->isRealizationOfNpc() && resident->id(name))
        {
            foundResident++;
            Spawned += ({ resident });
        }
    }
    ExpectEq(1, foundResident, path);
}

void NorthernN5RoadHasThePlannedScale()
{
    object region = clone_object("/areas/northern-road/hrondil-approaches/region.c");

    ExpectEq(128, shortestRoomPathInRegion(region,
        "/areas/northern-road/hrondil-approaches/0x0.c",
        "/areas/northern-road/hrondil-approaches/24x8.c"));
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

void NorthernN5BoundariesAreReciprocal()
{
    object n4 = load_object("/areas/northern-road/belathon-eolach/24x8.c");
    object n5Start = load_object("/areas/northern-road/hrondil-approaches/0x0.c");
    object n5End = load_object("/areas/northern-road/hrondil-approaches/24x8.c");
    object n6 = load_object("/areas/northern-road/lower-northern-wilds/0x0.c");

    ExpectEq("/areas/northern-road/hrondil-approaches/0x0.c",
        n4->getExitDirections()["default"]["north"]);
    ExpectEq("/areas/northern-road/belathon-eolach/24x8.c",
        n5Start->getExitDirections()["default"]["south"]);
    ExpectEq("/areas/northern-road/lower-northern-wilds/0x0.c",
        n5End->getExitDirections()["default"]["north"]);
    ExpectEq("/areas/northern-road/hrondil-approaches/24x8.c",
        n6->getExitDirections()["default"]["south"]);
}

void NorthernN5RoadShowsUplandCountry()
{
    object region = clone_object("/areas/northern-road/hrondil-approaches/region.c");
    mapping farm = region->getEnvironment("0x2")->buildRoomSnapshot();
    mapping hrondilTurnoff = region->getEnvironment("12x4")->
        buildRoomSnapshot();
    mapping patrolTrack = region->getEnvironment("21x6")->
        buildRoomSnapshot();
    mapping northboundRoad = region->getEnvironment("24x8")->
        buildRoomSnapshot();

    ExpectTrue(sizeof(filter(farm["features"],
        (: $1["name"] == "dirt road" :))) > 0,
        "0x2 maintained road");
    ExpectTrue(sizeof(filter(farm["features"],
        (: $1["name"] == "field drain" :))) > 0,
        "0x2 tenant field drainage");
    ExpectTrue(sizeof(filter(farm["items"],
        (: $1["name"] == "wooden fence" :))) > 0,
        "0x2 field boundary");
    ExpectTrue(sizeof(filter(hrondilTurnoff["items"],
        (: $1["name"] == "signpost" :))) > 0,
        "12x4 Hrondil directions");
    ExpectTrue(sizeof(filter(patrolTrack["items"],
        (: $1["name"] == "warning sign" :))) > 0,
        "21x6 patrol warning");
    ExpectTrue(sizeof(filter(northboundRoad["items"],
        (: $1["name"] == "milestone" :))) > 0,
        "24x8 N6 milestone");

    destruct(region);
}

void NorthernN5RegionIsAuthored()
{
    validateAuthoredRegions(({ "/areas/northern-road/hrondil-approaches/region.c" }));
}

void NorthernN5EncountersStayAtOpeningLevels()
{
    object region = clone_object("/areas/northern-road/hrondil-approaches/region.c");
    object room = region->getEnvironment("7x2");
    move_object(Player, room);
    int count = 0;

    foreach (object encounter in all_inventory(room))
    {
        if (encounter != Player)
        {
            ExpectTrue(encounter->effectiveLevel() >= 1 &&
                encounter->effectiveLevel() <= 5);
            ExpectTrue(member(inherit_list(encounter),
                "/lib/realizations/monster.c") >= 0);
            count++;
            Spawned += ({ encounter });
        }
    }
    ExpectTrue(count >= 1 && count <= 3);
    destruct(region);
}

void NorthernN5ResidentsArePresent()
{
    expectN5ResidentAt("/areas/northern-road/hrondil-approaches/8x2.c", "Iarwen");
    expectN5ResidentAt("/areas/northern-road/hrondil-approaches/12x4.c", "Merron");
    expectN5ResidentAt("/areas/northern-road/hrondil-approaches/18x6.c", "Cerdan");
}
