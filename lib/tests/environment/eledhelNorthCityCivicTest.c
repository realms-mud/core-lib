//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/tests/environment/eledhelCountrysideTest.c";

void Init()
{
    selectTestMethods(({
        "NorthernCivicWardConnectsToTheAvenue",
        "PublicLibraryAndMuseumHaveTheirStaff",
        "MorlethsStoneStocksHerbsAndWelcomesAVisitor",
        "PrisonWinchOpensCellsForAnEscapingPrisoner",
        "NavalQuarterAndDocksConnectToTheCivicWard",
        "NorthernHarborHasItsCrewAndSupplies"
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

void NorthernCivicWardConnectsToTheAvenue()
{
    for (int x = 15; x < 20; x++)
    {
        string path = sprintf("/areas/eledhel/northern-city/%dx6.c", x);
        string eastPath = sprintf("/areas/eledhel/northern-city/%dx6.c",
            x + 1);
        object room = load_object(path);
        object eastRoom = load_object(eastPath);

        ExpectEq(eastPath, room->getExitDirections()["default"]["east"]);
        ExpectEq(path, eastRoom->getExitDirections()["default"]["west"]);
    }

    object junction = load_object(
        "/areas/eledhel/northern-city/20x6.c");
    object crossStreet = load_object(
        "/areas/eledhel/northern-city/20x8.c");

    ExpectEq("/areas/eledhel/northern-city/20x7.c",
        junction->getExitDirections()["default"]["north"]);
    ExpectEq("/areas/eledhel/northern-city/20x8.c",
        load_object("/areas/eledhel/northern-city/20x7.c")->
            getExitDirections()["default"]["north"]);
    ExpectEq("/areas/eledhel/northern-city/19x8.c",
        crossStreet->getExitDirections()["default"]["west"]);
    ExpectEq("/areas/eledhel/northern-city/21x8.c",
        crossStreet->getExitDirections()["default"]["east"]);
}

void PublicLibraryAndMuseumHaveTheirStaff()
{
    object library = clone_object(
        "/areas/eledhel/northern-city/library/0x0.c");
    object museum = clone_object(
        "/areas/eledhel/northern-city/museum/0x0.c");
    int copyists = 0;
    int curators = 0;

    move_object(Player, library);
    foreach (object resident in all_inventory(library))
    {
        if (resident != Player && resident->id("Saelis"))
        {
            copyists++;
            ExpectTrue(resident->hasTopic("public shelves") > -1);
            Spawned += ({ resident });
        }
    }

    move_object(Player, museum);
    foreach (object resident in all_inventory(museum))
    {
        if (resident != Player && resident->id("Mereth"))
        {
            curators++;
            ExpectTrue(resident->hasTopic("harbor displays") > -1);
            Spawned += ({ resident });
        }
    }

    ExpectEq(1, copyists, "Public library copyist");
    ExpectEq(1, curators, "Museum curator");
    ExpectTrue(library->isEnvironmentalElement("book shelf"));
    ExpectTrue(museum->isEnvironmentalElement("museum display case"));
    ExpectEq("/areas/eledhel/northern-city/18x8.c",
        library->getExitDirections()["default"]["south"]);
    ExpectEq("/areas/eledhel/northern-city/17x8.c",
        museum->getExitDirections()["default"]["south"]);

    Harvested += ({ library, museum });
}

void MorlethsStoneStocksHerbsAndWelcomesAVisitor()
{
    object shop = clone_object(
        "/areas/eledhel/northern-city/morleths-stone/0x0.c");
    int morleths = 0;
    int customers = 0;

    move_object(Player, shop);
    foreach (object resident in all_inventory(shop))
    {
        if (resident != Player && resident->id("Morleth"))
        {
            morleths++;
            ExpectTrue(resident->hasTopic("herb safety") > -1);
            Spawned += ({ resident });
        }
        else if (resident != Player && resident->id("Tirren"))
        {
            customers++;
            ExpectTrue(resident->hasTopic("salve") > -1);
            Spawned += ({ resident });
        }
    }

    ExpectEq(1, morleths, "Morleth");
    ExpectEq(1, customers, "Herbalist's customer");
    ExpectTrue(shop->isEnvironmentalElement("mortar and pestle"));
    ExpectEq("/areas/eledhel/northern-city/21x8.c",
        shop->getExitDirections()["default"]["north"]);

    Harvested += ({ shop });
}

void PrisonWinchOpensCellsForAnEscapingPrisoner()
{
    string questPath = "/areas/eledhel/under-city/escapeQuest.c";
    object guardRoom = clone_object(
        "/areas/eledhel/northern-city/prison/2x3.c");
    object passage = load_object(
        "/areas/eledhel/northern-city/prison/2x2.c");
    object cell = clone_object(
        "/areas/eledhel/northern-city/prison/cell/0x0.c");
    object equipment = load_object(
        "/areas/eledhel/northern-city/prison/3x3.c");

    Harvested += ({ guardRoom, cell });
    ExpectFalse(passage->moveToIsAllowed(Player, cell));
    ExpectTrue(equipment->isEnvironmentalElement("weapon rack"));
    ExpectTrue(equipment->isEnvironmentalElement("chest"));

    move_object(Player, guardRoom);
    command("pull winch", Player);
    ExpectFalse(passage->cellsAreOpenFor(Player));
    ExpectFalse(passage->moveToIsAllowed(Player, cell));

    Player->beginQuest(questPath);
    command("pull winch", Player);
    ExpectTrue(passage->cellsAreOpenFor(Player));
    ExpectTrue(passage->moveToIsAllowed(Player, cell));
    ExpectTrue(cell->moveToIsAllowed(Player, passage));
    ExpectFalse(passage->cellsAreOpenFor(Player));

    ExpectEq("/areas/eledhel/northern-city/prison/0x2.c",
        load_object("/areas/eledhel/northern-city/prison/1x2.c")->
            getExitDirections()["default"]["south"]);
}

void NavalQuarterAndDocksConnectToTheCivicWard()
{
    for (int x = 21; x < 23; x++)
    {
        string path = sprintf("/areas/eledhel/northern-city/%dx8.c", x);
        string eastPath = sprintf("/areas/eledhel/northern-city/%dx8.c",
            x + 1);
        object room = load_object(path);
        object eastRoom = load_object(eastPath);

        ExpectEq(eastPath, room->getExitDirections()["default"]["east"]);
        ExpectEq(path, eastRoom->getExitDirections()["default"]["west"]);
    }

    object headquarters = load_object(
        "/areas/eledhel/northern-city/23x8.c");
    object guardedQuay = load_object(
        "/areas/eledhel/northern-city/23x7.c");
    object provisionsPier = load_object(
        "/areas/eledhel/northern-city/24x7.c");
    object landingPier = load_object(
        "/areas/eledhel/northern-city/24x8.c");

    ExpectEq("/areas/eledhel/northern-city/24x8.c",
        headquarters->getExitDirections()["default"]["east"]);
    ExpectEq("/areas/eledhel/northern-city/23x7.c",
        headquarters->getExitDirections()["default"]["south"]);
    ExpectEq("/areas/eledhel/northern-city/24x7.c",
        guardedQuay->getExitDirections()["default"]["east"]);
    ExpectEq("/areas/eledhel/northern-city/24x8.c",
        provisionsPier->getExitDirections()["default"]["north"]);
    ExpectEq("/areas/eledhel/northern-city/24x7.c",
        landingPier->getExitDirections()["default"]["south"]);
}

void NorthernHarborHasItsCrewAndSupplies()
{
    object headquartersEntry = clone_object(
        "/areas/eledhel/northern-city/naval-headquarters/0x0.c");
    object commandRoom = clone_object(
        "/areas/eledhel/northern-city/naval-headquarters/1x0.c");
    object watchRoom = clone_object(
        "/areas/eledhel/northern-city/naval-headquarters/1x1.c");
    object stores = clone_object(
        "/areas/eledhel/northern-city/naval-headquarters/0x1.c");
    object guardedQuay = clone_object(
        "/areas/eledhel/northern-city/23x7.c");
    object landingPier = clone_object(
        "/areas/eledhel/northern-city/24x8.c");
    object provisionPier = clone_object(
        "/areas/eledhel/northern-city/24x7.c");
    int commanders = 0;
    int watchOfficers = 0;
    int quartermasters = 0;
    int sentries = 0;
    int dockmasters = 0;
    int provisioners = 0;
    int customers = 0;

    ExpectEq("/areas/eledhel/northern-city/23x8.c",
        headquartersEntry->getExitDirections()["default"]["south"]);
    move_object(Player, commandRoom);
    foreach (object resident in all_inventory(commandRoom))
    {
        if (resident != Player && resident->id("Narev"))
        {
            commanders++;
            ExpectTrue(resident->hasTopic("harbor watch") > -1);
            Spawned += ({ resident });
        }
    }

    move_object(Player, stores);
    foreach (object resident in all_inventory(stores))
    {
        if (resident != Player && resident->id("Calven"))
        {
            quartermasters++;
            ExpectTrue(resident->hasTopic("stores") > -1);
            Spawned += ({ resident });
        }
    }

    move_object(Player, watchRoom);
    foreach (object resident in all_inventory(watchRoom))
    {
        if (resident != Player && resident->id("Selen"))
        {
            watchOfficers++;
            ExpectTrue(resident->hasTopic("ship log") > -1);
            Spawned += ({ resident });
        }
    }

    move_object(Player, guardedQuay);
    foreach (object resident in all_inventory(guardedQuay))
    {
        if (resident != Player && resident->id("Kerren"))
        {
            sentries++;
            ExpectTrue(resident->hasTopic("service quay") > -1);
            Spawned += ({ resident });
        }
    }

    move_object(Player, landingPier);
    foreach (object resident in all_inventory(landingPier))
    {
        if (resident != Player && resident->id("Iveren"))
        {
            dockmasters++;
            ExpectTrue(resident->hasTopic("berths") > -1);
            Spawned += ({ resident });
        }
    }

    move_object(Player, provisionPier);
    foreach (object resident in all_inventory(provisionPier))
    {
        if (resident != Player && resident->id("Taviel"))
        {
            provisioners++;
            ExpectTrue(resident->hasTopic("provisions") > -1);
            Spawned += ({ resident });
        }
        else if (resident != Player && resident->id("Nerion"))
        {
            customers++;
            ExpectTrue(resident->hasTopic("shipboard life") > -1);
            Spawned += ({ resident });
        }
    }

    ExpectEq(1, commanders, "Naval commander");
    ExpectEq(1, watchOfficers, "Harbor watch officer");
    ExpectEq(1, quartermasters, "Naval quartermaster");
    ExpectEq(1, sentries, "Quay sentry");
    ExpectEq(1, dockmasters, "Dockmaster");
    ExpectEq(1, provisioners, "Dock provisioner");
    ExpectEq(1, customers, "Sailor buying provisions");
    ExpectTrue(provisionPier->isEnvironmentalElement("crate of fish"));
    ExpectTrue(provisionPier->isEnvironmentalElement("fish cleaning table"));
    ExpectTrue(stores->isEnvironmentalElement("supply crate"));
    ExpectEq("/areas/eledhel/northern-city/naval-headquarters/0x0.c",
        stores->getExitDirections()["default"]["up"]);

    Harvested += ({ headquartersEntry, commandRoom, watchRoom, stores,
        guardedQuay, landingPier, provisionPier });
}
