//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/eledhel/southern-road/roadRoom.c";

public void Setup()
{
    setRoadCell("The road descends toward a mill stream in the valley.",
        "/lib/environment/terrain/forest.c", ([
            "west": "/areas/eledhel/south-rural-route-12/13x2.c",
            "east": "/areas/eledhel/south-rural-route-12/15x2.c"
        ]));
}
