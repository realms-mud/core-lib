//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/eledhel/southern-road/roadRoom.c";

public void Setup()
{
    setRoadCell("The King's Road enters low, wet grazing country.",
        "/lib/environment/terrain/farmland.c", ([
            "north": "/areas/eledhel/southwest-rural-five/14x9.c",
            "east": "/areas/eledhel/south-rural-route-13/1x2.c"
        ]));
}
