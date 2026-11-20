//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/eledhel/southern-road/roadRoom.c";

public void Setup()
{
    setRoadCell("The road leaves Rhaedhen's southern grazing fields.",
        "/lib/environment/terrain/farmland.c", ([
            "north": "/areas/eledhel/southwest-rural-three/17x4.c",
            "east": "/areas/eledhel/south-rural-route-04/1x2.c"
        ]));
}
