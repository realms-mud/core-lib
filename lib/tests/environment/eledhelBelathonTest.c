//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/tests/environment/eledhelCountrysideTest.c";

void Init()
{
    selectTestMethods(({
        "BelathonApproachHasThePlannedScale",
        "BelathonApproachConnectsToTheRoadAndHold",
        "BelathonUsesDomainInfrastructure",
        "BelathonHasItsHouseholdPresent",
        "BelathonRegionsAreAuthored"
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

protected void expectBelathonResidentAt(string path, string name)
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

void BelathonApproachHasThePlannedScale()
{
    object region = clone_object(
        "/areas/eledhel/estates/belathon/approach/region.c");

    ExpectEq(8, shortestRoomPathInRegion(region,
        "/areas/eledhel/estates/belathon/approach/0x0.c",
        "/areas/eledhel/estates/belathon/approach/0x8.c"));
    ExpectEq(1, region->xDimension());
    ExpectEq(9, region->yDimension());
    destruct(region);
}

void BelathonApproachConnectsToTheRoadAndHold()
{
    object approachEnd = load_object(
        "/areas/eledhel/estates/belathon/approach/0x8.c");
    object grounds = load_object(
        "/areas/eledhel/estates/belathon/grounds/0x0.c");
    object yard = load_object(
        "/areas/eledhel/estates/belathon/grounds/2x1.c");
    object keep = load_object(
        "/areas/eledhel/estates/belathon/keep-interior/0x0.c");

    ExpectEq("/areas/eledhel/estates/belathon/grounds/0x0.c",
        approachEnd->getExitDirections()["default"]["east"]);
    ExpectEq("/areas/eledhel/estates/belathon/approach/0x8.c",
        grounds->getExitDirections()["default"]["west"]);
    ExpectEq("/areas/eledhel/estates/belathon/keep-interior/0x0.c",
        yard->getExitDirections()["default"]["east"]);
    ExpectEq("/areas/eledhel/estates/belathon/grounds/2x1.c",
        keep->getExitDirections()["default"]["west"]);
}

void BelathonUsesDomainInfrastructure()
{
    object service = getService("domain");
    mapping holding = service->getAuthoredHolding("house belathon");

    ExpectTrue(mappingp(holding));
    ExpectEq("house-belathon", holding["id"]);
    ExpectEq("Brena Belathon", holding["owner"]);
    ExpectEq("/areas/eledhel/estates/belathon/grounds/0x2.c",
        holding["entry point"]);
    ExpectFalse(service->getPlayerHolding(Player, "house belathon"));
    ExpectTrue(sizeof(service->getPlayerDomain(
        Player, "house belathon", "keep")["layout"]) > 0);
}

void BelathonHasItsHouseholdPresent()
{
    expectBelathonResidentAt(
        "/areas/eledhel/estates/belathon/keep-interior/1x0.c", "Brena");
    expectBelathonResidentAt(
        "/areas/eledhel/estates/belathon/keep-interior/1x0.c", "Harumel");
    expectBelathonResidentAt(
        "/areas/eledhel/estates/belathon/grounds/1x2.c", "Haldreth");
}

void BelathonRegionsAreAuthored()
{
    validateAuthoredRegions(({
        "/areas/eledhel/estates/belathon/approach/region.c",
        "/areas/eledhel/estates/belathon/grounds/region.c",
        "/areas/eledhel/estates/belathon/keep-interior/region.c"
    }));
}
