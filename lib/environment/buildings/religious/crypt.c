//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("crypt");
    setFloorPlanType("church");

    addAdjectives(({
        "solemn", "stone", "ancient", "ornate", "funerary", "memorial"
        }));

    // Basic description template
    addDescriptionTemplate(
        "a ##Adjective## stone crypt with carved doors and decorative "
        "elements honoring the dead within"
    );

    // Time of day variations
    addTimeOfDayDescription("dawn", ({
        ". The first light of day touches the crypt's roof, while shadows "
        "still cling to the carved entrance and surrounding ground",
        ". At dawn, the stone structure takes on a golden hue, momentarily "
        "transformed from a house of death to something almost beautiful"
        }));

    addTimeOfDayDescription("morning", ({
        ". Morning light reveals the craftsmanship of the stonework, from "
        "carved symbols of faith to elaborate decorative elements",
        ". The crypt stands as a silent reminder of mortality amid the "
        "morning's life and activity"
        }));

    addTimeOfDayDescription("noon", ({
        ". At midday, the crypt casts a precise shadow, the sun highlighting "
        "the weathered state of the oldest carvings",
        ". Small creatures sometimes rest in the shade provided by the stone "
        "structure, unaware of its solemn purpose"
        }));

    addTimeOfDayDescription("afternoon", ({
        ". The afternoon light softens the crypt's appearance, warming the "
        "stone that has witnessed generations of mourners come and go",
        ". Lengthening shadows emphasize the entrance, making the heavy stone "
        "doors appear even more imposing"
        }));

    addTimeOfDayDescription("evening", ({
        ". As evening falls, the crypt seems to withdraw into itself, shadows "
        "gathering in the recesses of the carvings",
        ". The structure takes on a more forbidding aspect in the fading light, "
        "a reminder of the night that awaits all living things"
        }));

    addTimeOfDayDescription("dusk", ({
        ". At dusk, the crypt becomes a dark silhouette, its details fading "
        "while its presence remains unmistakable",
        ". The last light catches on the highest decorative elements, briefly "
        "illuminating symbols of faith or family crests"
        }));

    addTimeOfDayDescription("night", ({
        ". By night, the crypt is a solid shadow among shadows, the entrance "
        "particularly dark as if leading to a deeper darkness within",
        ". Moonlight washes over the stone structure, lending it an ethereal "
        "quality that suits its position between the worlds of living and dead"
        }));

    // Seasonal variations
    addSeasonDescription("spring", ({
        " with small wildflowers growing around its base and occasional tokens "
        "of remembrance left by visitors",
        " where spring rain cleanses the stone, revealing subtle colors in the "
        "rock chosen by builders long ago"
        }));

    addSeasonDescription("summer", ({
        " with the stone radiating accumulated heat and the scent of sun-warmed "
        "granite mingling with that of nearby flowers",
        " standing solid and unchanging while all around it life flourishes in "
        "the summer abundance"
        }));

    addSeasonDescription("autumn", ({
        " with fallen leaves gathering against its base and occasionally "
        "adorning the carved details with splashes of color",
        " where the autumnal mood of reflection makes visitors linger longer, "
        "contemplating the names and dates carved into the stone"
        }));

    addSeasonDescription("winter", ({
        " with snow outlining every carved detail and icicles forming along "
        "the roof edge",
        " standing as a monument to endurance as winter strips away life "
        "from the surrounding landscape"
        }));

    // Lighting condition descriptions
    addNearDarkDescriptionTemplate(
        "a small stone building with what appears to be decorative elements"
    );
    addLowLightDescriptionTemplate(
        "a stone crypt with carved details visible even in the dim light"
    );
    addDimLightDescriptionTemplate(
        "a memorial crypt with ornate stonework and heavy doors secured with "
        "metal fixtures"
    );
    addSomeLightDescriptionTemplate(
        "an ancient stone crypt with elaborate carvings of religious symbols, "
        "family crests, and funerary motifs surrounding metal-bound doors"
    );

    // Single item template
    addItemTemplate(
        "The crypt is a freestanding stone structure designed to house the "
        "remains of the notable dead. Built of carefully fitted blocks, it "
        "features ornate carvings that speak to both religious devotion and "
        "family legacy. Heavy doors secured with metal fixtures guard the "
        "entrance, while decorative elements - from carved angels to family "
        "crests - adorn the exterior. Unlike the sprawling catacombs, this "
        "singular structure serves as the final resting place for a specific "
        "family or individual of importance, their identity proclaimed in the "
        "stonework that will outlast generations."
    );
}
