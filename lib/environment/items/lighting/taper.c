//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("taper");
    addAlias("slender candle");
    addAlias("thin candle");

    addDescriptionTemplate("a slender wax taper, its wick unlit");
    addActiveSourceOfLight(2, "a slender taper burns with a small, steady flame", 1);

    addItemTemplate("the taper is made of pale wax, drawn out to a thin, elegant shape. "
        "It is often used for writing desks or altars.");
}
