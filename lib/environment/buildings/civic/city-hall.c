//*****************************************************************************
//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("city hall");
    setFloorPlanType("administrative building");

    addAdjectives(({ "imposing", "granite", "three-story", "official", "stately", "columned" }));

    // Basic description template
    addDescriptionTemplate("a ##Adjective## city hall built of granite, with tall columns "
        "flanking massive double doors and the words `City Hall' carved above the entrance");

    // Time of day variations
    addTimeOfDayDescription("dawn", ({
        ". The first light of day glints off the granite facade, and warm light spills "
        "from the tall windows onto the steps",
        ". At dawn, the building stands quiet but expectant, its doors soon to open to the public"
        }));

    addTimeOfDayDescription("morning", ({
        ". The plaza in front of city hall bustles with townsfolk attending to civic matters",
        ". Sunlight streams through the windows, illuminating the marble floors inside",
        ". The sound of voices and footsteps echoes from the entrance as the day's business begins"
        }));

    addTimeOfDayDescription("noon", ({
        ". At midday, the granite walls are bright in the sun, and the building is alive "
        "with the comings and goings of officials and citizens",
        ". The city crest above the doors stands out sharply in the overhead light",
        ". The square outside is busy with people seeking council or attending hearings"
        }));

    addTimeOfDayDescription("afternoon", ({
        ". Afternoon shadows stretch across the steps, and the building's columns cast long lines "
        "on the plaza",
        ". The bustle of civic activity continues, with clerks and messengers moving in and out",
        ". The sun warms the stone, and the city hall remains a hub of official business"
        }));

    addTimeOfDayDescription("evening", ({
        ". As evening falls, lanterns are lit within, casting a golden glow through the windows",
        ". The last visitors depart, and the building takes on a quiet, dignified air",
        ". The city hall stands as a symbol of order, its silhouette prominent against the darkening sky"
        }));

    addTimeOfDayDescription("dusk", ({
        ". At dusk, the building's outline is softened by the fading light, and only a few lamps "
        "burn within",
        ". The plaza grows quiet as the day's business ends",
        ". The city hall stands silent, its doors closed for the night"
        }));

    addTimeOfDayDescription("night", ({
        ". By night, the city hall is mostly dark, with only a few windows faintly aglow",
        ". The building's imposing shape looms over the empty square",
        ". Moonlight glimmers on the granite, and the city crest above the doors is barely visible"
        }));

    // Seasonal variations
    addSeasonDescription("spring", ({
        " with flowerbeds in front bursting with color, softening the building's imposing presence",
        " as townsfolk gather on the steps to discuss the latest news under budding trees",
        " where the fresh air carries the scent of blossoms through the open doors"
        }));

    addSeasonDescription("summer", ({
        " with sunlight reflecting off the granite and the plaza lively with townspeople",
        " as the shade of the columns offers respite from the midday heat",
        " where the sound of children playing in the square mixes with the business of governance"
        }));

    addSeasonDescription("autumn", ({
        " framed by trees with golden leaves, the steps often dusted with fallen foliage",
        " as the crisp air brings a sense of urgency to the day's affairs",
        " where the city hall stands as a steadfast presence amid the changing season"
        }));

    addSeasonDescription("winter", ({
        " that has a dusting of snow sitting atop it, the steps swept clean for visitors",
        " with icicles hanging from the eaves and the windows glowing warmly against the cold",
        " where the cold air makes the granite seem even more imposing"
        }));

    // Lighting condition descriptions
    addNearDarkDescriptionTemplate("the silhouette of a large, columned building, its features "
        "barely visible in the gloom");

    addLowLightDescriptionTemplate("the outline of a three-story granite building with tall columns "
        "and massive doors, faintly illuminated by street lamps");

    addDimLightDescriptionTemplate("a large, dark granite building with imposing columns and "
        "the faint glint of carved letters above the entrance");

    addSomeLightDescriptionTemplate("a stately, three-story granite city hall with tall columns, "
        "broad steps, and the words `City Hall' carved above the massive double doors");

    // Single item template
    addItemTemplate("The city hall is an imposing, three-story structure of gray granite, "
        "with tall columns supporting a portico above the broad entrance. Massive double doors "
        "lead inside, and the city crest is carved in relief above the words `City Hall'. "
        "Wide steps lead up from the plaza, and the building's many windows reflect the "
        "activity of civic life within.");
}
