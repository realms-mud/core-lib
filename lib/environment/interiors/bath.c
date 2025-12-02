//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/interiors/baseInterior.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("bath");

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
}
