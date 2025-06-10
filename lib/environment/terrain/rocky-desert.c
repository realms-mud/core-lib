//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/terrain/baseTerrain.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("rocky desert");

    addAdjectives(({
        "arid rocky desert with scattered boulders and hardy shrubs",
        "expanse of sun-bleached rocks and coarse sand",
        "desolate landscape of jagged stones and sparse vegetation",
        "windswept desert where rocky outcrops break the horizon",
        "barren terrain dotted with spiny bushes and cacti",
        "sun-baked ground littered with pebbles and ancient stones",
        "harsh desert where the wind whistles between rugged rocks",
        "vast plain of gravel, sand, and scattered Joshua trees",
        "rock-strewn desert where lizards dart between the stones",
        "open desert with distant mountains shimmering in the heat"
        }));

    addTimeOfDayDescription("dawn", ({
        " bathed in the cool, pink light of early morning",
        " where long shadows stretch across the rocks",
        " as the first rays of sun glint off the stony ground"
        }));

    addTimeOfDayDescription("morning", ({
        " growing brighter as the sun rises over the desert",
        " with the rocks warming quickly under the clear sky",
        " as small animals emerge to bask in the gentle heat"
        }));

    addTimeOfDayDescription("noon", ({
        " under the relentless glare of the midday sun",
        " where the heat is intense and the air shimmers",
        " as the ground radiates waves of heat"
        }));

    addTimeOfDayDescription("afternoon", ({
        " as the sun beats down on the parched earth",
        " with the landscape wavering in the heat",
        " where the wind picks up, sending sand and dust swirling"
        }));

    addTimeOfDayDescription("evening", ({
        " cooling as the sun sinks toward the horizon",
        " with the sky ablaze in hues of orange and red",
        " as the desert prepares for the chill of night"
        }));

    addTimeOfDayDescription("dusk", ({
        " as the last light fades from the sky",
        " with the rocks casting long, deep shadows",
        " as nocturnal creatures begin to stir"
        }));

    addTimeOfDayDescription("night", ({
        " under a canopy of countless stars",
        " where the temperature drops sharply",
        " as the desert becomes a realm of shadows and silence"
        }));

    addTimeOfDayDescription("late night", ({
        " shrouded in deep silence",
        " where the moon casts long, eerie shadows",
        " as the desert seems endless and empty"
        }));

    addTimeOfDayDescription("midnight", ({
        " in utter darkness save for the stars",
        " where the desert is at its coldest and most silent"
        }));

    addSeasonDescription("winter", ({
        " with cold nights and mild days",
        " where frost sometimes forms on the rocks",
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
    addNearDarkDescriptionTemplate("a pitch-black rocky desert where only the stars and moon offer guidance");
    addLowLightDescriptionTemplate("a barely-lit rocky desert where boulders are little more than shadows");
    addDimLightDescriptionTemplate("a dimly-lit rocky desert where the stones glow faintly in the gloom");
    addSomeLightDescriptionTemplate("a sunlit rocky desert where every rock and shrub is illuminated");
}
