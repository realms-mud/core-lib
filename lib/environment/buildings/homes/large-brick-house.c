//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("large brick house");
    setFloorPlanType("house");

    addAdjectives(({
        "impressive", "substantial", "large", "red-brick", "handsome", "stately"
        }));

    // Basic description template
    addDescriptionTemplate(
        "a ##Adjective## brick house with tall chimneys and numerous multipaned "
        "windows"
    );

    // Time of day variations
    addTimeOfDayDescription("dawn", ({
        ". The first light of day touches the brick walls, bringing out the rich "
        "variety of reds and browns in the fired clay",
        ". At dawn, thin trails of smoke begin to rise from the chimneys as "
        "servants stoke fires to warm the spacious rooms within"
        }));

    addTimeOfDayDescription("morning", ({
        ". Morning light plays across the brick facade, emphasizing the "
        "craftsmanship and pattern of the brickwork",
        ". The household stirs to life, with well-dressed occupants occasionally "
        "visible through the large windows"
        }));

    addTimeOfDayDescription("noon", ({
        ". At midday, the brick absorbs the sun's warmth, creating an atmosphere "
        "of solid comfort around the substantial dwelling",
        ". The carefully maintained grounds surrounding the house provide a "
        "fitting frame for this demonstration of prosperity"
        }));

    addTimeOfDayDescription("afternoon", ({
        ". The afternoon sun brings a warm glow to the red brick, highlighting "
        "the contrasting lighter stonework around doors and windows",
        ". Visitors of good standing occasionally arrive, their quality of dress "
        "matching the obvious wealth displayed in the house itself"
        }));

    addTimeOfDayDescription("evening", ({
        ". As evening falls, lamplight begins to glow behind the many windows, "
        "revealing glimpses of well-appointed rooms within",
        ". The brick takes on a deeper hue in the fading light, the house "
        "appearing even more substantial as shadows gather"
        }));

    addTimeOfDayDescription("dusk", ({
        ". At dusk, the house's silhouette stands strong against the darkening "
        "sky, its multiple chimneys distinctive above the roofline",
        ". The sound of a piano occasionally drifts from within as evening "
        "activities commence in this house of evident means"
        }));

    addTimeOfDayDescription("night", ({
        ". By night, the house is marked by warm light from several windows and "
        "a lantern burning steadily by the front entrance",
        ". The dark red of the brick becomes almost black in the moonlight, "
        "giving the house a dignified solemnity"
        }));

    // Seasonal variations
    addSeasonDescription("spring", ({
        " with fruit trees blooming in the surrounding garden and window boxes "
        "freshly planted with colorful flowers",
        " where the brick provides a perfect backdrop for the fresh green of "
        "new leaves on carefully positioned ornamental shrubs"
        }));

    addSeasonDescription("summer", ({
        " with windows open behind fine curtains and the occasional sound of "
        "a social gathering drifting across the manicured lawn",
        " surrounded by perfectly maintained gardens that showcase the "
        "residents' refined taste and wealth"
        }));

    addSeasonDescription("autumn", ({
        " with ivy turning scarlet against the red brick, enhancing the warm "
        "tones of the facade",
        " where the brick seems most at home among autumn colors, its ruddy "
        "hues a perfect complement to the seasonal transformation"
        }));

    addSeasonDescription("winter", ({
        " with smoke constantly rising from multiple chimneys and snow "
        "outlining each window ledge and decorative element",
        " where the warm red of the brick offers a cheerful contrast to winter's "
        "monochrome landscape"
        }));

    // Lighting condition descriptions
    addNearDarkDescriptionTemplate(
        "a large rectangular structure with multiple chimneys"
    );
    addLowLightDescriptionTemplate(
        "a substantial building of dark material with many windows and tall "
        "chimneys"
    );
    addDimLightDescriptionTemplate(
        "a large brick house with multiple windows, tall chimneys, and "
        "decorative stonework around the entrance"
    );
    addSomeLightDescriptionTemplate(
        "an impressive red-brick house with numerous multipaned windows, tall "
        "chimneys, and elegant stonework accenting the doors and windows"
    );

    // Single item template
    addItemTemplate(
        "The house is constructed of high-quality red brick laid in a precise "
        "pattern that speaks to the skill of its builders. Multiple tall "
        "chimneys rise from a slate roof, and large windows with multipaned "
        "glass bring light to spacious rooms within. Stone lintels and sills "
        "provide contrast to the warm brick, while an imposing front door with "
        "decorative surrounds marks the main entrance. The grounds are well "
        "kept, with formal plantings and gravel paths completing the picture of "
        "a residence belonging to a family of means and standing."
    );

    addSourceOfLight(4);
}
