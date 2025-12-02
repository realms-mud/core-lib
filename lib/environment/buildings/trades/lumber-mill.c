//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("lumber mill");
    setFloorPlanType("trade");

    addAdjectives(({
        "busy", "timber", "noisy", "sawdust-covered", "spacious", "industrial"
        }));

    addDescriptionTemplate(
        "a ##Adjective## lumber mill with a tall waterwheel and stacks of logs"
    );

    addTimeOfDayDescription("dawn", ({
        ". At dawn, the lumber mill is quiet, the waterwheel turning slowly "
        "in the morning mist",
        ". The first workers arrive, ready to begin the day's labor"
        }));

    addTimeOfDayDescription("morning", ({
        ". In the morning, the mill is alive with the sound of saws and "
        "the scent of fresh-cut wood",
        ". Workers move logs and stack planks in the growing sunlight"
        }));

    addTimeOfDayDescription("noon", ({
        ". At midday, the mill is busy, the waterwheel spinning and saws "
        "buzzing",
        ". Workers pause for a meal among the stacks of timber"
        }));

    addTimeOfDayDescription("afternoon", ({
        ". In the afternoon, the mill's output is at its peak, with sawdust "
        "drifting in the air",
        ". The sound of sawing and hammering echoes through the yard"
        }));

    addTimeOfDayDescription("evening", ({
        ". As evening falls, the mill quiets and the last logs are stacked "
        "for the night",
        ". The waterwheel slows as the day's work comes to an end"
        }));

    addTimeOfDayDescription("dusk", ({
        ". At dusk, the mill stands silent, the scent of sawdust lingering "
        "in the air",
        ". The last rays of sunlight glint off the stacks of fresh timber"
        }));

    addTimeOfDayDescription("night", ({
        ". By night, the mill is dark and quiet, the waterwheel turning "
        "slowly in the moonlight",
        ". The mill is watched over by a lone night watchman"
        }));

    addSeasonDescription("spring", ({
        " with new logs arriving from the forest and the scent of sap in "
        "the air",
        " as the mill prepares for the busy season ahead"
        }));

    addSeasonDescription("summer", ({
        " with the yard filled with stacks of timber and the sound of "
        "busy saws",
        " as the mill works long hours to meet the demands of builders"
        }));

    addSeasonDescription("autumn", ({
        " with the last logs of the season arriving and the mill preparing "
        "for winter",
        " as workers stack timber high to dry before the cold sets in"
        }));

    addSeasonDescription("winter", ({
        " with snow piled against the walls and the mill working to supply "
        "firewood",
        " as the mill's output slows, but the fires burn bright inside"
        }));

    addNearDarkDescriptionTemplate(
        "a timber-framed lumber mill with a tall waterwheel and shadowed yard"
    );
    addLowLightDescriptionTemplate(
        "a busy lumber mill with stacks of logs and the scent of sawdust"
    );
    addDimLightDescriptionTemplate(
        "a sawdust-covered mill with saws, planks, and a turning waterwheel"
    );
    addSomeLightDescriptionTemplate(
        "a spacious lumber mill with fresh timber, a waterwheel, and busy workers"
    );

    addItemTemplate(
        "The lumber mill is a large, timber-framed building with a tall "
        "waterwheel turning beside it. Inside, saws and hammers fill the air "
        "with noise, and the scent of fresh-cut wood is everywhere. Stacks of "
        "logs and planks fill the yard, and workers move busily from dawn "
        "until dusk. The mill is the heart of the village's building trade."
    );
}
