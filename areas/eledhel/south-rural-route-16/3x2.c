//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/eledhel/southern-road/roadRoom.c";

public void Setup()
{
    setRoadCell("A ruined roadside shrine rises beyond a thorn hedge.",
        "/lib/environment/terrain/plains.c", ([
            "west": "/areas/eledhel/south-rural-route-16/2x2.c",
            "east": "/areas/eledhel/south-rural-route-16/4x2.c"
        ]));
}
