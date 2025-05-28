//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/interiors/baseInterior.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("castle gatehouse");

    addAdjectives(({
        "fortified stone gatehouse with arrow slits and heavy wooden doors",
        "imposing entry chamber where guards watch over the portcullis mechanism",
        "defensive passage with murder holes in the ceiling and thick stone walls",
        "arched gateway chamber echoing with the footsteps of sentries",
        "battlemented gatehouse with iron portcullis and winding staircases",
        "guarded entryway where sunlight slants through narrow windows"
        }));

    addDescriptionTemplate("a ##Adjective##");

    addNearDarkDescriptionTemplate(
        "a shadowy gatehouse where only the faint outline of the portcullis and "
        "the glint of metal from arrow slits are visible in the darkness"
    );

    addLowLightDescriptionTemplate(
        "a dimly lit gatehouse, where the heavy doors and stone walls loom large "
        "and the air feels tense and cold"
    );

    addDimLightDescriptionTemplate(
        "a dimly-lit ##Adjective##, the flicker of torchlight revealing the "
        "portcullis, arrow slits, and the mechanism for raising the gate"
    );

    addSomeLightDescriptionTemplate(
        "a well-lit ##Adjective##, sunlight streaming through the gateway and "
        "narrow windows to illuminate the stone floor and defensive features"
    );
}
