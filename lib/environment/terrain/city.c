//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/terrain/baseTerrain.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("city");
    addAdjectives(({
        "bustling city with narrow streets and timber-framed buildings",
        "walled city where cobblestone streets wind between stone and timber structures",
        "crowded urban center with buildings leaning precariously over cramped alleys",
        "budding city where centuries of history are layered in stone and wood",
        "lively settlement surrounded by imposing stone walls",
        "sprawling city with a maze of streets radiating from the central square",
        "fortified urban center where merchant stalls line the main thoroughfares",
        "city with guild halls and workshops humming with constant activity",
        "densely packed city where buildings crowd together behind protective walls",
        "thriving urban center where church spires and guild halls dominate the skyline",
        "city with streets packed with traders, craftsmen and local residents",
        "winding warren of narrow streets and crooked buildings within ancient walls",
        "historic city where every stone and timber tells tales of bygone eras",
        "vibrant urban landscape alive with the sounds of commerce and daily life"
        }));

    addTimeOfDayDescription("dawn", ({
        " where early morning light gradually illuminates the city walls and towers",
        " just awakening as bakers light their ovens and street vendors begin to set up",
        " wrapped in the new morn's light as apprentices unshutter workshops",
        " where the first rays catch the weathered stone of church spires and towers",
        " stirring to life as roosters crow and early risers begin their daily tasks",
        " with dew glistening on cobblestones before the day's traffic wears it away"
        }));

    addTimeOfDayDescription("morning", ({
        " bustling with morning activity as merchants open their shops",
        " alive with the calls of traders and the clatter of cart wheels on stone",
        " where sunlight streams between buildings, illuminating narrow streets",
        " filled with the aromas of fresh bread and the sounds of craftsmen at work",
        " with city guards changing shifts at the gates and along the walls",
        " where children dart between adults on their way to chores or apprenticeships"
        }));

    addTimeOfDayDescription("noon", ({
        " at its most crowded as citizens fill the streets and marketplaces",
        " where the midday bells ring out across the bustling squares",
        " with taverns filling as workers break for their midday meal",
        " where the sun beats down on stone walls and tiled roofs",
        " alive with the peak of commerce as goods change hands in the market",
        " where the smells of cooking food waft from homes and eating houses"
        }));

    addTimeOfDayDescription("afternoon", ({
        " continuing its busy pace as merchants call the day's final bargains",
        " where shadows lengthen across the cobblestones and guild halls",
        " with a steady flow of traffic through the city gates before they close",
        " where apprentices clean workshops as the day's work winds down",
        " filled with the sounds of craftsmen completing their daily tasks",
        " where children play in side streets as the day's heat begins to wane"
        }));

    addTimeOfDayDescription("evening", ({
        " where lamplighters begin their rounds, bringing light to darkening streets",
        " as shop windows close and tavern doors open to the night's revelers",
        " with the city guard increasing their patrols as night approaches",
        " where cooking fires send smoke curling above countless chimneys",
        " as workers return home while merchants count their day's earnings",
        " with a gentle bustle as daily commerce gives way to evening leisure"
        }));

    addTimeOfDayDescription("dusk", ({
        " where shadows deepen between buildings as daylight fades",
        " with streets emptying as citizens retreat to homes and taverns",
        " where torches and lanterns create pools of light in the growing darkness",
        " as the city gates close with a final toll of the bell",
        " with the silhouettes of towers and spires sharp against the darkening sky",
        " as night watchmen take up their positions along the quieting streets"
        }));

    addTimeOfDayDescription("night", ({
        " where lanterns cast islands of light in the darkness between buildings",
        " with most windows shuttered though light leaks around the edges",
        " where watchmen patrol with torches, their footsteps echoing on stone",
        " as taverns spill light, music, and occasionally rowdy patrons into the street",
        " with most citizens safely behind locked doors while others conduct night business",
        " where only the occasional shadowy figure hurries along deserted alleys"
        }));

    addTimeOfDayDescription("late night", ({
        " where silence reigns except for the call of nightwatchmen marking the hour",
        " with empty streets save for stray cats and the occasional night traveler",
        " where distant laughter from late-open taverns breaks the quiet",
        " as most buildings stand dark and silent under the night sky",
        " with shuttered windows and barred doors keeping danger at bay",
        " where even the taverns have closed, leaving the streets to shadows"
        }));

    addTimeOfDayDescription("midnight", ({
        " silent under the stars with only guards and thieves abroad",
        " where moonlight creates a silvery landscape of rooftops and towers",
        " with streets empty save for the occasional patrol with lanterns",
        " standing quiet while citizens sleep behind locked doors",
        " where shadows seem deepest and silence most complete",
        " with an otherworldly quality as if the past and present overlap"
        }));

    addSeasonDescription("winter", ({
        " with snow blanketing rooftops and turning narrow streets to slush",
        " where smoke rises from countless chimneys into the cold winter air",
        " silent under a layer of snow that muffles the usual urban clamor",
        " with icicles hanging from eaves and citizens hurrying against the cold",
        " where braziers burn at guard posts and market stalls to ward off frost",
        " huddled against the bitter wind that whistles between buildings"
        }));

    addSeasonDescription("spring", ({
        " where new growth appears in window boxes and tiny gardens",
        " bustling with renewed energy as winter's grip loosens",
        " with streets muddy from spring rains and increased foot traffic",
        " where vendors sell the first flowers and fresh produce of the season",
        " as citizens clean winter's grime from facades and cobblestones",
        " with doors thrown open to welcome the warm breeze after winter's chill"
        }));

    addSeasonDescription("summer", ({
        " where activity shifts to shaded areas as citizens seek relief from heat",
        " with streets dusty from the summer drought and constant traffic",
        " where the scents of flowers mix with the less pleasant odors of urban life",
        " bustling despite the heat as commerce and life continue unabated",
        " with windows open to catch any breeze through stifling buildings",
        " where water carriers do brisk business on hot, crowded streets"
        }));

    addSeasonDescription("autumn", ({
        " with fallen leaves collecting in corners and clogging gutters",
        " where early evening mists make lanterns glow with haloes",
        " as merchants stock winter goods and citizens prepare for cold months",
        " with a crispness to the air as summer's heat gives way to autumn's chill",
        " where the smell of wood smoke begins to mingle with urban scents",
        " bustling with harvest activities and preparation for winter festivals"
        }));

    addDescriptionTemplate("a ##Adjective##");
    addNearDarkDescriptionTemplate("a darkened city where only faint outlines of buildings can be discerned against the night sky");
    addLowLightDescriptionTemplate("a dimly visible city where scattered lights from windows and occasional torches break the gloom");
    addDimLightDescriptionTemplate("a shadowy city where buildings loom as dark silhouettes and lit windows create patches of warm light");
    addSomeLightDescriptionTemplate("a city where sunlight illuminates the intricate tapestry of buildings, streets, and daily life");
}
