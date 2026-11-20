//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/eledhel/southern-road/roadRoom.c";

public void Setup()
{
    setRoadCell("The King's Road crosses a ridge beneath the trees.",
        "/lib/environment/terrain/forest.c", ([
            "east": "/areas/eledhel/south-rural-route-03/23x2.c",
            "west": "/areas/eledhel/south-rural-route-03/21x2.c"
        ]));
}
