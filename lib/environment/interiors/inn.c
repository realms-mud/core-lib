//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/interiors/baseInterior.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("inn interior");

    addAdjectives(({
        "bustling common room filled with laughter, clinking tankards, and the "
            "aroma of roasting meat",
        "smoky taproom where lantern light glows through a haze above crowded "
            "tables",
        "timber-framed hall with exposed beams and a roaring hearth at its center",
        "warm gathering place where travelers share tales over hearty stew and ale",
        "welcoming inn with polished oak floors and flower boxes at the windows",
        "noisy tavern where minstrels play lively tunes and patrons sing along",
        "firelit chamber with long benches, heavy trestle tables, and flickering "
            "shadows",
        "clean but aged inn where the walls are darkened by years of smoke and "
            "merriment",
        "well-worn taproom with scuffed floors and a bar polished by countless "
            "elbows",
        "raucous hall where dice games and boisterous laughter echo late into the "
            "night",
        "lamplit parlor with brass sconces and the scent of beeswax and mulled wine",
        "beamed-ceiling room hung with drying herbs and garlands for festival days",
        "crowded inn where every seat is taken and the air is thick with stories",
        "cheerful taproom where the innkeeper greets each guest by name",
        "rustic chamber with rough-hewn tables and a stone fireplace blazing",
        "vast ale-scented room where barrels are stacked behind the bar and "
            "tankards never run dry",
        "lively inn where the sound of music and dancing feet fills the air",
        "shadowy corner where a lone traveler nurses a drink and watches the crowd",
        "large oak-paneled room adorned with hunting trophies and faded banners",
        "draughty hall where the wind rattles the shutters but the fire keeps the "
            "cold at bay",
        "lantern-lit taproom with stained glass windows casting colored patterns on "
            "the floor",
        "storied inn whose walls are carved with the names of generations of guests",
        "hearth-warmed chamber where a great dog sleeps before the fire",
        "flagstone-floored room where spilled ale and muddy boots leave their mark",
        "cozy nook with cushioned benches and a view of the bustling street outside",
        "rough-hewn taproom where the laughter is loud and the welcome is genuine"
    }));

    addDescriptionTemplate("a ##Adjective##");

    addNearDarkDescriptionTemplate(
        "a shadowy inn where only the faint glow of embers in the hearth and "
        "the outline of heavy beams are visible in the darkness"
    );

    addLowLightDescriptionTemplate(
        "a dimly lit inn, where lanterns flicker and shadows gather in the "
        "corners, highlighting the rough-hewn tables and timber walls"
    );

    addDimLightDescriptionTemplate(
        "a dimly-lit ##Adjective##, the golden light from the hearth and "
        "lanterns revealing tankards, benches, and the gleam of polished wood"
    );

    addSomeLightDescriptionTemplate(
        "a well-lit ##Adjective##, sunlight streaming through leaded windows "
        "to illuminate the bustling common room, the long bar, and the lively "
        "crowd of patrons"
    );
}
