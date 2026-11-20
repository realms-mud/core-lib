//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/eledhel/southern-road/roadRoom.c";

public void Setup()
{
    setRoadCell("A cluster of farmsteads lies beyond a low stone fence.",
        "/lib/environment/terrain/farmland.c", ([
            "west": "/areas/eledhel/south-rural-route-08/21x2.c",
            "east": "/areas/eledhel/south-rural-route-08/23x2.c"
        ]));
}
