//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("dell");
    addAdjectives(({ "hidden", "shaded", "peaceful", "secluded", "quiet", "wooded", "lush" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({
        " where the first light of day filters through the canopy, casting dappled shadows on the soft moss-covered ground and revealing hidden corners of the dell",
        " where the world begins to stir in the cool morning air, the gentle light creeping through the trees to reveal the peaceful beauty of the dell"
        }));
    addTimeOfDayDescription("morning", ({
        " where the morning sun gently pierces through the leaves, casting soft rays onto the lush undergrowth, and the air is still, filled with the scent of damp earth",
        " where the forest is alive with the sound of birdsong and the soft rustle of leaves, and the dell feels like a hidden paradise waking to the day"
        }));
    addTimeOfDayDescription("noon", ({
        " where the bright midday sun shines directly into the dell, casting clear light on the trees and the fern-covered floor, while the air is warm and still",
        " where the dell feels both secluded and alive, the midday sun filtered through the dense trees, creating pockets of light and shade across the ground"
        }));
    addTimeOfDayDescription("afternoon", ({
        " where the sun begins to dip behind the trees, casting long shadows and softening the light in the dell, creating an atmosphere of quiet serenity",
        " where the air cools slightly, and the dell seems even more peaceful as the shadows of the trees stretch over the mossy ground"
        }));
    addTimeOfDayDescription("evening", ({
        " where the light of the setting sun filters softly through the trees, the dell bathed in golden hues, and the world seems to slow down, peaceful and quiet",
        " where the dell is filled with the soft rustling of leaves in the evening breeze, and the sky takes on warm, muted colors as the day winds down"
        }));
    addTimeOfDayDescription("dusk", ({
        " where the last light of day fades, and the dell becomes wrapped in soft twilight, with the sounds of evening creatures slowly coming to life",
        " where the dell is quiet, the light fading into cool tones as the world shifts into night, and the air feels thick with the scent of earth and foliage"
        }));
    addTimeOfDayDescription("night", ({
        " where the dell is enveloped in the stillness of night, the trees casting long, dark shadows and the stars above twinkling in the clear sky",
        " where the air is cool and still, the only sounds are the occasional rustle of leaves or a distant owl, and the dell feels deep in its quiet solitude"
        }));
    addTimeOfDayDescription("late night", ({
        " where the dell lies in complete silence, the cool night air settling on the leaves and the earth, with only the moonlight filtering through the trees",
        " where the world is asleep, and the dell is bathed in the soft glow of moonlight, with the quiet stillness broken only by the occasional movement in the undergrowth"
        }));
    addTimeOfDayDescription("midnight", ({
        " where the dell is cloaked in darkness, the trees towering overhead like silent guardians, and the only light is the faint glow of distant stars",
        " where the dell is a secret place, hidden beneath the night sky, with only the whisper of the wind and the soft rustling of branches disturbing the silence"
        }));

    // Seasonal Descriptions
    addSeasonDescription("winter", ({
        " where the dell is quiet and still, a blanket of snow covering the ground, the trees bare and frosted, and the air crisp and cold",
        " where the cold settles over the dell, the soft snow muffling sounds and the trees standing like silent sentinels in the winter stillness"
        }));

    addSeasonDescription("spring", ({
        " where new life begins to emerge, with bright green shoots and delicate flowers sprouting from the soft earth, and the air is fresh with the scent of blooming blossoms",
        " where the dell awakens with a gentle breeze, the trees coming into leaf and the ground covered with fresh, dewy grass and flowers in full bloom"
        }));

    addSeasonDescription("summer", ({
        " where the dell is lush and full of life, the trees thick with leaves and the undergrowth dense, and the air is warm and filled with the sound of insects and birds",
        " where the heat of summer brings a rich, green fullness to the dell, the leaves rustling softly in the warm air and the ground soft with damp earth"
        }));

    addSeasonDescription("autumn", ({
        " where the leaves turn brilliant shades of red, orange, and gold, the ground covered with fallen leaves, and the air becomes cool and crisp",
        " where the dell feels quiet and contemplative, the trees shedding their leaves in a colorful display, and the scent of earth and decay fills the air"
        }));

    // Base Description Template
    addDescriptionTemplate("a ##Adjective## dell, nestled in a secluded hollow, shaded by ancient trees and filled with soft moss, wildflowers, and the gentle sounds of nature");
}
