//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/tests/environment/eledhelCountrysideTest.c";

void Init()
{
    selectTestMethods(({
        "NorthernN6RoadHasThePlannedScale",
        "NorthernN6BoundariesAreReciprocal",
        "NorthernN6RoadShowsLowerWilds",
        "NorthernN6RegionIsAuthored",
        "NorthernN6EncountersStayAtOpeningLevels",
        "NorthernN6ResidentsArePresent"
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

protected void expectN6ResidentAt(string path, string name)
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

void NorthernN6RoadHasThePlannedScale()
{
    object region = clone_object("/areas/northern-road/lower-northern-wilds/region.c");

    ExpectEq(128, shortestRoomPathInRegion(region,
        "/areas/northern-road/lower-northern-wilds/0x0.c",
        "/areas/northern-road/lower-northern-wilds/24x8.c"));
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

void NorthernN6BoundariesAreReciprocal()
{
    object n5 = load_object("/areas/northern-road/hrondil-approaches/24x8.c");
    object n6Start = load_object("/areas/northern-road/lower-northern-wilds/0x0.c");
    object n6End = load_object("/areas/northern-road/lower-northern-wilds/24x8.c");
    object n7 = load_object("/areas/northern-road/upper-northern-wilds/0x0.c");

    ExpectEq("/areas/northern-road/lower-northern-wilds/0x0.c",
        n5->getExitDirections()["default"]["north"]);
    ExpectEq("/areas/northern-road/hrondil-approaches/24x8.c",
        n6Start->getExitDirections()["default"]["south"]);
    ExpectEq("/areas/northern-road/upper-northern-wilds/0x0.c",
        n6End->getExitDirections()["default"]["north"]);
    ExpectEq("/areas/northern-road/lower-northern-wilds/24x8.c",
        n7->getExitDirections()["default"]["south"]);
}

void NorthernN6RoadShowsLowerWilds()
{
    object region = clone_object("/areas/northern-road/lower-northern-wilds/region.c");
    mapping roadStart = region->getEnvironment("0x0")->
        buildRoomSnapshot();
    mapping ford = region->getEnvironment("5x4")->buildRoomSnapshot();
    mapping rangerStop = region->getEnvironment("7x2")->
        buildRoomSnapshot();
    mapping charcoalCamp = region->getEnvironment("12x4")->
        buildRoomSnapshot();
    mapping bog = region->getEnvironment("14x2")->buildRoomSnapshot();
    mapping tower = region->getEnvironment("18x8")->buildRoomSnapshot();
    mapping northboundRoad = region->getEnvironment("24x8")->
        buildRoomSnapshot();
    object towerRoom = load_object(
        "/areas/northern-road/lower-northern-wilds/18x8.c");
    object cellar = load_object(
        "/areas/northern-road/lower-northern-wilds/relay-tower/cellar.c");

    ExpectTrue(sizeof(filter(roadStart["features"],
        (: $1["name"] == "dirt road" :))) > 0,
        "0x0 maintained road surface");
    ExpectTrue(sizeof(filter(ford["features"],
        (: $1["name"] == "shallow ford" :))) > 0,
        "5x4 forest ford");
    ExpectTrue(sizeof(filter(rangerStop["features"],
        (: $1["name"] == "marked timber plot" :))) > 0,
        "7x2 managed timber");
    ExpectTrue(sizeof(filter(rangerStop["items"],
        (: $1["name"] == "warning sign" :))) > 0,
        "7x2 outlaw warning");
    ExpectTrue(sizeof(filter(charcoalCamp["features"],
        (: $1["name"] == "charcoal clamp" :))) > 0,
        "12x4 charcoal hearth");
    ExpectTrue(sizeof(filter(charcoalCamp["items"],
        (: $1["name"] == "woodpile" :))) > 0,
        "12x4 stacked fuel");
    ExpectTrue(sizeof(filter(bog["features"],
        (: $1["name"] == "peat bog" :))) > 0,
        "14x2 peatland");
    ExpectTrue(sizeof(filter(tower["features"],
        (: $1["name"] == "ruined relay tower" :))) > 0,
        "18x8 relay landmark");
    ExpectEq("/areas/northern-road/lower-northern-wilds/relay-tower/cellar.c",
        towerRoom->getExitDirections()["default"]["down"]);
    ExpectEq("/areas/northern-road/lower-northern-wilds/18x8.c",
        cellar->getExitDirections()["default"]["up"]);
    ExpectTrue(sizeof(filter(northboundRoad["items"],
        (: $1["name"] == "milestone" :))) > 0,
        "24x8 N7 milestone");

    destruct(region);
}

void NorthernN6RegionIsAuthored()
{
    validateAuthoredRegions(({ "/areas/northern-road/lower-northern-wilds/region.c" }));
}

void NorthernN6EncountersStayAtOpeningLevels()
{
    object room = clone_object("/areas/northern-road/lower-northern-wilds/7x2.c");
    move_object(Player, room);
    int count = 0;

    foreach (object encounter in all_inventory(room))
    {
        if (encounter != Player && member(inherit_list(encounter),
            "/lib/realizations/monster.c") >= 0)
        {
            ExpectTrue(encounter->effectiveLevel() >= 1 &&
                encounter->effectiveLevel() <= 6,
                "N6 encounter level stays within 1-6");
            count++;
            Spawned += ({ encounter });
        }
    }
    ExpectTrue(count <= 3, "N6 encounter count stays within 3");
}

void NorthernN6ResidentsArePresent()
{
    expectN6ResidentAt("/areas/northern-road/lower-northern-wilds/7x2.c", "Elaron");
    expectN6ResidentAt("/areas/northern-road/lower-northern-wilds/12x4.c", "Nimwen");
    expectN6ResidentAt("/areas/northern-road/lower-northern-wilds/18x6.c", "Calendir");
}
