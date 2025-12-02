//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("stone school");
    setFloorPlanType("school");

    addAdjectives(({
        "solid", "gray", "weathered", "stone", "imposing", "enduring"
        }));

    // Basic description template
    addDescriptionTemplate(
        "a ##Adjective## stone schoolhouse with narrow windows and a small "
        "bell tower"
    );

    // Time of day variations
    addTimeOfDayDescription("dawn", ({
        ". The first light of day touches the stone walls, casting long shadows "
        "across the schoolyard",
        ". At dawn, mist often clings to the cool stone walls, giving the "
        "building an ethereal appearance"
        }));

    addTimeOfDayDescription("morning", ({
        ". The school bell echoes from the stone tower, its clear tone calling "
        "students from throughout the village",
        ". Morning brings life to the otherwise austere building as children "
        "file through the heavy wooden door"
        }));

    addTimeOfDayDescription("noon", ({
        ". At midday, the stone walls provide welcome coolness inside, while "
        "students take their meal in the sunny yard",
        ". The sound of lessons being recited in unison carries through the "
        "thick walls during the noon hour"
        }));

    addTimeOfDayDescription("afternoon", ({
        ". The afternoon sun warms the gray stone face, softening the otherwise "
        "stern appearance of the schoolhouse",
        ". Shadows from the bell tower stretch across the yard where students "
        "practice their letters in the dirt"
        }));

    addTimeOfDayDescription("evening", ({
        ". As evening approaches, the stone walls hold the day's warmth while "
        "students depart with their books and slates",
        ". Oil lamps glow from within, their light warm against the cool stone "
        "as the schoolmaster prepares for tomorrow"
        }));

    addTimeOfDayDescription("dusk", ({
        ". At dusk, the schoolhouse fades into shadow, only its square bell tower "
        "distinct against the darkening sky",
        ". The caretaker lights a single lantern by the entrance as darkness "
        "settles around the sturdy stone structure"
        }));

    addTimeOfDayDescription("night", ({
        ". By night, the stone schoolhouse stands as a dark sentinel, moonlight "
        "reflecting off its slate roof",
        ". The massive stones seem to absorb the silence of night, the building "
        "patient until morning brings activity once more"
        }));

    // Seasonal variations
    addSeasonDescription("spring", ({
        " with moss brightening the north-facing walls and small flowers growing "
        "between flagstones in the yard",
        " where students sometimes take their lessons outdoors, sitting on stone "
        "benches when spring weather permits"
        }));

    addSeasonDescription("summer", ({
        " with thick walls that keep the interior cool despite the summer heat "
        "outside",
        " surrounded by a dusty yard where village children play games during "
        "breaks from their studies"
        }));

    addSeasonDescription("autumn", ({
        " with ivy turning crimson against the gray stone walls and smoke rising "
        "from the chimney on chilly mornings",
        " as fallen leaves gather in corners of the schoolyard and students return "
        "after helping with the harvest"
        }));

    addSeasonDescription("winter", ({
        " with snow collecting on the window ledges and icicles forming from the "
        "stone eaves",
        " where despite the bitter cold outside, the great hearth keeps the "
        "schoolroom tolerable for dedicated learning"
        }));

    // Lighting condition descriptions
    addNearDarkDescriptionTemplate(
        "a solid, block-like structure with what appears to be a small tower at "
        "one corner"
    );
    addLowLightDescriptionTemplate(
        "a stone building with narrow windows and what seems to be a bell tower"
    );
    addDimLightDescriptionTemplate(
        "a gray stone schoolhouse with narrow windows and a square bell tower"
    );
    addSomeLightDescriptionTemplate(
        "an imposing stone schoolhouse with narrow windows, a slate roof, and a "
        "square bell tower"
    );

    // Single item template
    addItemTemplate(
        "The schoolhouse is constructed of solid gray stone blocks with a slate "
        "roof and a square bell tower at one corner. Narrow windows with deep "
        "sills allow light into the schoolroom while a large hearth provides "
        "warmth in colder months. A heavy wooden door faces the village square, "
        "and a flagstone path leads to the entrance. Inside, rows of wooden "
        "benches and tables serve the village children who come to learn their "
        "letters and numbers."
    );

    addSourceOfLight(3);
}
