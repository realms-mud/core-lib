//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("scorpion");
    addAlias("siege scorpion");
    addAlias("bolt thrower");

    addAdjectives(({ "compact", "wooden", "torsion-powered", "siege", "deadly" }));
    addDescriptionTemplate("a ##Adjective## scorpion ballista aimed at the field");

    addItemTemplate(
        "The scorpion is a compact siege engine, its wooden frame supporting a "
        "powerful torsion mechanism. A long arm is fitted with a groove for "
        "massive bolts, and a crank is used to draw it back. The weapon is "
        "aimed at distant targets, ready to unleash deadly force."
    );

    addNearDarkDescriptionTemplate(
        "the outline of a scorpion is barely visible, its form lost in the "
        "shadows"
    );
    addLowLightDescriptionTemplate(
        "a scorpion stands in the gloom, its frame and arm just visible"
    );
    addDimLightDescriptionTemplate(
        "the scorpion is faintly illuminated, its torsion mechanism and arm "
        "just visible"
    );
    addSomeLightDescriptionTemplate(
        "the scorpion is clearly visible, its construction and deadly purpose "
        "apparent"
    );
    addDescriptionTemplate(
        "sunlight shines on the scorpion, highlighting its powerful frame and "
        "deadly arm"
    );
}
