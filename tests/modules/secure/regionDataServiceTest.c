//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object DataAccess;
object Database;

/////////////////////////////////////////////////////////////////////////////
mapping createEmptyGrid(int x, int y)
{
    mapping grid = ([]);

    for (int i = 0; i < x; i++)
    {
        grid[i] = ([]);
        for (int j = 0; j < y; j++)
        {
            grid[i][j] = ([
                "x": i,
                "y": j,
                "room type": "none",
                "is placed": 0,
                "exits": ([]),
                "environment": 0
            ]);
        }
    }
    return grid;
}

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    ignoreList += ({ "createEmptyGrid" });

    setRestoreCaller(this_object());
    Database = clone_object("/lib/tests/modules/secure/fakeDatabase.c");
    Database->PrepDatabase();
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    DataAccess = 
        clone_object("/lib/modules/secure/dataServices/regionDataService.c");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(DataAccess);
}

/////////////////////////////////////////////////////////////////////////////
void CanSaveToDatabase()
{
    DataAccess->saveRegion("test", "forest", 5, 6, "/path/to/nowhere.c",
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
            "objects": ([
                "/lib/some/critter.c":([
                    "state": "default",
                    "is random": 1,
                    "probability": 25,
                    "quantity": 1
                ]),
                "/lib/some/other/critter.c":([
                    "state": "default",
                    "is random": 1,
                    "probability": 75,
                    "quantity": 1
                ])
            ])
        ]) }));

    mapping grid = createEmptyGrid(5, 6);

    mapping output =
        DataAccess->loadRegion("north", "/path/to/nowhere.c", grid);

    ExpectEq("north", output["entry direction"]);
    ExpectEq("/path/to/nowhere.c", output["entry point"]);
    ExpectEq("test", output["name"]);
    ExpectEq("forest", output["type"]);
    ExpectEq(5, output["x-dimension"]);
    ExpectEq(6, output["y-dimension"]);
    ExpectEq(([ "identifier": "/some/path/x.c,1x2",
        "y": 2,
        "elements": ({ ([ 
            "x-coordinate": 1,
            "location": "east",
            "z-coordinate": 1,
            "y-coordinate": 0,
            "value": "/lib/something-else.c",
            "element type": "feature",
            "state": "default"
        ]),
        ([  "x-coordinate": 0,
            "location": "north",
            "z-coordinate": 1,
            "y-coordinate": 1,
            "value": "/lib/something-else.c",
            "element type": "feature",
            "state": "default"
        ]),
        ([  "x-coordinate": 0,
            "location": "",
            "z-coordinate": 0,
            "y-coordinate": 0,
            "value": "/lib/something.c",
            "element type": "terrain",
            "state": "default"
        ]) }),
        "name": "weasel",
        "exits": ([
            "north": "/lib/somewhere/else.c",
            "south": "/lib/elsewhere.c"
        ]),
        "is cloned": 0,
        "room type": "entry",
        "objects": ({ ([ 
            "path": "/lib/some/other/critter.c",
            "is random": 1,
            "probability": 75,
            "state": "default"
        ]),
        ([  "path": "/lib/some/critter.c",
            "is random": 1,
            "probability": 25,
            "state": "default"
        ]) }),
        "shop": "",
        "description": "",
        "is placed": 1,
        "x": 1
    ]), output["grid"][1][2]);
}
