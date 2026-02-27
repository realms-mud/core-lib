//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("arcane circle");
    addAlias("magic circle");
    addAlias("summoning circle");
    addAlias("ritual circle");

    addAdjectives(({ "intricate", "glowing", "silver-inlaid", "ancient",
        "complex", "inscribed", "elaborate", "etched", "mystical",
        "faded" }));

    addDescriptionTemplate("an ##Adjective## arcane circle etched into the floor");

    addItemTemplate(
        "The arcane circle is a complex arrangement of concentric rings, "
        "sigils, and geometric patterns etched deep into the stone floor "
        "and inlaid with silver wire. Runes of power are inscribed at the "
        "cardinal points, and the whole design pulses with a faint, barely "
        "perceptible energy. The air above it shimmers slightly."
    );

    addSomeLightDescriptionTemplate(
        "an arcane circle is etched into the floor, its silver inlay "
        "gleaming and faintly pulsing"
    );
    addDimLightDescriptionTemplate(
        "a circle of silver-inlaid sigils is visible on the floor, faintly "
        "glowing"
    );
    addLowLightDescriptionTemplate(
        "faint silvery lines trace a circular pattern on the floor"
    );
    addNearDarkDescriptionTemplate(
        "the faintest silvery glow traces a pattern on the floor"
    );
}
