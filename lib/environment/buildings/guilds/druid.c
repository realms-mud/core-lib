//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("druid grove");
    InteriorType("sacred forest glade");
    setFloorPlanType("guild");

    addTimeOfDayDescription("dawn", ({
        ". The first light of dawn bathes the grove in soft golden hues, and the sound of birdsong fills the air"
        }));
    addTimeOfDayDescription("morning", ({
        ". The air is thick with the scent of damp earth and wildflowers as druids move through the trees, chanting softly"
        }));
    addTimeOfDayDescription("noon", ({
        ". Sunlight filters through the canopy, casting dappled light on the moss-covered stones and vibrant plant life"
        }));
    addTimeOfDayDescription("afternoon", ({
        ". The grove is alive with activity: squirrels leap between branches, deer graze in the distance, and the whisper of the wind through the leaves is almost rhythmic"
        }));
    addTimeOfDayDescription("evening", ({
        ". The colors of the sunset reflect off the surface of a nearby stream, and fireflies begin to dance in the twilight"
        }));
    addTimeOfDayDescription("dusk", ({
        ". The air cools, and the grove becomes quieter as the stars start to twinkle through the branches of ancient trees"
        }));
    addTimeOfDayDescription("night", ({
        " illuminated by the soft glow of bioluminescent plants and the gentle hum of nocturnal creatures, the grove feels peaceful and serene"
        }));
    addTimeOfDayDescription("late night", ({
        " still and tranquil, the grove filled with the soft rustle of leaves and the occasional hoot of an owl in the distance"
        }));
    addTimeOfDayDescription("midnight", ({
        " bathed in silver moonlight, the grove feels ancient, and the energy of the earth is palpable underfoot"
        }));

    addSeasonDescription("winter", ({
        " with snow lightly dusting the ground and frost creeping along the branches of trees, the grove remains peaceful, untouched by the cold"
        }));
    addSeasonDescription("spring", ({
        " bursting with new life-flowers bloom, buds sprout, and the air is fragrant with the scent of fresh growth"
        }));
    addSeasonDescription("summer", ({
        " lush and full of life, with thick, green foliage, buzzing bees, and the warm hum of nature in full bloom"
        }));
    addSeasonDescription("autumn", ({
        " with leaves turning vibrant shades of orange, red, and gold, and the ground covered in a soft carpet of fallen leaves"
        }));

    addSourceOfLight(4, "bioluminescent flora and moonlight", "night");

    addDescriptionTemplate("a sacred grove filled with ancient trees, magical plants, and peaceful wildlife");
    addNearDarkDescriptionTemplate("a shadowed grove, the moonlight filtering through the branches of towering trees");
    addLowLightDescriptionTemplate("a dimly lit forest clearing, filled with the sound of rustling leaves and distant creatures");
    addDimLightDescriptionTemplate("a mystical grove of towering trees, with patches of light from glowing plants and the soft sound of nature all around");
    addSomeLightDescriptionTemplate("a tranquil and vibrant grove, alive with nature's magic and the hum of the earth");
}
