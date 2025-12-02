//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("wind mill");
    setFloorPlanType("trade");

    addAdjectives(({
        "tall", "whitewashed", "spinning", "timber", "iconic", "lofty"
        }));

    addDescriptionTemplate(
        "a ##Adjective## wind mill with broad sails and a conical roof"
    );

    addTimeOfDayDescription("dawn", ({
        ". At dawn, the wind mill's sails turn slowly in the morning breeze",
        ". The first light glimmers on the whitewashed walls"
        }));

    addTimeOfDayDescription("morning", ({
        ". In the morning, the wind mill is busy, the sails spinning briskly",
        ". The sound of grinding grain drifts from the open door"
        }));

    addTimeOfDayDescription("noon", ({
        ". At midday, the wind mill stands tall against the bright sky",
        ". Workers pause for a meal as sacks of flour are stacked inside"
        }));

    addTimeOfDayDescription("afternoon", ({
        ". In the afternoon, the wind mill's sails catch the strongest winds",
        ". The building hums with the sound of grinding stones"
        }));

    addTimeOfDayDescription("evening", ({
        ". As evening falls, the sails slow and the mill quiets",
        ". The last sacks of flour are loaded for delivery"
        }));

    addTimeOfDayDescription("dusk", ({
        ". At dusk, the wind mill stands silhouetted against the fading sky",
        ". The sails creak in the gentle breeze"
        }));

    addTimeOfDayDescription("night", ({
        ". By night, the wind mill is still, its sails at rest",
        ". The mill stands silent, waiting for the next day's wind"
        }));

    addSeasonDescription("spring", ({
        " surrounded by green fields and the scent of fresh grain",
        " as the wind mill prepares for the busy season ahead"
        }));

    addSeasonDescription("summer", ({
        " with the sails spinning in the warm breeze and the air filled with "
        "the scent of flour",
        " as the mill works long hours to meet demand"
        }));

    addSeasonDescription("autumn", ({
        " with sacks of grain arriving from the harvest",
        " as the wind mill is at its busiest, grinding the season's bounty"
        }));

    addSeasonDescription("winter", ({
        " with snow piled against the walls and the sails creaking in the wind",
        " as the mill works to supply flour for the cold months"
        }));

    addNearDarkDescriptionTemplate(
        "a tall wind mill with shadowed sails and a conical roof"
    );
    addLowLightDescriptionTemplate(
        "a whitewashed wind mill with broad sails and the scent of flour"
    );
    addDimLightDescriptionTemplate(
        "a spinning wind mill with grinding stones and stacked sacks"
    );
    addSomeLightDescriptionTemplate(
        "an iconic wind mill with busy workers, spinning sails, and open doors"
    );

    addItemTemplate(
        "The wind mill is a tall, whitewashed building with broad sails and a "
        "conical roof. Inside, grinding stones turn grain into flour, and the "
        "air is filled with the scent of fresh bread. Workers move busily, "
        "stacking sacks and tending the machinery."
    );

    addSourceOfLight(1);
}
