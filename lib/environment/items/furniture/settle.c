//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("settle");
    addAlias("bench");
    addAlias("wooden settle");
    addAlias("high-backed bench");

    addAdjectives(({ "wooden", "high-backed", "carved", "old", "sturdy", "broad",
        "plain", "functional", "worn", "panelled" }));

    addDescriptionTemplate("a ##Adjective## settle with a high back and arms");

    addItemTemplate(
        "This settle is a long, high-backed bench made from sturdy wood. The "
        "back and arms are panelled and carved with simple designs, and the "
        "seat lifts to reveal a storage compartment."
    );

    addSomeLightDescriptionTemplate(
        "a wooden settle stands against the wall, its high back imposing"
    );
    addDimLightDescriptionTemplate(
        "a settle is visible in the gloom, its outline long and upright"
    );
    addLowLightDescriptionTemplate(
        "a faint shape of a settle can be made out, little more than a shadow"
    );
    addNearDarkDescriptionTemplate(
        "a vague shadow suggests a settle is present, but details are lost in "
        "the darkness"
    );
}
