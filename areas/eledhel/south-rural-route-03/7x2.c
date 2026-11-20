//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/eledhel/southern-road/roadRoom.c";

public void Setup()
{
    setRoadCell("A stand of oak shades the King's Road.",
        "/lib/environment/terrain/forest.c", ([
            "east": "/areas/eledhel/south-rural-route-03/8x2.c",
            "west": "/areas/eledhel/south-rural-route-03/6x2.c"
        ]));
}
