//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/areas/eledhel/southern-road/roadRoom.c";

public void Setup()
{
    setRoadCell("A raised bank overlooks the Rhuendhen grazing marsh.",
        "/lib/environment/terrain/farmland.c", ([
            "west": "/areas/eledhel/south-rural-route-14/20x2.c",
            "east": "/areas/eledhel/south-rural-route-14/22x2.c"
        ]));
}
