//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("magical light");
    addAlias("arcane light");
    addAlias("glowing orb");
    addAlias("enchanted light");

    addDescriptionTemplate("an orb floats here");
    addActiveSourceOfLight(10, "the magical light pulses gently, bathing the area "
        "in a steady, otherworldly radiance", 1);

    addItemTemplate("the magical light appears as a floating orb, its surface "
        "shimmering with shifting colors. It emits a steady, shadowless glow, "
        "unaffected by wind or touch.");
}
