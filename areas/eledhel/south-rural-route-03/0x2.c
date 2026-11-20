//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/eledhel/southern-road/roadRoom.c";

public void Setup()
{
    setRoadCell("The King's Road returns to the northern edge of Eledhel.",
        "/lib/environment/terrain/farmland.c", ([
            "east": "/areas/eledhel/south-rural-route-03/1x2.c",
            "north": "/areas/eledhel/southwest-rural-three/24x0.c"
        ]));
}
