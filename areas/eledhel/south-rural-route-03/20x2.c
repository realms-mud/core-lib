//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/eledhel/southern-road/roadRoom.c";

public void Setup()
{
    setRoadCell("The King's Road crosses a wet meadow at a stone causeway.",
        "/lib/environment/terrain/farmland.c", ([
            "east": "/areas/eledhel/south-rural-route-03/21x2.c",
            "west": "/areas/eledhel/south-rural-route-03/19x2.c"
        ]));
}
