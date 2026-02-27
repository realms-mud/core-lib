//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("lifting crane");
    addAlias("crane");
    addAlias("derrick");
    addAlias("hoist");

    addAdjectives(({ "wooden", "tall", "heavy", "creaking", "rope-hung",
        "sturdy", "massive", "weathered", "functional", "towering" }));

    addDescriptionTemplate("a ##Adjective## lifting crane for moving heavy loads");

    addItemTemplate(
        "The lifting crane is a tall wooden structure with a pivoting arm "
        "and a system of ropes and pulleys for hoisting heavy loads. The "
        "base is weighted with stone counterbalances, and the ropes are "
        "thick hemp wound around a wooden drum winch. It creaks ominously "
        "when loaded but has borne enormous weights without failure."
    );

    addSomeLightDescriptionTemplate(
        "a tall lifting crane towers overhead, its ropes and pulleys "
        "dangling"
    );
    addDimLightDescriptionTemplate(
        "a tall wooden structure with ropes and a pivoting arm is visible"
    );
    addLowLightDescriptionTemplate(
        "a tall structure with dangling ropes towers overhead"
    );
    addNearDarkDescriptionTemplate(
        "the creak of rope and wood suggests a large hoisting mechanism "
        "overhead"
    );
}
