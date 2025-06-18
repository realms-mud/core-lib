//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("warehouse");
    setFloorPlanType("trade");

    addAdjectives(({
        "large", "stone", "spacious", "busy", "timber", "well-guarded"
        }));

    addDescriptionTemplate(
        "a ##Adjective## warehouse with wide doors and stacks of crates"
    );

    addTimeOfDayDescription("dawn", ({
        ". At dawn, the warehouse is quiet, the first light glinting off "
        "stacked crates",
        ". Workers gather at the doors, ready to begin the day's labor"
        }));

    addTimeOfDayDescription("morning", ({
        ". In the morning, the warehouse is busy with the sound of carts and "
        "shouted orders",
        ". Goods are loaded and unloaded as the day begins"
        }));

    addTimeOfDayDescription("noon", ({
        ". At midday, the warehouse is cool and shaded, a refuge from the sun",
        ". Workers pause for a meal among the stacks of goods"
        }));

    addTimeOfDayDescription("afternoon", ({
        ". In the afternoon, the warehouse's output is at its peak, with "
        "goods moving in and out",
        ". The sound of work echoes through the building"
        }));

    addTimeOfDayDescription("evening", ({
        ". As evening falls, the warehouse quiets and the doors are closed",
        ". The last carts leave as the sun sets behind the building"
        }));

    addTimeOfDayDescription("dusk", ({
        ". At dusk, the warehouse stands silent, the day's work done",
        ". The building's outline is dark against the fading sky"
        }));

    addTimeOfDayDescription("night", ({
        ". By night, the warehouse is dark and still, watched over by a lone "
        "night watchman",
        ". The warehouse rests, the day's labor at an end"
        }));

    addSeasonDescription("spring", ({
        " with new goods arriving and the promise of a busy season ahead",
        " as the warehouse prepares for the influx of trade"
        }));

    addSeasonDescription("summer", ({
        " with open doors letting in warm breezes and the sound of busy work",
        " as the warehouse is filled with the hum of commerce"
        }));

    addSeasonDescription("autumn", ({
        " with goods stacked high and preparations for winter underway",
        " as the warehouse completes orders for the harvest season"
        }));

    addSeasonDescription("winter", ({
        " with fires burning in the hearth and the warehouse warm and bright",
        " as workers move goods to supply the town through the cold months"
        }));

    addNearDarkDescriptionTemplate(
        "a large warehouse with shadowed stacks of crates and silent carts"
    );
    addLowLightDescriptionTemplate(
        "a busy warehouse with wide doors and the scent of spices"
    );
    addDimLightDescriptionTemplate(
        "a spacious warehouse with crates, barrels, and busy workers"
    );
    addSomeLightDescriptionTemplate(
        "a well-guarded warehouse with open doors, stacked goods, and busy labor"
    );

    addItemTemplate(
        "The warehouse is a large, stone building with wide doors and stacks "
        "of crates and barrels. Workers move goods in and out, and the air is "
        "filled with the scent of spices, grain, and trade. The warehouse is "
        "the heart of the town's commerce and storage."
    );

    addSourceOfLight(1);
}
