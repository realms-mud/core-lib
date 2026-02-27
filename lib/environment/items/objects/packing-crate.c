//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("packing crate");
    addAlias("crate");
    addAlias("shipping crate");
    addAlias("wooden crate");

    addAdjectives(({ "wooden", "nailed-shut", "stenciled", "heavy",
        "sturdy", "battered", "stacked", "rough", "iron-cornered",
        "well-traveled" }));

    addDescriptionTemplate("a ##Adjective## packing crate awaiting transport");

    addItemTemplate(
        "The packing crate is a rough box of thick planks nailed together "
        "and reinforced with iron corners. Shipping marks are stenciled "
        "on the sides in faded paint, and straw packing material pokes "
        "out from between the boards. It has clearly traveled far."
    );

    addSomeLightDescriptionTemplate(
        "a packing crate sits nearby, its shipping marks clearly visible"
    );
    addDimLightDescriptionTemplate(
        "a large wooden crate is visible, its markings hard to read"
    );
    addLowLightDescriptionTemplate(
        "a large boxy shape suggests a crate or container"
    );
    addNearDarkDescriptionTemplate(
        "a large angular shape sits nearby in the darkness"
    );
}
