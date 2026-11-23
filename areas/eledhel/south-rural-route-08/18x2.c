//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/eledhel/southern-road/roadRoom.c";

public void Setup()
{
    setRoadCell("The road passes a lonely watch shelter.",
        "/lib/environment/terrain/plains.c", ([
            "west": "/areas/eledhel/south-rural-route-08/17x2.c",
            "east": "/areas/eledhel/south-rural-route-08/19x2.c",
            "south": "/areas/eledhel/hadrath/watchlands/0x0.c"
        ]));
}
