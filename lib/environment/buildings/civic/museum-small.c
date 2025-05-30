//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("small museum");
    setFloorPlanType("museum");

    addAdjectives(({ "quaint", "modest", "historical", "local",
        "well-maintained" }));

    // Basic description template
    addDescriptionTemplate("a ##Adjective## wooden building housing a museum "
        "dedicated to local history and artifacts");

    // Add time of day variations
    addTimeOfDayDescription("dawn", ({
        ". The early morning light casts long shadows across the building's "
        "facade, highlighting the handcrafted wooden signage",
        ". Dawn brings a peaceful stillness to the museum grounds, where dew "
        "glistens on the small garden of native plants",
        ". As the first light touches the building, the brass fixtures on the "
        "entrance door reflect golden rays, awaiting the day's visitors"
        }));

    addTimeOfDayDescription("morning", ({
        ". Morning sunlight streams through the eastern windows, illuminating "
        "display cases and making the polished wooden floors glow warmly",
        ". The morning brings the curator unlocking the front door and opening "
        "the shutters to welcome the day's first curious visitors",
        ". Sunlight reveals the intricate woodwork details along the eaves, "
        "carved by local artisans to depict scenes from regional history"
        }));

    addTimeOfDayDescription("noon", ({
        ". At midday, the building stands proudly in full light, its weathered "
        "wooden walls telling a story as compelling as the exhibits within",
        ". The noon sun highlights the plaques beside the entrance, describing "
        "notable donations and the founding of this community treasure",
        ". Under the bright light of day, visitors can be seen moving from "
        "window to window, peering at the carefully arranged displays"
        }));

    addTimeOfDayDescription("afternoon", ({
        ". The afternoon sun bathes the western wall in warm light, the aged "
        "wood seeming to glow with the stories contained within",
        ". Slanting afternoon light creates interesting shadows through the "
        "windows, adding drama to the historical tableaus inside",
        ". As afternoon progresses, small groups gather on the benches outside, "
        "discussing the artifacts and local lore they've just discovered"
        }));

    addTimeOfDayDescription("evening", ({
        ". In the evening hours, oil lamps are lit inside, creating warm pools "
        "of light around the most treasured exhibits",
        ". The setting sun casts a golden glow on the wooden exterior, while "
        "lamplight begins to illuminate the interior displays",
        ". Evening brings a special atmosphere to the small museum, with "
        "shadows deepening around artifacts that have witnessed centuries"
        }));

    addTimeOfDayDescription("dusk", ({
        ". At dusk, the curator makes final rounds, carefully covering sensitive "
        "exhibits before securing the building for the night",
        ". The fading light transforms the museum into a silhouette of history, "
        "with only a few lamps remaining lit within",
        ". As dusk settles, the museum seems to hold the day's stories close, "
        "its windows darkening one by one as exhibits are put to rest"
        }));

    addTimeOfDayDescription("night", ({
        ". By night, a single lamp burns in the curator's office, keeping "
        "watch over the collected memories and treasures of the community",
        ". Moonlight washes the simple wooden structure in silver, creating an "
        "almost reverent atmosphere around this repository of history",
        ". In the stillness of night, the museum stands as guardian of the "
        "past, its darkened windows concealing artifacts of bygone eras"
        }));

    // Add seasonal variations
    addSeasonDescription("spring", ({
        " with newly planted flower beds framing the entrance, bringing color "
        "and life to the historical setting",
        " where open windows allow spring breezes to freshen the interior, "
        "carrying away the musty scent of preserved artifacts",
        " surrounded by awakening trees whose branches frame the building as "
        "if presenting it as an artifact of community pride"
        }));

    addSeasonDescription("summer", ({
        " with doors propped open to create a cooling cross-breeze for visitors "
        "examining the exhibits on warm summer days",
        " where the shaded porch becomes an extension of the museum, displaying "
        "hardier artifacts and offering respite from the heat",
        " surrounded by vibrant summer gardens maintained by local volunteers, "
        "featuring plants mentioned in the historical records inside"
        }));

    addSeasonDescription("autumn", ({
        " with autumn leaves gathering around the foundation and occasionally "
        "blowing in when the door opens to admit curious visitors",
        " where the smell of woodsmoke from the small stove mingles with the "
        "scent of preserved documents and artifacts",
        " surrounded by trees in brilliant fall colors that complement the "
        "warm tones of the wooden structure itself"
        }));

    addSeasonDescription("winter", ({
        " with smoke rising from the chimney, promising warmth to visitors "
        "coming to explore local history on cold winter days",
        " its wooden frame dusted with snow that enhances the timeless quality "
        "of this repository of community memory",
        " where frosted windows create natural frames for the historical "
        "exhibits visible from outside, like scenes from the past frozen in time"
        }));

    // Add lighting condition descriptions
    addNearDarkDescriptionTemplate("a shadowy building with what might be "
        "display cases visible through darkened windows");

    addLowLightDescriptionTemplate("a modest wooden structure with signs "
        "suggesting it houses a collection of historical items");

    addDimLightDescriptionTemplate("a small wooden museum with a covered "
        "entrance porch and informational placards visible by the door");

    addSomeLightDescriptionTemplate("a well-maintained wooden building clearly "
        "marked as the local museum, with artifacts visible through the windows");

    // Single item template
    addItemTemplate("The simple yet dignified structure features wide windows "
        "designed to illuminate the displays within, while informational "
        "plaques beside the entrance explain the museum's focus on preserving "
        "local history and culture");
}
