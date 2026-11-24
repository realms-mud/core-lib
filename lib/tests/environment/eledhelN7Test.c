//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/tests/environment/eledhelCountrysideTest.c";

void Init()
{
    selectTestMethods(({
        "NorthernN7BoundaryIsReciprocal",
        "NorthernN7FirstRoadLegIsConnected",
        "NorthernN7PhaedraOutpostIsConnected",
        "NorthernN7OutpostHasItsGarrison",
        "NorthernN7WindwardInnIsConnected",
        "NorthernN7WindwardInnHasItsKeeper",
        "NorthernN7FullRegionIncludesItsBranches",
        "NorthernN7MillAndFisheryRoutesAreReciprocal",
        "NorthernN7BridgeHasAFordCrossing",
        "NorthernN7MillCellarIsPlayerRevealed",
        "NorthernN7ResidentsHavePersonalConversations",
        "NorthernN7BarrowRidgeIsConnected"
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

void NorthernN7BoundaryIsReciprocal()
{
    object n6 = load_object("/areas/northern-road/lower-northern-wilds/24x8.c");
    object n7 = load_object("/areas/northern-road/upper-northern-wilds/0x0.c");

    ExpectEq("/areas/northern-road/upper-northern-wilds/0x0.c",
        n6->getExitDirections()["default"]["north"]);
    ExpectEq("/areas/northern-road/lower-northern-wilds/24x8.c",
        n7->getExitDirections()["default"]["south"]);
    ExpectTrue(n7->isEnvironmentalElement("dirt road"));
}

void NorthernN7FirstRoadLegIsConnected()
{
    string previous = "/areas/northern-road/upper-northern-wilds/0x0.c";

    for (int x = 1; x <= 24; x++)
    {
        string path = sprintf("/areas/northern-road/upper-northern-wilds/%dx0.c", x);
        object room = load_object(path);
        mapping exits = room->getExitDirections()["default"];

        ExpectEq(previous, exits["west"], path);
        ExpectTrue(room->isEnvironmentalElement("dirt road"), path);
        if (x < 24)
        {
            ExpectEq(sprintf("/areas/northern-road/upper-northern-wilds/%dx0.c", x + 1),
                exits["east"], path);
        }
        previous = path;
    }
}

void NorthernN7PhaedraOutpostIsConnected()
{
    object road = load_object("/areas/northern-road/upper-northern-wilds/0x0.c");
    object yard = load_object(
        "/areas/northern-road/upper-northern-wilds/phaedra-outpost/courtyard.c");
    object gatehouse = load_object(
        "/areas/northern-road/upper-northern-wilds/phaedra-outpost/gatehouse.c");
    object drillYard = load_object(
        "/areas/northern-road/upper-northern-wilds/phaedra-outpost/drill-yard.c");
    object lookout = load_object(
        "/areas/northern-road/upper-northern-wilds/phaedra-outpost/lookout.c");

    ExpectEq("/areas/northern-road/upper-northern-wilds/phaedra-outpost/courtyard.c",
        road->getExitDirections()["default"]["north"]);
    ExpectEq("/areas/northern-road/upper-northern-wilds/1x0.c",
        road->getExitDirections()["default"]["east"]);
    ExpectEq("/areas/northern-road/upper-northern-wilds/0x0.c",
        yard->getExitDirections()["default"]["south"]);
    ExpectEq("/areas/northern-road/upper-northern-wilds/phaedra-outpost/gatehouse.c",
        yard->getExitDirections()["default"]["north"]);
    ExpectEq("/areas/northern-road/upper-northern-wilds/phaedra-outpost/courtyard.c",
        gatehouse->getExitDirections()["default"]["south"]);
    ExpectEq("/areas/northern-road/upper-northern-wilds/phaedra-outpost/drill-yard.c",
        yard->getExitDirections()["default"]["east"]);
    ExpectEq("/areas/northern-road/upper-northern-wilds/phaedra-outpost/courtyard.c",
        drillYard->getExitDirections()["default"]["west"]);
    ExpectEq("/areas/northern-road/upper-northern-wilds/phaedra-outpost/lookout.c",
        yard->getExitDirections()["default"]["up"]);
    ExpectEq("/areas/northern-road/upper-northern-wilds/phaedra-outpost/courtyard.c",
        lookout->getExitDirections()["default"]["down"]);
}

void NorthernN7OutpostHasItsGarrison()
{
    object yard = clone_object(
        "/areas/northern-road/upper-northern-wilds/phaedra-outpost/courtyard.c");
    object gatehouse = clone_object(
        "/areas/northern-road/upper-northern-wilds/phaedra-outpost/gatehouse.c");
    int sentries = 0;
    int quartermasters = 0;

    move_object(Player, yard);
    foreach (object resident in all_inventory(yard))
    {
        if (resident != Player && resident->id("Nerys Ansel"))
        {
            sentries++;
            Spawned += ({ resident });
        }
    }

    move_object(Player, gatehouse);
    foreach (object resident in all_inventory(gatehouse))
    {
        if (resident != Player &&
            resident->id("Hedran Varel"))
        {
            quartermasters++;
            Spawned += ({ resident });
        }
    }

    ExpectEq(1, sentries, "Outpost sentry");
    ExpectEq(1, quartermasters, "Outpost quartermaster");
    Harvested += ({ yard, gatehouse });
}

void NorthernN7WindwardInnIsConnected()
{
    object road = load_object("/areas/northern-road/upper-northern-wilds/0x0.c");
    object commonRoom = load_object(
        "/areas/northern-road/upper-northern-wilds/windward-inn/common-room.c");
    object loft = load_object("/areas/northern-road/upper-northern-wilds/windward-inn/loft.c");
    object stableYard = load_object(
        "/areas/northern-road/upper-northern-wilds/windward-inn/stable-yard.c");

    ExpectEq("/areas/northern-road/upper-northern-wilds/windward-inn/common-room.c",
        road->getExitDirections()["default"]["west"]);
    ExpectEq("/areas/northern-road/upper-northern-wilds/0x0.c",
        commonRoom->getExitDirections()["default"]["east"]);
    ExpectEq("/areas/northern-road/upper-northern-wilds/windward-inn/loft.c",
        commonRoom->getExitDirections()["default"]["west"]);
    ExpectEq("/areas/northern-road/upper-northern-wilds/windward-inn/common-room.c",
        loft->getExitDirections()["default"]["east"]);
    ExpectEq("/areas/northern-road/upper-northern-wilds/windward-inn/stable-yard.c",
        commonRoom->getExitDirections()["default"]["south"]);
    ExpectEq("/areas/northern-road/upper-northern-wilds/windward-inn/common-room.c",
        stableYard->getExitDirections()["default"]["north"]);
}

void NorthernN7WindwardInnHasItsKeeper()
{
    object commonRoom = clone_object(
        "/areas/northern-road/upper-northern-wilds/windward-inn/common-room.c");
    int keepers = 0;

    move_object(Player, commonRoom);
    foreach (object resident in all_inventory(commonRoom))
    {
        if (resident != Player && resident->id("Mira"))
        {
            keepers++;
            Spawned += ({ resident });
        }
    }

    ExpectEq(1, keepers, "Windward Inn keeper");
    ExpectTrue(commonRoom->isEnvironmentalElement("long table"));
    ExpectTrue(commonRoom->isEnvironmentalElement("hearth"));
    Harvested += ({ commonRoom });
}

void NorthernN7FullRegionIncludesItsBranches()
{
    object region = load_object(
        "/areas/northern-road/upper-northern-wilds/region.c");
    object roadStart = region->getEnvironment("0x4");
    object millYard = region->getEnvironment("5x3");
    object coach = region->getEnvironment("8x3");
    object ford = region->getEnvironment("12x6");
    object landing = region->getEnvironment("15x5");
    object outpostRegion = load_object(
        "/areas/northern-road/upper-northern-wilds/phaedra-outpost/region.c");
    object innRegion = load_object(
        "/areas/northern-road/upper-northern-wilds/windward-inn/region.c");

    ExpectEq(25, region->xDimension());
    ExpectEq(9, region->yDimension());
    ExpectEq("/areas/northern-road/lower-northern-wilds/24x8.c",
        region->entryPoint());
    ExpectEq("south", region->entryDirection());
    ExpectTrue(objectp(roadStart));
    ExpectTrue(objectp(millYard));
    ExpectTrue(objectp(coach));
    ExpectTrue(objectp(ford));
    ExpectTrue(objectp(landing));
    ExpectTrue(coach->isEnvironmentalElement("wrecked stagecoach"));
    ExpectTrue(
        region->getEnvironment("11x4")->isEnvironmentalElement(
            "spring votive stones"));
    ExpectEq(5, outpostRegion->xDimension());
    ExpectEq(5, outpostRegion->yDimension());
    ExpectEq(5, innRegion->xDimension());
    ExpectEq(5, innRegion->yDimension());
}

void NorthernN7MillAndFisheryRoutesAreReciprocal()
{
    object mainRoad = load_object(
        "/areas/northern-road/upper-northern-wilds/5x0.c");
    object yard = load_object(
        "/areas/northern-road/upper-northern-wilds/hollow-mill/yard.c");
    object store = load_object(
        "/areas/northern-road/upper-northern-wilds/hollow-mill/grain-store.c");
    object wheelRoom = load_object(
        "/areas/northern-road/upper-northern-wilds/hollow-mill/wheel-room.c");
    object ridgePath = load_object(
        "/areas/northern-road/upper-northern-wilds/inland/ridge-path.c");
    object lastSlope = load_object(
        "/areas/northern-road/upper-northern-wilds/inland/return-slope.c");
    object roadEnd = load_object(
        "/areas/northern-road/upper-northern-wilds/11x0.c");
    object coastRoad = load_object(
        "/areas/northern-road/upper-northern-wilds/15x0.c");
    object landing = load_object(
        "/areas/northern-road/upper-northern-wilds/fishery/landing.c");
    object netYard = load_object(
        "/areas/northern-road/upper-northern-wilds/fishery/net-yard.c");
    object boatShed = load_object(
        "/areas/northern-road/upper-northern-wilds/fishery/boat-shed.c");
    object tideCave = load_object(
        "/areas/northern-road/upper-northern-wilds/fishery/tide-cave.c");

    ExpectEq("/areas/northern-road/upper-northern-wilds/hollow-mill/yard.c",
        mainRoad->getExitDirections()["default"]["north"]);
    ExpectEq("/areas/northern-road/upper-northern-wilds/5x0.c",
        yard->getExitDirections()["default"]["south"]);
    ExpectEq("/areas/northern-road/upper-northern-wilds/hollow-mill/"
        "grain-store.c", yard->getExitDirections()["default"]["north"]);
    ExpectEq("/areas/northern-road/upper-northern-wilds/hollow-mill/"
        "wheel-room.c", store->getExitDirections()["default"]["east"]);
    ExpectEq("/areas/northern-road/upper-northern-wilds/inland/ridge-path.c",
        wheelRoom->getExitDirections()["default"]["east"]);
    ExpectEq("/areas/northern-road/upper-northern-wilds/11x0.c",
        lastSlope->getExitDirections()["default"]["south"]);
    ExpectEq("/areas/northern-road/upper-northern-wilds/inland/return-slope.c",
        roadEnd->getExitDirections()["default"]["north"]);
    ExpectEq("/areas/northern-road/upper-northern-wilds/fishery/landing.c",
        coastRoad->getExitDirections()["default"]["south"]);
    ExpectEq("/areas/northern-road/upper-northern-wilds/15x0.c",
        landing->getExitDirections()["default"]["north"]);
    ExpectEq("/areas/northern-road/upper-northern-wilds/fishery/net-yard.c",
        landing->getExitDirections()["default"]["east"]);
    ExpectEq("/areas/northern-road/upper-northern-wilds/fishery/boat-shed.c",
        netYard->getExitDirections()["default"]["east"]);
    ExpectEq("/areas/northern-road/upper-northern-wilds/fishery/tide-cave.c",
        landing->getExitDirections()["default"]["south"]);
    ExpectTrue(tideCave->isEnvironmentalElement("cave"));
}

void NorthernN7BridgeHasAFordCrossing()
{
    object northBank = load_object(
        "/areas/northern-road/upper-northern-wilds/bridge/north-bank.c");
    object brokenSpan = load_object(
        "/areas/northern-road/upper-northern-wilds/bridge/broken-span.c");
    object ford = load_object(
        "/areas/northern-road/upper-northern-wilds/bridge/ford.c");
    object eastBank = load_object(
        "/areas/northern-road/upper-northern-wilds/bridge/east-bank.c");
    mapping spanExits = brokenSpan->getExitDirections()["default"];

    ExpectEq("/areas/northern-road/upper-northern-wilds/12x0.c",
        northBank->getExitDirections()["default"]["north"]);
    ExpectFalse(member(spanExits, "east"));
    ExpectEq("/areas/northern-road/upper-northern-wilds/bridge/east-bank.c",
        ford->getExitDirections()["default"]["east"]);
    ExpectEq("/areas/northern-road/upper-northern-wilds/13x0.c",
        eastBank->getExitDirections()["default"]["north"]);
    ExpectTrue(ford->isEnvironmentalElement("shallow ford"));
}

void NorthernN7MillCellarIsPlayerRevealed()
{
    object wheelRoom = clone_object(
        "/areas/northern-road/upper-northern-wilds/hollow-mill/wheel-room.c");
    object cellar = clone_object(
        "/areas/northern-road/upper-northern-wilds/hollow-mill/cellar-entry.c");
    object cache = load_object(
        "/areas/northern-road/upper-northern-wilds/hollow-mill/cellar-cache.c");
    object secondPlayer = clone_object(
        "/lib/tests/support/services/mockPlayer.c");
    secondPlayer.Name("alice");
    secondPlayer.addCommands();
    move_object(Player, wheelRoom);
    move_object(secondPlayer, wheelRoom);

    ExpectFalse(wheelRoom->moveToIsAllowed(Player, cellar));
    command("pull ring", Player);
    ExpectTrue(wheelRoom->moveToIsAllowed(Player, cellar));
    ExpectFalse(wheelRoom->moveToIsAllowed(secondPlayer, cellar));
    ExpectTrue(cache->isEnvironmentalElement("broken cart"));

    Spawned += ({ secondPlayer });
    Harvested += ({ wheelRoom, cellar });
}

void NorthernN7ResidentsHavePersonalConversations()
{
    object quartermaster = clone_object(
        "/areas/northern-road/upper-northern-wilds/characters/"
        "hedran-varel.c");
    object sentry = clone_object(
        "/areas/northern-road/upper-northern-wilds/characters/"
        "nerys-ansel.c");
    object innkeeper = clone_object(
        "/areas/northern-road/upper-northern-wilds/characters/"
        "mira-ellery.c");
    object miller = clone_object(
        "/areas/northern-road/upper-northern-wilds/characters/oren-vey.c");
    object netMender = clone_object(
        "/areas/northern-road/upper-northern-wilds/characters/sairen-drel.c");
    object boatwright = clone_object(
        "/areas/northern-road/upper-northern-wilds/characters/ilden-marr.c");
    object keeper = clone_object(
        "/areas/northern-road/upper-northern-wilds/characters/eira-pell.c");
    object survivor = clone_object(
        "/areas/northern-road/upper-northern-wilds/characters/anwen-rusk.c");

    Spawned += ({ quartermaster, sentry, innkeeper, miller, netMender,
        boatwright, keeper, survivor });
    ExpectTrue(quartermaster->hasTopic("the signal chain") > -1);
    ExpectTrue(sentry->hasTopic("the red patch") > -1);
    ExpectTrue(innkeeper->hasTopic("your old partner") > -1);
    ExpectTrue(miller->hasTopic("the missing sacks") > -1);
    ExpectTrue(netMender->hasTopic("your brother") > -1);
    ExpectTrue(boatwright->hasTopic("your finger") > -1);
    ExpectTrue(keeper->hasTopic("the three mounds") > -1);
    ExpectTrue(survivor->hasTopic("your sister") > -1);
}

void NorthernN7BarrowRidgeIsConnected()
{
    object road = load_object(
        "/areas/northern-road/upper-northern-wilds/24x0.c");
    object region = load_object(
        "/areas/northern-road/upper-northern-wilds/barrow-ridge/region.c");
    object ring = region->getEnvironment("2x3");
    object sealedMound = region->getEnvironment("1x3");
    object openedMound = region->getEnvironment("3x3");
    object antechamber = load_object(
        "/areas/northern-road/upper-northern-wilds/barrow-ridge/"
        "antechamber.c");
    object chamber = load_object(
        "/areas/northern-road/upper-northern-wilds/barrow-ridge/"
        "burial-chamber.c");

    ExpectEq(5, region->xDimension());
    ExpectEq(5, region->yDimension());
    ExpectEq("/areas/northern-road/upper-northern-wilds/24x0.c",
        region->entryPoint());
    ExpectEq("/areas/northern-road/upper-northern-wilds/barrow-ridge/"
        "approach.c", road->getExitDirections()["default"]["north"]);
    ExpectTrue(ring->isEnvironmentalElement("barrow"));
    ExpectTrue(sealedMound->isEnvironmentalElement("barrow"));
    ExpectEq("/areas/northern-road/upper-northern-wilds/barrow-ridge/"
        "antechamber.c", openedMound->getExitDirections()["default"]["down"]);
    ExpectEq("/areas/northern-road/upper-northern-wilds/barrow-ridge/"
        "burial-chamber.c", antechamber->getExitDirections()["default"]["down"]);
    ExpectTrue(chamber->getExitDirections()["default"]["up"]);
}
