//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/eledhel/southern-road/roadRoom.c";

public void Setup()
{
    setRoadCell("A signpost points toward the Llenadur drovers' rest.",
        "/lib/environment/terrain/plains.c", ([
            "west": "/areas/eledhel/south-rural-route-11/8x2.c",
            "east": "/areas/eledhel/south-rural-route-11/10x2.c"
        ]));
}
