//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/eledhel/southern-road/roadRoom.c";

public void Setup()
{
    setRoadCell("The road passes a quiet stand of alder.",
        "/lib/environment/terrain/forest.c", ([
            "west": "/areas/eledhel/south-rural-route-09/20x2.c",
            "east": "/areas/eledhel/south-rural-route-09/22x2.c"
        ]));
}
