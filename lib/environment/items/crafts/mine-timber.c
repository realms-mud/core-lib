//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("mine timber");
    addAlias("pit prop");
    addAlias("shoring");
    addAlias("mine support");

    addAdjectives(({ "heavy", "rough-hewn", "creaking", "stout",
        "bark-covered", "wedged", "old", "bowed", "straining",
        "essential" }));

    addDescriptionTemplate("##Adjective## mine timbers supporting the ceiling");

    addItemTemplate(
        "The mine timbers are stout logs set vertically with a heavy "
        "crossbeam overhead, bracing the tunnel ceiling against collapse. "
        "The wood is rough-hewn and still bears its bark, and some of the "
        "timbers are bowed under the immense weight of the earth above. "
        "Wedges are hammered into the joints to keep everything tight."
    );

    addSomeLightDescriptionTemplate(
        "mine timbers brace the ceiling, their stout forms bearing the "
        "weight of the earth"
    );
    addDimLightDescriptionTemplate(
        "timber supports are visible, bracing the tunnel ceiling"
    );
    addLowLightDescriptionTemplate(
        "vertical and horizontal timbers frame the passage"
    );
    addNearDarkDescriptionTemplate(
        "the creak of strained timber suggests mine supports nearby"
    );
}
