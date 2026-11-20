//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/eledhel/southern-road/roadRoom.c";

public void Setup()
{
    setRoadCell("The King's Road descends toward Rhaedhen's fields.",
        "/lib/environment/terrain/farmland.c", ([
            "east": "/areas/eledhel/south-rural-route-03/18x2.c",
            "west": "/areas/eledhel/south-rural-route-03/16x2.c"
        ]));
}
