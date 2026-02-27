//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("wheelbarrow");
    addAlias("barrow");
    addAlias("garden barrow");

    addAdjectives(({ "wooden", "sturdy", "mud-caked", "battered", "old",
        "well-used", "rustic", "single-wheeled", "tipped", "weathered" }));

    addDescriptionTemplate("a ##Adjective## wheelbarrow leaning against a wall");

    addItemTemplate(
        "This single-wheeled barrow has seen hard use. Its wooden bed is "
        "stained with dirt and mortar, the handles are splintered in places, "
        "and the iron wheel squeaks on its axle. A few clods of dried earth "
        "still cling to its interior."
    );

    addSomeLightDescriptionTemplate(
        "a wheelbarrow leans against a wall, caked with dried mud"
    );
    addDimLightDescriptionTemplate(
        "a wheelbarrow is propped nearby, its outline just visible"
    );
    addLowLightDescriptionTemplate(
        "a shape that might be a wheelbarrow rests against something"
    );
    addNearDarkDescriptionTemplate(
        "a vague shape is propped against the wall"
    );
}
