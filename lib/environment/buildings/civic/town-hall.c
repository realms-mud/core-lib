//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("town hall");
    setFloorPlanType("town hall");

    addAdjectives(({
        "stately", "timbered", "half-timbered", "prominent", "civic", "communal"
        }));

    // Basic description template
    addDescriptionTemplate(
        "a ##Adjective## town hall with a steep-pitched roof and a prominent "
        "clocktower rising from its center"
    );

    // Time of day variations
    addTimeOfDayDescription("dawn", ({
        ". The first light of day catches on the weathervane atop the clock "
        "tower, gleaming gold against the brightening sky",
        ". At dawn, the town hall stands as a silent sentinel, awaiting the "
        "day's civic business and community gatherings"
        }));

    addTimeOfDayDescription("morning", ({
        ". The morning bell rings from the tower, marking the hour and calling "
        "town officials to their duties",
        ". Townsfolk gather at the wide steps, discussing local matters before "
        "the council begins its morning session"
        }));

    addTimeOfDayDescription("noon", ({
        ". At midday, the building bustles with activity as citizens come to "
        "address concerns or witness council proceedings",
        ". The noon sun illuminates the building's facade, highlighting the "
        "intricate carvings that celebrate the town's history"
        }));

    addTimeOfDayDescription("afternoon", ({
        ". The afternoon brings a steady stream of visitors, from merchants "
        "seeking permits to couples registering marriages",
        ". Shadows from the clock tower stretch across the square as town "
        "criers emerge to announce the day's news and proclamations"
        }));

    addTimeOfDayDescription("evening", ({
        ". As evening falls, oil lamps are lit within, casting warm light "
        "through the tall windows onto the cobblestone square",
        ". The evening bell tolls from the tower, marking the end of official "
        "business but often the beginning of community gatherings"
        }));

    addTimeOfDayDescription("dusk", ({
        ". At dusk, the silhouette of the hall stands proud against the fading "
        "light, its clocktower visible from throughout the town",
        ". The hall's windows glow amber as council members conclude late "
        "debates or citizens gather for evening assemblies"
        }));

    addTimeOfDayDescription("night", ({
        ". By night, the town hall's tower is illuminated by hanging lanterns, "
        "a beacon for travelers and night watchmen",
        ". The great hall occasionally echoes with music and laughter during "
        "night festivals, the building serving both governance and celebration"
        }));

    // Seasonal variations
    addSeasonDescription("spring", ({
        " with colorful banners hanging from its eaves announcing spring "
        "festivals and upcoming council elections",
        " where spring rains wash the timbers to a deep rich brown, and "
        "window boxes bloom with the town's colors"
        }));

    addSeasonDescription("summer", ({
        " with its great doors thrown wide to catch cooling breezes, and town "
        "records airing in the sunlight to prevent mustiness",
        " where summer markets fill the square before it, vendors setting up "
        "stalls in the shade of its imposing presence"
        }));

    addSeasonDescription("autumn", ({
        " with harvest decoration adorning its entrance and the scent of wood "
        "smoke drifting from its massive stone hearths",
        " where autumn wind sends leaves swirling around the clock tower as "
        "citizens gather to plan winter preparations"
        }));

    addSeasonDescription("winter", ({
        " with snow gathered on the steep roof and icicles hanging from the "
        "elaborately carved eaves",
        " where winter's chill is kept at bay by roaring fires in the great "
        "hall, making it a center of community warmth and gathering"
        }));

    // Lighting condition descriptions
    addNearDarkDescriptionTemplate(
        "a large structure with what appears to be a tower rising from its center"
    );
    addLowLightDescriptionTemplate(
        "a substantial half-timbered building with a prominent tower and many "
        "windows"
    );
    addDimLightDescriptionTemplate(
        "a stately town hall with dark timber framing, many windows, and a "
        "central clock tower"
    );
    addSomeLightDescriptionTemplate(
        "an impressive half-timbered town hall with ornate woodwork, tall "
        "windows, and a commanding clock tower at its center"
    );

    // Single item template
    addItemTemplate(
        "The town hall is an impressive structure of half-timbered construction, "
        "with dark wooden beams creating geometric patterns against whitewashed "
        "walls. A steep-pitched roof of slate tiles is crowned by a square clock "
        "tower with faces on all four sides. Wide oak doors open into a great "
        "hall for public gatherings, while the upper floors house council "
        "chambers and town records. Carved details around doors and windows "
        "depict scenes from the town's founding and history."
    );

    addSourceOfLight(6);
}
