//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/interiors/baseInterior.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name(bath");

    addAdjectives(({
        "spacious bathhouse with steaming pools and marble benches arranged throughout",
        "elegant bathing complex with multiple chambers of varying temperatures",
        "communal bathing establishment where columns rise from heated floors to vaulted ceilings",
        "grand bathhouse where conversation and relaxation mingle in the steam-filled air",
        "magnificent public bath with mosaics depicting aquatic scenes decorating the walls",
        "impressive thermal complex with central bathing pool surrounded by colonnaded walkways"
        }));

    addDescriptionTemplate("a ##Adjective##");

    addNearDarkDescriptionTemplate("a dimly lit bathhouse where only the "
        "reflection of water catches what little light there is, steam rising "
        "as ghostly shapes in the darkness");

    addLowLightDescriptionTemplate("a bathhouse lit by occasional oil lamps, "
        "their flames reflected and multiplied in the rippling water of the "
        "bathing pools");

    addDimLightDescriptionTemplate("a ##Adjective##, the dim lighting creating "
        "a peaceful atmosphere as light plays across the water's surface and "
        "through clouds of rising steam");

    addSomeLightDescriptionTemplate("a well-lit ##Adjective##, sunlight "
        "streaming through high windows to dance across the water's surface "
        "and illuminate the detailed mosaics on the walls and floors");

    // Add sounds unique to a bathhouse setting
    addSoundTemplate("the gentle splashing of water echoes softly throughout "
        "the space");
    addSoundTemplate("hushed conversations blend with the occasional sound of "
        "water being poured");
    addSoundTemplate("the soft dripping of water from fountain fixtures creates "
        "a soothing backdrop");

    // Add smells unique to a bathhouse setting
    addSmellTemplate("the air is heavy with humidity and scented with mineral "
        "salts");
    addSmellTemplate("herbal essences mingle with the clean scent of heated "
        "water");
    addSmellTemplate("the distinctive mineral smell of the hot springs "
        "permeates the atmosphere");

    // Add thermal sensations appropriate for a bathhouse
    addTouchTemplate("waves of humid warmth emanate from the heated pools");
    addTouchTemplate("the contrast between cool marble and warm, moist air is "
        "immediately noticeable");
    addTouchTemplate("the stone floor is pleasantly warm underfoot, heated by "
        "the hypocaust system below");
}
