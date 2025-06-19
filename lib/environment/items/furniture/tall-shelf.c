//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseContainer.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("tall shelf");
    addAlias("shelf");
    addAlias("wooden shelf");
    addAlias("standing shelf");

    addAdjectives(({ "tall", "wooden", "open", "sturdy", "broad",
        "carved", "plain", "functional", "old" }));

    addDescriptionTemplate("a ##Adjective## tall shelf with several wide planks");

    addItemTemplate(
        "This tall shelf is made from sturdy wood, its open design "
        "allowing easy access to stored items. The planks are wide and "
        "supported by carved uprights, perfect for holding pottery, books, or "
        "tools."
    );

    addSomeLightDescriptionTemplate(
        "a tall wooden shelf stands against the wall, its planks lined with "
        "various items"
    );
    addDimLightDescriptionTemplate(
        "a tall shelf is visible in the gloom, its outline rising above most "
        "furniture"
    );
    addLowLightDescriptionTemplate(
        "a faint shape of a tall shelf can be made out, little more than a "
        "shadow"
    );
    addNearDarkDescriptionTemplate(
        "a vague shadow suggests a tall shelf is present, but details are lost "
        "in the darkness"
    );
}
