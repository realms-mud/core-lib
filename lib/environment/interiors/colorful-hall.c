//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/interiors/baseInterior.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("colorful hall");

    addAdjectives(({
        "vivid hall draped in brilliant fabrics",
        "bright chamber adorned with painted walls and mosaic floors",
        "lively room where colors swirl in patterns and banners",
        "ornate hall filled with vibrant tapestries and stained glass",
        "cheerful chamber where every surface bursts with color",
        "festive room where light plays across painted stone and silks"
        }));

    addDescriptionTemplate("a ##Adjective##");
    addNearDarkDescriptionTemplate("a darkened room. The colors are lost in shadow, barely discernible.");
    addLowLightDescriptionTemplate("a shadowed chamber where dim light catches flashes of color here and there.");
    addDimLightDescriptionTemplate("a softly-lit ##Adjective##, the colors muted but present");
    addSomeLightDescriptionTemplate("a radiant ##Adjective##, glowing with color in the steady light");
}
