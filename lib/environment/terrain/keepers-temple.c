//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/terrain/baseTerrain.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("keeper's temple");

    addAdjectives(({
        "ominous temple shrouded in perpetual shadow",
        "forbidding stone temple etched with cryptic runes",
        "temple where black candles flicker in alcoves",
        "sinister sanctuary reeking of incense and decay",
        "temple where the air is thick with whispered prayers",
        "gloomy hall where shadows writhe along the walls",
        "temple adorned with symbols of the Keepers of the Night",
        "sanctum where the scent of blood and old magic lingers",
        "temple where the floor is cold, black stone",
        "temple where the silence is broken only by distant chanting"
        }));

    addTimeOfDayDescription("dawn", ({
        " barely touched by the first light of day",
        " where the shadows seem to resist the sunrise",
        " as the temple's darkness lingers stubbornly"
        }));

    addTimeOfDayDescription("morning", ({
        " with pale light struggling to penetrate the gloom",
        " as the air remains heavy with incense and secrets",
        " where the Keepers begin their silent rituals"
        }));

    addTimeOfDayDescription("noon", ({
        " where the sun's rays are swallowed by thick stone walls",
        " as the temple remains cool and dim",
        " with only faint light filtering through narrow windows"
        }));

    addTimeOfDayDescription("afternoon", ({
        " as the shadows lengthen and the air grows colder",
        " where the chanting of the Keepers grows louder",
        " with flickering candlelight dancing on the walls"
        }));

    addTimeOfDayDescription("evening", ({
        " as the temple is bathed in the deepening gloom",
        " where the rituals of the Keepers reach their height",
        " with the air thick with the scent of burning herbs"
        }));

    addTimeOfDayDescription("night", ({
        " cloaked in utter darkness",
        " where the only light comes from eerie, unnatural flames",
        " as the Keepers of the Night perform their most secret rites"
        }));

    addSeasonDescription("winter", ({
        " where the cold seeps through the stone and the air is icy",
        " as the temple feels even more desolate and forbidding"
        }));

    addSeasonDescription("spring", ({
        " with dampness clinging to the stones and mold in the corners",
        " as the Keepers whisper prayers for renewal in the darkness"
        }));

    addSeasonDescription("summer", ({
        " where the air is stifling and heavy with incense",
        " as the shadows seem to deepen despite the heat outside"
        }));

    addSeasonDescription("autumn", ({
        " with fallen leaves swirling in the entryway",
        " as the Keepers prepare for the long nights ahead"
        }));

    addDescriptionTemplate("a ##Adjective##");
    addNearDarkDescriptionTemplate("a pitch-black temple where only the faintest glimmer of candlelight reveals the presence of the Keepers");
    addLowLightDescriptionTemplate("a barely-lit temple where shadows gather in every corner");
    addDimLightDescriptionTemplate("a dimly-lit temple where the air is thick with incense and secrets");
    addSomeLightDescriptionTemplate("a shadowed temple where flickering candles cast strange shapes on the walls");
}
