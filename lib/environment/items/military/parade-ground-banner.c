//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("parade ground banner");
    addAlias("banner");
    addAlias("standard");

    addAdjectives(({ "colorful", "embroidered", "tall", "regimental", "fluttering" }));
    addDescriptionTemplate("a ##Adjective## parade ground banner on a tall pole");

    addItemTemplate(
        "The parade ground banner stands tall on a polished wooden pole, its "
        "brightly colored fabric emblazoned with the insignia of the local "
        "lord or company. The banner flutters in the breeze, marking the "
        "center of the parade ground."
    );

    addNearDarkDescriptionTemplate(
        "the outline of a parade ground banner is barely visible, its colors "
        "lost in the gloom"
    );
    addLowLightDescriptionTemplate(
        "a parade ground banner stands in the shadows, its insignia hard to "
        "distinguish"
    );
    addDimLightDescriptionTemplate(
        "the parade ground banner is faintly illuminated, its colors muted"
    );
    addSomeLightDescriptionTemplate(
        "the parade ground banner is clearly visible, its colors and insignia "
        "standing out"
    );
    addDescriptionTemplate(
        "sunlight shines on the parade ground banner, making its colors vivid "
        "and its insignia unmistakable"
    );
}
