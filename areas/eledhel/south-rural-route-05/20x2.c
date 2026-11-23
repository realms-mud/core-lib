//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/eledhel/southern-road/roadRoom.c";

public void Setup()
{
    setRoadCell("The road descends past the last orchard rows; "
        "a farm lane turns north toward Tirwen.",
        "/lib/environment/terrain/farmland.c", ([
            "west": "/areas/eledhel/south-rural-route-05/19x2.c",
            "east": "/areas/eledhel/south-rural-route-05/21x2.c",
            "north": "/areas/eledhel/tirwen/3x1.c"
        ]));
}
