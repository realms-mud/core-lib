//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("glen");
    addAdjectives(({ "narrow", "secluded", "wooded", "misty", "serene", "lush", "quiet", "hidden" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({
        " where a soft mist clings to the trees and the brook that runs through the glen reflects the pale light of early morning",
        " where the first hints of light filter through the trees, casting faint silver glows on the dewy grass and moss-covered stones"
        }));
    addTimeOfDayDescription("morning", ({
        " where the sun begins to rise over the glen's steep sides, lighting the treetops while the floor remains cool and shadowed",
        " where birdsong echoes gently through the quiet valley, and the glen awakens slowly to the warmth of morning"
        }));
    addTimeOfDayDescription("noon", ({
        " where the sunlight reaches the heart of the glen, warming the stream's surface and bringing out the deep greens of the foliage",
        " where dappled light dances through the leaves, and the quiet rush of water blends with the hum of summer insects"
        }));
    addTimeOfDayDescription("afternoon", ({
        " where the glen is bathed in golden light, shadows lengthening across the mossy ground and the stream glistening in the waning sun",
        " where the trees rustle gently in the soft breeze, and the glen feels timeless and still"
        }));
    addTimeOfDayDescription("evening", ({
        " where the sun sets behind the hills, casting the glen in cool shadow and bathing the treetops in a warm, fading glow",
        " where the glen grows quiet, and the fading light gives the narrow valley a mysterious, peaceful air"
        }));
    addTimeOfDayDescription("dusk", ({
        " where twilight wraps the glen in soft blue-grey light, the brook reflecting the last colors of the day as the world hushes",
        " where the valley darkens beneath the encroaching night, the trees becoming silhouettes against a fading sky"
        }));
    addTimeOfDayDescription("night", ({
        " where the glen lies quiet under a blanket of stars, the stream whispering softly in the darkness and the trees looming like watchful guardians",
        " where moonlight filters through the canopy, glinting off damp rocks and casting pale reflections in the stream"
        }));
    addTimeOfDayDescription("late night", ({
        " where the glen is completely still, the air cool and damp, with only the soft murmur of water and the occasional hoot of an owl",
        " where darkness gathers thick in the narrow valley, the stream's course marked only by its faint glimmer and gurgle"
        }));
    addTimeOfDayDescription("midnight", ({
        " where the glen feels untouched by time, the only illumination the faint gleam of moonlight on leaves and water",
        " where the steep hillsides and trees vanish into shadow, and the stream is a silver thread beneath the stars"
        }));

    // Seasonal Descriptions
    addSeasonDescription("winter", ({
        " where a thin layer of snow coats the ground and the stream runs dark between banks of frost-covered moss",
        " where bare trees line the glen and the air is cold and still, with ice forming at the water's edge"
        }));

    addSeasonDescription("spring", ({
        " where the glen comes to life with the sound of rushing water, blooming wildflowers, and the bright green of new leaves",
        " where the scent of fresh earth and growing things fills the air, and small birds flit between budding branches"
        }));

    addSeasonDescription("summer", ({
        " where the glen is lush and vibrant, the canopy thick with leaves, and the brook sparkles in the warm sunlight",
        " where cool shade offers refuge from the heat, and the glen hums with bees and birdsong"
        }));

    addSeasonDescription("autumn", ({
        " where fallen leaves carpet the ground in reds and golds, and the stream runs clear beneath the turning trees",
        " where the air is crisp, and the glen feels hushed and reflective, touched by the season's fading light"
        }));

    // Base Description Template
    addDescriptionTemplate("a ##Adjective## glen, nestled between steep wooded slopes, where a narrow brook winds through mossy rocks and the air is cool and still");
}
