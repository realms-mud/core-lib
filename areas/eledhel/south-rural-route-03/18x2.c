//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/eledhel/southern-road/roadRoom.c";

public void Setup()
{
    setRoadCell("The King's Road passes a run of exposed grey rock.",
        "/lib/environment/terrain/plains.c", ([
            "east": "/areas/eledhel/south-rural-route-03/19x2.c",
            "west": "/areas/eledhel/south-rural-route-03/17x2.c"
        ]));
}
