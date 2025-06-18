//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("distillery");
    setFloorPlanType("trade");

    addAdjectives(({
        "stone", "busy", "aromatic", "smoky", "well-built", "industrial"
        }));

    addDescriptionTemplate(
        "a ##Adjective## distillery with tall copper stills and a stone chimney"
    );

    addTimeOfDayDescription("dawn", ({
        ". At dawn, the distillery's fires are already burning, and the "
        "air is thick with the scent of mash",
        ". Workers begin their day tending the stills and preparing barrels"
        }));

    addTimeOfDayDescription("morning", ({
        ". In the morning, the distillery is busy with workers moving "
        "grain and checking the bubbling vats",
        ". The sound of clinking bottles and the smell of fermenting "
        "grain fill the air"
        }));

    addTimeOfDayDescription("noon", ({
        ". At midday, the distillery is warm and humid, with sunlight "
        "streaming through high windows",
        ". Workers pause for a meal among the barrels and crates"
        }));

    addTimeOfDayDescription("afternoon", ({
        ". In the afternoon, the distillery is filled with the rhythmic "
        "sound of coopers hammering staves",
        ". The scent of spirits grows stronger as the day's work continues"
        }));

    addTimeOfDayDescription("evening", ({
        ". As evening falls, the fires are banked and the last barrels "
        "are rolled into storage",
        ". The distillery quiets as workers finish their tasks and prepare "
        "to leave"
        }));

    addTimeOfDayDescription("dusk", ({
        ". At dusk, the distillery glows with the last light of the fires, "
        "casting long shadows",
        ". The day's work winds down, and the scent of spirits lingers in "
        "the air"
        }));

    addTimeOfDayDescription("night", ({
        ". By night, the distillery is quiet, its fires banked and the "
        "building watched by a lone night watchman",
        ". The stone walls hold the day's warmth, and the scent of "
        "distilled spirits hangs in the air"
        }));

    addSeasonDescription("spring", ({
        " with fresh grain arriving for the first batches of the year",
        " as the distillery prepares special spirits for spring festivals"
        }));

    addSeasonDescription("summer", ({
        " with open doors letting in warm air and the sound of busy "
        "workers",
        " as barrels are filled and stored for aging in the heat"
        }));

    addSeasonDescription("autumn", ({
        " with the scent of apples and late grain in the air",
        " as the distillery works overtime to process the harvest"
        }));

    addSeasonDescription("winter", ({
        " with snow piled against the stone walls and the fires burning "
        "brightly inside",
        " as the distillery produces warming spirits for the cold season"
        }));

    addNearDarkDescriptionTemplate(
        "a stone distillery with a tall chimney and faintly glowing windows"
    );
    addLowLightDescriptionTemplate(
        "a distillery with copper stills and the scent of spirits in the air"
    );
    addDimLightDescriptionTemplate(
        "an aromatic distillery with barrels stacked along the walls"
    );
    addSomeLightDescriptionTemplate(
        "a busy distillery with copper stills, stone floors, and a smoky haze"
    );

    addItemTemplate(
        "The distillery is a sturdy stone building with a tall chimney and "
        "rows of copper stills. Inside, barrels and crates are stacked high, "
        "and the air is thick with the scent of fermenting grain and "
        "distilled spirits. Workers tend the fires and check the bubbling "
        "vats, while coopers assemble barrels for aging. The distillery is "
        "a place of industry, warmth, and the promise of strong drink."
    );

    addSourceOfLight(2);
}
