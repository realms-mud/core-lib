//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/tests/environment/eledhelCountrysideTest.c";

void Init()
{
    selectTestMethods(({
        "MinlachApproachesBoundaryAndGateAreConnected",
        "MinlachApproachesMainRoadHasTwentyFiveLinkedRooms",
        "MinlachApproachesRegionIncludesItsWorkingBranches",
        "MinlachApproachesFarmMillLoopIsConnected",
        "MinlachApproachesTollKeepAndDroverPensAreConnected",
        "MinlachApproachesWarningPrecedesTheGallowsTrack",
        "MinlachApproachesResidentsHavePersonalConversations"
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

void MinlachApproachesBoundaryAndGateAreConnected()
{
    object n7 = load_object(
        "/areas/northern-road/upper-northern-wilds/24x0.c");
    object entry = load_object(
        "/areas/northern-road/minlach-approaches/0x4.c");
    object approach = load_object(
        "/areas/northern-road/minlach-approaches/24x4.c");
    object gate = load_object("/areas/minlach/1x0.c");

    ExpectEq("/areas/northern-road/minlach-approaches/0x4.c",
        n7->getExitDirections()["default"]["east"]);
    ExpectEq("/areas/northern-road/upper-northern-wilds/24x0.c",
        entry->getExitDirections()["default"]["west"]);
    ExpectEq("/areas/minlach/1x0.c",
        approach->getExitDirections()["default"]["east"]);
    ExpectEq("/areas/northern-road/minlach-approaches/24x4.c",
        gate->getExitDirections()["default"]["west"]);
    ExpectEq("/areas/eledhel/north-road/2x4.c",
        gate->getExitDirections()["default"]["south"]);
}

void MinlachApproachesMainRoadHasTwentyFiveLinkedRooms()
{
    string previous =
        "/areas/northern-road/upper-northern-wilds/24x0.c";

    for (int x = 0; x <= 24; x++)
    {
        string path = sprintf(
            "/areas/northern-road/minlach-approaches/%dx4.c", x);
        object room = load_object(path);
        mapping exits = room->getExitDirections()["default"];

        ExpectEq(previous, exits["west"], path);
        if (x < 24)
        {
            ExpectEq(
                sprintf("/areas/northern-road/minlach-approaches/%dx4.c",
                    x + 1),
                exits["east"], path);
        }
        else
        {
            ExpectEq("/areas/minlach/1x0.c", exits["east"], path);
        }
        previous = path;
    }
}

void MinlachApproachesRegionIncludesItsWorkingBranches()
{
    object region = load_object(
        "/areas/northern-road/minlach-approaches/region.c");
    object shrine = region->getEnvironment("2x2");
    object shrineApproach = region->getEnvironment("2x3");
    object mill = region->getEnvironment("7x6");
    object tollPost = region->getEnvironment("12x2");
    object waterLane = region->getEnvironment("19x5");
    object hill = region->getEnvironment("22x2");
    object hillPath = region->getEnvironment("23x2");
    object hillLoop = region->getEnvironment("23x3");
    object supplyYard = region->getEnvironment("23x6");
    object supplyApproach = region->getEnvironment("23x5");
    object wall = region->getEnvironment("24x4");

    ExpectEq(25, region->xDimension());
    ExpectEq(10, region->yDimension());
    ExpectEq("/areas/northern-road/upper-northern-wilds/24x0.c",
        region->entryPoint());
    ExpectTrue(shrine->isEnvironmentalElement("roadside shrine"),
        "roadside shrine is visible");
    ExpectTrue(shrineApproach->getExitDirections()["default"]["south"],
        "shrine path returns to the road");
    ExpectTrue(mill->isEnvironmentalElement("grain bin"),
        "mill has a grain bin");
    ExpectTrue(tollPost->isEnvironmentalElement("notice board"),
        "toll post has its public notice board");
    ExpectTrue(waterLane->isEnvironmentalElement("water trough"),
        "watering lane has a trough");
    ExpectTrue(hill->isEnvironmentalElement("old gallows"),
        "memorial hill contains the old gallows");
    ExpectTrue(hillPath->getExitDirections()["default"]["west"],
        "memorial loop returns west");
    ExpectTrue(hillLoop->getExitDirections()["default"]["north"],
        "memorial loop connects north");
    ExpectTrue(supplyApproach->getExitDirections()["default"]["south"],
        "supply yard connects to the approach");
    ExpectTrue(supplyYard->isEnvironmentalElement("fieldstone wall"),
        "wall continues beside the supply yard");
    ExpectTrue(wall->isEnvironmentalElement("fieldstone wall"),
        "town wall marks Minlach's approach");
}

void MinlachApproachesFarmMillLoopIsConnected()
{
    object road = load_object(
        "/areas/northern-road/minlach-approaches/5x4.c");
    object lane = load_object(
        "/areas/northern-road/minlach-approaches/5x5.c");
    object yard = load_object(
        "/areas/northern-road/minlach-approaches/6x5.c");
    object race = load_object(
        "/areas/northern-road/minlach-approaches/6x6.c");
    object mill = load_object(
        "/areas/northern-road/minlach-approaches/7x6.c");
    object green = load_object(
        "/areas/northern-road/minlach-approaches/7x5.c");

    ExpectEq("/areas/northern-road/minlach-approaches/5x5.c",
        road->getExitDirections()["default"]["south"]);
    ExpectEq("/areas/northern-road/minlach-approaches/6x5.c",
        lane->getExitDirections()["default"]["east"]);
    ExpectEq("/areas/northern-road/minlach-approaches/6x6.c",
        yard->getExitDirections()["default"]["south"]);
    ExpectEq("/areas/northern-road/minlach-approaches/7x6.c",
        race->getExitDirections()["default"]["east"]);
    ExpectEq("/areas/northern-road/minlach-approaches/7x5.c",
        mill->getExitDirections()["default"]["north"]);
    ExpectEq("/areas/northern-road/minlach-approaches/7x4.c",
        green->getExitDirections()["default"]["north"]);
}

void MinlachApproachesTollKeepAndDroverPensAreConnected()
{
    object approach = load_object(
        "/areas/northern-road/minlach-approaches/12x3.c");
    object yard = load_object(
        "/areas/northern-road/minlach-approaches/12x2.c");
    object office = load_object(
        "/areas/northern-road/minlach-approaches/12x1.c");
    object stable = load_object(
        "/areas/northern-road/minlach-approaches/13x2.c");
    object road = load_object(
        "/areas/northern-road/minlach-approaches/18x4.c");
    object pen = load_object(
        "/areas/northern-road/minlach-approaches/18x5.c");
    object water = load_object(
        "/areas/northern-road/minlach-approaches/19x5.c");
    object trough = load_object(
        "/areas/northern-road/minlach-approaches/19x6.c");

    ExpectEq("/areas/northern-road/minlach-approaches/12x2.c",
        approach->getExitDirections()["default"]["north"]);
    ExpectEq("/areas/northern-road/minlach-approaches/12x1.c",
        yard->getExitDirections()["default"]["north"]);
    ExpectEq("/areas/northern-road/minlach-approaches/13x2.c",
        yard->getExitDirections()["default"]["east"]);
    ExpectEq("/areas/northern-road/minlach-approaches/12x2.c",
        stable->getExitDirections()["default"]["west"]);
    ExpectTrue(office->isEnvironmentalElement("toll ledger"),
        "toll ledger is visible in the office");
    ExpectEq("/areas/northern-road/minlach-approaches/18x5.c",
        road->getExitDirections()["default"]["south"]);
    ExpectEq("/areas/northern-road/minlach-approaches/19x5.c",
        pen->getExitDirections()["default"]["east"]);
    ExpectEq("/areas/northern-road/minlach-approaches/19x6.c",
        water->getExitDirections()["default"]["south"]);
    ExpectTrue(trough->getExitDirections()["default"]["north"],
        "trough route returns to the pens");
}

void MinlachApproachesWarningPrecedesTheGallowsTrack()
{
    object road = load_object(
        "/areas/northern-road/minlach-approaches/22x4.c");
    object approach = load_object(
        "/areas/northern-road/minlach-approaches/22x3.c");
    object gallows = load_object(
        "/areas/northern-road/minlach-approaches/22x2.c");

    ExpectTrue(road->isEnvironmentalElement("outlaw warning sign"),
        "warning is visible before the track");
    ExpectEq("/areas/northern-road/minlach-approaches/22x3.c",
        road->getExitDirections()["default"]["north"]);
    ExpectEq("/areas/northern-road/minlach-approaches/22x2.c",
        approach->getExitDirections()["default"]["north"]);
    ExpectTrue(gallows->isEnvironmentalElement("old gallows"),
        "the track reaches the memorial");
}

void MinlachApproachesResidentsHavePersonalConversations()
{
    object miller = clone_object(
        "/areas/northern-road/minlach-approaches/characters/mera-vell.c");
    object fieldHand = clone_object(
        "/areas/northern-road/minlach-approaches/characters/renn-vell.c");
    object drover = clone_object(
        "/areas/northern-road/minlach-approaches/characters/vessa-arn.c");
    object sergeant = clone_object(
        "/areas/northern-road/minlach-approaches/characters/cael-reth.c");
    object chandler = clone_object(
        "/areas/northern-road/minlach-approaches/characters/dulin-hadrik.c");
    object shrineKeeper = clone_object(
        "/areas/northern-road/minlach-approaches/characters/erieth-sorn.c");

    Spawned += ({ miller, fieldHand, drover, sergeant, chandler,
        shrineKeeper });
    ExpectTrue(miller->hasTopic("the stream") > -1,
        "miller has a stream topic");
    ExpectTrue(fieldHand->hasTopic("the measure") > -1,
        "field hand has a measure topic");
    ExpectTrue(drover->hasTopic("the animals") > -1,
        "drover has an animal topic");
    ExpectTrue(sergeant->hasTopic("the exemptions") > -1,
        "sergeant explains exemptions");
    ExpectTrue(chandler->hasTopic("the lanterns") > -1,
        "chandler explains signal lanterns");
    ExpectTrue(shrineKeeper->hasTopic("the names") > -1,
        "shrine keeper knows the memorial names");
}
