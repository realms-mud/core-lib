//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/interiors/baseInterior.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("guard room");

    addAdjectives(({
        "stone-walled guard room with weapon racks and a heavy oak table",
        "fortified chamber where guards rest between patrols, shields hung on the walls",
        "spartan room with narrow windows, bunks, and a rack of spears",
        "secure guardroom with a roaring hearth and benches for armored sentries",
        "watchful chamber where the air smells of oil, leather, and steel",
        "barracks-like room with sturdy cots and a rack of polished helms"
        }));

    addDescriptionTemplate("a ##Adjective##");

    addNearDarkDescriptionTemplate(
        "a shadowy guard room where only the faint outline of weapon racks and "
        "the glint of metal from a shield are visible in the darkness"
    );

    addLowLightDescriptionTemplate(
        "a dimly lit guard room, where the stone walls and heavy furniture loom "
        "large and the air feels tense and cold"
    );

    addDimLightDescriptionTemplate(
        "a dimly-lit ##Adjective##, the flicker of torchlight revealing bunks, "
        "shields, and the gleam of steel weapons"
    );

    addSomeLightDescriptionTemplate(
        "a well-lit ##Adjective##, sunlight streaming through narrow windows to "
        "illuminate the weapons, armor, and sturdy furnishings"
    );
}
