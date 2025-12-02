//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("wooden house");
    setFloorPlanType("house");

    addAdjectives(({
        "cozy", "sturdy", "timber", "weathered", "handcrafted", "welcoming"
        }));

    // Basic description template
    addDescriptionTemplate(
        "a ##Adjective## wooden house with a shingled roof and a covered porch"
    );

    // Time of day variations
    addTimeOfDayDescription("dawn", ({
        ". The first light of day touches the timber walls, bringing out the "
        "rich honey tones of the seasoned wood",
        ". At dawn, wisps of smoke curl from the stone chimney, suggesting a "
        "hearth rekindled for the morning meal"
        }));

    addTimeOfDayDescription("morning", ({
        ". Morning sunlight plays across the wooden exterior, highlighting "
        "the skilled craftsmanship in every joined timber and carved detail",
        ". The house seems to come alive in the morning light, the wood "
        "almost glowing with warmth despite the early hour"
        }));

    addTimeOfDayDescription("noon", ({
        ". At midday, the wooden structure absorbs the sun's heat, the timber "
        "expanding slightly with a gentle creak of settling beams",
        ". The covered porch offers welcoming shade at noon, its wooden boards "
        "smooth from years of use"
        }));

    addTimeOfDayDescription("afternoon", ({
        ". The afternoon sun casts long shadows from the carved porch posts, "
        "creating patterns across the front of the house",
        ". Each knot and grain in the wooden walls is emphasized by the slanting "
        "afternoon light, telling the story of the trees that became this home"
        }));

    addTimeOfDayDescription("evening", ({
        ". As evening approaches, golden lamplight begins to spill from the "
        "windows, complementing the natural warmth of the wooden walls",
        ". The house seems most itself at evening, when the aged timber glows "
        "with both the day's accumulated heat and light from within"
        }));

    addTimeOfDayDescription("dusk", ({
        ". At dusk, the wooden structure settles with soft creaks and groans, "
        "adjusting to the cooling air as night approaches",
        ". The darkening sky makes the windows' warm glow more pronounced, each "
        "pane of glass a beacon against the wooden frame"
        }));

    addTimeOfDayDescription("night", ({
        ". By night, the wooden house stands as a darker silhouette, with only "
        "the occasional gleam of moonlight on a window or carved detail",
        ". Moonlight gives the timber a silvery cast, transforming the daytime's "
        "golden warmth to nighttime mystery"
        }));

    // Seasonal variations
    addSeasonDescription("spring", ({
        " with climbing vines beginning to leaf out around the porch posts and "
        "window boxes ready for planting",
        " where the wood develops a subtle fragrance in the damp spring air, a "
        "pleasant reminder of its forest origins"
        }));

    addSeasonDescription("summer", ({
        " with windows thrown open to catch summer breezes through the wooden "
        "rooms inside",
        " surrounded by flowering bushes that contrast beautifully with the "
        "natural tones of the seasoned timber"
        }));

    addSeasonDescription("autumn", ({
        " with fallen leaves gathering against the foundation and smoke often "
        "rising from the stone chimney",
        " where the wooden walls have darkened slightly over the summer, now "
        "a perfect complement to autumn's golden palette"
        }));

    addSeasonDescription("winter", ({
        " with snow outlining every beam and board of its sturdy construction",
        " where frost patterns form on the window glass, their delicate "
        "crystalline structures contrasting with the solid wooden frames"
        }));

    // Lighting condition descriptions
    addNearDarkDescriptionTemplate(
        "a dark shape with what appears to be a peaked roof and porch"
    );
    addLowLightDescriptionTemplate(
        "a wooden building with a covered porch and chimney"
    );
    addDimLightDescriptionTemplate(
        "a timber house with a shingled roof, covered porch, and stone chimney"
    );
    addSomeLightDescriptionTemplate(
        "a well-crafted wooden house with carefully joined timbers, a shingled "
        "roof, and a welcoming covered porch"
    );

    // Single item template
    addItemTemplate(
        "The house showcases traditional woodworking skill, constructed of "
        "carefully joined timbers with dovetail corners and pegged beams. The "
        "walls have weathered to a rich, warm tone that speaks of years of sun "
        "and rain. A covered porch stretches across the front, supported by "
        "carved wooden posts, while a stone chimney rises from one side. The "
        "shingled roof has a pleasing slope, designed to shed rain and snow "
        "efficiently. Small details - carved window frames, a decorative lintel "
        "above the door - elevate the structure from merely functional to "
        "genuinely handsome."
    );

    addSourceOfLight(3);
}
