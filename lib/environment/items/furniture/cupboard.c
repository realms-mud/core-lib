//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseContainer.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("cupboard");
    addAlias("cabinet");
    addAlias("kitchen cupboard");
    addAlias("wooden cupboard");

    addAdjectives(({ "wooden", "sturdy", "carved", "panelled", "broad", "old",
        "well-made", "tall", "plain", "heavy" }));

    addDescriptionTemplate("a ##Adjective## cupboard with iron hinges and a heavy latch");

    addItemTemplate(
        "This cupboard is built from thick planks, its doors set with iron hinges "
        "and a heavy latch. The panels are carved with simple designs, and the "
        "interior offers space for storing dishes, utensils, or household goods."
    );

    addSomeLightDescriptionTemplate(
        "a wooden cupboard stands against the wall, its doors closed and surface "
        "worn by years of use"
    );
    addDimLightDescriptionTemplate(
        "a sturdy cupboard is visible in the gloom, its outline broad and imposing"
    );
    addLowLightDescriptionTemplate(
        "a faint shape of a cupboard can be made out, little more than a shadow"
    );
    addNearDarkDescriptionTemplate(
        "a vague shadow suggests a cupboard is present, but details are lost in the "
        "darkness"
    );
}
