//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Environment;
object Region;
object Player;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player->Name("bob");
    Player->addCommands();
    Player->colorConfiguration("3-bit");
    Player->charsetConfiguration("unicode");

    Region = clone_object("/lib/tests/support/environment/regionHelper.c");

    Environment = clone_object("/lib/environment/generatedEnvironment.c");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Environment);
    destruct(Region);
    destruct(Player);
}

/////////////////////////////////////////////////////////////////////////////
void GenerateEnvironmentCorrectlyCreatesRoom()
{
    Region->setRegionName("a forest");
    Region->setRegionType("forest");

    Region->setDimensions(10, 5);

    mapping data = ([
        "x": 1,
        "y": 2,
        "room type": "room",
        "is placed": 1,
        "exits": ([
            "north": "3x1"
        ]),
        "environment": Environment
    ]);

    Environment->generateEnvironment(data, Region);
    ExpectSubStringMatch("(grove|tree|forest).*one obvious exit: north", 
        Environment->long());
}

/////////////////////////////////////////////////////////////////////////////
void CanMoveFromOneGeneratedRoomToTheNext()
{
    Region->setRegionName("a forest");
    Region->setRegionType("forest");

    Region->setDimensions(10, 5);

    mapping data = ([
        "x":1,
        "y": 2,
        "room type": "room",
        "is placed": 1,
        "exits": ([
            "north": "1x3"
        ])
    ]);
    Region->addTestRoom(1, 2, data);

    mapping data2 = ([
        "x":1,
        "y": 3,
        "room type": "room",
        "is placed": 1,
        "exits": ([
            "south": "1x2"
        ])
    ]);
    Region->addTestRoom(1, 3, data2);

    move_object(Player, data["environment"]);
    ExpectEq(object_name(data["environment"]), object_name(environment(Player)));

    command("n", Player);
    ExpectEq(object_name(data2["environment"]), object_name(environment(Player)));

    command("s", Player);
    ExpectEq(object_name(data["environment"]), object_name(environment(Player)));
}

/////////////////////////////////////////////////////////////////////////////
void EncountersGeneratedWhenUserEntersEnvironment()
{
    Region->setRegionName("a temple");
    Region->setRegionType("keeper's temple");

    Region->setDimensions(5, 5);

    mapping data = ([
        "x":1,
        "y": 2,
        "room type": "room",
        "is placed": 1,
        "exits": ([
            "north": "1x3"
        ])
    ]);
    Region->addTestRoom(1, 2, data);

    move_object(Player, data["environment"]);

    ExpectTrue(sizeof(all_inventory(data["environment"])) > 1);
    ExpectTrue(sizeof(all_inventory(all_inventory(data["environment"])[0])));
}
