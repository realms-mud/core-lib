//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/eledhel/southern-road/roadRoom.c";

public void Setup()
{
    setRoadCell("A shallow ditch marks the northern edge of Oelthir's fields.",
        "/lib/environment/terrain/farmland.c", ([
            "west": "/areas/eledhel/south-rural-route-15/19x2.c",
            "east": "/areas/eledhel/south-rural-route-15/21x2.c"
        ]));
}
