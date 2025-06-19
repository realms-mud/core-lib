//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("rack");
    addAlias("clothes rack");
    addAlias("weapon rack");
    addAlias("wooden rack");

    addAdjectives(({ "wooden", "sturdy", "broad", "old", "functional", "tall",
        "plain", "carved", "upright", "well-made" }));

    addDescriptionTemplate("a ##Adjective## rack for hanging or storing items");

    addItemTemplate(
        "This rack is made from sturdy wood, with pegs and bars for hanging "
        "clothes, weapons, or tools. The frame is upright and stable, and the "
        "wood is worn smooth by years of use."
    );

    addSomeLightDescriptionTemplate(
        "a wooden rack stands near the wall, its pegs empty"
    );
    addDimLightDescriptionTemplate(
        "a rack is visible in the gloom, its outline upright and broad"
    );
    addLowLightDescriptionTemplate(
        "a faint shape of a rack can be made out, little more than a shadow"
    );
    addNearDarkDescriptionTemplate(
        "a vague shadow suggests a rack is present, but details are lost in the "
        "darkness"
    );
}
