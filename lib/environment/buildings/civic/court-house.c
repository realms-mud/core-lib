//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("court house");
    setFloorPlanType("court house");

    addAdjectives(({
        "imposing", "granite", "stately", "three-story", "judicial", "severe"
        }));

    // Basic description template
    addDescriptionTemplate(
        "a ##Adjective## granite court house with tall columns flanking the "
        "entrance and wide stone steps leading to massive oak doors"
    );

    // Time of day variations
    addTimeOfDayDescription("dawn", ({
        ". The first light of day strikes the granite facade, imparting a solemn "
        "glow to the otherwise austere building",
        ". At dawn, a few clerks and officials can be seen entering through a "
        "side door, preparing for the day's proceedings"
        }));

    addTimeOfDayDescription("morning", ({
        ". People gather on the steps, some nervous, others determined, all "
        "awaiting their turn before the magistrates within",
        ". Morning light streams through the tall windows, illuminating the "
        "official notices posted beside the entrance"
        }));

    addTimeOfDayDescription("noon", ({
        ". At midday, the court house buzzes with activity as cases are heard "
        "and judgments pronounced within its stone walls",
        ". The gavel's sharp rap occasionally echoes through open windows, "
        "momentarily silencing the murmurs of those waiting outside"
        }));

    addTimeOfDayDescription("afternoon", ({
        ". The afternoon brings continued legal proceedings, with messengers "
        "rushing in and out carrying important documents",
        ". Shadows lengthen across the courthouse steps where petitioners wait, "
        "some dejected, others relieved after their hearings"
        }));

    addTimeOfDayDescription("evening", ({
        ". As evening approaches, lamps are lit within chambers where important "
        "cases continue beyond the usual hours",
        ". The court house takes on an even more imposing presence as shadows "
        "deepen around its solid form"
        }));

    addTimeOfDayDescription("dusk", ({
        ". At dusk, the granite walls darken to match the falling night, and "
        "most chambers stand empty until morning",
        ". Court officials exit through the grand doors, discussing the day's "
        "proceedings as they descend the wide steps"
        }));

    addTimeOfDayDescription("night", ({
        ". By night, the court house stands silent, its windows dark except for "
        "the occasional lamp where clerks work late on important cases",
        ". Moonlight plays across the stone columns, giving them an otherworldly "
        "presence appropriate to a place of judgment"
        }));

    // Seasonal variations
    addSeasonDescription("spring", ({
        " with formal gardens flanking the entrance beginning to bloom, adding "
        "rare color to the austere building",
        " where spring rains wash the granite to a gleaming finish, as if "
        "cleansing the very stones of winter's grime"
        }));

    addSeasonDescription("summer", ({
        " with its massive doors propped open to allow air circulation through "
        "the otherwise stifling chambers within",
        " where petitioners gather in shaded spots along the colonnade, seeking "
        "relief from the summer heat while awaiting their hearings"
        }));

    addSeasonDescription("autumn", ({
        " with fallen leaves gathering in corners of the steps, occasionally "
        "swept away by diligent courthouse staff",
        " as the cooler air brings a clarity to the structure's details, each "
        "carved element standing out in sharp relief"
        }));

    addSeasonDescription("winter", ({
        " with a dusting of snow sitting atop it, highlighting the severe lines "
        "of its classical architecture",
        " where smoke rises from multiple chimneys as hearths work to warm the "
        "cavernous stone chambers within"
        }));

    // Lighting condition descriptions
    addNearDarkDescriptionTemplate(
        "the silhouette of a large building with what appear to be columns at "
        "its entrance"
    );
    addLowLightDescriptionTemplate(
        "the silhouette of a large, three-story building with a formal, "
        "columned entrance"
    );
    addDimLightDescriptionTemplate(
        "a large and imposing granite building with columns and wide steps "
        "leading to its entrance"
    );
    addSomeLightDescriptionTemplate(
        "a large, three-story granite court house with classical columns "
        "flanking its entrance and wide steps leading to massive oak doors"
    );

    // Single item template
    addItemTemplate(
        "The court house is an imposing three-story structure of gray granite, "
        "built in a severe classical style with tall columns supporting a "
        "pediment above the entrance. Wide stone steps lead to massive oak "
        "doors bound with iron, and tall windows with iron gratings line the "
        "facade. Above the entrance, the scales of justice are carved in "
        "relief, a reminder of the building's solemn purpose. The structure "
        "projects permanence, authority, and the unyielding nature of law."
    );

    addSourceOfLight(5);
}
