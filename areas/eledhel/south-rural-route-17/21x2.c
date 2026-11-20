//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/eledhel/southern-road/roadRoom.c";

public void Setup()
{
    setRoadCell("The King's Road enters Linwaeth's northern wool commons.",
        "/lib/environment/terrain/village.c", ([
            "west": "/areas/eledhel/south-rural-route-17/20x2.c",
            "south": "/areas/linwaeth/12x0.c"
        ]));
}
