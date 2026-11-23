//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/tests/environment/eledhelCountrysideTest.c";

void Init()
{
    selectTestMethods(({
        "SouthGatePassageConnectsToWallWalk",
        "SouthernDockMarketStocksProvisions",
        "SouthernShipyardConnectsToBothQuays",
        "EverySouthernHarborInteriorLoads"
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

void SouthGatePassageConnectsToWallWalk()
{
    object gate = load_object("/areas/eledhel/southern-city/12x1.c");
    object stairs = load_object(
        "/areas/eledhel/southern-city/south-gate-wall/0x0.c");
    object passage = load_object(
        "/areas/eledhel/southern-city/south-gate-wall/1x0.c");
    object wallWalk = clone_object(
        "/areas/eledhel/southern-city/south-gate-wall/2x0.c");
    object sentry = 0;

    ExpectEq("/areas/eledhel/southern-city/south-gate-wall/0x0.c",
        gate->getExitDirections()["default"]["up"]);
    ExpectEq("/areas/eledhel/southern-city/12x1.c",
        stairs->getExitDirections()["default"]["down"]);
    ExpectEq("/areas/eledhel/southern-city/south-gate-wall/1x0.c",
        stairs->getExitDirections()["default"]["up"]);
    ExpectEq("/areas/eledhel/southern-city/south-gate-wall/2x0.c",
        passage->getExitDirections()["default"]["east"]);
    ExpectEq("/areas/eledhel/southern-city/south-gate-wall/1x0.c",
        wallWalk->getExitDirections()["default"]["west"]);

    move_object(Player, wallWalk);
    foreach (object resident in all_inventory(wallWalk))
    {
        if (resident != Player && resident->id("Kethran"))
        {
            sentry = resident;
            Spawned += ({ resident });
        }
    }

    ExpectTrue(objectp(sentry));
    ExpectTrue(sentry->hasTopic("wall walk") > -1);
    Harvested += ({ wallWalk, gate, stairs, passage });
}

void SouthernDockMarketStocksProvisions()
{
    object quay = load_object("/areas/eledhel/southern-city/20x4.c");
    object market = clone_object(
        "/areas/eledhel/southern-city/south-dock-market/0x0.c");
    object merchant = 0;
    object customer = 0;

    ExpectEq("/areas/eledhel/southern-city/south-dock-market/0x0.c",
        quay->getExitDirections()["default"]["north"]);
    ExpectEq("/areas/eledhel/southern-city/20x4.c",
        market->getExitDirections()["default"]["south"]);
    ExpectTrue(quay->isEnvironmentalElement("plank door"));
    ExpectTrue(market->isEnvironmentalElement("plank door"));
    ExpectEq("food", market->getShop()->shopType());
    ExpectTrue(sizeof(market->getShop()->storeInventory()) > 0);

    move_object(Player, market);
    foreach (object resident in all_inventory(market))
    {
        if (resident != Player && resident->id("Dareth"))
        {
            merchant = resident;
            Spawned += ({ resident });
        }
        else if (resident != Player && resident->id("Pethren"))
        {
            customer = resident;
            Spawned += ({ resident });
        }
    }

    ExpectTrue(objectp(merchant));
    ExpectTrue(merchant->hasTopic("provisions") > -1);
    ExpectTrue(objectp(customer));
    ExpectTrue(customer->hasTopic("harbor watch") > -1);
    Harvested += ({ quay, market });
}

void SouthernShipyardConnectsToBothQuays()
{
    object yardEntrance = load_object(
        "/areas/eledhel/southern-city/21x7.c");
    object dockEntrance = load_object(
        "/areas/eledhel/southern-city/22x4.c");
    object yard = clone_object(
        "/areas/eledhel/southern-city/shipyard/0x0.c");
    object office = clone_object(
        "/areas/eledhel/southern-city/shipyard/1x0.c");
    object loft = load_object(
        "/areas/eledhel/southern-city/shipyard/1x1.c");
    object shipwright = 0;
    object apprentice = 0;

    ExpectEq("/areas/eledhel/southern-city/shipyard/0x0.c",
        yardEntrance->getExitDirections()["default"]["east"]);
    ExpectEq("/areas/eledhel/southern-city/21x7.c",
        yard->getExitDirections()["default"]["west"]);
    ExpectEq("/areas/eledhel/southern-city/shipyard/1x0.c",
        dockEntrance->getExitDirections()["default"]["north"]);
    ExpectEq("/areas/eledhel/southern-city/22x4.c",
        office->getExitDirections()["default"]["south"]);
    ExpectEq("/areas/eledhel/southern-city/shipyard/1x1.c",
        office->getExitDirections()["default"]["north"]);
    ExpectEq("/areas/eledhel/southern-city/shipyard/1x0.c",
        loft->getExitDirections()["default"]["south"]);

    move_object(Player, yard);
    foreach (object resident in all_inventory(yard))
    {
        if (resident != Player && resident->id("Edril"))
        {
            shipwright = resident;
            Spawned += ({ resident });
        }
    }

    move_object(Player, office);
    foreach (object resident in all_inventory(office))
    {
        if (resident != Player && resident->id("Othwen"))
        {
            apprentice = resident;
            Spawned += ({ resident });
        }
    }

    ExpectTrue(objectp(shipwright));
    ExpectTrue(shipwright->hasTopic("ship repairs") > -1);
    ExpectTrue(objectp(apprentice));
    ExpectTrue(apprentice->hasTopic("yard training") > -1);
    ExpectTrue(yard->isEnvironmentalElement("workbench"));
    Harvested += ({ yard, office, loft, yardEntrance, dockEntrance });
}

void EverySouthernHarborInteriorLoads()
{
    string *rooms = ({
        "/areas/eledhel/southern-city/south-gate-wall/0x0.c",
        "/areas/eledhel/southern-city/south-gate-wall/1x0.c",
        "/areas/eledhel/southern-city/south-gate-wall/2x0.c",
        "/areas/eledhel/southern-city/south-dock-market/0x0.c",
        "/areas/eledhel/southern-city/shipyard/0x0.c",
        "/areas/eledhel/southern-city/shipyard/1x0.c",
        "/areas/eledhel/southern-city/shipyard/1x1.c"
    });

    foreach (string roomPath in rooms)
    {
        ExpectTrue(objectp(load_object(roomPath)), roomPath);
    }
}
