//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/eledhel/southern-road/roadRoom.c";

public void Setup()
{
    setRoadCell("The King's Road bends through an open meadow.",
        "/lib/environment/terrain/plains.c", ([
            "west": "/areas/eledhel/south-rural-route-01/14x2.c",
            "east": "/areas/eledhel/south-rural-route-01/16x2.c"
        ]));
}
