//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/interiors/baseInterior.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("towering citadel of flames");

    addAdjectives(({
        "towering citadel, its walls crackling with unrelenting fire",
        "imposing fortress of flames, where molten lava streams down its stone walls",
        "blazing citadel, the air thick with the heat of endless fire",
        "infernal citadel, a fortress forged in the heart of an eternal flame",
        "fiery stronghold, where flames lick at the sky and light the night",
        "majestic citadel of fire, its towers rising like pillars of flame"
        }));

    addDescriptionTemplate("a ##Adjective##");
    addNearDarkDescriptionTemplate("a darkened citadel, the outline of its towers faintly visible, but flames flicker at the edges of the stone, casting eerie light.");
    addLowLightDescriptionTemplate("a dim citadel, where the flickering light of constant flames illuminates the walls, casting long shadows.");
    addDimLightDescriptionTemplate("a dimly-lit ##Adjective##, where the fiery glow from within the walls warms the air and distorts the horizon");
    addSomeLightDescriptionTemplate("a blazing ##Adjective##, the entire citadel alive with the flicker of fire and molten streams of lava");
}
