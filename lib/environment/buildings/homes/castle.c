//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("castle");
    setFloorPlanType("castle");

    addAdjectives(({
        "imposing", "stone", "formidable", "ancient", "towering", "fortified"
        }));

    // Basic description template
    addDescriptionTemplate(
        "a ##Adjective## castle with crenellated towers and massive walls of "
        "weathered stone"
    );

    // Time of day variations
    addTimeOfDayDescription("dawn", ({
        ". The first light of day touches the highest towers, while the walls "
        "below remain in deep shadow",
        ". At dawn, guards can be seen changing watch along the battlements, "
        "their silhouettes stark against the brightening sky"
        }));

    addTimeOfDayDescription("morning", ({
        ". Morning activity fills the castle, with servants, soldiers, and nobles "
        "going about their business in the courtyard below the great walls",
        ". Sunlight reveals the castle's scars - repairs to stonework and newer "
        "sections standing alongside ancient walls that have stood for centuries"
        }));

    addTimeOfDayDescription("noon", ({
        ". At midday, the castle's shadow shrinks to almost nothing, as the sun "
        "beats down on stone that has witnessed countless summers",
        ". The banner atop the highest tower hangs limp in the noon heat, its "
        "colors vibrant against the weathered stone of the keep"
        }));

    addTimeOfDayDescription("afternoon", ({
        ". The afternoon light brings out the texture of the ancient stonework, "
        "highlighting the craftsmanship of long-dead masons",
        ". Shadows begin to stretch from the western walls, gradually reaching "
        "across the moat as the day advances"
        }));

    addTimeOfDayDescription("evening", ({
        ". As evening falls, torches and braziers are lit along the walls and "
        "gatehouses, creating a ring of light around the darkening fortress",
        ". The castle takes on an ominous aspect in the fading light, looming "
        "over the surrounding landscape like a stone sentinel"
        }));

    addTimeOfDayDescription("dusk", ({
        ". At dusk, the castle becomes a dark silhouette against the sky, with "
        "only torchlight marking the presence of guards on the battlements",
        ". The massive drawbridge rises as darkness falls, the castle closing "
        "itself off from the world until morning"
        }));

    addTimeOfDayDescription("night", ({
        ". By night, the castle stands as a darker shadow against the night sky, "
        "with only occasional torch light visible along the walls",
        ". Moonlight casts eerie shadows from the towers and battlements, giving "
        "the ancient fortress an otherworldly appearance"
        }));

    // Seasonal variations
    addSeasonDescription("spring", ({
        " with wildflowers growing improbably from cracks in the lower walls",
        " where nesting birds occupy countless niches in the stonework, their "
        "calls echoing off the massive walls"
        }));

    addSeasonDescription("summer", ({
        " with banners hanging limply in the summer heat and sun-baked stones "
        "radiating warmth long after sunset",
        " surrounded by lush greenery that contrasts sharply with the gray stone "
        "of its ancient walls and towers"
        }));

    addSeasonDescription("autumn", ({
        " with morning mist often shrouding its base, making the towers seem to "
        "float above the world",
        " as autumn winds carry the sounds of the castle - from guard calls to "
        "smithy hammers - across the surrounding countryside"
        }));

    addSeasonDescription("winter", ({
        " with snow outlining every merlon and crenel along its battlements",
        " where icicles hang from gargoyles and drain spouts, turning fearsome "
        "stone faces into crystalline wonders"
        }));

    // Lighting condition descriptions
    addNearDarkDescriptionTemplate(
        "a massive silhouette with towers rising against the sky"
    );
    addLowLightDescriptionTemplate(
        "an imposing fortress with high walls and several towers"
    );
    addDimLightDescriptionTemplate(
        "a formidable castle with crenellated towers and thick stone walls"
    );
    addSomeLightDescriptionTemplate(
        "an ancient stone castle with massive walls, multiple towers, and "
        "battlements lined with crenellations"
    );

    // Single item template
    addItemTemplate(
        "The castle dominates the landscape, its gray stone walls rising to "
        "impressive heights and culminating in crenellated battlements. Multiple "
        "towers of varying sizes provide vantage points over the surrounding "
        "territory, while arrow slits and murder holes speak to its defensive "
        "purpose. A deep moat surrounds the outer walls, crossed by a massive "
        "drawbridge at the gatehouse. Centuries of weather and warfare have left "
        "their mark on the stonework, but the fortress stands as imposing as "
        "ever, a symbol of power and permanence."
    );

    addSourceOfLight(6);
}
