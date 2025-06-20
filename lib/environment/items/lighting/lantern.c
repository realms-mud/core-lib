//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("lantern");
    addAlias("oil lantern");
    addAlias("lamp");

    addDescriptionTemplate("a metal lantern with glass panes sits here, its "
        "wick unlit");
    addActiveSourceOfLight(5, "a lantern glows warmly, its flame protected by "
        "glass panes", 1);

    addItemTemplate("the lantern is made of brass and glass, with a hinged door "
        "for lighting the wick. Soot stains the inside of the glass.");
}
