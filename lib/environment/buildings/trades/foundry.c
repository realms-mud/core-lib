//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("foundry");
    setFloorPlanType("trade");

    addAdjectives(({
        "smoky", "noisy", "iron", "sooty", "industrial", "massive"
        }));

    addDescriptionTemplate(
        "a ##Adjective## foundry with glowing furnaces and ringing anvils"
    );

    addTimeOfDayDescription("dawn", ({
        ". At dawn, the foundry's fires are stoked and the first workers "
        "arrive to begin their shift",
        ". The air is already thick with smoke and the clang of metal"
        }));

    addTimeOfDayDescription("morning", ({
        ". In the morning, the foundry is alive with the sound of hammers "
        "and the roar of the furnaces",
        ". Workers pour molten metal into molds and shape iron at the anvils"
        }));

    addTimeOfDayDescription("noon", ({
        ". At midday, the foundry is hot and noisy, with workers pausing "
        "briefly for a meal",
        ". The heat from the furnaces is intense, and the air shimmers "
        "with it"
        }));

    addTimeOfDayDescription("afternoon", ({
        ". In the afternoon, the foundry's output is at its peak, with "
        "finished castings cooling on racks",
        ". The sound of metal on metal echoes through the building"
        }));

    addTimeOfDayDescription("evening", ({
        ". As evening falls, the fires are banked and the last castings "
        "are set aside to cool",
        ". The foundry quiets as workers finish their shift and leave"
        }));

    addTimeOfDayDescription("dusk", ({
        ". At dusk, the foundry glows with the last light of the furnaces, "
        "casting long shadows",
        ". The clang of hammers slows as the day comes to an end"
        }));

    addTimeOfDayDescription("night", ({
        ". By night, the foundry is quiet, its fires banked and the "
        "building watched by a lone night watchman",
        ". The air is still warm from the day's work, and the scent of "
        "smoke lingers"
        }));

    addSeasonDescription("spring", ({
        " with new orders for tools and implements arriving from the fields",
        " as the foundry prepares to supply the needs of the growing season"
        }));

    addSeasonDescription("summer", ({
        " with the heat inside rivaling the sun outside",
        " as the foundry works long hours to meet the demands of the busy "
        "season"
        }));

    addSeasonDescription("autumn", ({
        " with orders for plows and tools for the harvest",
        " as the foundry produces iron goods for the coming winter"
        }));

    addSeasonDescription("winter", ({
        " with snow piled against the walls and the foundry's fires burning "
        "brightly inside",
        " as the foundry produces stoves and tools to help the town endure "
        "the cold"
        }));

    addNearDarkDescriptionTemplate(
        "a massive foundry with glowing windows and a smoky haze"
    );
    addLowLightDescriptionTemplate(
        "a foundry with sooty walls, glowing furnaces, and ringing anvils"
    );
    addDimLightDescriptionTemplate(
        "an iron foundry with stacks of metal and the scent of smoke"
    );
    addSomeLightDescriptionTemplate(
        "a noisy foundry with glowing furnaces, anvils, and busy workers"
    );

    addItemTemplate(
        "The foundry is a large, iron-framed building with thick stone walls "
        "and tall chimneys. Inside, glowing furnaces and ringing anvils fill "
        "the air with heat and noise. Workers pour molten metal into molds, "
        "shape iron at the anvils, and stack finished goods on heavy racks. "
        "The foundry is a place of industry, strength, and the constant "
        "rhythm of metalwork."
    );

    addSourceOfLight(2);
}
