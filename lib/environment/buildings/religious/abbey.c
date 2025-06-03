//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("abbey");
    setFloorPlanType("church");

    addAdjectives(({
        "grand", "stone", "cloistered", "peaceful", "ancient", "sacred"
        }));

    // Basic description template
    addDescriptionTemplate(
        "a ##Adjective## abbey with a central church, surrounding cloisters, "
        "and outbuildings arranged within stone walls"
    );

    // Time of day variations
    addTimeOfDayDescription("dawn", ({
        ". The first light of day finds the abbey already active, as monks rise "
        "for morning prayers with a discipline unchanged for centuries",
        ". At dawn, plainchant rises from the church, the pure tones floating "
        "across the abbey grounds as the day's first ritual begins"
        }));

    addTimeOfDayDescription("morning", ({
        ". Morning reveals the abbey's extensive grounds - gardens, workshops, "
        "scriptorium, and dormitories surrounding the central church",
        ". The abbey functions as a small, self-contained world, with monks "
        "moving purposefully between buildings according to their duties"
        }));

    addTimeOfDayDescription("noon", ({
        ". At midday, the abbey bell rings for prayers, temporarily halting the "
        "various labors that occupy the community",
        ". Sunlight falls through the cloister arches, creating geometric "
        "patterns of light and shadow across the worn stone path"
        }));

    addTimeOfDayDescription("afternoon", ({
        ". The afternoon brings quiet industry to the abbey - monks working at "
        "crafts, tending gardens, copying manuscripts, or studying texts",
        ". The stone walls have weathered countless seasons, the abbey standing "
        "as a testament to faith's endurance through changing times"
        }));

    addTimeOfDayDescription("evening", ({
        ". As evening approaches, the pace of activity slows and lamps are lit "
        "within the buildings, warm light spilling through arched windows",
        ". The abbey seems most peaceful at evening, when vespers bring the "
        "community together once more before the day ends"
        }));

    addTimeOfDayDescription("dusk", ({
        ". At dusk, the abbey is outlined against the darkening sky, lights "
        "appearing one by one within the various buildings",
        ". The stone walls enclose a world apart, the rhythm of abbey life "
        "continuing regardless of the world outside"
        }));

    addTimeOfDayDescription("night", ({
        ". By night, the abbey grows quiet except for the night offices, when "
        "monks rise from sleep to continue the unending cycle of prayer",
        ". Moonlight bathes the stone buildings and enclosed gardens, giving "
        "the abbey a serene, otherworldly quality"
        }));

    // Seasonal variations
    addSeasonDescription("spring", ({
        " with herbs and vegetables sprouting in the garden beds and fruit trees "
        "blossoming within the orchard walls",
        " where spring brings renewed activity to the grounds as winter projects "
        "are set aside for planting and outdoor repairs"
        }));

    addSeasonDescription("summer", ({
        " with monks working long hours in the gardens and fields, the self-"
        "sufficient community capitalizing on good weather",
        " where summer heat is moderated by thick stone walls, the interior "
        "spaces remaining cool even as the gardens flourish outside"
        }));

    addSeasonDescription("autumn", ({
        " with the final harvest being gathered and preparations underway for the "
        "winter months of study and indoor crafts",
        " where autumn brings a particular beauty to the grounds, the changing "
        "leaves complementing the weathered stone of the buildings"
        }));

    addSeasonDescription("winter", ({
        " with smoke rising from multiple chimneys and the community's focus "
        "turning inward to study, prayer, and sheltered work",
        " where despite the season's harshness, the abbey routine continues "
        "uninterrupted, the enclosed world maintaining its timeless rhythm"
        }));

    // Lighting condition descriptions
    addNearDarkDescriptionTemplate(
        "a large complex of buildings surrounded by what appears to be a wall"
    );
    addLowLightDescriptionTemplate(
        "a collection of stone buildings arranged around a central church, "
        "enclosed by walls"
    );
    addDimLightDescriptionTemplate(
        "an abbey with a central church, cloistered walkways, and various "
        "outbuildings within stone walls"
    );
    addSomeLightDescriptionTemplate(
        "a grand stone abbey complex consisting of a central church with a bell "
        "tower, surrounded by cloisters, workshops, dormitories, gardens, and "
        "other buildings necessary for a self-contained religious community"
    );

    // Single item template
    addItemTemplate(
        "The abbey is a complex of stone buildings centered around a church with "
        "a prominent bell tower. A covered cloister surrounds an inner garden, "
        "providing a sheltered walkway between the church and other buildings. "
        "The complex includes dormitories, refectory, kitchens, workshops, a "
        "scriptorium, and infirmary - all necessary for the self-sufficient "
        "monastic community. Gardens, orchards, and sometimes fields lie within "
        "the outer walls. The architecture is functional yet beautiful, with "
        "arched doorways, carved capitals on columns, and occasional decorative "
        "elements that reflect the balance of practical needs and spiritual "
        "devotion."
    );
}
