//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/interiors/baseInterior.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("library");

    addAdjectives(({
        "quiet library lined with towering shelves of ancient leather-bound tomes",
        "scholarly chamber where candlelight glimmers on polished reading tables",
        "vaulted hall filled with the scent of parchment, ink, and old wood",
        "dim library where dust motes dance in shafts of light from arched windows",
        "storied room with carved bookcases and ladders reaching to the ceiling",
        "peaceful study lined with scroll racks and illuminated manuscripts",
        "shadowy library where the silence is broken only by the turning of pages",
        "grand chamber with stained glass windows casting colored light on the floor",
        "narrow alcove where rare books are kept behind locked iron grilles",
        "warm library with a crackling hearth and high-backed reading chairs"
        }));

    addDescriptionTemplate("a ##Adjective##");

    addNearDarkDescriptionTemplate(
        "a shadowy library where only the faint outline of shelves and the glint "
        "of brass candleholders are visible in the darkness"
    );

    addLowLightDescriptionTemplate(
        "a dimly lit library, where the flicker of candlelight reveals rows of "
        "books and the shapes of reading tables"
    );

    addDimLightDescriptionTemplate(
        "a dimly-lit ##Adjective##, the golden glow from scattered candles and "
        "lanterns illuminating the spines of ancient books"
    );

    addSomeLightDescriptionTemplate(
        "a well-lit ##Adjective##, sunlight streaming through tall windows to "
        "illuminate the shelves, reading desks, and intricate woodwork"
    );
}
