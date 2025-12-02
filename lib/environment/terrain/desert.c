//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/terrain/baseTerrain.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("desert");
    addAdjectives(({
        "vast desert of rolling dunes",
        "arid expanse of sun-baked sand",
        "windswept desert where the horizon shimmers with heat",
        "barren wasteland of cracked earth and scattered stones",
        "endless sea of sand stretching beneath a cloudless sky",
        "desolate desert where only the hardiest life survives",
        "scorched landscape marked by the tracks of elusive creatures",
        "sun-bleached desert with sparse, thorny vegetation",
        "harsh desert where the wind carves ripples in the sand",
        "lonely desert where silence reigns under the blazing sun"
        }));

    addTimeOfDayDescription("dawn", ({
        " bathed in the cool, pale light of early morning",
        " where long shadows stretch across the dunes",
        " as the first rays of sun begin to warm the sand",
        " with a gentle breeze stirring the surface",
        " where the desert awakens from the chill of night"
        }));

    addTimeOfDayDescription("morning", ({
        " growing brighter as the sun climbs higher",
        " with the sand beginning to radiate heat",
        " where mirages shimmer in the distance",
        " as the desert comes alive with the movement of early creatures"
        }));

    addTimeOfDayDescription("noon", ({
        " under the relentless glare of the midday sun",
        " where the heat is nearly unbearable",
        " with the sand too hot to touch",
        " as the air shimmers with rising waves of heat"
        }));

    addTimeOfDayDescription("afternoon", ({
        " as the sun continues its scorching journey",
        " with the landscape wavering in the heat",
        " where the wind picks up, sending sand swirling",
        " as shadows begin to lengthen across the dunes"
        }));

    addTimeOfDayDescription("evening", ({
        " cooling as the sun sinks toward the horizon",
        " with the sky ablaze in hues of orange and red",
        " as the desert prepares for the chill of night",
        " where the wind calms and silence deepens"
        }));

    addTimeOfDayDescription("dusk", ({
        " as the last light fades from the sky",
        " with the sand cooling rapidly",
        " where the desert takes on a mysterious, muted beauty",
        " as nocturnal creatures begin to stir"
        }));

    addTimeOfDayDescription("night", ({
        " under a canopy of countless stars",
        " where the temperature drops sharply",
        " with the sand cold and the air still",
        " as the desert becomes a realm of shadows and silence"
        }));

    addTimeOfDayDescription("late night", ({
        " shrouded in deep silence",
        " where the moon casts long, eerie shadows",
        " as the desert seems endless and empty",
        " with only the faintest sounds of life"
        }));

    addTimeOfDayDescription("midnight", ({
        " in utter darkness save for the stars",
        " where the desert is at its coldest and most silent",
        " as the world seems paused beneath the night sky"
        }));

    addSeasonDescription("winter", ({
        " with cold nights and mild days",
        " where frost sometimes forms on the sand",
        " as the desert endures the harshest season"
        }));

    addSeasonDescription("spring", ({
        " with rare blooms of hardy desert flowers",
        " as life briefly flourishes after scarce rains",
        " where the air is filled with the scent of new growth"
        }));

    addSeasonDescription("summer", ({
        " at its hottest and driest",
        " where the sun is merciless and shade is rare",
        " as the desert tests the limits of endurance"
        }));

    addSeasonDescription("autumn", ({
        " with cooler nights and gentler days",
        " as the desert prepares for the coming cold",
        " where the wind carries the scent of distant change"
        }));

    addDescriptionTemplate("a ##Adjective##");
    addNearDarkDescriptionTemplate("a pitch-black desert where only the stars and moon offer guidance");
    addLowLightDescriptionTemplate("a barely-lit desert where dunes are little more than shadows");
    addDimLightDescriptionTemplate("a dimly-lit desert where the sand glows faintly in the gloom");
    addSomeLightDescriptionTemplate("a sunlit desert where every grain of sand is illuminated");
}
