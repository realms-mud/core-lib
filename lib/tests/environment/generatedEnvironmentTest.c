//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Environment;
object Region;
object Player;

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    ignoreList += ({ "getRegionData" });
}

/////////////////////////////////////////////////////////////////////////////
private mapping *getRegionData(object region)
{
    mapping *data = ({
      ([
        "y": 0,
        "name": "1x0",
        "exits": ([
           "north": "1x1"
         ]),
        "room type": "entry",
        "x": 1,
        "is placed": 1
      ]),
      ([
        "y": 0,
        "name": "3x0",
        "exits": ([ 
           "west": "2x0",
           "north": "3x1",
           "east": "4x0"
         ]),
        "room type": "room",
        "x": 3,
        "is placed": 1
      ]),
      ([
        "y": 2,
        "name": "0x2",
        "exits": ([
           "east": "1x2"
         ]),
        "room type": "room",
        "x": 0,
        "is placed": 1
      ]),
      ([
        "y": 1,
        "name": "3x1",
        "exits": ([
           "west": "2x1",
           "south": "3x0"
         ]),
        "room type": "room",
        "x": 3,
        "is placed": 1
      ]),
      ([
        "y": 2,
        "name": "3x2",
        "exits": ([
           "east": "4x2"
         ]),
        "room type": "room",
        "x": 3,
        "is placed": 1
      ]),
      ([
        "y": 0,
        "name": "4x0",
        "exits": ([ 
           "west": "3x0",
           "north": "4x1"
         ]),
        "room type": "room",
        "x": 4,
        "is placed": 1
      ]),
      ([
        "y": 0,
        "name": "2x0",
        "exits": ([
           "east": "3x0"
         ]),
        "room type": "room",
        "x": 2,
        "is placed": 1
      ]),
      ([ 
        "y": 1,
        "name": "2x1",
        "exits": ([
           "north": "2x2",
           "east": "3x1",
           "west": "1x1"
         ]),
        "room type": "path",
        "x": 2,
        "is placed": 1
      ]),
      ([
        "y": 1,
        "name": "1x1",
        "exits": ([
           "south": "1x0",
           "east": "2x1"
         ]),
        "room type": "path",
        "x": 1,
        "is placed": 1
      ]),
      ([
        "y": 2,
        "name": "1x2",
        "exits": ([ 
           "east": "2x2",
           "west": "0x2"
         ]),
        "room type": "path",
        "x": 1,
        "is placed": 1
      ]),
      ([
        "y": 2,
        "name": "2x2",
        "exits": ([
           "south": "2x1",
           "north": "2x3",
           "west": "1x2"
         ]),
        "room type": "path",
        "x": 2,
        "is placed": 1
      ]),
      ([
        "y": 2,
        "name": "4x2",
        "exits": ([
           "south": "4x1",
           "west": "3x2"
         ]),
        "room type": "path",
        "x": 4,
        "is placed": 1
      ]),
      ([
        "y": 1,
        "name": "4x1",
        "exits": ([
           "south": "4x0",
           "north": "4x2"
         ]),
        "room type": "path",
        "x": 4,
        "is placed": 1
      ]),
      ([
        "y": 4,
        "name": "1x4",
        "exit to" : "north",
        "exits": ([
           "south": "1x3"
         ]),
        "room type": "exit",
        "x": 1,
        "is placed": 1
      ]),
      ([
        "y": 3,
        "name": "1x3",
        "exits": ([
           "east": "2x3",
           "north": "1x4"
         ]),
        "room type": "path",
        "x": 1,
        "is placed": 1
      ]),
      ([
        "y": 3,
        "name": "2x3",
        "exits": ([ 
           "south": "2x2",
           "west": "1x3"
         ]),
        "room type": "path",
        "x": 2,
        "is placed": 1
      ])
    });

    foreach(mapping room in data)
    {
        Region->addTestRoom(room["x"], room["y"], room);
    }

    return data;
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    load_object("/lib/dictionaries/environmentDictionary.c");
    ToggleCallOutBypass();

    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player->Name("bob");
    Player->addCommands();
    Player->colorConfiguration("none");
    Player->charsetConfiguration("ascii");

    Region = clone_object("/lib/tests/support/environment/regionHelper.c");

    Environment = clone_object("/lib/environment/generatedEnvironment.c");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Environment);
    destruct(Region);
    destruct(Player);

    ToggleCallOutBypass();
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

/////////////////////////////////////////////////////////////////////////////
void ExitPointsConnectedToNewRegion()
{
    Region->setRegionName("a temple");
    Region->setRegionType("keeper's temple");

    Region->setDimensions(5, 5);

    mapping data = ([
        "x": 4,
        "y": 4,
        "name": "4x4",
        "room type": "exit",
        "exit to": "north",
        "exit coordinates": ({ 4, 0 }),
        "is placed" : 1,
        "exits" : ([
            "south":"4x3"
        ])
    ]);
    Region->addTestRoom(4, 4, data);

    move_object(Player, data["environment"]);

    ExpectEq("4x4", environment(Player)->getCoordinates());
    ExpectEq(Region, environment(Player)->getRegion());

    command("n", Player);
    ExpectEq("4x0", environment(Player)->getCoordinates());
    ExpectNotEq(Region, environment(Player)->getRegion());

    command("s", Player);
    ExpectEq("4x4", environment(Player)->getCoordinates());
    ExpectEq(Region, environment(Player)->getRegion());
}

/////////////////////////////////////////////////////////////////////////////
void MapCorrectlyDisplayed()
{
    Region->setRegionName("a temple");
    Region->setRegionType("keeper's temple");

    Region->setDimensions(5, 5);

    mapping *data = getRegionData(Region);

    move_object(Player, data[0]["environment"]);
    ExpectEq("\n    |          \n"
        "    X          \n"
        "    |          \n"
        "    |          \n"
        "    o--o       \n"
        "       |       \n"
        "       |       \n"
        " #--o--o  #--o \n"
        "       |     | \n"
        "       |     | \n"
        "    o--o--#  o \n"
        "    |     |  | \n"
        "    |     |  | \n"
        "    P  #--#--# \n"
        "               \n", Region->displayMap(Player));
}

/////////////////////////////////////////////////////////////////////////////
void MiniMapCorrectlyDisplayedOnMinY()
{
    Region->setRegionName("a temple");
    Region->setRegionType("keeper's temple");

    Region->setDimensions(5, 5);

    mapping *data = getRegionData(Region);

    move_object(Player, data[0]["environment"]);

    ExpectEq("       | '\n"
        " #--o--o '\n"
        "       | '\n"
        "       | '\n"
        "    o--o-'\n"
        "    |    '\n"
        "    |    '\n"
        "    P  #-'\n"
        "         '\n", 
        implode(Region->getMiniMap(environment(Player), Player), "\n"));
}

/////////////////////////////////////////////////////////////////////////////
void MiniMapCorrectlyDisplayedOnMaxY()
{
    Region->setRegionName("a temple");
    Region->setRegionType("keeper's temple");

    Region->setDimensions(5, 5);

    mapping *data = getRegionData(Region);

    move_object(Player, data[13]["environment"]);

    ExpectEq("    |    '\n"
        "    P    '\n"
        "    |    '\n"
        "    |    '\n"
        "    o--o '\n"
        "       | '\n"
        "       | '\n"
        " #--o--o '\n"
        "       | '\n",
        implode(Region->getMiniMap(environment(Player), Player), "\n"));
}

/////////////////////////////////////////////////////////////////////////////
void MiniMapCorrectlyDisplayedOnMinX()
{
    Region->setRegionName("a temple");
    Region->setRegionType("keeper's temple");

    Region->setDimensions(5, 5);

    mapping *data = getRegionData(Region);

    move_object(Player, data[2]["environment"]);

    ExpectEq("    |    '\n"
        "    o--o '\n"
        "       | '\n"
        "       | '\n"
        " P--o--o '\n"
        "       | '\n"
        "       | '\n"
        "    o--o-'\n"
        "    |    '\n",
        implode(Region->getMiniMap(environment(Player), Player), "\n"));
}

/////////////////////////////////////////////////////////////////////////////
void MiniMapCorrectlyDisplayedOnMaxX()
{
    Region->setRegionName("a temple");
    Region->setRegionType("keeper's temple");

    Region->setDimensions(5, 5);

    mapping *data = getRegionData(Region);

    move_object(Player, data[12]["environment"]);

    ExpectEq(" |       '\n"
        "-o  #--o '\n"
        " |     | '\n"
        " |     | '\n"
        "-o--#  P '\n"
        "    |  | '\n"
        "    |  | '\n"
        " #--#--# '\n"
        "         '\n",
        implode(Region->getMiniMap(environment(Player), Player), "\n"));
}

/////////////////////////////////////////////////////////////////////////////
void MiniMapCorrectlyDisplayedInMapInterior()
{
    Player->colorConfiguration("3-bit");
    Region->setRegionName("a temple");
    Region->setRegionType("keeper's temple");

    Region->setDimensions(5, 5);

    mapping *data = getRegionData(Region);

    move_object(Player, data[10]["environment"]);

    ExpectEq(
        "\x1b[0;36m \x1b[0m\x1b[0;36m|\x1b[0m\x1b[0;36m \x1b[0m\x1b[0;36m \x1b[0m\x1b[0;36m \x1b[0m\x1b[0;36m \x1b[0m\x1b[0;36m \x1b[0m\x1b[0;36m \x1b[0m\x1b[0;36m \x1b[0m\x1b[0;31m'\x1b[0m\n"
        "\x1b[0;36m \x1b[0mo\x1b[0;36m-\x1b[0m\x1b[0;36m-\x1b[0mo\x1b[0;36m \x1b[0m\x1b[0;36m \x1b[0m\x1b[0;36m \x1b[0m\x1b[0;36m \x1b[0m\x1b[0;31m'\x1b[0m\n"
        "\x1b[0;36m \x1b[0m\x1b[0;36m \x1b[0m\x1b[0;36m \x1b[0m\x1b[0;36m \x1b[0m\x1b[0;36m|\x1b[0m\x1b[0;36m \x1b[0m\x1b[0;36m \x1b[0m\x1b[0;36m \x1b[0m\x1b[0;36m \x1b[0m\x1b[0;31m'\x1b[0m\n"
        "\x1b[0;36m \x1b[0m\x1b[0;36m \x1b[0m\x1b[0;36m \x1b[0m\x1b[0;41m \x1b[0m\x1b[0;41;33m|\x1b[0m\x1b[0;41m \x1b[0m\x1b[0;36m \x1b[0m\x1b[0;36m \x1b[0m\x1b[0;36m \x1b[0m\x1b[0;31m'\x1b[0m\n"
        "\x1b[0;36m-\x1b[0mo\x1b[0;36m-\x1b[0m\x1b[0;41;33m-\x1b[0m\x1b[0;41;33mP\x1b[0m\x1b[0;41m \x1b[0m\x1b[0;36m \x1b[0m\x1b[0;34;1m#\x1b[0m\x1b[0;36m-\x1b[0m\x1b[0;31m'\x1b[0m\n"
        "\x1b[0;36m \x1b[0m\x1b[0;36m \x1b[0m\x1b[0;36m \x1b[0m\x1b[0;41m \x1b[0m\x1b[0;41;33m|\x1b[0m\x1b[0;41m \x1b[0m\x1b[0;36m \x1b[0m\x1b[0;36m \x1b[0m\x1b[0;36m \x1b[0m\x1b[0;31m'\x1b[0m\n"
        "\x1b[0;36m \x1b[0m\x1b[0;36m \x1b[0m\x1b[0;36m \x1b[0m\x1b[0;36m \x1b[0m\x1b[0;36m|\x1b[0m\x1b[0;36m \x1b[0m\x1b[0;36m \x1b[0m\x1b[0;36m \x1b[0m\x1b[0;36m \x1b[0m\x1b[0;31m'\x1b[0m\n"
        "\x1b[0;36m \x1b[0mo\x1b[0;36m-\x1b[0m\x1b[0;36m-\x1b[0mo\x1b[0;36m-\x1b[0m\x1b[0;36m-\x1b[0m\x1b[0;34;1m#\x1b[0m\x1b[0;36m \x1b[0m\x1b[0;31m'\x1b[0m\n"
        "\x1b[0;36m \x1b[0m\x1b[0;36m|\x1b[0m\x1b[0;36m \x1b[0m\x1b[0;36m \x1b[0m\x1b[0;36m \x1b[0m\x1b[0;36m \x1b[0m\x1b[0;36m \x1b[0m\x1b[0;36m|\x1b[0m\x1b[0;36m \x1b[0m\x1b[0;31m'\x1b[0m\n",
        implode(Region->getMiniMap(environment(Player), Player), "\n"));
}

/////////////////////////////////////////////////////////////////////////////
void MiniMapCorrectlyDisplayedInEnvironment()
{
    Region->setRegionName("a temple");
    Region->setRegionType("keeper's temple");

    Region->setDimensions(5, 5);

    mapping *data = getRegionData(Region);

    move_object(Player, data[0]["environment"]);

    command("l", Player);
    ExpectSubStringMatch("       | ' .* To the north is a path.\n"
        " #--o--o '\n"
        "       | '\n"
        "       | '\n"
        "    o--o-'\n"
        "    |    '\n"
        "    |    '\n"
        "    P  #-'\n"
        "         '\n"
        "The sun is high in the summer sky.\n"
        " -=-=- There is one obvious exit: north\n",
        Player->caughtMessage());
}
