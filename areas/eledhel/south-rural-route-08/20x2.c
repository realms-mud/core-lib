//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/eledhel/southern-road/roadRoom.c";

public void Setup()
{
    setRoadCell("A stone post marks the border of Hadrath's patrol lands.",
        "/lib/environment/terrain/plains.c", ([
            "west": "/areas/eledhel/south-rural-route-08/19x2.c",
            "east": "/areas/eledhel/south-rural-route-08/21x2.c"
        ]));
}
