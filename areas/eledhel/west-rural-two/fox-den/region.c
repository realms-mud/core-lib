//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/region.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setRegionName("The Split-Root Fox Den");
    setRegionType("forest");
    setRegionLevel(2);
    setDimensions(5, 5);

    setCoordinate(0, 0,
        "/areas/eledhel/west-rural-two/fox-den/0x0.c", "entry");
    setCoordinate(1, 0,
        "/areas/eledhel/west-rural-two/fox-den/1x0.c", "path");
    setCoordinate(0, 1,
        "/areas/eledhel/west-rural-two/fox-den/0x1.c", "path");
    setCoordinate(1, 1,
        "/areas/eledhel/west-rural-two/fox-den/1x1.c", "room");
}
