//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("Oneiromancer Guild Hall");
    InteriorType("dreamweaver's sanctum and ethereal chambers");
    setFloorPlanType("guild");

    addTimeOfDayDescription("dawn", ({
        ". The soft glow of early morning light pierces the veil of dreams, casting long shadows through the hall as if the very walls are drifting in and out of reality"
        }));
    addTimeOfDayDescription("morning", ({
        ". The air feels light and fluid, as if the guild hall itself is slowly shifting between waking and dreaming, and faint echoes of dreams still linger in the corners"
        }));
    addTimeOfDayDescription("noon", ({
        ". The midday sun casts an otherworldly glow over the guild hall, and the architecture itself seems to bend, as if caught between the realms of sleep and wakefulness"
        }));
    addTimeOfDayDescription("afternoon", ({
        ". As the day wanes, the hall is alive with the shimmering light of dream energy, and mages study their tomes on lucid dreaming and dream manipulation"
        }));
    addTimeOfDayDescription("evening", ({
        ". As dusk settles, the guild hall becomes more surreal, the air thick with the scent of incense, and the walls themselves seem to breathe in time with the dreams of those within"
        }));
    addTimeOfDayDescription("dusk", ({
        ". The guild hall takes on an ethereal glow, where the lines between reality and dream blur, and the faint whisper of dreamers' voices echo through the chambers"
        }));
    addTimeOfDayDescription("night", ({
        " when the hall is enveloped in darkness, yet flickers of dream-like lights pulse through the space, as Oneiromancers commune with the dream realm and manipulate the sleep of the guild's members"
        }));
    addTimeOfDayDescription("late night", ({
        " when the boundaries between reality and dreams fade completely, and the guild hall shimmers with dream energy, creating strange, shifting visions and echoes of long-forgotten dreams"
        }));
    addTimeOfDayDescription("midnight", ({
        " when the guild hall is silent and shrouded in mystery, the dream realms fully intertwined with the waking world, as Oneiromancers enter a deep trance to navigate the dreams of others"
        }));

    addSeasonDescription("winter", ({
        " when the air is crisp and the guild hall feels like it is suspended in a dream-like state, with the quiet of snowfall mixing with the soft hum of dreams being woven by the Oneiromancers"
        }));
    addSeasonDescription("spring", ({
        " when new dreams begin to awaken, and the guild hall seems to bloom with the energy of creativity, inspiration, and visions of the future that flow through the dreamers' minds"
        }));
    addSeasonDescription("summer", ({
        " when the dreams become more vivid and intense, the guild hall filled with vibrant colors and shifting, surreal landscapes, as Oneiromancers tap into the deepest recesses of the mind"
        }));
    addSeasonDescription("autumn", ({
        " when the dream energy becomes quieter, more introspective, and the guild hall is alive with the whispers of forgotten dreams and lost memories, as Oneiromancers seek to retrieve them"
        }));

    addSourceOfLight(4, "dream energy and floating lights", "night");

    addDescriptionTemplate("an ethereal guild hall where dreams and reality intertwine, and the manipulation of the dream realm is an art perfected by its mages");
    addNearDarkDescriptionTemplate("a surreal tower that seems to shimmer and shift between dimensions, with vague outlines of dream-like images flickering in the distance");
    addLowLightDescriptionTemplate("a guild hall bathed in soft, flickering light, where the lines between reality and the dream realm are ever so thin, as mages work to control the dreams of others");
    addDimLightDescriptionTemplate("a hall where the dream world collides with the waking world, the architecture warping like fluid as Oneiromancers practice their art of dream manipulation");
    addSomeLightDescriptionTemplate("a guild hall that feels like a living dream itself, where floating orbs of light and shifting images guide the Oneiromancers through their journey of the subconscious");
}