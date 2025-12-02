//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("manor");
    setFloorPlanType("manor");

    addAdjectives(({
        "grand", "lordly", "imposing", "elegant", "noble", "magnificent"
        }));

    // Basic description template
    addDescriptionTemplate(
        "a ##Adjective## manor house with multiple wings, tall chimneys, and an "
        "impressive facade of dressed stone"
    );

    // Time of day variations
    addTimeOfDayDescription("dawn", ({
        ". The first light of day highlights the manor's east wing, while the "
        "rest remains in dignified shadow",
        ". At dawn, servants can be seen beginning their daily routines, "
        "tending to the needs of the noble household within"
        }));

    addTimeOfDayDescription("morning", ({
        ". Morning sunlight plays across the manor's facade, illuminating the "
        "family crest carved above the main entrance",
        ". The household is fully awake now, with horses being readied in the "
        "stable yard and uniformed staff visible through ground floor windows"
        }));

    addTimeOfDayDescription("noon", ({
        ". At midday, the manor stands as a testament to power and wealth, its "
        "shadow stretching across the formal gardens",
        ". Visitors of quality arrive through the ornate gates, their carriages "
        "stopping before the grand entrance"
        }));

    addTimeOfDayDescription("afternoon", ({
        ". The afternoon light emphasizes the fine craftsmanship of the manor's "
        "construction, from carved stone details to leaded glass windows",
        ". Noble residents might be glimpsed taking afternoon air on the "
        "terraced garden, attended by servants carrying refreshments"
        }));

    addTimeOfDayDescription("evening", ({
        ". As evening falls, light begins to illuminate dozens of windows, "
        "revealing glimpses of opulent furnishings and artwork within",
        ". The manor takes on a magical quality at evening, when torch-bearing "
        "footmen attend to arriving guests for dinner or social gathering"
        }));

    addTimeOfDayDescription("dusk", ({
        ". At dusk, the manor's silhouette dominates the landscape, its many "
        "wings and chimneys creating a distinctive skyline",
        ". Lanterns are lit along the drive and gardens, creating a welcoming "
        "path for late-arriving visitors of distinction"
        }));

    addTimeOfDayDescription("night", ({
        ". By night, the manor becomes a beacon of civilization, its many "
        "windows aglow with the warm light of chandeliers and hearth fires",
        ". Moonlight gleams on the weathervanes and decorative elements that "
        "crown the roof, emphasizing the height and grandeur of the residence"
        }));

    // Seasonal variations
    addSeasonDescription("spring", ({
        " with formal gardens coming into bloom and fountains playing in "
        "courtyards after the winter's dormancy",
        " where new growth frames the ancient stonework, the juxtaposition "
        "emphasizing both renewal and enduring power"
        }));

    addSeasonDescription("summer", ({
        " with tall windows open to catch breezes and servants carrying trays "
        "to garden tables where the family takes refreshment",
        " surrounded by immaculately maintained gardens in full splendor, each "
        "vista carefully designed to impress and delight"
        }));

    addSeasonDescription("autumn", ({
        " with ivy turning crimson across the stone walls and smoke rising from "
        "multiple chimneys as the weather cools",
        " where the noble family returns from summer travels, bringing the house "
        "to full life with hunting parties and harvest celebrations"
        }));

    addSeasonDescription("winter", ({
        " with snow outlining architectural details and lanterns burning bright "
        "against the early darkness",
        " where despite the season's chill, the manor exudes warmth and comfort "
        "for those privileged enough to be welcomed inside"
        }));

    // Lighting condition descriptions
    addNearDarkDescriptionTemplate(
        "a massive structure with multiple wings and many chimneys"
    );
    addLowLightDescriptionTemplate(
        "a large, impressive building with multiple sections and what appears "
        "to be ornate architectural details"
    );
    addDimLightDescriptionTemplate(
        "an elegant manor house with multiple wings, tall chimneys, and "
        "finely crafted stonework"
    );
    addSomeLightDescriptionTemplate(
        "a grand manor house with multiple wings, ornate stonework, tall "
        "chimneys, and impressive formal gardens surrounding it"
    );

    // Single item template
    addItemTemplate(
        "The manor is an impressive display of wealth and status, constructed "
        "of finely dressed stone with multiple wings stretching from a central "
        "block. Tall chimneys rise from the slate roof, while ornate stonework "
        "adorns windows, doors, and corner quoins. A family crest is "
        "prominently carved above the main entrance, which is approached via a "
        "sweeping drive. Formal gardens surround the residence, with terraces, "
        "fountains, and carefully planned vistas. Stables, carriage houses, and "
        "servants' quarters form a discrete second courtyard, supporting the "
        "lifestyle of the noble family in residence."
    );

    addSourceOfLight(7);
}
