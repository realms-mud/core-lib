//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/terrain/baseTerrain.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("ruin exterior");

    addAdjectives(({
        "crumbling stone ruin with toppled walls",
        "ruined fortress where ivy creeps over shattered battlements",
        "weathered remains of a once-mighty castle",
        "tumbledown walls and broken towers open to the sky",
        "ancient ruin where moss and lichen cover fallen stones",
        "desolate ruin with gaping archways and collapsed roofs",
        "ruin where the wind whistles through empty windows",
        "overgrown ruin where nature reclaims the stone",
        "ruined stronghold with scattered debris and rubble",
        "haunted-looking ruin where shadows linger in the cracks"
        }));

    addTimeOfDayDescription("dawn", ({
        " bathed in the pale light of sunrise",
        " where morning mist clings to the broken stones",
        " as the first rays of sun reveal the ruin's scars"
        }));

    addTimeOfDayDescription("morning", ({
        " with sunlight glinting off mossy walls",
        " as birds nest in the cracks and crevices",
        " where the ruin stands silent and still"
        }));

    addTimeOfDayDescription("noon", ({
        " under the harsh glare of midday sun",
        " where the stones radiate heat and the shadows are short",
        " as the ruin looms stark against the sky"
        }));

    addTimeOfDayDescription("afternoon", ({
        " as the sun slants across the broken battlements",
        " with long shadows stretching over the rubble",
        " where the wind stirs dust and fallen leaves"
        }));

    addTimeOfDayDescription("evening", ({
        " glowing in the warm light of sunset",
        " as the ruin is cast in golden hues",
        " where the air grows cool and the ruin seems even more forlorn"
        }));

    addTimeOfDayDescription("night", ({
        " under a sky filled with stars and the whisper of wind",
        " where the ruin is cloaked in darkness and mystery",
        " as the stones seem to hold secrets of the past"
        }));

    addSeasonDescription("winter", ({
        " dusted with snow and rimed with frost",
        " where icicles hang from broken arches",
        " as the ruin endures the biting cold"
        }));

    addSeasonDescription("spring", ({
        " with new green shoots pushing through the rubble",
        " as wildflowers bloom among the fallen stones",
        " where the air is fresh and alive with birdsong"
        }));

    addSeasonDescription("summer", ({
        " overgrown with vines and thick with buzzing insects",
        " where the sun bakes the exposed stone",
        " as the ruin is half-hidden by lush growth"
        }));

    addSeasonDescription("autumn", ({
        " carpeted with fallen leaves and drifting mist",
        " as the ruin stands silent in the cooling air",
        " where the stones are slick with autumn rain"
        }));

    addDescriptionTemplate("a ##Adjective##");
    addNearDarkDescriptionTemplate("a shadowy ruin where only the outlines of broken walls are visible");
    addLowLightDescriptionTemplate("a barely-lit ruin where the stones are little more than shapes in the gloom");
    addDimLightDescriptionTemplate("a dimly-lit ruin where the rubble is painted in shades of gray");
    addSomeLightDescriptionTemplate("a sunlit ruin where every crack and fallen stone is clear");
}
