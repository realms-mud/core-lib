//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/eledhel/southern-road/roadRoom.c";

public void Setup()
{
    setRoadCell("The King's Road climbs onto a low ridge.",
        "/lib/environment/terrain/plains.c", ([
            "east": "/areas/eledhel/south-rural-route-03/9x2.c",
            "west": "/areas/eledhel/south-rural-route-03/7x2.c"
        ]));
}
