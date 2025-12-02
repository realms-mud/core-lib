//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/interiors/baseInterior.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("gloomy temple and shadowed chambers");

    addAdjectives(({
        "dark and gloomy temple, the air thick with sorrow",
        "shadowed hall where light barely touches the cold stone",
        "ancient temple where the very walls seem to weep with age",
        "silent temple, its halls heavy with forgotten prayers",
        "eerie stone sanctuary where shadows stretch and twist",
        "desolate temple where the faintest light is swallowed by darkness"
        }));

    addDescriptionTemplate("a ##Adjective##");
    addNearDarkDescriptionTemplate("a pitch-black temple, the walls indistinguishable from the void, and the faintest hint of something moving in the shadows.");
    addLowLightDescriptionTemplate("a dim temple, the walls only faintly visible in the low light, shadows creeping across the stone floor.");
    addDimLightDescriptionTemplate("a dimly-lit ##Adjective##, the air thick with dust and the whispers of forgotten rites");
    addSomeLightDescriptionTemplate("a dimly illuminated ##Adjective##, where the shadows cling like ghosts to the walls");
}
