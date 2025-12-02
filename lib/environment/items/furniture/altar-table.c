//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("altar table");
    addAlias("altar");
    addAlias("table");
    addAlias("wooden altar");

    addAdjectives(({ "stone", "wooden", "carved", "plain", "broad", "old",
        "polished", "ornate", "sacred", "rectangular" }));

    addDescriptionTemplate("a ##Adjective## altar table set against the wall");

    addItemTemplate(
        "This altar table is made from heavy wood or stone, its surface broad "
        "and polished. The legs are sturdy, and the top is sometimes draped "
        "with cloth or decorated with simple carvings."
    );

    addSomeLightDescriptionTemplate(
        "an altar table stands against the wall, its surface bare"
    );
    addDimLightDescriptionTemplate(
        "an altar table is visible in the gloom, its outline broad and plain"
    );
    addLowLightDescriptionTemplate(
        "a faint shape of an altar table can be made out, little more than a shadow"
    );
    addNearDarkDescriptionTemplate(
        "a vague shadow suggests an altar table is present, but details are lost "
        "in the darkness"
    );
}
