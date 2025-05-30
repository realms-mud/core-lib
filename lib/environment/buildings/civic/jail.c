//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("jail");
    setFloorPlanType("jail");

    addAdjectives(({ "grim", "sturdy", "imposing", "barred", "bleak", "stone" }));

    // Basic description template
    addDescriptionTemplate(
        "a ##Adjective## brick jail with iron-barred windows and a heavy oak door"
    );

    // Time of day variations
    addTimeOfDayDescription("dawn", ({
        ". The first light of day reveals the cold iron bars and the dampness on "
            "the stone walls",
        ". At dawn, a faint glow seeps through the barred windows, casting long "
            "shadows inside"
        }));

    addTimeOfDayDescription("morning", ({
        ". Morning sunlight glints off the iron bars, and the sound of guards "
            "changing shifts echoes outside",
        ". The jail stands silent and foreboding as the town awakens"
        }));

    addTimeOfDayDescription("noon", ({
        ". At midday, the stone walls radiate heat, and the barred windows offer "
            "little relief from the sun",
        ". The jail's presence is a constant reminder of law and order in the "
            "bustling town"
        }));

    addTimeOfDayDescription("afternoon", ({
        ". The afternoon sun casts harsh shadows across the yard and highlights "
            "the weathered bricks",
        ". The clang of metal and distant voices can be heard from within"
        }));

    addTimeOfDayDescription("evening", ({
        ". As evening falls, lanterns are lit inside, their glow barely visible "
            "through the thick bars",
        ". The jail takes on an even more forbidding aspect as darkness gathers"
        }));

    addTimeOfDayDescription("dusk", ({
        ". At dusk, the building's outline is stark against the fading light, and "
            "the barred windows are dark",
        ". The last rays of sunlight glint off the ironwork before night settles in"
        }));

    addTimeOfDayDescription("night", ({
        ". By night, only a few lanterns burn within, casting dim light through the "
            "barred windows",
        ". The jail looms as a silent, watchful presence in the darkness"
        }));

    addTimeOfDayDescription("midnight", ({
        ". At midnight, the jail is quiet, its heavy door locked tight and only the "
            "occasional footstep echoing outside"
        }));

    addTimeOfDayDescription("late night", ({
        ". In the late night hours, the jail is nearly silent, with only the "
            "faintest glow from within"
        }));

    // Seasonal variations
    addSeasonDescription("spring", ({
        " with rainwater streaking the stone and new grass growing along the "
            "foundation",
        " as the air carries the scent of wet earth and distant blossoms"
        }));

    addSeasonDescription("summer", ({
        " with heat shimmering above the stone walls and the iron bars warm to the "
            "touch",
        " as insects buzz around the yard and the air is thick with humidity"
        }));

    addSeasonDescription("autumn", ({
        " with fallen leaves gathering in the corners of the yard and the air "
            "growing crisp",
        " as the stone walls seem even colder in the fading light"
        }));

    addSeasonDescription("winter", ({
        " with a dusting of snow sitting atop it and icicles hanging from the "
            "barred windows",
        " as the cold air seeps through every crack in the stone"
        }));

    // Lighting condition descriptions
    addNearDarkDescriptionTemplate(
        "a shadowy, imposing building with only the faintest outline of barred "
        "windows visible"
    );
    addLowLightDescriptionTemplate(
        "a sturdy, three-story building with iron-barred windows, barely visible "
        "in the gloom"
    );
    addDimLightDescriptionTemplate(
        "a large, dark brick building with barred windows and a heavy door"
    );
    addSomeLightDescriptionTemplate(
        "a sturdy brick jail with iron-barred windows and a heavy oak door"
    );

    // Single item template
    addItemTemplate(
        "The jail is a grim, sturdy structure of weathered brick and stone, with "
        "iron bars reinforcing every window and a heavy oak door set into the "
        "front. A small yard, enclosed by a high fence, lies to one side, and "
        "the building's presence is both imposing and unmistakable."
    );

    addSourceOfLight(7);
}
