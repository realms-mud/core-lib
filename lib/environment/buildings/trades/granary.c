//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("granary");
    setFloorPlanType("trade");

    addAdjectives(({
        "tall", "circular", "stone", "thatched", "sturdy", "well-kept"
        }));

    addDescriptionTemplate(
        "a ##Adjective## granary with thick stone walls and a conical roof"
    );

    addTimeOfDayDescription("dawn", ({
        ". At dawn, the granary stands silent, dew glistening on its roof",
        ". The first light of day reveals the granary's sturdy silhouette "
        "against the fields"
        }));

    addTimeOfDayDescription("morning", ({
        ". In the morning, workers arrive to check the stores and sweep the "
        "floors",
        ". The granary's doors are opened to let in fresh air and sunlight"
        }));

    addTimeOfDayDescription("noon", ({
        ". At midday, the granary is cool inside, a refuge from the sun",
        ". Farmers bring in sacks of grain, filling the air with the scent "
        "of harvest"
        }));

    addTimeOfDayDescription("afternoon", ({
        ". In the afternoon, the granary is busy with the sound of shovels "
        "and grain being poured",
        ". The sun casts long shadows across the granary's thick walls"
        }));

    addTimeOfDayDescription("evening", ({
        ". As evening falls, the granary doors are closed and locked for the "
        "night",
        ". The last rays of sunlight glint off the thatched roof"
        }));

    addTimeOfDayDescription("dusk", ({
        ". At dusk, the granary stands as a quiet guardian of the village's "
        "food stores",
        ". The building's outline is dark against the fading sky"
        }));

    addTimeOfDayDescription("night", ({
        ". By night, the granary is silent, its stores safe behind heavy doors",
        ". The granary is watched over by the occasional patrol of a village "
        "guard"
        }));

    addSeasonDescription("spring", ({
        " surrounded by fields of young grain and the promise of a new harvest",
        " as the granary is cleaned and prepared for the coming season"
        }));

    addSeasonDescription("summer", ({
        " with the scent of ripening grain drifting from the nearby fields",
        " as the granary begins to fill with the first fruits of the harvest"
        }));

    addSeasonDescription("autumn", ({
        " overflowing with sacks of grain and the bustle of harvest time",
        " as the granary is at its busiest, storing the village's bounty"
        }));

    addSeasonDescription("winter", ({
        " with snow piled against its walls and the stores carefully rationed",
        " as the granary's stores are drawn down to feed the village"
        }));

    addNearDarkDescriptionTemplate(
        "a tall granary with a conical roof and heavy wooden doors"
    );
    addLowLightDescriptionTemplate(
        "a stone granary with thick walls and a thatched roof"
    );
    addDimLightDescriptionTemplate(
        "a circular granary with bins and sacks stacked inside"
    );
    addSomeLightDescriptionTemplate(
        "a well-kept granary with stone walls, a high roof, and sturdy doors"
    );

    addItemTemplate(
        "The granary is a tall, circular building made of thick stone, topped "
        "with a conical thatched roof. Heavy wooden doors guard the entrance, "
        "and inside, bins and sacks of grain are stacked high. The air is cool "
        "and dry, preserving the village's food stores through the seasons."
    );

    addSourceOfLight(1);
}
