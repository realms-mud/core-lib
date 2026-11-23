//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/tests/environment/eledhelCountrysideTest.c";

void Init()
{
    selectTestMethods(({
        "NorthernRoadMeasuresGundilAndBelectarDistances",
        "NorthernRoadConnectsTheCapitalVillageAndNextStage",
        "NorthernHouseRegionsAreAuthored",
        "NorthernHousesUseDomainInfrastructure",
        "GundilAndBelectarResidentsArePresent",
        "NorthernRoadEncountersStayAtOpeningLevels"
    }));
}

void NorthernRoadMeasuresGundilAndBelectarDistances()
{
    object region = clone_object("/areas/northern-road/gundil-coast/region.c");
    ExpectEq(53, shortestRoomPathInRegion(region,
        "/areas/northern-road/gundil-coast/0x0.c",
        "/areas/northern-road/gundil-coast/9x8.c"));
    ExpectEq(10, region->xDimension());
    ExpectEq(10, region->yDimension());
    destruct(region);

    region = clone_object(
        "/areas/eledhel/estates/belectar/approach/region.c");
    ExpectEq(26, shortestRoomPathInRegion(region,
        "/areas/eledhel/estates/belectar/approach/0x0.c",
        "/areas/eledhel/estates/belectar/approach/6x4.c"));
    ExpectEq(9, region->xDimension());
    ExpectEq(5, region->yDimension());
    destruct(region);
}

void NorthernRoadConnectsTheCapitalVillageAndNextStage()
{
    object n1 = load_object("/areas/northern-road/north-gate/9x8.c");
    object n2Start = load_object("/areas/northern-road/gundil-coast/0x0.c");
    object n2End = load_object("/areas/northern-road/gundil-coast/9x8.c");
    object n3 = load_object("/areas/northern-road/northern-manor/0x0.c");
    object village = load_object(
        "/areas/northern-road/gundil-coast/gundil-village/0x2.c");
    object grounds = load_object(
        "/areas/eledhel/estates/gundil/grounds/0x0.c");
    object gundilApproach = load_object(
        "/areas/eledhel/estates/gundil/grounds/0x1.c");
    object belectarStart = load_object(
        "/areas/eledhel/estates/belectar/approach/0x0.c");
    object belectarEnd = load_object(
        "/areas/eledhel/estates/belectar/approach/6x4.c");
    object belectarGrounds = load_object(
        "/areas/eledhel/estates/belectar/grounds/0x0.c");

    ExpectEq("/areas/northern-road/gundil-coast/0x0.c",
        n1->getExitDirections()["default"]["north"]);
    ExpectEq("/areas/northern-road/north-gate/9x8.c",
        n2Start->getExitDirections()["default"]["south"]);
    ExpectEq("/areas/northern-road/northern-manor/0x0.c",
        n2End->getExitDirections()["default"]["north"]);
    ExpectEq("/areas/northern-road/gundil-coast/9x8.c",
        n3->getExitDirections()["default"]["south"]);
    ExpectEq("/areas/northern-road/gundil-coast/gundil-village/0x2.c",
        n2End->getExitDirections()["default"]["east"]);
    ExpectEq("/areas/northern-road/gundil-coast/9x8.c",
        village->getExitDirections()["default"]["west"]);
    ExpectEq("/areas/eledhel/estates/gundil/grounds/0x0.c",
        load_object(
            "/areas/northern-road/gundil-coast/gundil-village/4x2.c")->
                getExitDirections()["default"]["east"]);
    ExpectEq("/areas/northern-road/gundil-coast/gundil-village/4x2.c",
        grounds->getExitDirections()["default"]["west"]);
    ExpectEq("/areas/eledhel/estates/belectar/approach/0x0.c",
        gundilApproach->getExitDirections()["default"]["east"]);
    ExpectEq("/areas/eledhel/estates/gundil/grounds/0x1.c",
        belectarStart->getExitDirections()["default"]["west"]);
    ExpectEq("/areas/eledhel/estates/belectar/grounds/0x0.c",
        belectarEnd->getExitDirections()["default"]["east"]);
    ExpectEq("/areas/eledhel/estates/belectar/approach/6x4.c",
        belectarGrounds->getExitDirections()["default"]["west"]);
}

void NorthernHouseRegionsAreAuthored()
{
    validateAuthoredRegions(({
        "/areas/northern-road/gundil-coast/region.c",
        "/areas/northern-road/gundil-coast/gundil-village/region.c",
        "/areas/eledhel/estates/gundil/grounds/region.c",
        "/areas/eledhel/estates/gundil/keep-interior/region.c",
        "/areas/eledhel/estates/belectar/approach/region.c",
        "/areas/eledhel/estates/belectar/grounds/region.c",
        "/areas/eledhel/estates/belectar/keep-interior/region.c"
    }));
}

void NorthernHousesUseDomainInfrastructure()
{
    object service = getService("domain");
    mapping gundil = service->getAuthoredHolding("house gundil");
    mapping belectar = service->getAuthoredHolding("house belectar");

    ExpectTrue(mappingp(gundil));
    ExpectEq("house-gundil", gundil["id"]);
    ExpectEq("House Gundil", gundil["name"]);
    ExpectEq("Lord Gruffyd and Lady Alyssa", gundil["owner"]);
    ExpectEq("keep", gundil["type"]);
    ExpectFalse(service->getPlayerHolding(Player, "house gundil"));
    ExpectTrue(sizeof(service->getPlayerDomain(
        Player, "house gundil", "keep")["layout"]) > 0);

    ExpectTrue(mappingp(belectar));
    ExpectEq("house-belectar", belectar["id"]);
    ExpectEq("House Belectar", belectar["name"]);
    ExpectEq("Lord Arawn Belectar", belectar["owner"]);
    ExpectEq("keep", belectar["type"]);
    ExpectFalse(service->getPlayerHolding(Player, "house belectar"));
    ExpectTrue(sizeof(service->getPlayerDomain(
        Player, "house belectar", "keep")["layout"]) > 0);
}

protected void expectResidentAt(string path, string name)
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

void GundilAndBelectarResidentsArePresent()
{
    expectResidentAt(
        "/areas/northern-road/gundil-coast/gundil-village/2x2.c", "Calwen");
    expectResidentAt(
        "/areas/northern-road/gundil-coast/gundil-village/4x3.c", "Dairen");
    expectResidentAt(
        "/areas/northern-road/gundil-coast/gundil-village/4x4.c", "Aereth");
    expectResidentAt(
        "/areas/eledhel/estates/gundil/keep-interior/1x0.c",
        "Gruffyd");
    expectResidentAt(
        "/areas/eledhel/estates/belectar/keep-interior/1x0.c",
        "Arawn");
}

void NorthernRoadEncountersStayAtOpeningLevels()
{
    object region = clone_object("/areas/northern-road/gundil-coast/region.c");
    object room = region->getEnvironment("4x4");
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
            Harvested += ({ encounter });
        }
    }
    ExpectTrue(count >= 1 && count <= 3);
    destruct(region);
}
