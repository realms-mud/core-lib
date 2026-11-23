//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/tests/environment/eledhelCountrysideTest.c";

void Init()
{
    selectTestMethods(({
        "HrondilRoadAndApproachAreConnected",
        "HrondilKeepAndVillageAreConnected",
        "HrondilUsesDomainInfrastructure",
        "HrondilRegionsAreAuthored",
        "HrondilHouseholdAndVillagersArePresent"
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

protected void expectHrondilResidentAt(string path, string name)
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

void HrondilRoadAndApproachAreConnected()
{
    object region = clone_object("/areas/hrondil/region.c");
    object road = load_object("/areas/northern-road/hrondil-approaches/12x4.c");
    object approach = load_object("/areas/hrondil/approach/0x0.c");
    object approachEnd = load_object("/areas/hrondil/approach/0x8.c");
    object grounds = load_object("/areas/hrondil/grounds/0x0.c");
    object approachRegion = clone_object(
        "/areas/hrondil/approach/region.c");

    ExpectEq(128, shortestRoomPathInRegion(region,
        "/areas/northern-road/hrondil-approaches/0x0.c",
        "/areas/northern-road/hrondil-approaches/24x8.c"));
    ExpectEq(8, shortestRoomPathInRegion(approachRegion,
        "/areas/hrondil/approach/0x0.c",
        "/areas/hrondil/approach/0x8.c"));
    ExpectEq("/areas/hrondil/approach/0x0.c",
        road->getExitDirections()["default"]["north"]);
    ExpectEq("/areas/northern-road/hrondil-approaches/12x4.c",
        approach->getExitDirections()["default"]["south"]);
    ExpectEq("/areas/hrondil/grounds/0x0.c",
        approachEnd->getExitDirections()["default"]["east"]);
    ExpectEq("/areas/hrondil/approach/0x8.c",
        grounds->getExitDirections()["default"]["west"]);
    destruct(region);
    destruct(approachRegion);
}

void HrondilKeepAndVillageAreConnected()
{
    object grounds = load_object("/areas/hrondil/grounds/1x2.c");
    object village = load_object("/areas/hrondil/village/0x0.c");
    object keepYard = load_object("/areas/hrondil/grounds/2x1.c");
    object keep = load_object("/areas/hrondil/keep-interior/0x0.c");

    ExpectEq("/areas/hrondil/village/0x0.c",
        grounds->getExitDirections()["default"]["north"]);
    ExpectEq("/areas/hrondil/grounds/1x2.c",
        village->getExitDirections()["default"]["south"]);
    ExpectEq("/areas/hrondil/keep-interior/0x0.c",
        keepYard->getExitDirections()["default"]["east"]);
    ExpectEq("/areas/hrondil/grounds/2x1.c",
        keep->getExitDirections()["default"]["west"]);
}

void HrondilUsesDomainInfrastructure()
{
    object service = getService("domain");
    mapping holding = service->getAuthoredHolding("house hrondil");

    ExpectTrue(mappingp(holding));
    ExpectEq("house-hrondil", holding["id"]);
    ExpectEq("Lord Gunther Hrondil", holding["owner"]);
    ExpectEq("/areas/hrondil/grounds/0x0.c", holding["entry point"]);
    ExpectFalse(service->getPlayerHolding(Player, "house hrondil"));
    ExpectTrue(sizeof(service->getPlayerDomain(
        Player, "house hrondil", "keep")["layout"]) > 0);
}

void HrondilRegionsAreAuthored()
{
    validateAuthoredRegions(({
        "/areas/hrondil/region.c",
        "/areas/hrondil/approach/region.c",
        "/areas/hrondil/grounds/region.c",
        "/areas/hrondil/village/region.c",
        "/areas/hrondil/keep-interior/region.c"
    }));
}

void HrondilHouseholdAndVillagersArePresent()
{
    expectHrondilResidentAt(
        "/areas/hrondil/keep-interior/1x0.c", "Gunther Hrondil");
    expectHrondilResidentAt(
        "/areas/hrondil/keep-interior/0x0.c", "Hrondil keep guard");
    expectHrondilResidentAt(
        "/areas/hrondil/village/1x1.c", "Gwineth");
    expectHrondilResidentAt(
        "/areas/hrondil/village/2x0.c", "Mellor");
}
