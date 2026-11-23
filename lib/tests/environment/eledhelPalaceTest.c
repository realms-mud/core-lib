//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/tests/environment/eledhelCountrysideTest.c";

void Init()
{
    selectTestMethods(({
        "PalaceEntryConnectsToTheOldCity",
        "PalaceCourtHasItsHouseholdStaff",
        "PalaceGardenAndStableWingsAreReachable",
        "PalacePrivateRoomOpensToTheOldPassage",
        "EveryMarkedPalaceCoordinateLoads",
        "PalaceResidentsHaveConversations"
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

void PalaceEntryConnectsToTheOldCity()
{
    object city = load_object("/areas/eledhel/central-city/14x5.c");
    object gate = load_object(
        "/areas/eledhel/central-city/palace/0x2.c");
    object region = load_object(
        "/areas/eledhel/central-city/palace/region.c");

    ExpectEq("/areas/eledhel/central-city/palace/0x2.c",
        city->getExitDirections()["default"]["east"]);
    ExpectEq("/areas/eledhel/central-city/14x5.c",
        gate->getExitDirections()["default"]["west"]);
    ExpectTrue(objectp(region));
}

void PalaceResidentsHaveConversations()
{
    string *roomPaths = ({
        "/areas/eledhel/central-city/palace/0x1.c",
        "/areas/eledhel/central-city/palace/0x3.c",
        "/areas/eledhel/central-city/palace/1x2.c",
        "/areas/eledhel/central-city/palace/1x3.c",
        "/areas/eledhel/central-city/palace/3x0.c",
        "/areas/eledhel/central-city/palace/4x2.c",
        "/areas/eledhel/central-city/palace/5x1.c",
        "/areas/eledhel/central-city/palace/1x1.c",
        "/areas/eledhel/central-city/palace/1x1.c",
        "/areas/eledhel/central-city/palace/1x1.c",
        "/areas/eledhel/central-city/palace/2x3.c",
        "/areas/eledhel/central-city/palace/5x1.c"
    });
    string *residentNames = ({
        "Sendral", "Palace guard", "Petitioner", "Court scribe",
        "Aven", "Tiriel", "Hareth", "Ardenel", "Arueil", "Aredec",
        "Morwen", "Aldoran"
    });
    string *topics = ({
        "household", "visitors", "petition", "records",
        "precedent", "appointments", "horses", "the court",
        "the royal family", "Aegis Guard", "diplomacy", "stable wing"
    });
    object *rooms = ({});

    for (int i = 0; i < sizeof(roomPaths); i++)
    {
        object room = clone_object(roomPaths[i]);
        int residents = 0;
        move_object(Player, room);

        foreach (object resident in all_inventory(room))
        {
            if (resident != Player && resident->id(residentNames[i]))
            {
                residents++;
                ExpectTrue(resident->hasTopic(topics[i]) > -1);
                Spawned += ({ resident });
            }
        }

        ExpectEq(1, residents, residentNames[i]);
        rooms += ({ room });
    }

    Harvested += rooms;
}

void PalaceCourtHasItsHouseholdStaff()
{
    object guardroom = clone_object(
        "/areas/eledhel/central-city/palace/0x1.c");
    object reception = clone_object(
        "/areas/eledhel/central-city/palace/1x2.c");
    object hall = load_object(
        "/areas/eledhel/central-city/palace/1x1.c");
    int castellans = 0;
    int petitioners = 0;

    move_object(Player, guardroom);
    foreach (object resident in all_inventory(guardroom))
    {
        if (resident != Player && resident->id("Sendral"))
        {
            castellans++;
            Spawned += ({ resident });
        }
    }

    move_object(Player, reception);
    foreach (object resident in all_inventory(reception))
    {
        if (resident != Player && resident->id("Petitioner"))
        {
            petitioners++;
            Spawned += ({ resident });
        }
    }

    ExpectEq(1, castellans, "Palace castellan");
    ExpectEq(1, petitioners, "Palace petitioner");
    ExpectTrue(hall->isEnvironmentalElement("long table"));
    ExpectTrue(hall->isEnvironmentalElement("chandelier"));
    Harvested += ({ guardroom, reception });
}

void PalaceGardenAndStableWingsAreReachable()
{
    object garden = load_object(
        "/areas/eledhel/central-city/palace/3x2.c");
    object stable = load_object(
        "/areas/eledhel/central-city/palace/5x1.c");

    ExpectTrue(garden->isEnvironmentalElement("pond"));
    ExpectEq("/areas/eledhel/central-city/palace/4x2.c",
        garden->getExitDirections()["default"]["east"]);
    ExpectEq("/areas/eledhel/central-city/palace/5x0.c",
        stable->getExitDirections()["default"]["north"]);
    ExpectEq("/areas/eledhel/central-city/palace/5x2.c",
        stable->getExitDirections()["default"]["south"]);
}

void PalacePrivateRoomOpensToTheOldPassage()
{
    object chamber = load_object(
        "/areas/eledhel/central-city/palace/2x3.c");
    object passage = load_object(
        "/areas/eledhel/central-city/palace/hidden-passage.c");

    ExpectEq("/areas/eledhel/central-city/palace/hidden-passage.c",
        chamber->getExitDirections()["default"]["down"]);
    ExpectEq("/areas/eledhel/central-city/palace/2x3.c",
        passage->getExitDirections()["default"]["up"]);
}

void EveryMarkedPalaceCoordinateLoads()
{
    object region = load_object(
        "/areas/eledhel/central-city/palace/region.c");

    for (int x = 0; x < region->xDimension(); x++)
    {
        for (int y = 0; y < region->yDimension(); y++)
        {
            if (x != 5 || y != 4)
            {
                string coordinate = sprintf("%dx%d", x, y);
                ExpectTrue(objectp(region->getEnvironment(coordinate)),
                    sprintf("Palace coordinate %s loads", coordinate));
            }
        }
    }
}
