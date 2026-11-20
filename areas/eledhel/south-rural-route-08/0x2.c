//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/eledhel/southern-road/roadRoom.c";

public void Setup()
{
    setRoadCell("The King's Road enters the uplands watched by Hadrath.",
        "/lib/environment/terrain/plains.c", ([
            "west": "/areas/eledhel/southwest-rural-four/24x9.c",
            "east": "/areas/eledhel/south-rural-route-08/1x2.c"
        ]));
}
