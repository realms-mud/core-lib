//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("large limestone house");
    setFloorPlanType("house");

    addAdjectives(({
        "stately", "elegant", "large", "limestone", "impressive", "substantial"
        }));

    // Basic description template
    addDescriptionTemplate(
        "a ##Adjective## limestone house with tall windows and decorative "
        "stonework along the roofline"
    );

    // Time of day variations
    addTimeOfDayDescription("dawn", ({
        ". The first light of day touches the pale limestone walls, giving them "
        "a soft golden glow that highlights the fine craftsmanship",
        ". At dawn, the house appears almost ethereal, its limestone exterior "
        "catching the early light while shadows still pool around its foundation"
        }));

    addTimeOfDayDescription("morning", ({
        ". Morning light reveals the precise masonry of the limestone blocks, "
        "each carefully dressed and fitted to its neighbors",
        ". Servants can be seen coming and going through a side entrance as the "
        "household begins its daily activities"
        }));

    addTimeOfDayDescription("noon", ({
        ". At midday, the limestone glows almost white in the sun, making the "
        "house stand out prominently from its surroundings",
        ". The carefully tended garden around the house offers shade from the "
        "noon sun, with stone benches placed strategically for comfort"
        }));

    addTimeOfDayDescription("afternoon", ({
        ". The afternoon sun casts soft shadows across the facade, emphasizing "
        "the subtle carvings around doors and windows",
        ". Well-dressed visitors occasionally arrive through the imposing front "
        "entrance, evidence of the social status this residence conveys"
        }));

    addTimeOfDayDescription("evening", ({
        ". As evening approaches, the limestone takes on a warmer hue, and "
        "lamplight begins to glow behind the tall windows",
        ". The house seems most alive at evening, when its windows shine with "
        "light and the silhouettes of residents move behind sheer curtains"
        }));

    addTimeOfDayDescription("dusk", ({
        ". At dusk, the limestone fades to a soft gray, and the house takes on a "
        "more subdued elegance as shadows deepen",
        ". The decorative stonework along the roofline creates intricate patterns "
        "against the darkening sky"
        }));

    addTimeOfDayDescription("night", ({
        ". By night, the pale stone seems to capture and reflect moonlight, giving "
        "the house an almost luminous quality in the darkness",
        ". Several windows remain lit well into the night, suggesting a household "
        "of means and social engagements"
        }));

    // Seasonal variations
    addSeasonDescription("spring", ({
        " with meticulously pruned ornamental trees blooming in the surrounding "
        "garden",
        " where climbing roses begin their ascent up trellises strategically "
        "placed to enhance the building's beauty"
        }));

    addSeasonDescription("summer", ({
        " with tall windows open behind sheer curtains that billow gently in the "
        "summer breeze",
        " surrounded by a carefully maintained garden in full bloom, showcasing "
        "the owner's wealth and taste"
        }));

    addSeasonDescription("autumn", ({
        " with ivy turning crimson against the pale limestone walls, creating a "
        "dramatic visual contrast",
        " where fallen leaves are quickly swept from the grounds by attentive "
        "servants maintaining the property's pristine appearance"
        }));

    addSeasonDescription("winter", ({
        " with smoke rising from multiple chimneys and frost emphasizing the "
        "detailed stonework",
        " where despite the season, the house exudes warmth and permanence, its "
        "solid walls defying winter's chill"
        }));

    // Lighting condition descriptions
    addNearDarkDescriptionTemplate(
        "a large, pale structure with what appears to be multiple chimneys"
    );
    addLowLightDescriptionTemplate(
        "a substantial two-story building made of light-colored stone with "
        "numerous tall windows"
    );
    addDimLightDescriptionTemplate(
        "a large limestone house with elegant proportions, tall windows, and "
        "decorative stonework"
    );
    addSomeLightDescriptionTemplate(
        "an impressive two-story limestone house with tall windows, multiple "
        "chimneys, and intricate decorative stonework along the roofline"
    );

    // Single item template
    addItemTemplate(
        "The house is constructed of finely dressed limestone blocks, precisely "
        "cut and laid to create a facade of elegant symmetry. Two full stories "
        "with tall windows suggest spacious, well-lit rooms within. Decorative "
        "stonework adorns the roofline and frames the windows and doors, "
        "demonstrating both wealth and aesthetic refinement. A formal garden "
        "surrounds the structure, with gravel paths leading to the imposing "
        "front entrance. Multiple chimneys rise from the hipped roof, promising "
        "warmth and comfort appropriate to a residence of this stature."
    );

    addSourceOfLight(4);
}
