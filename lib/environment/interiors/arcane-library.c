//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/interiors/baseInterior.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("arcane library and mystic sanctum");

    addAdjectives(({
        "vast library, filled with countless scrolls and ancient tomes",
        "mystical sanctum, the air thick with the scent of old parchment and incense",
        "sacred hall where magic and knowledge intertwine in silence",
        "arcane library, its shelves stretching high into shadowed alcoves",
        "hidden sanctum, where magical power hums quietly in the air",
        "grand chamber lined with enchanted bookshelves and glowing runes"
        }));

    addDescriptionTemplate("a ##Adjective##");
    addNearDarkDescriptionTemplate("a shadowy sanctum, the faintest light of magical runes tracing across the bookshelves, the only sound the rustle of pages turning.");
    addLowLightDescriptionTemplate("a dimly lit library, where the glow of magical energy pulses from the spines of ancient books.");
    addDimLightDescriptionTemplate("a dimly-lit ##Adjective##, the light soft and filled with arcane energy, casting strange shadows on the floor");
    addSomeLightDescriptionTemplate("a softly illuminated ##Adjective##, where every book and scroll seems to glow with untold secrets");
}
