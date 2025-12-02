//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseContainer.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("wine rack");
    addAlias("rack");
    addAlias("bottle rack");
    addAlias("wooden wine rack");

    addAdjectives(({ "wooden", "sturdy", "carved", "old", "broad", "functional",
        "well-made", "tall", "plain", "polished" }));

    addDescriptionTemplate("a ##Adjective## wine rack with slots for bottles");

    addItemTemplate(
        "This wine rack is made from sturdy wood, with carved slots for holding "
        "bottles securely. The frame is broad and stable, and the wood is "
        "polished smooth by years of use."
    );

    addSomeLightDescriptionTemplate(
        "a wooden wine rack stands against the wall, its slots filled with bottles"
    );
    addDimLightDescriptionTemplate(
        "a wine rack is visible in the gloom, its outline broad and low"
    );
    addLowLightDescriptionTemplate(
        "a faint shape of a wine rack can be made out, little more than a shadow"
    );
    addNearDarkDescriptionTemplate(
        "a vague shadow suggests a wine rack is present, but details are lost in "
        "the darkness"
    );
}
