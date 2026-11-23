//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/tests/environment/eledhelCountrysideTest.c";

void Init()
{
    selectTestMethods(({
        "EolachApproachHasThePlannedScale",
        "EolachApproachConnectsToTheRoadAndKeep",
        "EolachApproachShowsFarmsAndManagedBowwood",
        "EolachUsesDomainInfrastructure",
        "EolachHasItsResidentsAndGateArchers",
        "EolachRegionsAreAuthored"
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

protected void expectEolachResidentAt(string path, string name)
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

void EolachApproachHasThePlannedScale()
{
    object region = clone_object(
        "/areas/eledhel/estates/eolach/approach/region.c");

    ExpectEq(26, shortestRoomPathInRegion(region,
        "/areas/eledhel/estates/eolach/approach/0x0.c",
        "/areas/eledhel/estates/eolach/approach/8x2.c"));
    ExpectEq(9, region->xDimension());
    ExpectEq(3, region->yDimension());
    destruct(region);
}

void EolachApproachConnectsToTheRoadAndKeep()
{
    object approachStart = load_object(
        "/areas/eledhel/estates/eolach/approach/0x0.c");
    object approachEnd = load_object(
        "/areas/eledhel/estates/eolach/approach/8x2.c");
    object grounds = load_object(
        "/areas/eledhel/estates/eolach/grounds/0x0.c");
    object yard = load_object(
        "/areas/eledhel/estates/eolach/grounds/2x1.c");
    object keep = load_object(
        "/areas/eledhel/estates/eolach/keep-interior/0x0.c");

    ExpectEq("/areas/northern-road/belathon-eolach/5x4.c",
        approachStart->getExitDirections()["default"]["south"]);
    ExpectEq("/areas/eledhel/estates/eolach/approach/0x0.c",
        load_object("/areas/northern-road/belathon-eolach/5x4.c")->
            getExitDirections()["default"]["north"]);
    ExpectEq("/areas/eledhel/estates/eolach/grounds/0x0.c",
        approachEnd->getExitDirections()["default"]["east"]);
    ExpectEq("/areas/eledhel/estates/eolach/approach/8x2.c",
        grounds->getExitDirections()["default"]["west"]);
    ExpectEq("/areas/eledhel/estates/eolach/keep-interior/0x0.c",
        yard->getExitDirections()["default"]["east"]);
    ExpectEq("/areas/eledhel/estates/eolach/grounds/2x1.c",
        keep->getExitDirections()["default"]["west"]);
}

void EolachUsesDomainInfrastructure()
{
    object service = getService("domain");
    mapping holding = service->getAuthoredHolding("house eolach");

    ExpectTrue(mappingp(holding));
    ExpectEq("house-eolach", holding["id"]);
    ExpectEq("Lord Balechor", holding["owner"]);
    ExpectEq("/areas/eledhel/estates/eolach/grounds/0x2.c",
        holding["entry point"]);
    ExpectFalse(service->getPlayerHolding(Player, "house eolach"));
    ExpectTrue(sizeof(service->getPlayerDomain(
        Player, "house eolach", "keep")["layout"]) > 0);
}

void EolachHasItsResidentsAndGateArchers()
{
    expectEolachResidentAt(
        "/areas/eledhel/estates/eolach/keep-interior/1x0.c", "Balechor");
    expectEolachResidentAt(
        "/areas/eledhel/estates/eolach/grounds/0x2.c",
        "Eolach steward");
    expectEolachResidentAt(
        "/areas/eledhel/estates/eolach/keep-interior/0x0.c",
        "Eolach archer");

    int archers = 0;
    string *garrisonRooms = ({
        "/areas/eledhel/estates/eolach/grounds/0x0.c",
        "/areas/eledhel/estates/eolach/grounds/1x0.c",
        "/areas/eledhel/estates/eolach/grounds/2x0.c",
        "/areas/eledhel/estates/eolach/grounds/0x1.c",
        "/areas/eledhel/estates/eolach/grounds/1x1.c",
        "/areas/eledhel/estates/eolach/grounds/2x1.c",
        "/areas/eledhel/estates/eolach/grounds/0x2.c",
        "/areas/eledhel/estates/eolach/grounds/1x2.c",
        "/areas/eledhel/estates/eolach/grounds/2x2.c",
        "/areas/eledhel/estates/eolach/keep-interior/0x0.c",
        "/areas/eledhel/estates/eolach/keep-interior/1x0.c",
        "/areas/eledhel/estates/eolach/keep-interior/2x0.c"
    });

    foreach (string path in garrisonRooms)
    {
        object room = clone_object(path);
        Harvested += ({ room });
        move_object(Player, room);

        foreach (object resident in all_inventory(room))
        {
            if (resident != Player &&
                function_exists("isRealizationOfNpc", resident) &&
                resident->isRealizationOfNpc() &&
                resident->id("Eolach archer"))
            {
                archers++;
                Spawned += ({ resident });
            }
        }
    }
    ExpectEq(12, archers);
}

void EolachApproachShowsFarmsAndManagedBowwood()
{
    object barleyRoom = load_object(
        "/areas/eledhel/estates/eolach/approach/1x0.c");
    object coppiceRoom = load_object(
        "/areas/eledhel/estates/eolach/approach/4x1.c");
    object markedTimberRoom = load_object(
        "/areas/eledhel/estates/eolach/approach/6x1.c");
    object harvestRoom = load_object(
        "/areas/eledhel/estates/eolach/approach/4x2.c");
    object noticeRoom = load_object(
        "/areas/eledhel/estates/eolach/approach/0x1.c");

    mapping barley = barleyRoom->buildRoomSnapshot();
    mapping coppice = coppiceRoom->buildRoomSnapshot();
    mapping markedTimber = markedTimberRoom->buildRoomSnapshot();
    mapping harvest = harvestRoom->buildRoomSnapshot();
    mapping notice = noticeRoom->buildRoomSnapshot();

    ExpectTrue(sizeof(filter(barley["features"],
        (: $1["name"] == "tenant barley field" :))) > 0);
    ExpectTrue(sizeof(filter(barley["features"],
        (: $1["name"] == "field drain" :))) > 0);
    ExpectTrue(sizeof(filter(coppice["features"],
        (: $1["name"] == "managed ash coppice" :))) > 0);
    ExpectTrue(sizeof(filter(markedTimber["features"],
        (: $1["name"] == "marked timber plot" :))) > 0);
    ExpectTrue(sizeof(filter(harvest["features"],
        (: $1["name"] == "tenant threshing floor" :))) > 0);
    ExpectTrue(sizeof(filter(harvest["items"],
        (: $1["name"] == "hand cart" :))) > 0);
    ExpectTrue(sizeof(filter(notice["items"],
        (: $1["name"] == "Eolach forester's board" :))) > 0);

    expectEolachResidentAt(
        "/areas/eledhel/estates/eolach/approach/8x1.c", "Eolach archer");
}

void EolachRegionsAreAuthored()
{
    validateAuthoredRegions(({
        "/areas/eledhel/estates/eolach/approach/region.c",
        "/areas/eledhel/estates/eolach/grounds/region.c",
        "/areas/eledhel/estates/eolach/keep-interior/region.c"
    }));
}
