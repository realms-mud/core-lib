//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/eledhel/southern-road/roadRoom.c";

public void Setup()
{
    setRoadCell("The road bends beneath the branches of a broad oak.",
        "/lib/environment/terrain/forest.c", ([
            "west": "/areas/eledhel/south-rural-route-12/3x2.c",
            "east": "/areas/eledhel/south-rural-route-12/5x2.c"
        ]));
}
