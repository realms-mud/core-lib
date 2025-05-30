//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("post office");
    setFloorPlanType("post office");

    addAdjectives(({
        "small", "brick", "bustling", "modest", "red-brick", "official"
        }));

    // Basic description template
    addDescriptionTemplate(
        "a ##Adjective## brick building with a shingled roof and a wooden sign "
        "reading `Post Office' above the door"
    );

    // Time of day variations
    addTimeOfDayDescription("dawn", ({
        ". The first light of day glimmers on the windows, and a faint glow can "
        "be seen from within",
        ". At dawn, the post office stands quiet, ready for the day's deliveries"
        }));

    addTimeOfDayDescription("morning", ({
        ". The door swings open and shut as townsfolk come to collect their letters",
        ". Sunlight streams through the windows, illuminating the busy counter "
        "inside"
        }));

    addTimeOfDayDescription("noon", ({
        ". At midday, the post office is bustling with activity as messengers and "
        "residents arrive",
        ". The building's red bricks are warm in the sun, and the sign above "
        "the door is easy to read"
        }));

    addTimeOfDayDescription("afternoon", ({
        ". The afternoon sun casts long shadows across the steps, and the sound of "
        "sorting mail drifts outside",
        ". Couriers hurry in and out, their satchels full of letters and parcels"
        }));

    addTimeOfDayDescription("evening", ({
        ". As evening falls, the last customers depart and the windows glow with "
        "lamplight",
        ". The post office takes on a quiet, welcoming air as the day winds down"
        }));

    addTimeOfDayDescription("dusk", ({
        ". At dusk, the building's outline is softened by the fading light, and "
        "the sign above the door is just visible",
        ". The post office stands ready for the next day's business"
        }));

    addTimeOfDayDescription("night", ({
        ". By night, the post office is closed, its windows dark and the door "
        "firmly shut",
        ". The building is quiet, with only the moonlight reflecting off the sign"
        }));

    // Seasonal variations
    addSeasonDescription("spring", ({
        " with flower boxes under the windows and the scent of fresh blooms in "
        "the air",
        " as townsfolk gather outside to chat while waiting for their mail"
        }));

    addSeasonDescription("summer", ({
        " with sunlight warming the bricks and the door propped open to let in "
        "a breeze",
        " as the sound of children playing mixes with the bustle of deliveries"
        }));

    addSeasonDescription("autumn", ({
        " with fallen leaves gathered on the steps and a crispness in the air",
        " as the postmaster sweeps the stoop clear of golden foliage"
        }));

    addSeasonDescription("winter", ({
        " with a dusting of snow on the roof and icicles hanging from the eaves",
        " as the warm glow from inside offers a welcome contrast to the cold"
        }));

    // Lighting condition descriptions
    addNearDarkDescriptionTemplate(
        "a small, shadowy building with a faint outline of a sign above the door"
    );
    addLowLightDescriptionTemplate(
        "a modest brick building with a shingled roof and a wooden sign, barely "
        "visible in the gloom"
    );
    addDimLightDescriptionTemplate(
        "a small brick building with a shingled roof and a sign reading "
        "`Post Office'"
    );
    addSomeLightDescriptionTemplate(
        "a bustling brick post office with a shingled roof and a wooden sign "
        "above the door"
    );

    // Single item template
    addItemTemplate(
        "The post office is a small, red-brick building with a shingled roof and "
        "a wooden sign reading `Post Office' above the door. Wide windows let in "
        "plenty of light, and a sturdy oak door welcomes visitors. The building "
        "serves as a hub of communication for the town, with townsfolk coming "
        "and going throughout the day."
    );
}
