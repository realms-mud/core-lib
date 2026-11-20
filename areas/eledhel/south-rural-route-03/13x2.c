//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/eledhel/southern-road/roadRoom.c";

public void Setup()
{
    setRoadCell("A roadside well marks the southern common.",
        "/lib/environment/terrain/plains.c", ([
            "east": "/areas/eledhel/south-rural-route-03/14x2.c",
            "west": "/areas/eledhel/south-rural-route-03/12x2.c"
        ]));
}
