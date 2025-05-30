//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("brick school");
    setFloorPlanType("school");

    addAdjectives(({
        "modest", "sturdy", "two-story", "red-brick", "village", "scholarly"
        }));

    // Basic description template
    addDescriptionTemplate(
        "a ##Adjective## brick schoolhouse with a slate roof and a small bell "
        "tower"
    );

    // Time of day variations
    addTimeOfDayDescription("dawn", ({
        ". The first light of day touches the brick walls, bringing warmth to "
        "the otherwise quiet building",
        ". At dawn, the schoolhouse stands silent, awaiting the arrival of "
        "students and the day's lessons"
        }));

    addTimeOfDayDescription("morning", ({
        ". The school bell rings to mark the morning hours, summoning children "
        "from throughout the village",
        ". Morning sunlight streams through the tall windows, illuminating "
        "rows of simple wooden desks inside"
        }));

    addTimeOfDayDescription("noon", ({
        ". At midday, the voices of children reciting lessons can be heard "
        "through the open windows",
        ". The schoolyard fills with activity as students take their midday "
        "meal and engage in brief play"
        }));

    addTimeOfDayDescription("afternoon", ({
        ". The afternoon sun warms the red brick facade, while the bell tower "
        "casts a lengthening shadow",
        ". Chalk dust can be seen floating in sunbeams that shine through the "
        "windows during afternoon lessons"
        }));

    addTimeOfDayDescription("evening", ({
        ". As evening approaches, students depart with their slates and books, "
        "leaving the schoolhouse quiet once more",
        ". Oil lamps glow softly inside as the schoolmaster prepares lessons "
        "for the following day"
        }));

    addTimeOfDayDescription("dusk", ({
        ". At dusk, the schoolhouse grows dim, its silhouette marked by the "
        "distinctive shape of the bell tower against the darkening sky",
        ". The caretaker can be seen making rounds, closing shutters and "
        "securing the building for the night"
        }));

    addTimeOfDayDescription("night", ({
        ". By night, the schoolhouse stands dark and silent, awaiting the new "
        "day and its duties of education",
        ". Moonlight casts long shadows from the bell tower across the empty "
        "schoolyard"
        }));

    // Seasonal variations
    addSeasonDescription("spring", ({
        " with wildflowers growing along its foundation and birds nesting in "
        "the eaves of the bell tower",
        " where children's voices mix with birdsong during outdoor lessons on "
        "pleasant spring days"
        }));

    addSeasonDescription("summer", ({
        " with windows thrown open to catch summer breezes, making the heat "
        "more bearable for students and teacher alike",
        " surrounded by a dusty yard where children play games during their "
        "brief respites from summer studies"
        }));

    addSeasonDescription("autumn", ({
        " with fallen leaves gathering around its foundation and the scent of "
        "woodsmoke from the stove inside",
        " as students return with stories of harvest work and new pupils join "
        "the classes after the busy season"
        }));

    addSeasonDescription("winter", ({
        " with smoke rising from the chimney and frost patterns forming on the "
        "windows of the schoolroom",
        " where students huddle near the iron stove during lessons, their "
        "breath visible in the chilly morning air"
        }));

    // Lighting condition descriptions
    addNearDarkDescriptionTemplate(
        "a rectangular building with what appears to be a small tower at one end"
    );
    addLowLightDescriptionTemplate(
        "a brick building with tall windows and what seems to be a bell tower"
    );
    addDimLightDescriptionTemplate(
        "a two-story brick schoolhouse with a slate roof and bell tower"
    );
    addSomeLightDescriptionTemplate(
        "a sturdy brick schoolhouse with tall windows, a slate roof, and a "
        "modest bell tower"
    );

    // Single item template
    addItemTemplate(
        "The schoolhouse is constructed of locally-fired red brick with a "
        "slate roof and a modest bell tower at one end. Tall, multi-paned "
        "windows allow light to fill the main classroom, while a smaller room "
        "at the back serves for advanced lessons. A simple wooden door faces "
        "the road, and the schoolyard is enclosed by a low fence. Inside, "
        "rows of wooden desks face a larger teacher's desk and slate board."
    );

    addSourceOfLight(3);
}
