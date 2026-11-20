//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/eledhel/southern-road/roadRoom.c";

public void Setup()
{
    setRoadCell("A stone boundary marker stands beside the King's Road.",
        "/lib/environment/terrain/plains.c", ([
            "west": "/areas/eledhel/south-rural-route-02/15x2.c",
            "east": "/areas/eledhel/south-rural-route-02/17x2.c"
        ]));
}
