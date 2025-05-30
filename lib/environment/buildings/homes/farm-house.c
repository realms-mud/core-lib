//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("farm house");
    setFloorPlanType("house");

    addAdjectives(({
        "rustic", "weathered", "practical", "timber", "homely", "sturdy"
        }));

    // Basic description template
    addDescriptionTemplate(
        "a ##Adjective## farm house with a thatched roof and timber framing"
    );

    // Time of day variations
    addTimeOfDayDescription("dawn", ({
        ". The first light of day finds the farm house already stirring with "
        "activity as rural work begins with the sun",
        ". At dawn, smoke rises from the chimney as the household prepares for "
        "a long day of farming duties"
        }));

    addTimeOfDayDescription("morning", ({
        ". Morning sees the farm house as the center of bustling activity, with "
        "family members coming and going on various chores",
        ". Chickens peck in the yard as morning chores proceed, the house "
        "standing as a hub for the day's agricultural activities"
        }));

    addTimeOfDayDescription("noon", ({
        ". At midday, the farm house offers welcome shade as workers take their "
        "brief respite from the fields",
        ". The noon meal brings family together in the kitchen, the heart of "
        "this practical country dwelling"
        }));

    addTimeOfDayDescription("afternoon", ({
        ". The afternoon sun warms the western wall of the house, where herbs "
        "dry in bundles under the eaves",
        ". As afternoon progresses, the house sees preparations for evening "
        "meals and the return of workers from distant fields"
        }));

    addTimeOfDayDescription("evening", ({
        ". As evening approaches, lamplight begins to glow behind the small "
        "windows, promising warmth and rest after a day of labor",
        ". The farm house becomes a haven of family activity as daylight fades "
        "and the day's work comes to an end"
        }));

    addTimeOfDayDescription("dusk", ({
        ". At dusk, the silhouette of the farm house stands against the "
        "darkening sky, a symbol of shelter as night approaches",
        ". The last tasks of the day are completed around the house as livestock "
        "are secured and tools put away for the night"
        }));

    addTimeOfDayDescription("night", ({
        ". By night, the farm house stands as a dark shape with perhaps one or "
        "two windows still glowing with lamplight",
        ". The structure settles and occasionally creaks in the night, the only "
        "sounds besides the distant calls of nocturnal creatures"
        }));

    // Seasonal variations
    addSeasonDescription("spring", ({
        " surrounded by newly-tilled fields and fruit trees covered in blossoms",
        " where spring cleaning sees quilts and blankets airing on lines beside "
        "the weathered walls"
        }));

    addSeasonDescription("summer", ({
        " with windows thrown open to catch any breeze and vegetables from the "
        "kitchen garden laid to dry in the sun",
        " surrounded by the golden waves of ripening grain fields that stretch "
        "to the horizon"
        }));

    addSeasonDescription("autumn", ({
        " with stores of firewood stacked against one wall and late harvest "
        "vegetables heaped in baskets by the door",
        " as smoke from preserving fires adds to the hearth smoke, preparing "
        "the household for winter's lean months"
        }));

    addSeasonDescription("winter", ({
        " with snow piled against the northern wall and icicles hanging from "
        "the thatched eaves",
        " where despite the bitter cold outside, smoke from the chimney "
        "promises warmth within the thick walls"
        }));

    // Lighting condition descriptions
    addNearDarkDescriptionTemplate(
        "a low structure with what appears to be a thatched roof"
    );
    addLowLightDescriptionTemplate(
        "a timber-framed building with a thatched roof and several outbuildings "
        "nearby"
    );
    addDimLightDescriptionTemplate(
        "a rustic farm house with timber framing, small windows, and a thick "
        "thatched roof"
    );
    addSomeLightDescriptionTemplate(
        "a weathered farm house with exposed timber framing, whitewashed wall "
        "panels, and a well-maintained thatched roof"
    );

    // Single item template
    addItemTemplate(
        "The farm house is constructed in the traditional style with a timber "
        "frame supporting whitewashed wattle and daub walls. Its steep roof "
        "is thatched with locally harvested reeds, providing excellent "
        "insulation against both summer heat and winter cold. Small windows "
        "with wooden shutters punctuate the exterior, while a sturdy door leads "
        "into the main room. A stone chimney rises from one end where the "
        "kitchen hearth forms the heart of family life. The house is "
        "surrounded by a kitchen garden, chicken coop, and various outbuildings "
        "necessary for farm life."
    );

    addSourceOfLight(2);
}
