//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("lectern");
    addAlias("reading stand");
    addAlias("book stand");
    addAlias("wooden lectern");

    addAdjectives(({ "wooden", "carved", "tall", "slanted", "plain", "old",
        "sturdy", "upright", "polished", "functional" }));

    addDescriptionTemplate("a ##Adjective## lectern for holding books or scrolls");

    addItemTemplate(
        "This lectern is made from sturdy wood, its slanted top designed to "
        "hold a book or scroll at a comfortable reading angle. The base is "
        "broad for stability, and the wood is worn smooth by years of use."
    );

    addSomeLightDescriptionTemplate(
        "a wooden lectern stands near the wall, its top angled for reading"
    );
    addDimLightDescriptionTemplate(
        "a lectern is visible in the gloom, its outline upright and plain"
    );
    addLowLightDescriptionTemplate(
        "a faint shape of a lectern can be made out, little more than a shadow"
    );
    addNearDarkDescriptionTemplate(
        "a vague shadow suggests a lectern is present, but details are lost in "
        "the darkness"
    );
}
