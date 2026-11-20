//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/eledhel/southern-road/roadRoom.c";

public void Setup()
{
    setRoadCell("A stand of alder grows beside a shallow ditch.",
        "/lib/environment/terrain/forest.c", ([
            "west": "/areas/eledhel/south-rural-route-11/6x2.c",
            "east": "/areas/eledhel/south-rural-route-11/8x2.c"
        ]));
}
