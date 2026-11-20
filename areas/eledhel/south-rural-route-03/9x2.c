//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/eledhel/southern-road/roadRoom.c";

public void Setup()
{
    setRoadCell("The King's Road crosses a broad stretch of open grass.",
        "/lib/environment/terrain/plains.c", ([
            "east": "/areas/eledhel/south-rural-route-03/10x2.c",
            "west": "/areas/eledhel/south-rural-route-03/8x2.c"
        ]));
}
