//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("church");
    setFloorPlanType("church");

    addAdjectives(({
        "stone", "reverent", "faithful", "village", "modest", "peaceful"
        }));

    // Basic description template
    addDescriptionTemplate(
        "a ##Adjective## church with a tall spire, arched windows of colored "
        "glass, and a welcoming wooden door"
    );

    // Time of day variations
    addTimeOfDayDescription("dawn", ({
        ". The first light of day streams through the eastern windows, painting "
        "the interior with colored light as morning prayers begin",
        ". At dawn, the church bell rings out across the sleeping village, "
        "calling the faithful to first worship"
        }));

    addTimeOfDayDescription("morning", ({
        ". Morning light illuminates the colored glass windows, creating "
        "patterns of light and story across the stone walls",
        ". The wooden door stands open in welcome, and the sound of hymns "
        "occasionally drifts from within"
        }));

    addTimeOfDayDescription("noon", ({
        ". At midday, the church stands serene, its spire reaching skyward as "
        "it has for generations of faithful worship",
        ". The shadows retreat to their shortest point, and the carved details "
        "around the door and windows are shown in their full beauty"
        }));

    addTimeOfDayDescription("afternoon", ({
        ". The afternoon sun warms the western wall, light streaming through "
        "the rose window above the main entrance",
        ". Small gatherings of villagers often pause on the church steps, the "
        "building serving as both spiritual center and community hub"
        }));

    addTimeOfDayDescription("evening", ({
        ". As evening approaches, candles are lit within the church, their warm "
        "glow transforming the colored windows into jewels against the dusk",
        ". The bell tolls for evening prayers, its clear tone carrying across "
        "the quieting village"
        }));

    addTimeOfDayDescription("dusk", ({
        ". At dusk, the church is outlined against the darkening sky, its spire "
        "the last to catch the fading light",
        ". The stone seems to hold a inner warmth as darkness falls, light from "
        "within suggesting comfort and community"
        }));

    addTimeOfDayDescription("night", ({
        ". By night, the church stands as a beacon of faith, light spilling "
        "from its windows to guide both soul and step through darkness",
        ". Moonlight washes over the stone walls and spire, giving the church "
        "an ethereal beauty as night prayers are offered inside"
        }));

    // Seasonal variations
    addSeasonDescription("spring", ({
        " with flowers decorating the entrance and new banners hanging within "
        "to celebrate the season of renewal",
        " where spring festivals bring the community together, the church "
        "grounds alive with celebration after winter's retreat"
        }));

    addSeasonDescription("summer", ({
        " with doors standing wide to catch summer breezes and parish children "
        "playing in the adjacent churchyard",
        " where summer weddings fill the schedule, the church bells ringing "
        "joyfully throughout the season"
        }));

    addSeasonDescription("autumn", ({
        " with harvest decorations adorning the entrance and fallen leaves "
        "gathering around the stone foundation",
        " where autumn services give thanks for the year's bounty, the church "
        "filled with offerings from field and orchard"
        }));

    addSeasonDescription("winter", ({
        " with evergreen boughs decorating the doors and windows glowing with "
        "warmth against winter's chill",
        " where despite snow gathering on the steps, the faithful still gather, "
        "drawn by both spiritual need and community"
        }));

    // Lighting condition descriptions
    addNearDarkDescriptionTemplate(
        "a structure with what appears to be a tall spire rising against the sky"
    );
    addLowLightDescriptionTemplate(
        "a stone building with a spire and what seem to be arched windows"
    );
    addDimLightDescriptionTemplate(
        "a church with a tall spire, arched windows, and a wooden door"
    );
    addSomeLightDescriptionTemplate(
        "a stone church with a tall spire, arched windows of colored glass, "
        "buttressed walls, and a carved wooden door"
    );

    // Single item template
    addItemTemplate(
        "The church is built of local stone in a traditional cruciform layout, "
        "with a tall spire rising from one end. Arched windows of colored glass "
        "depict stories of faith, while buttresses support the walls. The wooden "
        "door features carved panels illustrating virtues and saints. Inside, "
        "a central nave leads to the altar, with wooden pews for the congregation "
        "and small side chapels for private prayer. The church serves as both "
        "a place of worship and a center of community life, marking the rhythm "
        "of days with its bell and the cycle of life with its ceremonies."
    );

    addSourceOfLight(2);
}
