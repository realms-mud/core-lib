//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("field stone house");
    setFloorPlanType("house");

    addAdjectives(({
        "solid", "rustic", "enduring", "stone", "weathered", "hardy"
        }));

    // Basic description template
    addDescriptionTemplate(
        "a ##Adjective## field stone house with a slate roof and thick walls"
    );

    // Time of day variations
    addTimeOfDayDescription("dawn", ({
        ". The first light of day touches the varied stones of the walls, "
        "highlighting their earthy colors against the cool shadows",
        ". At dawn, the house appears particularly solid, as if it has grown "
        "from the very earth it stands upon"
        }));

    addTimeOfDayDescription("morning", ({
        ". Morning light emphasizes the craftsmanship of the stonework, where "
        "varied shapes and colors have been fitted together with skill",
        ". The stone house warms slowly in the morning sun, a testament to the "
        "insulating properties of its thick walls"
        }));

    addTimeOfDayDescription("noon", ({
        ". At midday, the stone walls provide cool refuge from the sun, the "
        "interior significantly cooler than the outside air",
        ". Small lizards sometimes sun themselves on the warm stones at noon, "
        "adding living decoration to the rugged walls"
        }));

    addTimeOfDayDescription("afternoon", ({
        ". The afternoon sun brings out the rich palette of the field stones - "
        "from ruddy browns to soft grays and occasional quartz sparkles",
        ". Deep-set windows cast dramatic shadows as the day advances, "
        "emphasizing the protective thickness of the walls"
        }));

    addTimeOfDayDescription("evening", ({
        ". As evening approaches, the stone walls release the day's stored heat, "
        "and golden lamplight begins to glow from within",
        ". The house seems most at home in evening light, which softens the "
        "rugged stonework while highlighting its natural beauty"
        }));

    addTimeOfDayDescription("dusk", ({
        ". At dusk, the house becomes a darker shape as details fade, though the "
        "distinctive texture of the stonework remains visible",
        ". The deep-set windows begin to glow with lamplight as darkness falls, "
        "like warm eyes in the stone facade"
        }));

    addTimeOfDayDescription("night", ({
        ". By night, the house is a solid shadow, its presence felt rather than "
        "seen in the darkness",
        ". Moonlight plays across the varied surfaces of the stone walls, "
        "creating a subtle tapestry of light and shadow"
        }));

    // Seasonal variations
    addSeasonDescription("spring", ({
        " with climbing plants beginning to send new tendrils along the "
        "stonework and birds nesting in crevices between stones",
        " surrounded by spring wildflowers that seem to echo the varied colors "
        "found in the field stone walls"
        }));

    addSeasonDescription("summer", ({
        " with windows open to catch breezes while the thick stone walls keep "
        "the interior naturally cool",
        " where householders often sit on stone benches beside the door, "
        "enjoying summer evenings in the shelter of their sturdy home"
        }));

    addSeasonDescription("autumn", ({
        " with fallen leaves gathering against its foundations and smoke rising "
        "steadily from the massive stone chimney",
        " as the stone absorbs the last warmth of autumn days, preparing for "
        "the coming winter"
        }));

    addSeasonDescription("winter", ({
        " with snow outlining every protruding stone and icicles hanging from "
        "the slate eaves",
        " where despite the bitter cold outside, the massive hearth and thick "
        "walls keep the interior surprisingly comfortable"
        }));

    // Lighting condition descriptions
    addNearDarkDescriptionTemplate(
        "a low, solid structure with what appears to be very thick walls"
    );
    addLowLightDescriptionTemplate(
        "a sturdy stone building with a slate roof and deep-set windows"
    );
    addDimLightDescriptionTemplate(
        "a field stone house with thick walls, small windows, and a large "
        "chimney"
    );
    addSomeLightDescriptionTemplate(
        "a rustic house built of varied field stones carefully fitted together, "
        "with deep-set windows and a slate roof"
    );

    // Single item template
    addItemTemplate(
        "The house is built from stones gathered from local fields, each "
        "selected and placed with care to create walls of remarkable strength "
        "and beauty. The varied stones create a natural mosaic of colors and "
        "textures, from smooth river rocks to angular granite pieces. Small "
        "windows are set deep in the thick walls, and the roof is made of "
        "overlapping slate tiles. A massive stone chimney dominates one wall, "
        "promising warmth even in the harshest weather. The overall impression "
        "is one of permanence and harmony with the surrounding landscape."
    );

    addSourceOfLight(2);
}
