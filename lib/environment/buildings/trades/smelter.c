//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("smelter");
    setFloorPlanType("trade");

    addAdjectives(({
        "hot", "sooty", "stone", "industrial", "noisy", "smoky"
        }));

    addDescriptionTemplate(
        "a ##Adjective## smelter with glowing furnaces and stacks of ore"
    );

    addTimeOfDayDescription("dawn", ({
        ". At dawn, the smelter's fires are stoked and the first workers arrive",
        ". The air is already thick with smoke and the scent of hot metal"
        }));

    addTimeOfDayDescription("morning", ({
        ". In the morning, the smelter is alive with the sound of bellows and "
        "the roar of the furnaces",
        ". Workers feed ore into the fires and pour molten metal into molds"
        }));

    addTimeOfDayDescription("noon", ({
        ". At midday, the smelter is hot and noisy, with workers pausing for a "
        "meal in the shade",
        ". The heat from the furnaces is intense, and the air shimmers with it"
        }));

    addTimeOfDayDescription("afternoon", ({
        ". In the afternoon, the smelter's output is at its peak, with "
        "finished ingots cooling on racks",
        ". The sound of metal on metal echoes through the building"
        }));

    addTimeOfDayDescription("evening", ({
        ". As evening falls, the fires are banked and the last ingots are set "
        "aside to cool",
        ". The smelter quiets as workers finish their shift and leave"
        }));

    addTimeOfDayDescription("dusk", ({
        ". At dusk, the smelter glows with the last light of the furnaces, "
        "casting long shadows",
        ". The clang of hammers slows as the day comes to an end"
        }));

    addTimeOfDayDescription("night", ({
        ". By night, the smelter is quiet, its fires banked and the building "
        "watched by a lone night watchman",
        ". The air is still warm from the day's work, and the scent of smoke "
        "lingers"
        }));

    addSeasonDescription("spring", ({
        " with new ore arriving and the promise of a busy season ahead",
        " as the smelter prepares to supply the needs of the growing town"
        }));

    addSeasonDescription("summer", ({
        " with the heat inside rivaling the sun outside",
        " as the smelter works long hours to meet demand"
        }));

    addSeasonDescription("autumn", ({
        " with orders for tools and ingots for the harvest",
        " as the smelter produces metal goods for the coming winter"
        }));

    addSeasonDescription("winter", ({
        " with snow piled against the walls and the smelter's fires burning "
        "brightly inside",
        " as the smelter produces stoves and tools to help the town endure "
        "the cold"
        }));

    addNearDarkDescriptionTemplate(
        "a stone smelter with glowing windows and a smoky haze"
    );
    addLowLightDescriptionTemplate(
        "a smelter with sooty walls, glowing furnaces, and stacks of ore"
    );
    addDimLightDescriptionTemplate(
        "an industrial smelter with racks of ingots and the scent of smoke"
    );
    addSomeLightDescriptionTemplate(
        "a noisy smelter with glowing furnaces, ingots, and busy workers"
    );

    addItemTemplate(
        "The smelter is a large, stone building with thick walls and tall "
        "chimneys. Inside, glowing furnaces and stacks of ore fill the air "
        "with heat and noise. Workers pour molten metal into molds and stack "
        "finished ingots on heavy racks. The smelter is a place of industry, "
        "strength, and the constant rhythm of metalwork."
    );

    addSourceOfLight(2);
}
