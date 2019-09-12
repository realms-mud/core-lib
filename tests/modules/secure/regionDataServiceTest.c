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
                "exits": ([ "north": "/lib/somewhere/else.c", "south": "/lib/elsewhere.c" ])
            ]) }));


    mapping grid = createEmptyGrid(5, 6);
}
