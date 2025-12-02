//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("ship yard");
    setFloorPlanType("trade");

    addAdjectives(({
        "bustling", "timber", "sprawling", "busy", "noisy", "waterside"
        }));

    addDescriptionTemplate(
        "a ##Adjective## ship yard with half-built hulls and stacks of timber"
    );

    addTimeOfDayDescription("dawn", ({
        ". At dawn, the ship yard is quiet, the first light glinting off "
        "the water",
        ". Workers gather, ready to begin the day's construction"
        }));

    addTimeOfDayDescription("morning", ({
        ". In the morning, the ship yard is alive with the sound of saws and "
        "hammers",
        ". The scent of fresh-cut timber fills the air as hulls take shape"
        }));

    addTimeOfDayDescription("noon", ({
        ". At midday, the ship yard is busy, the sun beating down on "
        "unfinished ships",
        ". Workers pause for a meal in the shade of stacked planks"
        }));

    addTimeOfDayDescription("afternoon", ({
        ". In the afternoon, the ship yard's output is at its peak, with "
        "crews working on decks and masts",
        ". The sound of construction and shouted orders fills the air"
        }));

    addTimeOfDayDescription("evening", ({
        ". As evening falls, the ship yard quiets and the day's work ends",
        ". The last rays of sunlight glint off the hulls and the water"
        }));

    addTimeOfDayDescription("dusk", ({
        ". At dusk, the ship yard stands silent, the tools set aside for the night",
        ". The last workers leave as the sky darkens over the water"
        }));

    addTimeOfDayDescription("night", ({
        ". By night, the ship yard is dark and still, watched over by a lone guard",
        ". The ship yard rests, the day's labor at an end"
        }));

    addSeasonDescription("spring", ({
        " with new timber arriving and the first keels laid for the season",
        " as the ship yard prepares for a busy time of building"
        }));

    addSeasonDescription("summer", ({
        " with the air filled with the scent of pitch and sawdust",
        " as the ship yard works long hours to meet demand"
        }));

    addSeasonDescription("autumn", ({
        " with the last ships launched before the winter storms",
        " as the ship yard prepares for the cold months ahead"
        }));

    addSeasonDescription("winter", ({
        " with snow dusting the hulls and work slowed by the cold",
        " as the ship yard focuses on repairs and maintenance"
        }));

    addNearDarkDescriptionTemplate(
        "a timber-framed ship yard with shadowed hulls and silent tools"
    );
    addLowLightDescriptionTemplate(
        "a busy ship yard with stacks of timber and half-built ships"
    );
    addDimLightDescriptionTemplate(
        "a sprawling ship yard with hulls, planks, and the scent of pitch"
    );
    addSomeLightDescriptionTemplate(
        "a bustling ship yard with busy workers, timber, and the sound of saws"
    );

    addItemTemplate(
        "The ship yard is a sprawling area by the water, filled with half-built "
        "hulls, stacks of timber, and the scent of pitch. Workers use saws and "
        "hammers to shape planks and build ships, while foremen oversee the "
        "construction. The ship yard is the heart of the town's maritime trade."
    );
}
