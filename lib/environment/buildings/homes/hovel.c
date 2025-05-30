//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("hovel");
    setFloorPlanType("hovel");

    addAdjectives(({
        "dilapidated", "ramshackle", "crude", "tiny", "leaning", "weatherbeaten"
        }));

    // Basic description template
    addDescriptionTemplate(
        "a ##Adjective## hovel with a sagging roof and walls of mixed materials"
    );

    // Time of day variations
    addTimeOfDayDescription("dawn", ({
        ". The first light of day does the structure no favors, revealing "
        "patches and repairs made with whatever materials came to hand",
        ". At dawn, thin smoke struggles from a crooked chimney, disappearing "
        "quickly into the morning air"
        }));

    addTimeOfDayDescription("morning", ({
        ". Morning reveals the resourcefulness behind the hovel's "
        "construction - wattle and daub, salvaged wood, and stones all combined",
        ". A threadbare cloth hangs across the single window, attempting to "
        "block the harsh morning light from the interior"
        }));

    addTimeOfDayDescription("noon", ({
        ". At midday, the hovel's shadow offers meager relief from the sun, "
        "falling over a small patch of hard-packed earth",
        ". A thin trickle of water collects from a makeshift gutter into a "
        "barrel - evidence of careful conservation of resources"
        }));

    addTimeOfDayDescription("afternoon", ({
        ". The afternoon light highlights the many repairs in the structure, "
        "each representing a small victory against the elements",
        ". Shadows grow longer across the small clearing surrounding the hovel, "
        "casting the crude dwelling in momentary dignity"
        }));

    addTimeOfDayDescription("evening", ({
        ". As evening falls, a faint glow appears through gaps in the walls, the "
        "meager light of perhaps a single candle or small hearth fire",
        ". The hovel almost disappears in the gathering darkness, becoming just "
        "another shadow in the twilight landscape"
        }));

    addTimeOfDayDescription("dusk", ({
        ". At dusk, the hovel's silhouette seems to sag further, as if the "
        "structure itself is weary after bearing another day's burden",
        ". The crooked chimney produces a wisp of smoke that hangs in the still "
        "evening air before dissipating"
        }));

    addTimeOfDayDescription("night", ({
        ". By night, the hovel is barely visible, with perhaps only the smallest "
        "glimmer of light escaping through the covered window",
        ". The night wind finds numerous entries through the poorly sealed "
        "walls, whistling softly through the cracks and gaps"
        }));

    // Seasonal variations
    addSeasonDescription("spring", ({
        " with wild plants growing through gaps in the walls and rainwater "
        "leaking through multiple spots in the patched roof",
        " where puddles form around the foundation during spring rains, "
        "threatening to undermine what little stability the structure has"
        }));

    addSeasonDescription("summer", ({
        " with the door propped permanently open in a futile attempt to create "
        "some airflow through the stifling interior",
        " surrounded by scraggly weeds and a few stunted vegetables struggling "
        "in the hard-packed dirt nearby"
        }));

    addSeasonDescription("autumn", ({
        " with gaps hastily stuffed with straw and moss in preparation for the "
        "coming cold months",
        " where fallen leaves are piled against the north wall, providing "
        "additional insulation for the poorly constructed structure"
        }));

    addSeasonDescription("winter", ({
        " with snow finding its way through countless cracks in the walls and "
        "frost forming on the interior side of the shutters",
        " where icicles form along the eaves, their weight threatening to "
        "further damage the already compromised structure"
        }));

    // Lighting condition descriptions
    addNearDarkDescriptionTemplate(
        "a small, irregular shape that might be some kind of rudimentary shelter"
    );
    addLowLightDescriptionTemplate(
        "a crude shelter made of mismatched materials with a visibly sagging roof"
    );
    addDimLightDescriptionTemplate(
        "a ramshackle hovel cobbled together from whatever materials were "
        "available"
    );
    addSomeLightDescriptionTemplate(
        "a dilapidated hovel with walls of mixed materials, a sagging roof, "
        "and a single crooked chimney"
    );

    // Single item template
    addItemTemplate(
        "The hovel is a testament to necessity and resourcefulness, constructed "
        "from whatever materials could be scavenged. Walls combine rough wattle "
        "and daub with salvaged planks and stones, while the sagging roof is a "
        "patchwork of thatch, bark, and repurposed boards. A single crooked "
        "chimney, made from river stones and clay, rises from one side. The door "
        "hangs slightly askew on leather hinges, and the single window is "
        "covered with oiled parchment rather than glass. A small herb patch and "
        "a water barrel represent the extent of amenities outside this humble "
        "dwelling."
    );

    addSourceOfLight(1);
}
