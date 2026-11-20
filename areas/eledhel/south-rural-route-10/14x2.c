//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/eledhel/southern-road/roadRoom.c";

public void Setup()
{
    setRoadCell("A flock grazes near a long, low sheep shelter.",
        "/lib/environment/terrain/farmland.c", ([
            "west": "/areas/eledhel/south-rural-route-10/13x2.c",
            "east": "/areas/eledhel/south-rural-route-10/15x2.c"
        ]));
}
