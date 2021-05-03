//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object DataAccess;
object Database;
object Region;
object Room;

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    setRestoreCaller(this_object());
    Database = clone_object("/lib/tests/modules/secure/fakeDatabase.c");
    Database.PrepDatabase();
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    DataAccess = 
        clone_object("/lib/modules/secure/dataServices/regionDataService.c");

    Region = clone_object("/lib/tests/support/environment/regionHelper.c");

    Room = load_object("/lib/tests/support/environment/regionRoom.c");
    Room.setGeneratedSettlementChance(100);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Room);
    destruct(Region);
    destruct(DataAccess);
}

/////////////////////////////////////////////////////////////////////////////
void CanSaveToDatabase()
{
    DataAccess.saveRegion("test", "forest", 5, 6, "/path/to/nowhere.c",
        "north", ({ ([
            "x": 1,
            "y" : 2,
            "room type" : "entry",
            "is placed" : 1,
            "name": "weasel",
            "identifier": "/some/path/x.c,1x2",
            "exits": ([ "north": "/lib/somewhere/else.c", "south": "/lib/elsewhere.c" ]),
            "elements" : ([ 
                "/lib/something.c": ([ 
                    "type": "terrain", 
                    "state": "default",
                    "x-coordinate": 0,
                    "y-coordinate" : 0,
                    "z-coordinate" : 0,
                ]),
                "/lib/something-else.c,north": ([ 
                    "type": "feature", 
                    "state": "default",
                    "x-coordinate": 0,
                    "y-coordinate" : 1,
                    "z-coordinate" : 1,
                ]),
                "/lib/something-else.c,east": ([ 
                    "type": "feature", 
                    "state": "default",
                    "x-coordinate": 1,
                    "y-coordinate" : 0,
                    "z-coordinate" : 1,
                ]),
            ]),
            "room objects": ([
                "/lib/some/critter.c":([
                    "state": "default",
                    "is random": 1,
                    "probability": 25,
                    "quantity": 1,
                    "type": "creature"
                ]),
                "/lib/some/other/critter.c":([
                    "state": "default",
                    "is random": 1,
                    "probability": 75,
                    "quantity": 1,
                    "type": "creature"
                ])
            ])
        ]) }));

    mapping output =
        DataAccess.loadRegion("north", "/path/to/nowhere.c");

    ExpectEq("north", output["entry direction"]);
    ExpectEq("/path/to/nowhere.c", output["entry point"]);
    ExpectEq("test", output["name"]);
    ExpectEq("forest", output["type"]);
    ExpectEq(5, output["x-dimension"]);
    ExpectEq(6, output["y-dimension"]);
    ExpectEq(([ "identifier": "/some/path/x.c,1x2",
        "y": 2,
        "room objects": ([ 
            "/lib/some/critter.c": ([ 
                "type": "creature",
                "quantity": 1,
                "is random": 1,
                "probability": 25,
                "state": "default"
            ]),
            "/lib/some/other/critter.c": ([
                "type": "creature",
                "quantity": 1,
                "is random": 1,
                "probability": 75,
                "state": "default"
            ])
        ]),
        "elements": ([
            "/lib/something-else.c,east": ([ 
                "z-rotation": 0,
                "y-rotation": 0,
                "z-coordinate": 1,
                "y-coordinate": 0,
                "state": "default",
                "x-coordinate": 1,
                "type": "feature",
                "x-rotation": 0
            ]),
            "/lib/something.c": ([
                "z-rotation": 0,
                "y-rotation": 0,
                "z-coordinate": 0,
                "y-coordinate": 0,
                "state": "default",
                "x-coordinate": 0,
                "type": "terrain",
                "x-rotation": 0
            ]),
            "/lib/something-else.c,north": ([
                "z-rotation": 0,
                "y-rotation": 0,
                "z-coordinate": 1,
                "y-coordinate": 1,
                "state": "default",
                "x-coordinate": 0,
                "type": "feature",
                "x-rotation": 0
            ])
        ]),
        "name": "weasel",
        "exits": ([
            "north": "/lib/somewhere/else.c",
            "south": "/lib/elsewhere.c"
        ]),
        "is cloned": 0,
        "room type": "entry",
        "shop": "",
        "description": "",
        "is placed": 1,
        "x": 1
    ]), output["grid"][1][2]);
}

/////////////////////////////////////////////////////////////////////////////
void CanRestoreRegion()
{   
    object user = clone_object("/lib/tests/support/services/mockPlayer.c");
    user.Name("bob");
    user.addCommands();

    object region = Room.addGeneratedRegion("north", "forest", 15, 10);
    region.save();
    destruct(Room);

    Room = load_object("/lib/tests/support/environment/regionRoom.c");
    object newRegion = Room.addGeneratedRegion("north", "forest", 15, 10);

    ExpectEq(region.displayMap(user), newRegion.displayMap(user));

    move_object(user, Room);

    command("n", user);
    ExpectEq(newRegion.getEntryCoordinates(), environment(user).getCoordinates());
    ExpectEq(newRegion.getEnvironment(newRegion.getEntryCoordinates()),
        environment(user));

    command("s", user);
    ExpectEq(Room, environment(user));
}
