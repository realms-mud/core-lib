//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("trestle table");
    addAlias("table");
    addAlias("wooden table");
    addAlias("banquet table");

    addAdjectives(({ "long", "wooden", "broad", "plain", "old", "sturdy",
        "removable", "worn", "functional", "rectangular" }));

    addDescriptionTemplate("a ##Adjective## trestle table with removable legs");

    addItemTemplate(
        "This trestle table is made from thick planks, its legs removable for "
        "easy transport or storage. The surface is broad and worn, suitable for "
        "feasts or gatherings."
    );

    addSomeLightDescriptionTemplate(
        "a long wooden trestle table stands in the hall, its surface marked by use"
    );
    addDimLightDescriptionTemplate(
        "a trestle table is visible in the gloom, its outline long and broad"
    );
    addLowLightDescriptionTemplate(
        "a faint shape of a trestle table can be made out, little more than a shadow"
    );
    addNearDarkDescriptionTemplate(
        "a vague shadow suggests a trestle table is present, but details are lost "
        "in the darkness"
    );
}
