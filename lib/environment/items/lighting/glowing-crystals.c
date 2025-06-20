//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("glowing crystals");
    addAlias("crystals");
    addAlias("glowstone");

    addDescriptionTemplate("a cluster of faintly glowing crystals is embedded "
        "in the wall");
    addActiveSourceOfLight(6, "the crystals emit a steady, magical light, "
        "bathing the area in a soft, otherworldly glow", 1);

    addItemTemplate("the crystals shimmer with an inner light, their facets "
        "casting prismatic patterns on the walls.");
}
