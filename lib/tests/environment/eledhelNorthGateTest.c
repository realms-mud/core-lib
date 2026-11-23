//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/tests/environment/eledhelCountrysideTest.c";

void Init()
{
    selectTestMethods(({
        "NorthGateRouteMeasuresTenMilesToErator",
        "NorthGateConnectsTheCapitalAladainAndNorthernRoad",
        "NorthGateMarketGardensShowWorkingPlots",
        "NorthGateRouteShowsWorkingCountryside",
        "NorthGateRegionsAreAuthored",
        "NorthGateEncounterPoolsStayAtOpeningLevels",
        "NorthGateResidentsAppearAtTheirWorksites",
        "EratorUsesTheDomainInfrastructure"
    }));
}

void NorthGateRouteMeasuresTenMilesToErator()
{
    object region = clone_object("/areas/northern-road/north-gate/region.c");

    ExpectEq(53, shortestRoomPathInRegion(region,
        "/areas/northern-road/north-gate/0x0.c",
        "/areas/northern-road/north-gate/9x8.c"));
    ExpectEq(25, region->xDimension());
    ExpectEq(10, region->yDimension());
    destruct(region);
}

void NorthGateConnectsTheCapitalAladainAndNorthernRoad()
{
    object oldNorthRoad = load_object(
        "/areas/eledhel/north-road/2x0.c");
    object northEntry = load_object("/areas/northern-road/north-gate/0x0.c");
    object aladainRoad = load_object(
        "/areas/eledhel/central-rural/21x3.c");
    object lane = load_object("/areas/northern-road/north-gate/3x4.c");
    object eratorRoad = load_object("/areas/northern-road/north-gate/9x8.c");
    object eratorLane = load_object("/areas/northern-road/north-gate/9x9.c");
    object eratorEntry = load_object(
        "/areas/eledhel/estates/erator/grounds/0x0.c");
    object coast = load_object("/areas/northern-road/gundil-coast/0x0.c");
    object marketGate = load_object(
        "/areas/northern-road/north-gate/market-gardens/2x4.c");

    ExpectEq("/areas/northern-road/north-gate/0x0.c",
        oldNorthRoad->getExitDirections()["default"]["east"]);
    ExpectEq("/areas/eledhel/north-road/2x0.c",
        northEntry->getExitDirections()["default"]["west"]);
    ExpectEq("/areas/northern-road/north-gate/3x3.c",
        aladainRoad->getExitDirections()["default"]["west"]);
    ExpectEq("/areas/northern-road/north-gate/3x3.c",
        lane->getExitDirections()["default"]["north"]);
    ExpectEq("/areas/eledhel/estates/erator/grounds/0x0.c",
        eratorLane->getExitDirections()["default"]["south"]);
    ExpectEq("/areas/northern-road/north-gate/9x9.c",
        eratorEntry->getExitDirections()["default"]["north"]);
    ExpectEq("/areas/northern-road/gundil-coast/0x0.c",
        eratorRoad->getExitDirections()["default"]["north"]);
    ExpectEq("/areas/northern-road/north-gate/9x8.c",
        coast->getExitDirections()["default"]["south"]);
    ExpectEq("/areas/northern-road/north-gate/10x5.c",
        load_object("/areas/northern-road/north-gate/9x5.c")->
            getExitDirections()["default"]["east"]);
    ExpectEq("/areas/northern-road/north-gate/12x5.c",
        marketGate->getExitDirections()["default"]["south"]);
    ExpectEq("/areas/northern-road/north-gate/market-gardens/2x4.c",
        load_object("/areas/northern-road/north-gate/12x5.c")->
            getExitDirections()["default"]["north"]);
}

void NorthGateMarketGardensShowWorkingPlots()
{
    object region = clone_object("/areas/northern-road/north-gate/region.c");
    string *locations = ({
        "10x0", "10x1", "10x2", "10x3", "10x4",
        "11x0", "11x1", "11x2", "11x3", "11x4",
        "12x0", "12x1", "12x2", "12x3", "12x4",
        "13x0", "13x1", "13x2", "13x3", "13x4",
        "14x0", "14x1", "14x2", "14x3", "14x4"
    });

    foreach (string location in locations)
    {
        object room = region->getEnvironment(location);
        mapping snapshot = room->buildRoomSnapshot();

        ExpectTrue(sizeof(filter(snapshot["features"],
            (: $1["name"] == "dirt road" :))) > 0, location);
    }

    mapping crops = region->getEnvironment("11x2")->buildRoomSnapshot();
    mapping sluice = region->getEnvironment("13x1")->buildRoomSnapshot();
    mapping irrigation = region->getEnvironment("13x3")->buildRoomSnapshot();
    mapping dispatch = region->getEnvironment("12x2")->buildRoomSnapshot();

    ExpectTrue(sizeof(filter(crops["features"],
        (: $1["name"] == "common root beds" :))) > 0);
    ExpectTrue(sizeof(filter(sluice["features"],
        (: $1["name"] == "silted sluice" :))) > 0);
    ExpectTrue(sizeof(filter(irrigation["features"],
        (: $1["name"] == "field drain" :))) > 0);
    ExpectTrue(sizeof(filter(dispatch["items"],
        (: $1["name"] == "market stall" :))) > 0);

    ExpectTrue(shortestRoomPathInRegion(region,
        "/areas/northern-road/north-gate/0x0.c",
        "/areas/northern-road/north-gate/market-gardens/2x4.c") > 0);

    destruct(region);
}

void NorthGateRouteShowsWorkingCountryside()
{
    object region = clone_object("/areas/northern-road/north-gate/region.c");
    mapping farm = region->getEnvironment("4x5")->buildRoomSnapshot();
    mapping meadow = region->getEnvironment("6x6")->buildRoomSnapshot();
    mapping woodland = region->getEnvironment("8x8")->buildRoomSnapshot();

    ExpectTrue(sizeof(filter(farm["features"],
        (: $1["name"] == "field drain" :))) > 0, "4x5 field drain");
    ExpectTrue(sizeof(filter(farm["features"],
        (: $1["name"] == "alder stand" :))) > 0, "4x5 alder stand");
    ExpectTrue(sizeof(filter(farm["items"],
        (: $1["name"] == "stone pile" :))) > 0, "4x5 sluice stones");
    ExpectTrue(sizeof(filter(meadow["features"],
        (: $1["name"] == "hillock" :))) > 0, "6x6 hillock");
    ExpectTrue(sizeof(filter(meadow["features"],
        (: $1["name"] == "rock spring" :))) > 0, "6x6 spring");
    ExpectTrue(sizeof(filter(woodland["features"],
        (: $1["name"] == "birch stand" :))) > 0, "8x8 birch stand");
    ExpectTrue(sizeof(filter(woodland["items"],
        (: $1["name"] == "fox tracks" :))) > 0, "8x8 fox tracks");

    destruct(region);
}

void NorthGateRegionsAreAuthored()
{
    validateAuthoredRegions(({
        "/areas/northern-road/north-gate/region.c",
        "/areas/eledhel/estates/erator/grounds/region.c",
        "/areas/eledhel/estates/erator/keep-interior/region.c"
    }));
}

void EratorUsesTheDomainInfrastructure()
{
    object service = getService("domain");
    mapping holding = service->getAuthoredHolding("house erator");

    ExpectTrue(mappingp(holding));
    ExpectEq("house-erator", holding["id"]);
    ExpectEq("House Erator", holding["name"]);
    ExpectEq("House Erator", holding["owner"]);
    ExpectEq("keep", holding["type"]);
    ExpectFalse(service->getPlayerHolding(Player, "house erator"));
    ExpectEq("/areas/eledhel/estates/erator/grounds/0x0.c",
        holding["entry point"]);
}

void NorthGateEncounterPoolsStayAtOpeningLevels()
{
    object region = clone_object("/areas/northern-road/north-gate/region.c");
    string *locations = ({
        "0x0",
        "7x0",
        "0x7",
        "1x6",
        "6x8"
    });

    foreach (string location in locations)
    {
        object room = region->getEnvironment(location);
        string path = sprintf("/areas/northern-road/north-gate/%s.c",
            location);
        move_object(Player, room);
        int count = 0;
        foreach (object encounter in all_inventory(room))
        {
            if (encounter != Player)
            {
                ExpectTrue(encounter->effectiveLevel() >= 1 &&
                    encounter->effectiveLevel() <= 3, path);
                ExpectTrue(member(inherit_list(encounter),
                    "/lib/realizations/monster.c") >= 0, path);
                count++;
                Harvested += ({ encounter });
            }
        }
        ExpectTrue(count >= 1 && count <= 3, path);
    }
    string *gardenLocations = ({ "10x0", "14x2", "10x3", "14x4" });
    string *gardenPaths = ({ "0x0", "4x2", "0x3", "4x4" });
    for (int index = 0; index < sizeof(gardenLocations); index++)
    {
        object gardenRoom = region->getEnvironment(gardenLocations[index]);
        string gardenPath = sprintf(
            "/areas/northern-road/north-gate/market-gardens/%s.c", gardenPaths[index]);
        move_object(Player, gardenRoom);
        int gardenCount = 0;
        foreach (object gardenEncounter in all_inventory(gardenRoom))
        {
            if (gardenEncounter != Player)
            {
                ExpectTrue(gardenEncounter->effectiveLevel() >= 1 &&
                    gardenEncounter->effectiveLevel() <= 3, gardenPath);
                ExpectTrue(member(inherit_list(gardenEncounter),
                    "/lib/realizations/monster.c") >= 0, gardenPath);
                gardenCount++;
                Harvested += ({ gardenEncounter });
            }
        }
        ExpectTrue(gardenCount >= 1 && gardenCount <= 3, gardenPath);
    }
    destruct(region);
}

void NorthGateResidentsAppearAtTheirWorksites()
{
    mapping residents = ([
        "/areas/northern-road/north-gate/4x1.c": "Maerwen",
        "/areas/northern-road/north-gate/4x5.c": "Daereth",
        "/areas/eledhel/estates/erator/grounds/2x1.c": "Elenwen",
        "/areas/northern-road/north-gate/market-gardens/2x2.c": "Aelwen",
        "/areas/northern-road/north-gate/market-gardens/3x1.c": "Mereneth"
    ]);

    foreach (string path, string name in residents)
    {
        object room = clone_object(path);
        Harvested += ({ room });
        move_object(Player, room);
        int foundResident = 0;
        foreach (object resident in all_inventory(room))
        {
            if (resident != Player &&
                function_exists("isRealizationOfNpc", resident) &&
                resident->isRealizationOfNpc())
            {
                ExpectTrue(resident->id(name), path);
                foundResident++;
                Spawned += ({ resident });
            }
        }
        ExpectEq(1, foundResident, path);
    }
}
