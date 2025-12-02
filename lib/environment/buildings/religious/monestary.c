//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("monestary");
    setFloorPlanType("church");

    addAdjectives(({
        "secluded", "stone", "contemplative", "quiet", "remote", "austere"
        }));

    // Basic description template
    addDescriptionTemplate(
        "a ##Adjective## monastery with simple stone buildings arranged "
        "around a central courtyard"
    );

    // Time of day variations
    addTimeOfDayDescription("dawn", ({
        ". The first light of day brings the monastery to quiet life, as monks "
        "rise for prayers before most of the world stirs",
        ". At dawn, a simple bell calls the brothers from their cells, its "
        "clear tone carrying across the still morning air"
        }));

    addTimeOfDayDescription("morning", ({
        ". Morning finds the monastery alive with purpose - prayers completed, "
        "the brothers turn to their assigned tasks with quiet discipline",
        ". The stone buildings warm slowly in the morning sun, dew evaporating "
        "from the herb garden tended by kneeling figures in simple robes"
        }));

    addTimeOfDayDescription("noon", ({
        ". At midday, the monastery observes a period of reflection, the "
        "brothers gathering for a simple meal eaten in contemplative silence",
        ". Sunlight floods the central courtyard, illuminating the worn stones "
        "polished by centuries of passing feet"
        }));

    addTimeOfDayDescription("afternoon", ({
        ". The afternoon brings dedicated labor - monks work at various crafts, "
        "from illuminating manuscripts to tending crops or brewing medicinals",
        ". Each stone in the walls has been placed with purpose, just as each "
        "hour in the monastery is assigned its proper duty"
        }));

    addTimeOfDayDescription("evening", ({
        ". As evening approaches, the pace of activity gentles and the brothers "
        "prepare for final prayers before the day's end",
        ". The monastery seems to gather inward as darkness falls, oil lamps "
        "appearing in windows like earthbound stars"
        }));

    addTimeOfDayDescription("dusk", ({
        ". At dusk, the monastery bell calls once more, summoning the brothers "
        "from their scattered tasks to gather in spiritual community",
        ". The simple buildings fade into shadow as dusk deepens, only their "
        "outlines and occasional window light marking their presence"
        }));

    addTimeOfDayDescription("night", ({
        ". By night, the monastery rests in profound silence, broken only by "
        "the soft footsteps of brothers rising for midnight prayer",
        ". Moonlight transforms the austere buildings, lending them an ethereal "
        "beauty that complements their spiritual purpose"
        }));

    // Seasonal variations
    addSeasonDescription("spring", ({
        " with early vegetables sprouting in careful rows and medicinal herbs "
        "beginning to green in the apothecary garden",
        " where spring cleaning brings monks to outdoor tasks, repairing winter "
        "damage and preparing for the growing season"
        }));

    addSeasonDescription("summer", ({
        " with simple wooden tables moved outdoors where brothers work in the "
        "better light while escaping the summer heat",
        " where the surrounding fields and gardens require constant attention, "
        "the monastery's self-sufficiency dependent on careful stewardship"
        }));

    addSeasonDescription("autumn", ({
        " with the last harvest being processed and stored, brothers working "
        "together to ensure winter provisions are secured",
        " where autumn winds bring a melancholy beauty to the grounds, fallen "
        "leaves swept away as methodically as worldly distractions"
        }));

    addSeasonDescription("winter", ({
        " with snow gathering on the simple rooflines and smoke rising steadily "
        "from chimneys as indoor work predominates",
        " where winter's quiet isolation suits the contemplative life, the "
        "monastery continuing its timeless routine regardless of the season"
        }));

    // Lighting condition descriptions
    addNearDarkDescriptionTemplate(
        "a collection of modest buildings arranged in what appears to be a "
        "planned layout"
    );
    addLowLightDescriptionTemplate(
        "a monastery complex with stone buildings surrounding a central "
        "courtyard"
    );
    addDimLightDescriptionTemplate(
        "a secluded stone monastery with simple buildings arranged around a "
        "central courtyard or cloister"
    );
    addSomeLightDescriptionTemplate(
        "an austere stone monastery consisting of a simple chapel, dormitory, "
        "refectory, and workshop buildings arranged around a central courtyard "
        "with a well"
    );

    // Single item template
    addItemTemplate(
        "The monastery consists of plain stone buildings arranged around a "
        "central courtyard, emphasizing function over decoration. A modest "
        "chapel stands at one end, while dormitories, a refectory, workshops, "
        "and storerooms complete the complex. The buildings are connected by "
        "covered walkways that allow movement regardless of weather. Gardens "
        "provide both food and medicinal herbs, essential for the community's "
        "self-sufficiency. Unlike the grander abbey, this monastery emphasizes "
        "simplicity and contemplation, its austere beauty reflecting the "
        "spiritual discipline of its residents, who have chosen to step away "
        "from worldly concerns in favor of prayer and inner focus."
    );
}
