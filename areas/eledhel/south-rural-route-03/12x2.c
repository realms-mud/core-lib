//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/eledhel/southern-road/roadRoom.c";

public void Setup()
{
    setRoadCell("The King's Road skirts a small grove of hazel.",
        "/lib/environment/terrain/forest.c", ([
            "east": "/areas/eledhel/south-rural-route-03/13x2.c",
            "west": "/areas/eledhel/south-rural-route-03/11x2.c"
        ]));
}
