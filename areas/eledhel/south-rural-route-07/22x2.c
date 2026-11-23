//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/eledhel/southern-road/roadRoom.c";

public void Setup()
{
    setRoadCell("The King's Road descends toward Dhorlen and its old "
        "river crossing.",
        "/lib/environment/terrain/plains.c", ([
            "west": "/areas/eledhel/south-rural-route-07/21x2.c",
            "east": "/areas/eledhel/south-rural-route-07/23x2.c",
            "south": "/areas/eledhel/dhorlen/3x1.c"
        ]));
}
