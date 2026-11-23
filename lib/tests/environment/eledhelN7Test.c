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
        "NorthernN7WindwardInnHasItsKeeper"
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
        if (resident != Player && resident->id("Phaedra outpost sentry"))
        {
            sentries++;
            Spawned += ({ resident });
        }
    }

    move_object(Player, gatehouse);
    foreach (object resident in all_inventory(gatehouse))
    {
        if (resident != Player &&
            resident->id("Phaedra outpost quartermaster"))
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
