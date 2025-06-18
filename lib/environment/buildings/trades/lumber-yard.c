//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("lumber yard");
    setFloorPlanType("trade");

    addAdjectives(({
        "spacious", "timber", "busy", "open", "sawdust-covered", "bustling"
        }));

    addDescriptionTemplate(
        "a ##Adjective## lumber yard with stacks of logs and piles of planks"
    );

    addTimeOfDayDescription("dawn", ({
        ". At dawn, the lumber yard is quiet, dew glistening on the logs",
        ". The first workers arrive, ready to begin the day's labor"
        }));

    addTimeOfDayDescription("morning", ({
        ". In the morning, the yard is alive with the sound of saws and "
        "the scent of fresh-cut wood",
        ". Workers move logs and stack planks in the growing sunlight"
        }));

    addTimeOfDayDescription("noon", ({
        ". At midday, the yard is busy, the sun beating down on stacks of timber",
        ". Workers pause for a meal among the piles of wood"
        }));

    addTimeOfDayDescription("afternoon", ({
        ". In the afternoon, the yard's output is at its peak, with sawdust "
        "drifting in the air",
        ". The sound of sawing and hammering echoes across the yard"
        }));

    addTimeOfDayDescription("evening", ({
        ". As evening falls, the yard quiets and the last logs are stacked "
        "for the night",
        ". The day's work ends as the sun sets behind the timber piles"
        }));

    addTimeOfDayDescription("dusk", ({
        ". At dusk, the yard stands silent, the scent of sawdust lingering",
        ". The last rays of sunlight glint off the stacks of fresh timber"
        }));

    addTimeOfDayDescription("night", ({
        ". By night, the yard is dark and quiet, watched over by a lone "
        "night watchman",
        ". The lumber yard is still, the day's labor at rest"
        }));

    addSeasonDescription("spring", ({
        " with new logs arriving from the forest and the scent of sap in the air",
        " as the yard prepares for the busy season ahead"
        }));

    addSeasonDescription("summer", ({
        " with the yard filled with stacks of timber and the sound of busy saws",
        " as the yard works long hours to meet the demands of builders"
        }));

    addSeasonDescription("autumn", ({
        " with the last logs of the season arriving and the yard preparing "
        "for winter",
        " as workers stack timber high to dry before the cold sets in"
        }));

    addSeasonDescription("winter", ({
        " with snow piled against the fences and the yard working to supply "
        "firewood",
        " as the yard's output slows, but the fires burn bright in the sheds"
        }));

    addNearDarkDescriptionTemplate(
        "a timber-framed lumber yard with shadowed stacks of logs"
    );
    addLowLightDescriptionTemplate(
        "a busy lumber yard with piles of logs and the scent of sawdust"
    );
    addDimLightDescriptionTemplate(
        "a sawdust-covered yard with planks, logs, and timber stacks"
    );
    addSomeLightDescriptionTemplate(
        "a spacious lumber yard with fresh timber, open sheds, and busy workers"
    );

    addItemTemplate(
        "The lumber yard is a large, open area with stacks of logs and piles "
        "of planks. Sheds shelter saws and tools, and the air is filled with "
        "the scent of fresh-cut wood. Workers move busily from dawn until dusk, "
        "preparing timber for the village's needs."
    );
}
