//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("oil lamp");
    addAlias("lamp");
    addAlias("clay lamp");

    addDescriptionTemplate("a small oil lamp, its wick unlit");
    addActiveSourceOfLight(3, "an oil lamp glows with a steady, yellow flame", 1);

    addItemTemplate("the oil lamp is made of fired clay, with a small spout for the wick. "
        "It is filled with oil and provides a gentle, steady light.");
}
