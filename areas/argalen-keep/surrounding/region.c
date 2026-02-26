//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/region.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setRegionName("Argalen Keep and Surroundings");
    setRegionType("forest");
    setDimensions(25, 10);

    // === Southern forest approach (y=0-2) ===
    // Road entry from the south through forest
    setCoordinate(12, 0,
        "/areas/argalen-keep/surrounding/12x0.c", "entry");
    setCoordinate(11, 0,
        "/areas/argalen-keep/surrounding/11x0.c", "room");
    setCoordinate(13, 0,
        "/areas/argalen-keep/surrounding/13x0.c", "room");

    // Forest road continues north
    setCoordinate(12, 1,
        "/areas/argalen-keep/surrounding/12x1.c", "path");
    setCoordinate(11, 1,
        "/areas/argalen-keep/surrounding/11x1.c", "room");
    setCoordinate(13, 1,
        "/areas/argalen-keep/surrounding/13x1.c", "room");

    // Road emerges into farmland
    setCoordinate(12, 2,
        "/areas/argalen-keep/surrounding/12x2.c", "path");
    setCoordinate(11, 2,
        "/areas/argalen-keep/surrounding/11x2.c", "room");
    setCoordinate(13, 2,
        "/areas/argalen-keep/surrounding/13x2.c", "room");

    // === Farmland and approach to village (y=3-4) ===
    // Road reaches village outskirts
    setCoordinate(12, 3,
        "/areas/argalen-keep/surrounding/12x3.c", "path");
    setCoordinate(11, 3,
        "/areas/argalen-keep/surrounding/11x3.c", "none");
    setCoordinate(13, 3,
        "/areas/argalen-keep/surrounding/13x3.c", "none");
    setCoordinate(10, 3,
        "/areas/argalen-keep/surrounding/10x3.c", "room");
    setCoordinate(14, 3,
        "/areas/argalen-keep/surrounding/14x3.c", "room");

    // Village south edge - first buildings
    setCoordinate(12, 4,
        "/areas/argalen-keep/surrounding/12x4.c", "path");
    setCoordinate(11, 4,
        "/areas/argalen-keep/surrounding/11x4.c", "none");
    setCoordinate(13, 4,
        "/areas/argalen-keep/surrounding/13x4.c", "none");

    // === Village center (y=5-6) ===
    // Village square with well, inn, market, shops
    setCoordinate(12, 5,
        "/areas/argalen-keep/surrounding/12x5.c", "room");
    setCoordinate(11, 5,
        "/areas/argalen-keep/surrounding/11x5.c", "path");
    setCoordinate(13, 5,
        "/areas/argalen-keep/surrounding/13x5.c", "path");
    setCoordinate(10, 5,
        "/areas/argalen-keep/surrounding/10x5.c", "none");
    setCoordinate(14, 5,
        "/areas/argalen-keep/surrounding/14x5.c", "none");

    // Village north side - church, homes
    setCoordinate(12, 6,
        "/areas/argalen-keep/surrounding/12x6.c", "path");
    setCoordinate(11, 6,
        "/areas/argalen-keep/surrounding/11x6.c", "none");
    setCoordinate(13, 6,
        "/areas/argalen-keep/surrounding/13x6.c", "none");

    // === Road to keep (y=7) ===
    setCoordinate(12, 7,
        "/areas/argalen-keep/surrounding/12x7.c", "path");
    setCoordinate(11, 7,
        "/areas/argalen-keep/surrounding/11x7.c", "none");
    setCoordinate(13, 7,
        "/areas/argalen-keep/surrounding/13x7.c", "none");

    // === Keep exterior (y=8-9) ===
    // Keep walls and gate
    setCoordinate(11, 8,
        "/areas/argalen-keep/surrounding/11x8.c", "none");
    setCoordinate(12, 8,
        "/areas/argalen-keep/surrounding/12x8.c", "room");
    setCoordinate(13, 8,
        "/areas/argalen-keep/surrounding/13x8.c", "none");
    setCoordinate(11, 9,
        "/areas/argalen-keep/surrounding/11x9.c", "none");
    setCoordinate(12, 9,
        "/areas/argalen-keep/surrounding/12x9.c", "none");
    setCoordinate(13, 9,
        "/areas/argalen-keep/surrounding/13x9.c", "none");

    // === Western forest and farms (y=3-5, x=7-9) ===
    setCoordinate(9, 3,
        "/areas/argalen-keep/surrounding/9x3.c", "room");
    setCoordinate(8, 4,
        "/areas/argalen-keep/surrounding/8x4.c", "room");
    setCoordinate(9, 4,
        "/areas/argalen-keep/surrounding/9x4.c", "room");
    setCoordinate(9, 5,
        "/areas/argalen-keep/surrounding/9x5.c", "room");

    // === Eastern hills and mine approach (y=3-5, x=15-17) ===
    setCoordinate(15, 3,
        "/areas/argalen-keep/surrounding/15x3.c", "room");
    setCoordinate(15, 4,
        "/areas/argalen-keep/surrounding/15x4.c", "room");
    setCoordinate(16, 4,
        "/areas/argalen-keep/surrounding/16x4.c", "room");
}
