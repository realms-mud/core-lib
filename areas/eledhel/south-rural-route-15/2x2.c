//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/eledhel/southern-road/roadRoom.c";

public void Setup()
{
    setRoadCell("The road climbs a ridge of dark, wind-cut stone.",
        "/lib/environment/terrain/plains.c", ([
            "west": "/areas/eledhel/south-rural-route-15/1x2.c",
            "east": "/areas/eledhel/south-rural-route-15/3x2.c"
        ]));
}
