//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("Keepers of the Night Guild Hall");
    InteriorType("gloomy temple and shadowed chambers");
    setFloorPlanType("necromantic sanctum");

    addTimeOfDayDescription("dawn", ({
        ". The pale light of dawn barely pierces the thick mists around the guild hall, casting a muted glow on the stone walls, while the shadows retreat into the corners"
        }));
    addTimeOfDayDescription("morning", ({
        ". A faint, unnatural chill hangs in the air as the first rays of light struggle to illuminate the darkened halls of the Keepers"
        }));
    addTimeOfDayDescription("noon", ({
        ". The noon sun does little to dispel the ever-present gloom inside the guild hall, though faint echoes of distant whispers seem to stir the air"
        }));
    addTimeOfDayDescription("afternoon", ({
        ". The guild hall is silent, save for the faint rustle of parchments and the eerie sound of distant rituals being performed in shadowed rooms"
        }));
    addTimeOfDayDescription("evening", ({
        ". The hall comes alive as the sun begins to set, with flickering torches casting dancing shadows over the dark, ornate walls"
        }));
    addTimeOfDayDescription("dusk", ({
        ". As the world outside darkens, the guild hall’s atmosphere thickens with power—arcane energies seem to pulse in the air as the rituals of the dead begin"
        }));
    addTimeOfDayDescription("night", ({
        " when the dead of night truly settles in, the guild hall is alive with the soft hum of necromantic magic, and the faint glow of candles illuminates the long corridors"
        }));
    addTimeOfDayDescription("late night", ({
        " under the darkened sky, where the only sound is the low murmur of necromancers performing their forbidden rituals in dim chambers"
        }));
    addTimeOfDayDescription("midnight", ({
        " as the clock strikes midnight, the air grows heavy with the energies of life and death intertwining, and the walls themselves seem to whisper secrets of the long-departed"
        }));

    addSeasonDescription("winter", ({
        " with frost creeping along the edges of the guild hall, the air cold and still, as the energies of death and decay are more powerful than ever"
        }));
    addSeasonDescription("spring", ({
        " a curious season in the guild hall, where dark rituals are performed to guide the souls of the dead, and the natural world is kept at a respectful distance"
        }));
    addSeasonDescription("summer", ({
        " the warmth of the outside world does little to temper the chill within the Keepers' halls, where the dead are summoned and bound to the will of the necromancers"
        }));
    addSeasonDescription("autumn", ({
        " with the season of decay in full force, the guild hall’s atmosphere becomes even more oppressive, with the scent of death and decay hanging thick in the air"
        }));

    addSourceOfLight(4, "candles, shadowed lamps, and glowing necromantic sigils", "night");

    addDescriptionTemplate("a dark and eerie guild hall, where the study of necromancy and death magic is practiced in shadow and silence");
    addNearDarkDescriptionTemplate("a looming stone structure, its silhouette obscured by fog and darkness, with faint light leaking from within");
    addLowLightDescriptionTemplate("a shadowy guild hall, the air thick with the scent of incense and the faint rustling of ancient tomes");
    addDimLightDescriptionTemplate("a gloomy, cold hall filled with cryptic symbols, necromantic tomes, and eerie shadows stretching across the walls");
    addSomeLightDescriptionTemplate("a foreboding guild hall dedicated to the study of the dead, with flickering candlelight and an ominous atmosphere of forbidden magic");
}