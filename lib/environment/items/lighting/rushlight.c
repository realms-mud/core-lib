//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("rushlight");
    addAlias("rush light");
    addAlias("fat-soaked rush");

    addDescriptionTemplate("a simple rushlight, its end charred from previous use");
    addActiveSourceOfLight(1, "a rushlight burns with a faint, flickering flame", 1);

    addItemTemplate("the rushlight is a dried rush stalk soaked in animal fat, "
        "providing a meager and short-lived light.");
}
