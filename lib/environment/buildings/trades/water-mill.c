//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("water mill");
    setFloorPlanType("trade");

    addAdjectives(({
        "stone", "riverside", "spinning", "timber", "picturesque", "busy"
        }));

    addDescriptionTemplate(
        "a ##Adjective## water mill with a turning wheel and rushing stream"
    );

    addTimeOfDayDescription("dawn", ({
        ". At dawn, the water mill's wheel turns slowly in the gentle current",
        ". The first light glimmers on the wet stones and flowing water"
        }));

    addTimeOfDayDescription("morning", ({
        ". In the morning, the water mill is busy, the wheel spinning briskly",
        ". The sound of grinding grain and rushing water fills the air"
        }));

    addTimeOfDayDescription("noon", ({
        ". At midday, the water mill is cool and shaded by the stream",
        ". Workers pause for a meal beside the flowing water"
        }));

    addTimeOfDayDescription("afternoon", ({
        ". In the afternoon, the water mill's wheel turns at its fastest",
        ". The building hums with the sound of grinding stones"
        }));

    addTimeOfDayDescription("evening", ({
        ". As evening falls, the wheel slows and the mill quiets",
        ". The last sacks of flour are loaded for delivery"
        }));

    addTimeOfDayDescription("dusk", ({
        ". At dusk, the water mill stands quiet, the wheel turning slowly",
        ". The stream reflects the fading light"
        }));

    addTimeOfDayDescription("night", ({
        ". By night, the water mill is still, the wheel at rest",
        ". The mill stands silent, the stream murmuring in the darkness"
        }));

    addSeasonDescription("spring", ({
        " with wildflowers blooming along the stream and the scent of fresh "
        "grain in the air",
        " as the water mill prepares for the busy season ahead"
        }));

    addSeasonDescription("summer", ({
        " with the wheel spinning in the strong current and the air filled "
        "with the scent of flour",
        " as the mill works long hours to meet demand"
        }));

    addSeasonDescription("autumn", ({
        " with sacks of grain arriving from the harvest",
        " as the water mill is at its busiest, grinding the season's bounty"
        }));

    addSeasonDescription("winter", ({
        " with ice forming on the wheel and the stream running cold",
        " as the mill works to supply flour for the cold months"
        }));

    addNearDarkDescriptionTemplate(
        "a stone water mill with a shadowed wheel and rushing stream"
    );
    addLowLightDescriptionTemplate(
        "a riverside water mill with a turning wheel and the scent of flour"
    );
    addDimLightDescriptionTemplate(
        "a spinning water mill with grinding stones and stacked sacks"
    );
    addSomeLightDescriptionTemplate(
        "a picturesque water mill with busy workers, turning wheel, and open doors"
    );

    addItemTemplate(
        "The water mill is a stone building set beside a rushing stream, with "
        "a large wheel turning in the current. Inside, grinding stones turn "
        "grain into flour, and the air is filled with the scent of fresh bread. "
        "Workers move busily, stacking sacks and tending the machinery."
    );

    addSourceOfLight(1);
}
