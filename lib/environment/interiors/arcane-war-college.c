//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/interiors/baseInterior.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("arcane war college");

    addAdjectives(({
        "imposing hall lined with arcane sigils and tactical maps",
        "stern chamber where magic and strategy converge",
        "high-ceilinged room echoing with the hum of latent power",
        "disciplinary hall lit by floating glyphs and everburning torches",
        "grim yet elegant chamber built from stone and enchanted steel",
        "austere room where spellwork and swordplay are equally honored"
        }));

    addDescriptionTemplate("a ##Adjective##");
    addNearDarkDescriptionTemplate("a shadowed hall. Faint magical glows pulse from dormant glyphs on the walls.");
    addLowLightDescriptionTemplate("a dim chamber where arcane symbols flicker faintly, casting long shadows.");
    addDimLightDescriptionTemplate("a dimly-lit ##Adjective##, with spells lingering in the air like static.");
    addSomeLightDescriptionTemplate("a sharply-lit ##Adjective##, every rune and inscription clearly visible");
}
