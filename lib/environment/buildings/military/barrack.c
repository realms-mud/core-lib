//*****************************************************************************
//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("barrack");
    setFloorPlanType("military");

    addAdjectives(({
        "long", "wooden", "practical", "military", "utilitarian", "sturdy"
        }));

    // Basic description template
    addDescriptionTemplate(
        "a ##Adjective## barracks building with a shingled roof and regularly "
        "spaced windows"
    );

    // Time of day variations
    addTimeOfDayDescription("dawn", ({
        ". The first light of day finds the barracks already active, with "
        "soldiers forming up outside for morning muster",
        ". At dawn, a horn sounds from within, rousing soldiers from their beds "
        "as smoke begins to rise from the cooking hearth"
        }));

    addTimeOfDayDescription("morning", ({
        ". Morning reveals the efficient design of the building - long and "
        "rectangular, built for housing troops rather than for beauty",
        ". The barracks empties as soldiers depart for duty, the building "
        "temporarily quiet until the midday meal"
        }));

    addTimeOfDayDescription("noon", ({
        ". At midday, off-duty soldiers gather at rough tables outside the "
        "barracks, taking their meal in the open air",
        ". The simple wooden structure serves its purpose well, providing "
        "shelter for those who defend the realm"
        }));

    addTimeOfDayDescription("afternoon", ({
        ". The afternoon sun warms the wooden walls, and sounds of activity can "
        "be heard as soldiers maintain equipment or rest between duties",
        ". Shadows lengthen across the packed earth surrounding the barracks, "
        "where boots have worn away any chance of grass growing"
        }));

    addTimeOfDayDescription("evening", ({
        ". As evening approaches, soldiers return to the barracks, light "
        "appearing in the windows as lanterns are lit within",
        ". The building becomes the center of off-duty life as night falls, "
        "voices and occasional laughter drifting through open windows"
        }));

    addTimeOfDayDescription("dusk", ({
        ". At dusk, the barracks is outlined against the darkening sky, smoke "
        "rising from its chimney as the evening meal is prepared",
        ". The day's final muster occurs outside the building as dusk falls, "
        "before soldiers retire or take up night duties"
        }));

    addTimeOfDayDescription("night", ({
        ". By night, the barracks is largely quiet, with only the occasional "
        "movement of those heading to or returning from watch duty",
        ". Moonlight falls on the simple wooden structure, most windows dark "
        "while those who defend by day rest for tomorrow's duties"
        }));

    // Seasonal variations
    addSeasonDescription("spring", ({
        " with equipment drying outside after spring rains and muddy boots "
        "lined neatly by the entrance",
        " where windows are thrown open to air out the winter's staleness from "
        "the long dormitory rooms within"
        }));

    addSeasonDescription("summer", ({
        " with doors propped open to catch any breeze and soldiers preferring "
        "the shade of nearby trees when off duty",
        " where summer heat makes the interior stifling, encouraging activities "
        "to move outdoors whenever possible"
        }));

    addSeasonDescription("autumn", ({
        " with firewood being stockpiled along one wall and repairs made to the "
        "roof before winter arrives",
        " where the evening fires are built larger as the nights grow cooler, "
        "smoke increasing from the stone chimney"
        }));

    addSeasonDescription("winter", ({
        " with snow piled against the windward wall and icicles hanging from "
        "the eaves of the sturdy structure",
        " where the windows are shuttered against the cold and smoke rises "
        "continually from the chimneys at each end"
        }));

    // Lighting condition descriptions
    addNearDarkDescriptionTemplate(
        "a long, low structure with a row of darkened windows"
    );
    addLowLightDescriptionTemplate(
        "a wooden building with multiple windows and what appears to be a "
        "military purpose"
    );
    addDimLightDescriptionTemplate(
        "a long wooden barracks with a shingled roof and regularly spaced windows"
    );
    addSomeLightDescriptionTemplate(
        "a practical wooden barracks building with a shingled roof, multiple "
        "windows with shutters, and doors at each end"
    );

    // Single item template
    addItemTemplate(
        "The barracks is a straightforward military structure, long and "
        "rectangular with a simple pitched roof of wooden shingles. Built "
        "primarily for function, the unadorned wooden walls feature regularly "
        "spaced windows with shutters that can be closed in bad weather. Doors "
        "at each end provide access and egress, while chimneys at both ends "
        "suggest hearths for heating the communal sleeping quarters within. "
        "The building shows signs of regular maintenance but no decorative "
        "touches - this is a place for soldiers, not ceremonies."
    );

    addSourceOfLight(3);
}
