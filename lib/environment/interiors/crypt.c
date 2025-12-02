//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/interiors/baseInterior.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("crypt");

    addAdjectives(({
        "ancient stone crypt lined with shadowy alcoves and carved sarcophagi",
        "gloomy burial chamber where dust and cobwebs cling to every surface",
        "solemn underground vault with vaulted ceilings and flickering torches",
        "chilly crypt where the air is thick with the scent of old stone and decay",
        "sacred resting place adorned with faded carvings and crumbling pillars",
        "dim burial vault where silence is broken only by the drip of water"
        }));

    addDescriptionTemplate("a ##Adjective##");

    addNearDarkDescriptionTemplate(
        "a pitch-black crypt where only the faintest glimmer of light reveals "
        "the outline of stone coffins and pillars lost in shadow"
    );

    addLowLightDescriptionTemplate(
        "a crypt shrouded in gloom, where the shapes of sarcophagi and alcoves "
        "are barely visible and the air feels heavy and cold"
    );

    addDimLightDescriptionTemplate(
        "a dimly-lit ##Adjective##, the flicker of torchlight casting long "
        "shadows across ancient stone and faded carvings"
    );

    addSomeLightDescriptionTemplate(
        "a solemn ##Adjective##, where shafts of light from above illuminate "
        "dust motes swirling in the still air and highlight the worn features "
        "of carved effigies and stone coffins"
    );
}
