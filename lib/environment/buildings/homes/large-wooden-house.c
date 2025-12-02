//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("large wooden house");
    setFloorPlanType("house");

    addAdjectives(({
        "spacious", "impressive", "two-story", "large", "grand", "substantial"
        }));

    // Basic description template
    addDescriptionTemplate(
        "a ##Adjective## wooden house with a wrap-around porch and multiple "
        "gabled windows"
    );

    // Time of day variations
    addTimeOfDayDescription("dawn", ({
        ". The first light of day touches the upper story first, illuminating "
        "the intricate wooden gables against the still-shadowed lower floor",
        ". At dawn, smoke rises from several chimneys, the massive timbers of "
        "the house gradually warming in the growing light"
        }));

    addTimeOfDayDescription("morning", ({
        ". Morning sunlight plays across the expansive wooden facade, revealing "
        "the quality craftsmanship in every carved detail and joined beam",
        ". The house seems to come alive in the morning light, its many windows "
        "gleaming and its weathered wooden walls glowing with rich character"
        }));

    addTimeOfDayDescription("noon", ({
        ". At midday, the large wooden structure casts significant shade, the "
        "wrap-around porch offering cool refuge from the sun",
        ". The two-story house stands impressive at noon, its substantial bulk "
        "highlighted by the overhead sun that emphasizes every architectural line"
        }));

    addTimeOfDayDescription("afternoon", ({
        ". The afternoon sun brings warmth to the western wall, the aged timber "
        "expanding with occasional creaks and settling sounds",
        ". Slanting light accentuates the craftsmanship of the wooden railings "
        "and support posts of the expansive porch that encircles the house"
        }));

    addTimeOfDayDescription("evening", ({
        ". As evening approaches, windows on both floors begin to glow with warm "
        "light, making the large house appear even more impressive",
        ". The house seems most majestic at evening, when the fading light "
        "softens the weathered wood and lamps create a welcoming atmosphere"
        }));

    addTimeOfDayDescription("dusk", ({
        ". At dusk, the large silhouette of the house dominates its "
        "surroundings, its many gables and chimneys distinct against the sky",
        ". The two-story structure settles for the night with gentle creaks as "
        "the timber cools, windows glowing one by one as lamps are lit inside"
        }));

    addTimeOfDayDescription("night", ({
        ". By night, the wooden house becomes an impressive arrangement of "
        "illuminated windows against dark timber, light spilling onto the porch",
        ". Moonlight washes over the large structure, creating interesting "
        "shadows where dormers and gables interrupt the roofline"
        }));

    // Seasonal variations
    addSeasonDescription("spring", ({
        " with flowering vines beginning their climb up trellises along the "
        "porch and birds nesting in the protected eaves",
        " where spring breezes carry the woody scent of the house, enhanced by "
        "the dampness of the season and newly blooming gardens"
        }));

    addSeasonDescription("summer", ({
        " with all windows open to create cross-breezes through the spacious "
        "rooms, and the porch furnished for outdoor living",
        " surrounded by lush gardens that complement the natural beauty of the "
        "wooden construction and provide shade for the lower story"
        }));

    addSeasonDescription("autumn", ({
        " with colorful leaves collecting on the broad steps and smoke curling "
        "from multiple chimneys as the weather cools",
        " where the aged wood of the house harmonizes perfectly with autumn's "
        "palette, the structure seeming to belong to this particular season"
        }));

    addSeasonDescription("winter", ({
        " with snow outlining every architectural detail and icicles hanging "
        "like crystal ornaments from the many eaves",
        " where the contrast between cold white snow and warm wooden walls is "
        "particularly striking, promising warmth within"
        }));

    // Lighting condition descriptions
    addNearDarkDescriptionTemplate(
        "a large, looming structure with what appears to be multiple levels and "
        "a wide porch"
    );
    addLowLightDescriptionTemplate(
        "a substantial wooden building with two stories and what seems to be a "
        "wrap-around porch"
    );
    addDimLightDescriptionTemplate(
        "a large two-story wooden house with multiple gabled windows and an "
        "impressive porch encircling the ground floor"
    );
    addSomeLightDescriptionTemplate(
        "an impressive wooden house with two full stories, ornately carved "
        "gables, multiple chimneys, and a wide wrap-around porch"
    );

    // Single item template
    addItemTemplate(
        "The large wooden house stands as a testament to master carpentry, "
        "constructed of massive timbers and intricate joinery that has stood "
        "the test of time. Two full stories rise above a stone foundation, with "
        "dormer windows jutting from the steep roof to create a habitable third "
        "level in the attic space. A generous porch wraps around the entire "
        "ground floor, supported by turned posts with decorative brackets. "
        "Multiple chimneys rise from the roof, promising warmth throughout the "
        "substantial interior. Every detail, from the carved window frames to "
        "the patterned railings, speaks of prosperity and craftsmanship."
    );

    addSourceOfLight(5);
}
