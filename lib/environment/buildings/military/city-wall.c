//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("city wall");
    setFloorPlanType("military");

    addAdjectives(({
        "massive", "stone", "defensive", "towering", "ancient", "formidable"
        }));

    // Basic description template
    addDescriptionTemplate(
        "a ##Adjective## city wall with battlements along the top and "
        "watchtowers spaced at intervals"
    );

    // Time of day variations
    addTimeOfDayDescription("dawn", ({
        ". The first light of day touches the top of the wall first, gradually "
        "illuminating the massive stonework from top to bottom",
        ". At dawn, guards change shift along the battlements, silhouettes "
        "moving against the brightening sky"
        }));

    addTimeOfDayDescription("morning", ({
        ". Morning reveals the full extent of the defensive structure, stretching "
        "far in both directions to encircle the city",
        ". The gates in the wall open fully as day begins, allowing the flow of "
        "commerce and travelers between city and countryside"
        }));

    addTimeOfDayDescription("noon", ({
        ". At midday, the wall casts a sharp shadow along its base, providing "
        "welcome shade for those passing nearby",
        ". The sun beats down on the stone, which has absorbed and withstood "
        "both weather and siege for generations"
        }));

    addTimeOfDayDescription("afternoon", ({
        ". The afternoon light brings out the texture of the ancient stonework, "
        "highlighting repairs and additions made over the centuries",
        ". Guards patrol the battlements with regularity, their duty to watch "
        "the approaches to the city unchanging regardless of peaceful times"
        }));

    addTimeOfDayDescription("evening", ({
        ". As evening approaches, torches are lit along the battlements, "
        "creating a line of fire that traces the city's perimeter",
        ". The wall takes on a more imposing aspect in the fading light, its "
        "protective purpose emphasized as darkness gathers outside the city"
        }));

    addTimeOfDayDescription("dusk", ({
        ". At dusk, the gates begin to close, the massive wooden doors swinging "
        "shut to secure the city for the night",
        ". The wall becomes a dark silhouette against the last light, torches "
        "along the battlements marking its commanding height"
        }));

    addTimeOfDayDescription("night", ({
        ". By night, the city wall defines the boundary between the relative "
        "safety within and the uncertain darkness without",
        ". Moonlight washes over the ancient stones, and guard lanterns move "
        "along the battlements as patrols continue through the night"
        }));

    // Seasonal variations
    addSeasonDescription("spring", ({
        " with small plants finding purchase in cracks between stones, adding "
        "touches of green to the weathered gray",
        " where spring rain darkens the stone temporarily, water flowing through "
        "carefully designed drainage channels to protect the structure"
        }));

    addSeasonDescription("summer", ({
        " with the stone radiating accumulated heat even after sunset, creating "
        "a microclimate along its base",
        " where the shade provided by the towering structure is sought by those "
        "seeking relief from the summer sun"
        }));

    addSeasonDescription("autumn", ({
        " with fallen leaves gathering along its base, swept by the wind into "
        "colorful drifts against the ancient stones",
        " where the wall provides shelter from autumn winds for the buildings "
        "nestled just inside its protective embrace"
        }));

    addSeasonDescription("winter", ({
        " with snow gathering along the battlements and icicles forming where "
        "water has seeped through the stonework",
        " where the wall blocks the worst of winter winds, its massive bulk a "
        "bulwark against both human threats and natural elements"
        }));

    // Lighting condition descriptions
    addNearDarkDescriptionTemplate(
        "a massive dark barrier stretching into the distance with intermittent "
        "points of light"
    );
    addLowLightDescriptionTemplate(
        "a high stone wall with battlements and what appear to be watchtowers "
        "at intervals"
    );
    addDimLightDescriptionTemplate(
        "a defensive city wall of enormous stone blocks with battlemented top "
        "and regularly spaced watchtowers"
    );
    addSomeLightDescriptionTemplate(
        "a formidable stone city wall with crenellated battlements, regularly "
        "spaced watchtowers, and massive gates positioned at strategic points"
    );

    // Single item template
    addItemTemplate(
        "The city wall represents generations of defensive engineering, built of "
        "massive stone blocks that rise to an imposing height. A walkway runs "
        "along the top, protected by crenellated battlements that provide "
        "cover for defenders. Watchtowers rise at strategic intervals, allowing "
        "for improved visibility and defense. The wall is pierced by several "
        "gates, each a defensive structure in its own right with portcullis, "
        "murder holes, and massive wooden doors reinforced with iron. Arrow slits "
        "and machicolations complete the defensive features of this enduring "
        "barrier designed to protect the city within."
    );
}
