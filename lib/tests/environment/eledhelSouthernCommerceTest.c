//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/tests/environment/eledhelCountrysideTest.c";

void Init()
{
    selectTestMethods(({
        "MarketAndWarehouseOpenFromTheCommercialStreet",
        "MarketAndWarehouseHaveWorkingStaff",
        "TheBowyerIsReachableFromTheStreet",
        "EveryCommercialInteriorLoads"
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

void MarketAndWarehouseOpenFromTheCommercialStreet()
{
    object marketStreet = load_object(
        "/areas/eledhel/southern-city/19x5.c");
    object warehouseStreet = load_object(
        "/areas/eledhel/southern-city/19x6.c");
    object market = clone_object(
        "/areas/eledhel/southern-city/market/0x0.c");
    object warehouse = clone_object(
        "/areas/eledhel/southern-city/warehouse/0x0.c");

    ExpectEq("/areas/eledhel/southern-city/market/0x0.c",
        marketStreet->getExitDirections()["default"]["east"]);
    ExpectEq("/areas/eledhel/southern-city/19x5.c",
        market->getExitDirections()["default"]["west"]);
    ExpectEq("/areas/eledhel/southern-city/warehouse/0x0.c",
        warehouseStreet->getExitDirections()["default"]["east"]);
    ExpectEq("/areas/eledhel/southern-city/19x6.c",
        warehouse->getExitDirections()["default"]["west"]);
    ExpectTrue(marketStreet->isEnvironmentalElement("plank door"));
    ExpectTrue(warehouseStreet->isEnvironmentalElement("plank door"));
    ExpectEq("food", market->getShop()->shopType());
    ExpectTrue(sizeof(market->getShop()->storeInventory()) > 0);

    Harvested += ({ marketStreet, warehouseStreet, market, warehouse });
}

void MarketAndWarehouseHaveWorkingStaff()
{
    object market = clone_object(
        "/areas/eledhel/southern-city/market/0x0.c");
    object warehouse = clone_object(
        "/areas/eledhel/southern-city/warehouse/0x0.c");
    object merchant = 0;
    object customer = 0;
    object clerk = 0;

    move_object(Player, market);
    foreach (object resident in all_inventory(market))
    {
        if (resident != Player && resident->id("Marden"))
        {
            merchant = resident;
            Spawned += ({ resident });
        }
        else if (resident != Player && resident->id("Celya"))
        {
            customer = resident;
            Spawned += ({ resident });
        }
    }

    move_object(Player, warehouse);
    foreach (object resident in all_inventory(warehouse))
    {
        if (resident != Player && resident->id("Tavrin"))
        {
            clerk = resident;
            Spawned += ({ resident });
        }
    }

    ExpectTrue(objectp(merchant));
    ExpectTrue(merchant->hasTopic("market stores") > -1);
    ExpectTrue(objectp(customer));
    ExpectTrue(customer->hasTopic("market list") > -1);
    ExpectTrue(objectp(clerk));
    ExpectTrue(clerk->hasTopic("warehouse tallies") > -1);
    Harvested += ({ market, warehouse });
}

void TheBowyerIsReachableFromTheStreet()
{
    object street = load_object("/areas/eledhel/southern-city/17x9.c");
    object shop = clone_object("/areas/eledhel/southern-city/16x9.c");
    object bowyer = 0;

    ExpectEq("/areas/eledhel/southern-city/16x9.c",
        street->getExitDirections()["default"]["west"]);
    ExpectEq("/areas/eledhel/southern-city/17x9.c",
        shop->getExitDirections()["default"]["east"]);
    ExpectTrue(street->isEnvironmentalElement("plank door"));
    ExpectEq("weapons", shop->getShop()->shopType());

    move_object(Player, shop);
    foreach (object resident in all_inventory(shop))
    {
        if (resident != Player && resident->id("Othar"))
        {
            bowyer = resident;
            Spawned += ({ resident });
        }
    }

    ExpectTrue(objectp(bowyer));
    ExpectTrue(bowyer->hasTopic("bow care") > -1);
    Harvested += ({ street, shop });
}

void EveryCommercialInteriorLoads()
{
    string *rooms = ({
        "/areas/eledhel/southern-city/market/0x0.c",
        "/areas/eledhel/southern-city/market/1x0.c",
        "/areas/eledhel/southern-city/warehouse/0x0.c",
        "/areas/eledhel/southern-city/warehouse/1x0.c"
    });

    foreach (string roomPath in rooms)
    {
        ExpectTrue(objectp(load_object(roomPath)), roomPath);
    }
}
