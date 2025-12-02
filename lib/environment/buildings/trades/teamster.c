//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("teamster");
    setFloorPlanType("trade");

    addAdjectives(({
        "busy", "timber", "open", "bustling", "wagon-filled", "spacious"
        }));

    addDescriptionTemplate(
        "a ##Adjective## teamster's yard with wagons, horses, and crates"
    );

    addTimeOfDayDescription("dawn", ({
        ". At dawn, the teamster's yard is quiet, the first wagons ready to "
        "depart",
        ". The first light glints off harnesses and wagon wheels"
        }));

    addTimeOfDayDescription("morning", ({
        ". In the morning, the yard is alive with the sound of horses and "
        "shouted orders",
        ". Teamsters load wagons and prepare for the day's journeys"
        }));

    addTimeOfDayDescription("noon", ({
        ". At midday, the yard is busy, the sun beating down on loaded wagons",
        ". Drivers pause for a meal in the shade of the stables"
        }));

    addTimeOfDayDescription("afternoon", ({
        ". In the afternoon, the yard's output is at its peak, with wagons "
        "coming and going",
        ". The sound of hooves and wheels echoes across the yard"
        }));

    addTimeOfDayDescription("evening", ({
        ". As evening falls, the yard quiets and the last wagons return",
        ". The day's work ends as the sun sets behind the stables"
        }));

    addTimeOfDayDescription("dusk", ({
        ". At dusk, the yard stands silent, the day's journeys complete",
        ". The last rays of sunlight glint off the wagon wheels"
        }));

    addTimeOfDayDescription("night", ({
        ". By night, the yard is dark and quiet, watched over by a lone "
        "night watchman",
        ". The teamster's yard is still, the day's labor at rest"
        }));

    addSeasonDescription("spring", ({
        " with new horses arriving and the promise of busy roads ahead",
        " as the yard prepares for the season's trade"
        }));

    addSeasonDescription("summer", ({
        " with the yard filled with wagons and the sound of busy teamsters",
        " as the yard works long hours to meet demand"
        }));

    addSeasonDescription("autumn", ({
        " with the last goods of the season arriving and the yard preparing "
        "for winter",
        " as workers stack crates high before the cold sets in"
        }));

    addSeasonDescription("winter", ({
        " with snow piled against the fences and the yard working to supply "
        "the town",
        " as the yard's output slows, but the fires burn bright in the stables"
        }));

    addNearDarkDescriptionTemplate(
        "a timber-framed teamster's yard with shadowed wagons and horses"
    );
    addLowLightDescriptionTemplate(
        "a busy teamster's yard with wagons, crates, and the scent of hay"
    );
    addDimLightDescriptionTemplate(
        "an open yard with wagons, horses, and stacks of crates"
    );
    addSomeLightDescriptionTemplate(
        "a bustling teamster's yard with fresh horses, wagons, and busy workers"
    );

    addItemTemplate(
        "The teamster's yard is a large, open area with wagons, horses, and "
        "crates stacked high. Sheds shelter harnesses and tools, and the air "
        "is filled with the scent of hay and the sound of hooves. Workers move "
        "busily from dawn until dusk, preparing for the town's trade and travel."
    );
}
