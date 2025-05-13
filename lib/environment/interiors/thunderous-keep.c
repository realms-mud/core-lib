//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/interiors/baseInterior.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("thunderous keep and arcane chambers");

    addAdjectives(({
        "storm-wracked keep where lightning strikes the stone",
        "towering fortress echoing with the sound of thunder",
        "arcane keep charged with the raw energy of the storm",
        "thunderous hall where the very walls hum with power",
        "vast keep where crackling storms are held at bay by arcane wards",
        "electrified chamber, the air thick with magical energy"
        }));

    addDescriptionTemplate("a ##Adjective##");
    addNearDarkDescriptionTemplate("a darkened keep, the faintest hints of crackling lightning visible in the corners of the room, distant thunder shaking the stone walls.");
    addLowLightDescriptionTemplate("a dimly lit chamber, where occasional flashes of lightning from outside illuminate the swirling arcane symbols on the walls.");
    addDimLightDescriptionTemplate("a dimly-lit ##Adjective##, the light flickering as the thunder vibrates the stone floors");
    addSomeLightDescriptionTemplate("a charged ##Adjective##, each flash of light casting long shadows and illuminating the arcane runes carved into the walls");
}
