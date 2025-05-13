//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("Cult of Xyris Hall");
    InteriorType("obsidian sanctuary");
    setFloorPlanType("religious guild hall");

    addTimeOfDayDescription("dawn", ({
        ". The hall lies in shadow even as morning breaks, its dark spire catching only the faintest light"
        }));
    addTimeOfDayDescription("morning", ({
        ". Pale robed figures move silently between stone altars, the air heavy with incense and silence"
        }));
    addTimeOfDayDescription("noon", ({
        ". Harsh sunlight does not reach the blackened windows, and the air around the entrance seems unnaturally still"
        }));
    addTimeOfDayDescription("afternoon", ({
        ". The sound of whispered prayer drifts from within, interspersed with the tolling of a low, hollow bell"
        }));
    addTimeOfDayDescription("evening", ({
        ". Shadows deepen unnaturally around the hall, and dim lanterns burn with cold violet flame"
        }));
    addTimeOfDayDescription("dusk", ({
        ". The air thickens as the sun sets, and a faint, unplaceable chill settles over the surrounding ground"
        }));
    addTimeOfDayDescription("night", ({
        " cloaked in darkness, its obsidian walls gleaming faintly under a sky that seems to darken more deeply above it"
        }));
    addTimeOfDayDescription("late night", ({
        " deathly quiet, save for the rustle of robes or the murmured mantras of hooded sentinels"
        }));
    addTimeOfDayDescription("midnight", ({
        " standing silent beneath the stars, a faint black glow pulsing slowly from its sanctum door"
        }));

    addSeasonDescription("winter", ({
        " cloaked in frost, with drifting snow never touching the steps leading to its door"
        }));
    addSeasonDescription("spring", ({
        " seeming untouched by the season's renewal, though black lilies bloom in shallow basins near the entrance"
        }));
    addSeasonDescription("summer", ({
        " cool and dry inside, while shadows remain long and unmoving even under a blazing sun"
        }));
    addSeasonDescription("autumn", ({
        " surrounded by withered leaves and a stillness deeper than mere seasonal decay"
        }));

    addSourceOfLight(5, "ghostflame lanterns", "night");

    addDescriptionTemplate("a black stone sanctuary where the Cult of Xyris honors the god of death");
    addNearDarkDescriptionTemplate("a shadow-cloaked spire with dim lights flickering behind bone-inlaid windows");
    addLowLightDescriptionTemplate("a tall, dark structure surrounded by a circle of stone obelisks and lifeless silence");
    addDimLightDescriptionTemplate("a foreboding obsidian hall etched with runes of ending and inevitability");
    addSomeLightDescriptionTemplate("an ancient sanctuary of black stone, its entrance flanked by carved skulls and burning violet lanterns");
}