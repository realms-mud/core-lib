//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/tests/environment/eledhelCountrysideTest.c";

void Init()
{
    selectTestMethods(({
        "SouthernInnIsOpenAndStaffed",
        "FoundryAndSmelterHaveWorkingEntrances",
        "EverySouthernTradeInteriorLoads"
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

void SouthernInnIsOpenAndStaffed()
{
    object street = load_object("/areas/eledhel/southern-city/16x3.c");
    object inn = clone_object("/areas/eledhel/southern-city/inn/0x1.c");
    object keeper = 0;
    object guest = 0;

    ExpectEq("/areas/eledhel/southern-city/inn/0x1.c",
        street->getExitDirections()["default"]["east"]);
    ExpectEq("/areas/eledhel/southern-city/16x3.c",
        inn->getExitDirections()["default"]["west"]);
    ExpectTrue(street->isEnvironmentalElement("plank door"));
    ExpectEq("food", inn->getShop()->shopType());

    move_object(Player, inn);
    foreach (object resident in all_inventory(inn))
    {
        if (resident != Player && resident->id("Maerin"))
        {
            keeper = resident;
            Spawned += ({ resident });
        }
        else if (resident != Player && resident->id("Perrin"))
        {
            guest = resident;
            Spawned += ({ resident });
        }
    }

    ExpectTrue(objectp(keeper));
    ExpectTrue(keeper->hasTopic("rooms and meals") > -1);
    ExpectTrue(objectp(guest));
    ExpectTrue(guest->hasTopic("the road") > -1);
    Harvested += ({ street, inn });
}

void FoundryAndSmelterHaveWorkingEntrances()
{
    object foundryStreet = load_object(
        "/areas/eledhel/southern-city/17x7.c");
    object smelterStreet = load_object(
        "/areas/eledhel/southern-city/14x6.c");
    object foundry = clone_object(
        "/areas/eledhel/southern-city/foundry/0x0.c");
    object smelter = clone_object(
        "/areas/eledhel/southern-city/smelter/0x0.c");
    object foundryMaster = 0;
    object smelterWorker = 0;

    ExpectEq("/areas/eledhel/southern-city/foundry/0x0.c",
        foundryStreet->getExitDirections()["default"]["west"]);
    ExpectEq("/areas/eledhel/southern-city/17x7.c",
        foundry->getExitDirections()["default"]["east"]);
    ExpectEq("/areas/eledhel/southern-city/smelter/0x0.c",
        smelterStreet->getExitDirections()["default"]["east"]);
    ExpectEq("/areas/eledhel/southern-city/14x6.c",
        smelter->getExitDirections()["default"]["west"]);
    ExpectTrue(foundry->isEnvironmentalElement("workbench"));
    ExpectTrue(smelter->isEnvironmentalElement("workbench"));

    move_object(Player, foundry);
    foreach (object resident in all_inventory(foundry))
    {
        if (resident != Player && resident->id("Bereth"))
        {
            foundryMaster = resident;
            Spawned += ({ resident });
        }
    }

    move_object(Player, smelter);
    foreach (object resident in all_inventory(smelter))
    {
        if (resident != Player && resident->id("Orvan"))
        {
            smelterWorker = resident;
            Spawned += ({ resident });
        }
    }

    ExpectTrue(objectp(foundryMaster));
    ExpectTrue(foundryMaster->hasTopic("foundry work") > -1);
    ExpectTrue(objectp(smelterWorker));
    ExpectTrue(smelterWorker->hasTopic("smelting") > -1);
    Harvested += ({ foundryStreet, smelterStreet, foundry, smelter });
}

void EverySouthernTradeInteriorLoads()
{
    string *rooms = ({
        "/areas/eledhel/southern-city/inn/0x1.c",
        "/areas/eledhel/southern-city/foundry/0x0.c",
        "/areas/eledhel/southern-city/smelter/0x0.c",
        "/areas/eledhel/southern-city/smelter/1x0.c"
    });

    foreach (string roomPath in rooms)
    {
        ExpectTrue(objectp(load_object(roomPath)), roomPath);
    }
}
