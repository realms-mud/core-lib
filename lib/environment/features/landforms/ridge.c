//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("ridge");
    addAdjectives(({ "narrow", "serrated", "winding", "exposed", "knife-edge",
        "undulating", "precipitous", "windy", "hazardous", "elevated" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({
        " where early light creates a dramatic interplay of illumination and shadow "
        "along both sides of the linear elevation, emphasizing its knife-edge quality",
        " where morning mist often clings to the slopes below while the ridge itself "
        "stands clear, appearing to float above a clouded sea"
        }));
    addTimeOfDayDescription("morning", ({
        " where the rising sun casts the ridge's shadow far to the west, creating "
        "a moving line that traces the formation's distinctive profile",
        " where birds ride thermals rising along its flanks, their flight paths "
        "following the natural highway created by this elevated spine"
        }));
    addTimeOfDayDescription("noon", ({
        " where midday light eliminates most shadows, transforming the ridge into "
        "a clearly defined line against the landscape, every detail exposed",
        " where the elevated path offers little shelter from sun or elements, the "
        "full heat of day tempered only by the constant wind"
        }));
    addTimeOfDayDescription("afternoon", ({
        " where the western slope catches rich afternoon light while the eastern "
        "face falls into shadow, emphasizing the ridge's dividing nature",
        " where travelers moving along its length cast long shadows that sometimes "
        "fall away into space on either side of the narrow path"
        }));
    addTimeOfDayDescription("evening", ({
        " where sunset transforms the ridge into a glowing line of fire as the "
        "last light catches its highest points while valleys darken",
        " where the elevated spine stands silhouetted against the evening sky, "
        "its jagged profile creating a distinctive horizon line"
        }));
    addTimeOfDayDescription("dusk", ({
        " where the failing light reduces the ridge to its essential form, a dark "
        "line against the deepening blue, its details lost to shadow",
        " where navigation becomes treacherous as visibility diminishes, the drop "
        "on either side an increasing presence felt more than seen"
        }));
    addTimeOfDayDescription("night", ({
        " where moonlight creates a silvery path along the ridge's spine, with "
        "darkness pooling in the depths on either side",
        " where the ridge becomes a narrow bridge between stars above and void "
        "below, a precarious path suspended in night"
        }));
    addTimeOfDayDescription("late night", ({
        " where the narrow path seems most isolated, a tenuous line traced between "
        "two darker voids, requiring careful movement in limited visibility",
        " where the wind's voice changes as it encounters this obstacle, creating "
        "moaning sounds that add to the sense of exposure and isolation"
        }));
    addTimeOfDayDescription("midnight", ({
        " where the deepest night conceals the drops on either side without "
        "diminishing awareness of their presence, a balance felt in every step",
        " where stars wheel overhead while the ridge itself becomes a pathway of "
        "deeper darkness, a line drawn through the night landscape"
        }));

    // Seasonal Descriptions
    addSeasonDescription("winter", ({
        " where snow cornices form along the edge, deceptively extending the "
        "apparent width while actually creating treacherous false footing",
        " where ice coats exposed rock and wind-sculpted snow forms elegant curves "
        "and dangerous slick surfaces along the narrow path"
        }));

    addSeasonDescription("spring", ({
        " where snowmelt reveals the true path again and first wildflowers emerge "
        "in protected pockets, adding unexpected color to the stark elevation",
        " where new growth on the slopes below creates a vivid contrast with the "
        "weathered stone of the ridge itself, still bearing winter's marks"
        }));

    addSeasonDescription("summer", ({
        " where the ridge offers a cooler route through the landscape, catching "
        "breezes that don't reach the valleys on either side",
        " where the exposed stone radiates accumulated heat and shimmers in the "
        "clear air, creating mirages that distort distant views"
        }));

    addSeasonDescription("autumn", ({
        " where the first frosts touch the ridge before the lands below, and wind "
        "whips fallen leaves along its length in spiraling patterns",
        " where the changing colors spread across the slopes on either side, viewed "
        "as if from a natural balcony suspended above the seasonal transformation"
        }));

    // Base Description Template
    addDescriptionTemplate("a ##Adjective## ridge extending like a spine across the landscape, its narrow top creating a natural but often precarious pathway with slopes falling away on both sides, offering expansive views and a keen sense of exposure");
}
