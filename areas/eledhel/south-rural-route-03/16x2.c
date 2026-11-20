//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/eledhel/southern-road/roadRoom.c";

public void Setup()
{
    setRoadCell("A wide cattle track joins the King's Road.",
        "/lib/environment/terrain/farmland.c", ([
            "east": "/areas/eledhel/south-rural-route-03/17x2.c",
            "west": "/areas/eledhel/south-rural-route-03/15x2.c"
        ]));
}
