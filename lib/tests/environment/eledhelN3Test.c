//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/tests/environment/eledhelCountrysideTest.c";

void Init()
{
    selectTestMethods(({
        "NorthernManorRoadHasThePlannedScale",
        "NorthernManorRoadConnectionsAreReciprocal",
        "NorthernManorRoadShowsWorkingLandscape",
        "NorthernManorRegionsAreAuthored",
        "NorthernManorsUseDomainInfrastructure",
        "NorthernManorsHaveNamedResidents",
        "NorthernManorRoadEncountersStayAtOpeningLevels"
    }));
}

void NorthernManorRoadHasThePlannedScale()
{
    object region = clone_object("/areas/northern-road/northern-manor/region.c");

    ExpectEq(128, shortestRoomPathInRegion(region,
        "/areas/northern-road/northern-manor/0x0.c",
        "/areas/northern-road/northern-manor/24x8.c"));
    ExpectEq(55, shortestRoomPathInRegion(region,
        "/areas/northern-road/northern-manor/0x0.c",
        "/areas/northern-road/northern-manor/3x4.c"));
    ExpectEq(110, shortestRoomPathInRegion(region,
        "/areas/northern-road/northern-manor/0x0.c",
        "/areas/northern-road/northern-manor/6x8.c"));
    ExpectEq(83, shortestRoomPathInRegion(region,
        "/areas/northern-road/northern-manor/0x0.c",
        "/areas/northern-road/northern-manor/19x6.c"));
    ExpectEq(25, region->xDimension());
    ExpectEq(10, region->yDimension());
    destruct(region);

    object westRoad = clone_object(
        "/areas/eledhel/estates/kirin/approach/region.c");
    object manorRoad = clone_object(
        "/areas/eledhel/estates/kirin/approach/second/region.c");

    int westLinks = shortestRoomPathInRegion(westRoad,
        "/areas/eledhel/estates/kirin/approach/0x0.c",
        "/areas/eledhel/estates/kirin/approach/13x0.c");
    int manorLinks = shortestRoomPathInRegion(manorRoad,
        "/areas/eledhel/estates/kirin/approach/second/0x0.c",
        "/areas/eledhel/estates/kirin/approach/second/12x0.c");
    ExpectEq(13, westLinks);
    ExpectEq(12, manorLinks);
    ExpectEq(26, westLinks + 1 + manorLinks);
    ExpectEq(14, westRoad->xDimension());
    ExpectEq(13, manorRoad->xDimension());
    destruct(westRoad);
    destruct(manorRoad);
}

void NorthernManorRoadConnectionsAreReciprocal()
{
    object n2 = load_object("/areas/northern-road/gundil-coast/9x8.c");
    object n3Start = load_object("/areas/northern-road/northern-manor/0x0.c");
    object n3End = load_object("/areas/northern-road/northern-manor/24x8.c");
    object n4 = load_object("/areas/northern-road/belathon-eolach/0x0.c");
    object anduradanRoad = load_object("/areas/northern-road/northern-manor/3x4.c");
    object anduradan = load_object(
        "/areas/eledhel/estates/anduradan/grounds/0x2.c");
    object dalthrenRoad = load_object("/areas/northern-road/northern-manor/6x8.c");
    object dalthren = load_object(
        "/areas/eledhel/estates/dalthren/grounds/0x2.c");
    object argalenRoad = load_object("/areas/northern-road/northern-manor/19x6.c");
    object coast = load_object(
        "/areas/argalen-keep/patrol-coast/24x4.c");
    object westStart = load_object(
        "/areas/eledhel/estates/kirin/approach/0x0.c");
    object westEnd = load_object(
        "/areas/eledhel/estates/kirin/approach/13x0.c");
    object manorStart = load_object(
        "/areas/eledhel/estates/kirin/approach/second/0x0.c");
    object manorEnd = load_object(
        "/areas/eledhel/estates/kirin/approach/second/12x0.c");
    object kirin = load_object(
        "/areas/eledhel/estates/kirin/grounds/0x2.c");

    ExpectEq("/areas/northern-road/northern-manor/0x0.c",
        n2->getExitDirections()["default"]["north"]);
    ExpectEq("/areas/northern-road/gundil-coast/9x8.c",
        n3Start->getExitDirections()["default"]["south"]);
    ExpectEq("/areas/northern-road/belathon-eolach/0x0.c",
        n3End->getExitDirections()["default"]["north"]);
    ExpectEq("/areas/northern-road/northern-manor/24x8.c",
        n4->getExitDirections()["default"]["south"]);
    ExpectEq("/areas/eledhel/estates/anduradan/grounds/0x2.c",
        anduradanRoad->getExitDirections()["default"]["north"]);
    ExpectEq("/areas/northern-road/northern-manor/3x4.c",
        anduradan->getExitDirections()["default"]["south"]);
    ExpectEq("/areas/eledhel/estates/dalthren/grounds/0x2.c",
        dalthrenRoad->getExitDirections()["default"]["north"]);
    ExpectEq("/areas/northern-road/northern-manor/6x8.c",
        dalthren->getExitDirections()["default"]["south"]);
    ExpectEq("/areas/argalen-keep/patrol-coast/24x4.c",
        argalenRoad->getExitDirections()["default"]["south"]);
    ExpectEq("/areas/northern-road/northern-manor/19x6.c",
        coast->getExitDirections()["default"]["north"]);
    ExpectEq("coast trail north-west corner",
        coast->decoratorType(0));
    ExpectEq("/areas/eledhel/estates/dalthren/grounds/0x2.c",
        westStart->getExitDirections()["default"]["west"]);
    ExpectEq("/areas/eledhel/estates/kirin/approach/second/0x0.c",
        westEnd->getExitDirections()["default"]["east"]);
    ExpectEq("/areas/eledhel/estates/kirin/approach/13x0.c",
        manorStart->getExitDirections()["default"]["west"]);
    ExpectEq("/areas/eledhel/estates/kirin/grounds/0x2.c",
        manorEnd->getExitDirections()["default"]["east"]);
    ExpectEq("/areas/eledhel/estates/kirin/approach/second/12x0.c",
        kirin->getExitDirections()["default"]["west"]);
}

void NorthernManorRoadShowsWorkingLandscape()
{
    object region = clone_object("/areas/northern-road/northern-manor/region.c");
    mapping farm = region->getEnvironment("1x4")->buildRoomSnapshot();
    mapping orchard = region->getEnvironment("3x4")->buildRoomSnapshot();
    mapping woodland = region->getEnvironment("3x6")->buildRoomSnapshot();
    mapping manorialField = region->getEnvironment("5x4")->
        buildRoomSnapshot();
    mapping exposedRoad = region->getEnvironment("5x8")->
        buildRoomSnapshot();
    mapping dalthrenTurnoff = region->getEnvironment("6x8")->
        buildRoomSnapshot();
    mapping laterTenantField = region->getEnvironment("22x4")->
        buildRoomSnapshot();
    mapping timberAmbush = region->getEnvironment("20x6")->
        buildRoomSnapshot();
    mapping wildlifeMargin = region->getEnvironment("24x2")->
        buildRoomSnapshot();
    mapping northernBoundary = region->getEnvironment("24x8")->
        buildRoomSnapshot();

    ExpectTrue(sizeof(filter(farm["features"],
        (: $1["name"] == "tenant oat field" :))) > 0, "1x4 tenant crop");
    ExpectTrue(sizeof(filter(farm["features"],
        (: $1["name"] == "field drain" :))) > 0, "1x4 field drainage");
    ExpectTrue(sizeof(filter(orchard["features"],
        (: $1["name"] == "apple stand" :))) > 0, "3x4 orchard");
    ExpectTrue(sizeof(filter(orchard["items"],
        (: $1["name"] == "signpost" :))) > 0, "3x4 estate directions");
    ExpectTrue(sizeof(filter(woodland["features"],
        (: $1["name"] == "beech stand" :))) > 0, "3x6 managed woodland");
    ExpectTrue(sizeof(filter(woodland["items"],
        (: $1["name"] == "fox tracks" :))) > 0, "3x6 wildlife sign");
    ExpectTrue(sizeof(filter(manorialField["items"],
        (: $1["name"] == "wooden fence" :))) > 0,
        "5x4 field boundary");
    ExpectTrue(sizeof(filter(exposedRoad["items"],
        (: $1["name"] == "broken cart" :))) > 0,
        "5x8 abandoned cart");
    ExpectTrue(sizeof(filter(dalthrenTurnoff["items"],
        (: $1["name"] == "signpost" :))) > 0,
        "6x8 estate turnoff");
    ExpectTrue(sizeof(filter(laterTenantField["features"],
        (: $1["name"] == "field drain" :))) > 0,
        "22x4 field drainage");
    ExpectTrue(sizeof(filter(timberAmbush["items"],
        (: $1["name"] == "broken cart" :))) > 0,
        "20x6 timber road evidence");
    ExpectTrue(sizeof(filter(wildlifeMargin["items"],
        (: $1["name"] == "fox tracks" :))) > 0,
        "24x2 woodland wildlife");
    ExpectTrue(sizeof(filter(northernBoundary["items"],
        (: $1["name"] == "milestone" :))) > 0,
        "24x8 northbound milestone");

    destruct(region);
}

void NorthernManorRegionsAreAuthored()
{
    validateAuthoredRegions(({
        "/areas/northern-road/northern-manor/region.c",
        "/areas/argalen-keep/patrol-coast/region.c",
        "/areas/eledhel/estates/anduradan/grounds/region.c",
        "/areas/eledhel/estates/anduradan/keep-interior/region.c",
        "/areas/eledhel/estates/dalthren/grounds/region.c",
        "/areas/eledhel/estates/dalthren/keep-interior/region.c",
        "/areas/eledhel/estates/kirin/grounds/region.c",
        "/areas/eledhel/estates/kirin/keep-interior/region.c",
        "/areas/eledhel/estates/kirin/approach/region.c",
        "/areas/eledhel/estates/kirin/approach/second/region.c"
    }));
}

void NorthernManorsUseDomainInfrastructure()
{
    object service = getService("domain");
    mapping anduradan = service->getAuthoredHolding("house anduradan");
    mapping dalthren = service->getAuthoredHolding("house dalthren");
    mapping kirin = service->getAuthoredHolding("house kirin");

    ExpectTrue(mappingp(anduradan));
    ExpectEq("house-anduradan", anduradan["id"]);
    ExpectEq("keep", anduradan["type"]);
    ExpectFalse(service->getPlayerHolding(Player, "house anduradan"));
    ExpectTrue(sizeof(service->getPlayerDomain(
        Player, "house anduradan", "keep")["layout"]) > 0);

    ExpectTrue(mappingp(dalthren));
    ExpectEq("house-dalthren", dalthren["id"]);
    ExpectEq("Aelinwen Dalthren", dalthren["owner"]);
    ExpectFalse(service->getPlayerHolding(Player, "house dalthren"));
    ExpectTrue(sizeof(service->getPlayerDomain(
        Player, "house dalthren", "keep")["layout"]) > 0);

    ExpectTrue(mappingp(kirin));
    ExpectEq("house-kirin", kirin["id"]);
    ExpectEq("General Kirin and Lady Riana", kirin["owner"]);
    ExpectFalse(service->getPlayerHolding(Player, "house kirin"));
    ExpectTrue(sizeof(service->getPlayerDomain(
        Player, "house kirin", "keep")["layout"]) > 0);
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

void NorthernManorsHaveNamedResidents()
{
    expectResidentAt(
        "/areas/eledhel/estates/anduradan/keep-interior/1x0.c",
        "Aerandir");
    expectResidentAt(
        "/areas/eledhel/estates/dalthren/keep-interior/1x0.c",
        "Aelinwen");
    expectResidentAt(
        "/areas/eledhel/estates/kirin/keep-interior/1x0.c",
        "Kirin");
    expectResidentAt(
        "/areas/eledhel/estates/kirin/keep-interior/1x0.c",
        "Riana");
    expectResidentAt(
        "/areas/eledhel/estates/kirin/keep-interior/2x0.c",
        "Haldor");
    expectResidentAt(
        "/areas/eledhel/estates/kirin/keep-interior/2x0.c",
        "Aeryn");
}

void NorthernManorRoadEncountersStayAtOpeningLevels()
{
    object region = clone_object("/areas/northern-road/northern-manor/region.c");
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
