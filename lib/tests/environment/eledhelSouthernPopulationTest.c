//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/tests/environment/eledhelCountrysideTest.c";

void Init()
{
    selectTestMethods(({
        "SouthernStreetsAndDocksHaveConversationalResidents"
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

void SouthernStreetsAndDocksHaveConversationalResidents()
{
    string *roomPaths = ({
        "/areas/eledhel/southern-city/1x2.c",
        "/areas/eledhel/southern-city/1x4.c",
        "/areas/eledhel/southern-city/1x6.c",
        "/areas/eledhel/southern-city/1x8.c",
        "/areas/eledhel/southern-city/2x1.c",
        "/areas/eledhel/southern-city/2x5.c",
        "/areas/eledhel/southern-city/2x8.c",
        "/areas/eledhel/southern-city/3x2.c",
        "/areas/eledhel/southern-city/3x5.c",
        "/areas/eledhel/southern-city/3x8.c",
        "/areas/eledhel/southern-city/4x2.c",
        "/areas/eledhel/southern-city/4x5.c",
        "/areas/eledhel/southern-city/4x8.c",
        "/areas/eledhel/southern-city/5x2.c",
        "/areas/eledhel/southern-city/5x5.c",
        "/areas/eledhel/southern-city/11x2.c",
        "/areas/eledhel/southern-city/11x5.c",
        "/areas/eledhel/southern-city/12x0.c",
        "/areas/eledhel/southern-city/12x1.c",
        "/areas/eledhel/southern-city/12x2.c",
        "/areas/eledhel/southern-city/12x5.c",
        "/areas/eledhel/southern-city/12x6.c",
        "/areas/eledhel/southern-city/12x7.c",
        "/areas/eledhel/southern-city/13x2.c",
        "/areas/eledhel/southern-city/14x2.c",
        "/areas/eledhel/southern-city/14x5.c",
        "/areas/eledhel/southern-city/14x6.c",
        "/areas/eledhel/southern-city/14x7.c",
        "/areas/eledhel/southern-city/14x8.c",
        "/areas/eledhel/southern-city/14x9.c",
        "/areas/eledhel/southern-city/15x2.c",
        "/areas/eledhel/southern-city/15x5.c",
        "/areas/eledhel/southern-city/16x1.c",
        "/areas/eledhel/southern-city/16x2.c",
        "/areas/eledhel/southern-city/16x3.c",
        "/areas/eledhel/southern-city/16x4.c",
        "/areas/eledhel/southern-city/16x5.c",
        "/areas/eledhel/southern-city/17x1.c",
        "/areas/eledhel/southern-city/17x2.c",
        "/areas/eledhel/southern-city/17x5.c",
        "/areas/eledhel/southern-city/20x2.c",
        "/areas/eledhel/southern-city/20x3.c",
        "/areas/eledhel/southern-city/20x4.c",
        "/areas/eledhel/southern-city/21x2.c",
        "/areas/eledhel/southern-city/21x3.c",
        "/areas/eledhel/southern-city/21x4.c",
        "/areas/eledhel/southern-city/22x2.c",
        "/areas/eledhel/southern-city/22x3.c",
        "/areas/eledhel/southern-city/22x4.c",
        "/areas/eledhel/southern-city/23x2.c",
        "/areas/eledhel/southern-city/23x3.c",
        "/areas/eledhel/southern-city/23x4.c"
    });
    string *residentNames = ({
        "Berin", "Elset", "Faren", "Hethin", "Irielle", "Jalen",
        "Kaelin", "Lethan", "Miral", "Norien", "Orven", "Paven",
        "Rethen", "Sileth", "Taren", "Verran", "Daina", "Halwen",
        "Telya", "Carn", "Lorian", "Mellen", "Neral", "Ossen",
        "Peryn", "Quelan", "Rinan", "Soren", "Tavia", "Urian",
        "Veler", "Weryn", "Yaveth", "Zoran", "Arel", "Brann",
        "Corwen", "Deyra", "Eland", "Fethil", "Grevan", "Halen",
        "Iveron", "Jask", "Keryn", "Luvain", "Aedran", "Beryn",
        "Cira", "Dalon", "Eryth", "Faler"
    });
    string *residentRaces = ({
        "human", "maegenstryd", "human", "maegenstryd", "maegenstryd",
        "human", "maegenstryd", "maegenstryd", "elf", "maegenstryd",
        "human", "maegenstryd", "human", "maegenstryd", "human",
        "maegenstryd", "human", "maegenstryd", "dwarf", "human",
        "maegenstryd", "human", "maegenstryd", "human", "maegenstryd",
        "halfling", "human", "maegenstryd", "human", "maegenstryd",
        "human", "maegenstryd", "human", "maegenstryd", "human",
        "maegenstryd", "human", "maegenstryd", "human", "maegenstryd",
        "human", "maegenstryd", "human", "maegenstryd", "human",
        "maegenstryd", "maegenstryd", "human", "elf", "human", "dwarf",
        "halfling"
    });
    string *topics = ({
        "bread deliveries", "courier routes", "pottery", "market list",
        "street lamps", "tailoring", "water delivery", "watch patrol",
        "fresh herbs", "baking", "messages", "masonry",
        "brewery deliveries", "temple lamps", "old voyages",
        "cart loading", "herbal remedies", "wheel repairs", "jewelry work",
        "cart traffic", "engraving", "glass handling", "pottery purchases",
        "dye lots", "cloth orders", "market carts", "wheelwright",
        "spice packets", "provisions list", "street trade", "forge orders",
        "bowstrings", "shop watch", "inn directions", "market purchases",
        "cart routes", "harbor road", "household goods", "cloth sales",
        "shop patrol", "cargo tally", "loading berth", "fish catch",
        "net repair", "skiff berths", "ship water", "rigging",
        "fish baskets", "crew supplies", "quay watch", "barrel repair",
        "berth records"
    });

    ExpectEq(52, sizeof(roomPaths));
    ExpectEq(sizeof(roomPaths), sizeof(residentNames));
    ExpectEq(sizeof(roomPaths), sizeof(residentRaces));
    ExpectEq(sizeof(roomPaths), sizeof(topics));

    for (int index = 0; index < sizeof(roomPaths); index++)
    {
        object room = clone_object(roomPaths[index]);
        object resident = 0;
        Harvested += ({ room });
        move_object(Player, room);

        foreach (object candidate in all_inventory(room))
        {
            if (candidate != Player && candidate->id(residentNames[index]))
            {
                resident = candidate;
            }
        }

        ExpectTrue(objectp(resident), residentNames[index]);
        if (objectp(resident))
        {
            ExpectEq(residentRaces[index], resident->Race(),
                sprintf("%s race", residentNames[index]));
            ExpectTrue(resident->hasTopic(topics[index]) > -1,
                sprintf("%s conversation topic", residentNames[index]));
            Spawned += ({ resident });
        }
    }
}
