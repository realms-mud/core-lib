//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/eledhel/southern-road/roadRoom.c";

public void Setup()
{
    setRoadCell("A low stone wall separates the King's Road from the orchard.",
        "/lib/environment/terrain/farmland.c", ([
            "west": "/areas/eledhel/south-rural-route-05/1x2.c",
            "east": "/areas/eledhel/south-rural-route-05/3x2.c"
        ]));
}
