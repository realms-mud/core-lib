//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/eledhel/southern-road/roadRoom.c";

public void Setup()
{
    setRoadCell("A stone marker warns of high water at the ford.",
        "/lib/environment/terrain/plains.c", ([
            "west": "/areas/eledhel/south-rural-route-07/6x2.c",
            "east": "/areas/eledhel/south-rural-route-07/8x2.c"
        ]));
}
