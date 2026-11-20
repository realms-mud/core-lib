//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/eledhel/southern-road/roadRoom.c";

public void Setup()
{
    setRoadCell("The King's Road passes rows of winter-bare fruit trees.",
        "/lib/environment/terrain/farmland.c", ([
            "west": "/areas/eledhel/south-rural-route-04/12x2.c",
            "east": "/areas/eledhel/south-rural-route-04/14x2.c"
        ]));
}
