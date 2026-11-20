//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/eledhel/southern-road/roadRoom.c";

public void Setup()
{
    setRoadCell("The King's Road follows a hedge above the river.",
        "/lib/environment/terrain/farmland.c", ([
            "west": "/areas/eledhel/south-rural-route-07/17x2.c",
            "east": "/areas/eledhel/south-rural-route-07/19x2.c"
        ]));
}
