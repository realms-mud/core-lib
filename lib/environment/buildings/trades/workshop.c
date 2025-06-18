//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("workshop");
    setFloorPlanType("trade");

    addAdjectives(({
        "busy", "timber", "well-lit", "cluttered", "spacious", "craftsman's"
        }));

    addDescriptionTemplate(
        "a ##Adjective## workshop with open doors and the scent of sawdust"
    );

    addTimeOfDayDescription("dawn", ({
        ". At dawn, the workshop is quiet, tools neatly arranged for the day",
        ". The first light glimmers on benches and half-finished projects"
        }));

    addTimeOfDayDescription("morning", ({
        ". In the morning, the workshop is alive with the sound of hammers "
        "and saws",
        ". Craftsmen and apprentices begin their work, filling the air with "
        "activity"
        }));

    addTimeOfDayDescription("noon", ({
        ". At midday, the workshop is busy, sunlight streaming through open "
        "windows",
        ". Workers pause for a meal among the scent of wood and oil"
        }));

    addTimeOfDayDescription("afternoon", ({
        ". In the afternoon, the workshop's output is at its peak, with "
        "finished goods stacked by the door",
        ". The sound of work echoes through the building"
        }));

    addTimeOfDayDescription("evening", ({
        ". As evening falls, the workshop quiets and tools are put away",
        ". The last rays of sunlight glint off polished wood and metal"
        }));

    addTimeOfDayDescription("dusk", ({
        ". At dusk, the workshop stands silent, the day's work done",
        ". The building's outline is dark against the fading sky"
        }));

    addTimeOfDayDescription("night", ({
        ". By night, the workshop is dark and still, watched over by a lone "
        "night watchman",
        ". The workshop rests, the day's labor at an end"
        }));

    addSeasonDescription("spring", ({
        " with new projects beginning and the scent of fresh wood in the air",
        " as craftsmen prepare for the busy season ahead"
        }));

    addSeasonDescription("summer", ({
        " with open doors letting in warm breezes and the sound of busy work",
        " as the workshop is filled with the hum of industry"
        }));

    addSeasonDescription("autumn", ({
        " with finished goods stacked high and preparations for winter underway",
        " as the workshop completes orders for the harvest season"
        }));

    addSeasonDescription("winter", ({
        " with fires burning in the hearth and the workshop warm and bright",
        " as craftsmen work late into the night to finish their tasks"
        }));

    addNearDarkDescriptionTemplate(
        "a timber-framed workshop with shadowed benches and silent tools"
    );
    addLowLightDescriptionTemplate(
        "a busy workshop with open doors and the scent of sawdust"
    );
    addDimLightDescriptionTemplate(
        "a craftsman's workshop with benches, tools, and half-finished goods"
    );
    addSomeLightDescriptionTemplate(
        "a well-lit workshop with busy workers, open windows, and stacked goods"
    );

    addItemTemplate(
        "The workshop is a timber-framed building filled with benches, tools, "
        "and half-finished projects. The air is thick with the scent of wood, "
        "oil, and metal. Craftsmen and apprentices work busily, shaping raw "
        "materials into useful goods for the town."
    );

    addSourceOfLight(1);
}
