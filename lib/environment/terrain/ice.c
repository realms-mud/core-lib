//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/terrain/baseTerrain.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("icy plateau");

    addAdjectives(({
        "windswept icy plateau stretching to the horizon",
        "bleak expanse of ice and snow",
        "frozen plateau with jagged outcrops of blue ice",
        "desolate ice field where the wind howls endlessly",
        "glittering plateau of hard-packed snow and ice",
        "frigid plain where frost clings to every surface",
        "vast, barren plateau with little shelter from the cold",
        "icy wilderness where the sun glints off endless white",
        "plateau where snowdrifts form sculpted ridges",
        "frozen wasteland where the air bites with every breath"
        }));

    addTimeOfDayDescription("dawn", ({
        " bathed in the pale pink light of sunrise",
        " where the first rays of sun sparkle on the ice",
        " as the cold air seems even sharper in the early light"
        }));

    addTimeOfDayDescription("morning", ({
        " with the sun rising over the frozen expanse",
        " as the ice glitters beneath a clear sky",
        " where the wind picks up, swirling snow across the plateau"
        }));

    addTimeOfDayDescription("noon", ({
        " under the harsh glare of the midday sun",
        " where the ice reflects blinding light in every direction",
        " as the cold remains unyielding despite the sun"
        }));

    addTimeOfDayDescription("afternoon", ({
        " as the sun slants across the plateau",
        " with long shadows stretching over the snow",
        " where the wind grows stronger and colder"
        }));

    addTimeOfDayDescription("evening", ({
        " glowing with the last light of day",
        " as the temperature drops rapidly",
        " where the sky turns brilliant shades of orange and purple"
        }));

    addTimeOfDayDescription("night", ({
        " under a sky filled with shimmering stars",
        " where the cold is at its most intense",
        " as the plateau is bathed in moonlight on the snow"
        }));

    addSeasonDescription("winter", ({
        " locked in deep freeze, with snow and ice everywhere",
        " where blizzards are common and the cold is relentless"
        }));

    addSeasonDescription("spring", ({
        " with slightly milder winds and patches of exposed rock",
        " as the snow softens and the days grow longer"
        }));

    addSeasonDescription("summer", ({
        " with long days and a dazzling sun, but still bitterly cold",
        " where the ice glistens under nearly endless daylight"
        }));

    addSeasonDescription("autumn", ({
        " as the winds grow colder and the snow deepens",
        " where the plateau prepares for the long winter ahead"
        }));

    addDescriptionTemplate("an ##Adjective##");
    addNearDarkDescriptionTemplate("a pitch-black icy plateau where only the stars and moon offer guidance");
    addLowLightDescriptionTemplate("a barely-lit icy plateau where snow and ice are little more than shadows");
    addDimLightDescriptionTemplate("a dimly-lit icy plateau where the ground glows faintly in the gloom");
    addSomeLightDescriptionTemplate("an icy plateau where every snowdrift and ridge is illuminated");
}
