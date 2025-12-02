//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("cupboard bed");
    addAlias("box bed");
    addAlias("enclosed bed");
    addAlias("wooden cupboard bed");

    addAdjectives(({ "wooden", "enclosed", "carved", "old", "sturdy", "broad",
        "panelled", "plain", "functional", "heavy" }));

    addDescriptionTemplate("a ##Adjective## cupboard bed with sliding doors");

    addItemTemplate(
        "This cupboard bed is a wooden sleeping compartment with sliding doors "
        "or shutters. The interior is just large enough for a mattress, and "
        "the wood is carved with simple patterns."
    );

    addSomeLightDescriptionTemplate(
        "a wooden cupboard bed stands against the wall, its doors closed"
    );
    addDimLightDescriptionTemplate(
        "a cupboard bed is visible in the gloom, its outline broad and enclosed"
    );
    addLowLightDescriptionTemplate(
        "a faint shape of a cupboard bed can be made out, little more than a shadow"
    );
    addNearDarkDescriptionTemplate(
        "a vague shadow suggests a cupboard bed is present, but details are lost "
        "in the darkness"
    );
}
