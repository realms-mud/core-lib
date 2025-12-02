//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("tall wall tower");
    setFloorPlanType("military");

    addAdjectives(({
        "imposing", "tall", "square", "fortified", "formidable", "defensive"
        }));

    // Basic description template
    addDescriptionTemplate(
        "a ##Adjective## wall tower with multiple fighting platforms and a "
        "commanding view of the surroundings"
    );

    // Time of day variations
    addTimeOfDayDescription("dawn", ({
        ". The first light of day touches the highest battlements, gradually "
        "illuminating the tower from top to bottom",
        ". At dawn, a flag is raised from the top of the tower, unfurling to "
        "catch the early morning breeze"
        }));

    addTimeOfDayDescription("morning", ({
        ". Morning reveals the full height of the tower, dominating the "
        "surrounding wall and landscape with its imposing presence",
        ". The sun illuminates the tower's eastern face, highlighting the "
        "different levels and defensive positions built into its structure"
        }));

    addTimeOfDayDescription("noon", ({
        ". At midday, the tower casts a long shadow, its sheer height providing "
        "an excellent vantage point for the sentries within",
        ". Guards move between levels, their silhouettes briefly visible through "
        "arrow slits as they maintain vigilant watch"
        }));

    addTimeOfDayDescription("afternoon", ({
        ". The afternoon sun highlights the western face of the tower, warming "
        "stones that have witnessed countless seasons of peace and conflict",
        ". From its upper platforms, sentries would be able to spot approaching "
        "travelers or threats long before they reach the walls"
        }));

    addTimeOfDayDescription("evening", ({
        ". As evening approaches, signal fires are prepared at the tower's top, "
        "ready to send messages across great distances if needed",
        ". The tower's height becomes most apparent as darkness falls, its upper "
        "levels still catching light while shadows claim the wall below"
        }));

    addTimeOfDayDescription("dusk", ({
        ". At dusk, torches are lit at different levels of the tower, creating a "
        "vertical constellation of lights visible from afar",
        ". The massive silhouette stands stark against the twilight sky, a "
        "reminder of strength and vigilance as night approaches"
        }));

    addTimeOfDayDescription("night", ({
        ". By night, the tower becomes a dark sentinel, with only occasional "
        "torch light visible from its various levels",
        ". Moonlight reveals the tower's formidable outline, from the solid base "
        "to the crenellated fighting platform at its summit"
        }));

    // Seasonal variations
    addSeasonDescription("spring", ({
        " with pennants flying from its upper battlements, snapping briskly in "
        "the changeable spring winds",
        " where the increased visibility of clear spring days makes its function "
        "as a lookout post particularly valuable"
        }));

    addSeasonDescription("summer", ({
        " with the stone radiating heat and guards rotating frequently between "
        "sun-exposed posts and shadowed interior levels",
        " where the height offers some respite from summer's heat, catching "
        "breezes that don't reach the ground below"
        }));

    addSeasonDescription("autumn", ({
        " with guards keeping braziers lit as the weather cools, smoke rising "
        "from the tower's upper level",
        " where the autumn clarity allows for exceptional visibility, the "
        "tower's height providing views to distant landmarks"
        }));

    addSeasonDescription("winter", ({
        " with snow gathering on each outward-facing stone and ice making the "
        "exterior stairs treacherous for the rotating guards",
        " where winter winds howl around its corners and through arrow slits, "
        "the tower standing defiant against the season's assault"
        }));

    // Lighting condition descriptions
    addNearDarkDescriptionTemplate(
        "a massive vertical structure rising high above what appears to be a "
        "defensive wall"
    );
    addLowLightDescriptionTemplate(
        "a tall square tower extending significantly above the adjoining wall, "
        "its full height difficult to gauge in dim light"
    );
    addDimLightDescriptionTemplate(
        "a tall defensive tower with multiple levels, arrow slits, and "
        "battlements at its top"
    );
    addSomeLightDescriptionTemplate(
        "an imposing square tower rising high above the defensive wall, with "
        "multiple fighting platforms, narrow windows, and crenellated battlements"
    );

    // Single item template
    addItemTemplate(
        "The tall wall tower is an impressive defensive structure that rises "
        "significantly higher than the adjoining fortifications. Square in "
        "design, the tower features multiple levels, each serving specific "
        "defensive purposes with arrow slits and murder holes strategically "
        "placed. Narrow windows on the upper levels suggest observation posts, "
        "while the top platform offers a commanding 360-degree view of the "
        "surroundings. The stonework shows expert craftsmanship, with larger "
        "blocks at the base tapering to slightly smaller ones higher up. A "
        "defensive door accessible only from the wall walk provides the sole "
        "entry point to this formidable structure."
    );

    addSourceOfLight(2);
}
