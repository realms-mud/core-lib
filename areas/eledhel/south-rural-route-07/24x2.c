//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/eledhel/southern-road/roadRoom.c";

public void Setup()
{
    setRoadCell("The road climbs toward the lower drove country.",
        "/lib/environment/terrain/plains.c", ([
            "west": "/areas/eledhel/south-rural-route-07/23x2.c",
            "south": "/areas/eledhel/southwest-rural-four/12x0.c"
        ]));
}
