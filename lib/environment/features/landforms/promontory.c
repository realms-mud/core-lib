//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("promontory");
    addAdjectives(({ "jutting", "windswept", "elevated", "panoramic", "dramatic",
        "protruding", "exposed", "commanding", "rocky", "isolated" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({
        " where the rising sun bathes the outstretched formation in first light, "
        "creating a golden island above a sea of shadow below",
        " where morning mist often surrounds the base, enhancing the sense of "
        "a projection into space, disconnected from the world below"
        }));
    addTimeOfDayDescription("morning", ({
        " where the promontory stands fully revealed in morning light, its "
        "distinctive shape casting a moving shadow across the lands beneath",
        " where birds ride air currents around its edges and the warming stone "
        "releases the scents of herbs and lichens into the clear air"
        }));
    addTimeOfDayDescription("noon", ({
        " where the exposed position offers no shelter from the sun's full "
        "strength, the rock hot underfoot and the air shimmering with heat",
        " where the shadow shrinks to little more than an outline directly beneath "
        "the outcropping, seemingly drawing the formation closer to the sky"
        }));
    addTimeOfDayDescription("afternoon", ({
        " where the westward face begins to glow with golden light while eastern "
        "aspects fall into shadow, enhancing the three-dimensional drama",
        " where the extended position captures cooling breezes, offering relief "
        "from the day's heat while providing unparalleled vistas"
        }));
    addTimeOfDayDescription("evening", ({
        " where sunset transforms the promontory into a platform of fire and gold, "
        "the last place to surrender the light as evening advances",
        " where the extended position creates a perfect viewpoint for watching "
        "the sun's descent, the world spread out below in all directions"
        }));
    addTimeOfDayDescription("dusk", ({
        " where the failing light outlines the jutting formation against the "
        "darkening sky, emphasizing its isolated projection from the main mass",
        " where the promontory seems to float as darkness claims the land below "
        "while the outcrop itself remains defined against the twilight sky"
        }));
    addTimeOfDayDescription("night", ({
        " where the promontory becomes a platform suspended between earth and sky, "
        "offering unobstructed views of stars in all directions",
        " where moonlight transforms the jutting formation into a silver island, "
        "the surrounding depths lost in shadow and mystery"
        }));
    addTimeOfDayDescription("late night", ({
        " where the extended position creates a profound sense of isolation, "
        "surrounded by darkness yet intimately connected to the night sky",
        " where the wind's voice changes as it encounters this interruption "
        "in its path, creating a unique song in the darkness"
        }));
    addTimeOfDayDescription("midnight", ({
        " where the deepest night emphasizes the vulnerability of this exposed "
        "position while also offering unparalleled communion with the stars",
        " where the division between earth and sky seems most tenuous, as if "
        "the promontory floats unconnected to either realm"
        }));

    // Seasonal Descriptions
    addSeasonDescription("winter", ({
        " where winter winds assail the exposed formation from all sides, sometimes "
        "creating snowdrifts in strange patterns unlike those on level ground",
        " where ice forms on windward surfaces and snow collects in depressions, "
        "transforming the rugged outcrop into a sculpture of white and stone"
        }));

    addSeasonDescription("spring", ({
        " where hardy plants emerge from cracks and crevices, creating surprising "
        "pockets of color against the weathered stone surface",
        " where migrating birds often rest on this landmark feature, using its "
        "elevation to survey the terrain before continuing their journey"
        }));

    addSeasonDescription("summer", ({
        " where the stone absorbs the sun's heat, creating a warm platform from "
        "which to view the world below through clear summer air",
        " where lizards bask on sun-warmed rocks and thermal updrafts create "
        "perfect conditions for soaring birds that nest in its crevices"
        }));

    addSeasonDescription("autumn", ({
        " where the promontory stands above a landscape transformed by autumn "
        "colors, offering views of the seasonal change spreading below",
        " where early morning frost forms delicate patterns across stone surfaces, "
        "melting quickly as the sun finds this elevated, exposed position"
        }));

    // Base Description Template
    addDescriptionTemplate("a ##Adjective## promontory extending boldly outward from the main terrain, creating a natural observation point that commands views in multiple directions and instills a profound sense of elevation and exposure");
}
