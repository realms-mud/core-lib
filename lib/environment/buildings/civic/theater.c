//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("theater");
    setFloorPlanType("theater");

    addAdjectives(({
        "grand", "wooden", "timbered", "prominent", "open-air", "lively"
        }));

    // Basic description template
    addDescriptionTemplate(
        "a ##Adjective## wooden theater with a high-peaked roof and covered "
        "gallery surrounding an open performance space"
    );

    // Time of day variations
    addTimeOfDayDescription("dawn", ({
        ". The first light of day illuminates the carved details along the "
        "eaves, giving the wooden structure a golden glow",
        ". At dawn, the theater stands quiet, the stage empty but expectant "
        "for the day's performances to come"
        }));

    addTimeOfDayDescription("morning", ({
        ". Actors can be seen rehearsing on the raised wooden stage, their "
        "voices carrying across the empty seats",
        ". Morning light streams through the open sides, creating dramatic "
        "patterns across the wooden benches"
        }));

    addTimeOfDayDescription("noon", ({
        ". At midday, workers prepare the theater for afternoon performances, "
        "sweeping the wooden floors and arranging props",
        ". Patrons begin to gather outside, anticipating the entertainment "
        "that will commence after the noon hour"
        }));

    addTimeOfDayDescription("afternoon", ({
        ". The afternoon brings a bustling crowd to the theater, with performers "
        "in colorful costumes greeting those who enter",
        ". Laughter and applause erupt from within as the day's performance "
        "entertains the gathered audience"
        }));

    addTimeOfDayDescription("evening", ({
        ". As evening falls, torches and oil lamps are lit around the gallery, "
        "casting a warm glow over the performance space",
        ". The theater comes alive at evening, filled with spectators and "
        "the dramatic voices of actors on stage"
        }));

    addTimeOfDayDescription("dusk", ({
        ". At dusk, the wooden structure is outlined against the darkening sky, "
        "light spilling from every opening as performances continue",
        ". The sound of music and merriment pours from the theater as dusk "
        "deepens into night"
        }));

    addTimeOfDayDescription("night", ({
        ". By night, the theater glows with dozens of lamps and torches, a "
        "beacon of entertainment in the darkness",
        ". Moonlight mingles with lamplight across the wooden galleries where "
        "spectators enjoy late performances"
        }));

    // Seasonal variations
    addSeasonDescription("spring", ({
        " with fresh garlands decorating the entrance and flower petals "
        "sometimes strewn across the stage during romantic scenes",
        " where spring breezes carry the sound of performances to those "
        "passing by outside"
        }));

    addSeasonDescription("summer", ({
        " with its sides opened wide to catch cooling breezes, colorful "
        "awnings providing shade for the audience",
        " where summer performances often spill outside as actors make "
        "dramatic entrances through the crowd"
        }));

    addSeasonDescription("autumn", ({
        " with autumn leaves occasionally drifting onto the stage, "
        "incorporated spontaneously into performances by skilled actors",
        " where the smell of roasting chestnuts mingles with applause as "
        "vendors sell treats to theater-goers"
        }));

    addSeasonDescription("winter", ({
        " with the sides partially enclosed by heavy curtains to keep in "
        "the warmth from strategically placed braziers",
        " where dedicated patrons bundle in furs and cloaks, sharing mulled "
        "wine as they enjoy winter performances"
        }));

    // Lighting condition descriptions
    addNearDarkDescriptionTemplate(
        "a large structure with a high roof and what appears to be open sides"
    );
    addLowLightDescriptionTemplate(
        "a wooden building with a distinctive high roof and gallery-like "
        "structure surrounding what seems to be an open center"
    );
    addDimLightDescriptionTemplate(
        "a large wooden theater with multiple levels of galleries surrounding "
        "a central stage area"
    );
    addSomeLightDescriptionTemplate(
        "a grand wooden theater with ornately carved supports, a high-peaked "
        "roof, and covered galleries overlooking the stage"
    );

    // Single item template
    addItemTemplate(
        "The theater is an impressive wooden structure with a high-peaked roof "
        "supported by carved timber posts. Multiple levels of galleries surround "
        "an open central area where a raised stage faces rows of wooden benches. "
        "Colorful banners hang from the eaves, announcing current performances, "
        "and elaborate carvings of theatrical masks and scenes from famous plays "
        "decorate the main entrance. The quality of the woodwork shows this is a "
        "place of cultural importance to the community."
    );

    addSourceOfLight(8);
}
