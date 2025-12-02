//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/interiors/baseInterior.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("prison cell");

    addAdjectives(({
        "dank stone cell where moisture seeps through the walls and forms puddles",
        "cramped chamber with iron manacles bolted to the rough stone walls",
        "cold prison where the only light comes from a tiny barred window",
        "dark dungeon cell with straw scattered across the uneven stone floor",
        "fetid chamber where the stench of human misery hangs in the stale air",
        "grim cell where rusty chains and shackles dangle from iron rings",
        "dismal prison hewn from solid rock far beneath the castle floors",
        "barren cell where scratches on the wall mark endless days of captivity",
        "harsh stone chamber with a heavy wooden door reinforced with iron bands",
        "cheerless dungeon where the moans of other prisoners echo faintly",
        "gloomy and oppressive cell where the ceiling is too low to stand upright",
        "forgotten prison where rats scurry through shadows and moldering straw",
        "bleak chamber where water drips ceaselessly from the low ceiling",
        "stark cell where a crude wooden pallet serves as the only furnishing",
        "dank and isolated dungeon where time passes only by the changing of the guards",
        "prison where centuries of captivity have worn grooves in the floor",
        "confining chamber where moss grows on stone that never sees the sun",
        "disheartening cell where iron bars separate prisoners from freedom"
        }));

    addDescriptionTemplate("a ##Adjective##");

    addNearDarkDescriptionTemplate(
        "a pitch-black cell where nothing is visible except the faintest outline "
        "of a barred door or window"
    );

    addLowLightDescriptionTemplate(
        "a dimly lit prison cell, where only shapes and shadows can be discerned "
        "in the gloom, the walls seeming to close in from all sides"
    );

    addDimLightDescriptionTemplate(
        "a dimly-lit ##Adjective##, the feeble light from a distant torch or "
        "narrow window barely illuminating the miserable conditions"
    );

    addSomeLightDescriptionTemplate(
        "a surprisingly well-lit ##Adjective##, rays of sunlight or torchlight "
        "filtering through the bars to reveal every detail of the confinement"
    );
}
