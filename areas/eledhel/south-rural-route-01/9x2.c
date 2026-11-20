//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/eledhel/southern-road/roadRoom.c";

public void Setup()
{
    setRoadCell("The King's Road winds past a cluster of farmsteads.",
        "/lib/environment/terrain/farmland.c", ([
            "west": "/areas/eledhel/south-rural-route-01/8x2.c",
            "east": "/areas/eledhel/south-rural-route-01/10x2.c"
        ]));
}
