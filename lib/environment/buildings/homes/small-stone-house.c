//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("small stone house");
    setFloorPlanType("house");

    addAdjectives(({
        "humble", "small", "sturdy", "stone", "rustic", "solid"
        }));

    // Basic description template
    addDescriptionTemplate(
        "a ##Adjective## stone house with a slate roof and a single chimney"
    );

    // Time of day variations
    addTimeOfDayDescription("dawn", ({
        ". The first light of day touches the gray stones, revealing the "
        "careful craftsmanship despite the dwelling's modest size",
        ". At dawn, thin smoke begins to rise from the chimney as the hearth "
        "fire is stoked for morning cooking"
        }));

    addTimeOfDayDescription("morning", ({
        ". Morning light emphasizes the varied textures of the fieldstones, "
        "each chosen and placed by hand to create the sturdy walls",
        ". The small dwelling appears particularly solid in morning light, its "
        "thick stone walls promising protection from any weather"
        }));

    addTimeOfDayDescription("noon", ({
        ". At midday, the stone walls remain cool despite the sun overhead, "
        "demonstrating the practical advantages of such construction",
        ". The tiny herb garden beside the door receives full sun at noon, "
        "aromatic plants thriving against the heat-storing stone wall"
        }));

    addTimeOfDayDescription("afternoon", ({
        ". The afternoon sun warms the western wall, the stones absorbing "
        "heat that will radiate into the small interior after sunset",
        ". Shadows begin to stretch from the simple structure, emphasizing its "
        "small but sturdy presence in the landscape"
        }));

    addTimeOfDayDescription("evening", ({
        ". As evening approaches, a warm glow appears in the single window, "
        "light spilling across the threshold from the hearth within",
        ". The small house seems most welcoming at evening, when the rough "
        "stone walls provide a sense of security against the coming night"
        }));

    addTimeOfDayDescription("dusk", ({
        ". At dusk, the stone house becomes a darker silhouette, only the "
        "chimney smoke and window light revealing it's a dwelling",
        ". The heat stored in the stones during the day begins to radiate "
        "inward as dusk falls, a natural benefit of the thick walls"
        }));

    addTimeOfDayDescription("night", ({
        ". By night, the stone house appears as a solid shadow, broken only "
        "by the gentle glow from its single window",
        ". Moonlight gives the rough stones a silvery cast, emphasizing the "
        "dwelling's humble but enduring construction"
        }));

    // Seasonal variations
    addSeasonDescription("spring", ({
        " with tiny wildflowers sprouting between the foundation stones and a "
        "small kitchen garden freshly turned for planting",
        " where the stone walls offer protection from spring rains, water "
        "beading on the carefully fitted stones before running to ground"
        }));

    addSeasonDescription("summer", ({
        " with the door propped open for ventilation while the thick stone "
        "walls keep the interior surprisingly cool",
        " surrounded by herbs and flowers that thrive in the small patches of "
        "earth against the warming stones of the walls"
        }));

    addSeasonDescription("autumn", ({
        " with leaves collecting in corners around the foundation and smoke "
        "rising more frequently from the stone chimney",
        " where drying herbs hang beneath the eaves, the stone walls providing "
        "protection from autumn winds that would otherwise take them"
        }));

    addSeasonDescription("winter", ({
        " with snow outlining the rough edges of each stone and ice forming "
        "crystal patterns on the small window",
        " where constant smoke from the chimney suggests the hearth fire within "
        "rarely goes out during the cold months"
        }));

    // Lighting condition descriptions
    addNearDarkDescriptionTemplate(
        "a small, blocky shape with what appears to be a chimney at one end"
    );
    addLowLightDescriptionTemplate(
        "a small stone structure with a slate roof and chimney"
    );
    addDimLightDescriptionTemplate(
        "a humble stone house with a single window and smoking chimney"
    );
    addSomeLightDescriptionTemplate(
        "a small, well-built stone house with a slate roof, single window, "
        "wooden door, and sturdy chimney"
    );

    // Single item template
    addItemTemplate(
        "The small stone house is built of fieldstones gathered locally, each "
        "chosen for its shape and fitted together with minimal mortar. A steep "
        "slate roof efficiently sheds rain and snow, extending slightly over "
        "the walls to provide additional protection from the elements. A "
        "single window with wooden shutters faces the path, while a sturdy "
        "wooden door completes the simple facade. The stone chimney at one end "
        "promises warmth within, rising slightly taller than the roof peak to "
        "ensure proper draft."
    );

    addSourceOfLight(2);
}
