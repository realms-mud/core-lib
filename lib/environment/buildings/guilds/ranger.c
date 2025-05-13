//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("Rangers Guild Hall");
    InteriorType("wooden hall nestled within a dense forest, with natural materials and vines intertwined with the structure");
    setFloorPlanType("outpost of wilderness protectors, built with natural materials like wood and stone");

    addTimeOfDayDescription("dawn", ({
        ". The first light of dawn filters through the dense canopy, casting long shadows across the wooden hall. The forest awakens, and the air is filled with the sounds of birds and rustling leaves"
        }));
    addTimeOfDayDescription("morning", ({
        ". Sunlight streams through the open windows, filling the hall with warmth as rangers prepare for their daily patrols. The smell of pine and fresh earth lingers in the air"
        }));
    addTimeOfDayDescription("noon", ({
        ". The sun is high, and the hall is alive with the sounds of rangers preparing for missions. Archery targets are set up in the clearing outside, and maps of the wilderness are sprawled across tables"
        }));
    addTimeOfDayDescription("afternoon", ({
        ". The forest outside is calm, the quiet sounds of nature filling the air as rangers return from their patrols or head out to track elusive prey or scout for threats"
        }));
    addTimeOfDayDescription("evening", ({
        ". As the sun sets, the guild hall fills with a soft, golden light, and rangers gather to share stories, review their findings, and plan their next expeditions into the wild"
        }));
    addTimeOfDayDescription("dusk", ({
        ". The forest is shrouded in a soft twilight, and the rangers return to the guild hall, their movements graceful and quiet as they bring in their day’s discoveries and prepare to rest"
        }));
    addTimeOfDayDescription("night", ({
        " when the guild hall is alive with the flickering light of fire pits and hearths. The rangers gather around to discuss their encounters, with the sounds of the forest providing a tranquil background"
        }));
    addTimeOfDayDescription("late night", ({
        " when the hall grows quieter, the embers of the fire fading as rangers prepare for the night’s rest. A sense of calm and peaceful vigilance settles over the guild"
        }));
    addTimeOfDayDescription("midnight", ({
        " when the guild hall is still, save for the occasional distant howl of a wolf or the hoot of an owl. The rangers rest, knowing the wilderness is always watching"
        }));

    addSeasonDescription("winter", ({
        " when the hall is snug against the cold, and the rangers prepare for winter patrols, their thick cloaks and tracking skills helping them navigate the harsh conditions"
        }));
    addSeasonDescription("spring", ({
        " when the guild hall is surrounded by fresh growth, the air is thick with the scent of blooming flowers, and the rangers begin their spring patrols, marking new trails and tracking the wildlife's return"
        }));
    addSeasonDescription("summer", ({
        " when the guild hall is lush and green, with the vibrant sounds of wildlife filling the air. Rangers head out into the wilderness to protect the land and track any disturbances in the forest"
        }));
    addSeasonDescription("autumn", ({
        " when the air grows crisp and the trees are painted with shades of red and gold. The rangers prepare for the season’s hunts and track the movement of creatures preparing for the winter"
        }));

    addSourceOfLight(6, "firelight, lanterns, and moonlight", "night");

    addDescriptionTemplate("a wooden hall nestled within the forest, with sturdy walls, open windows, and the scent of fresh pine and earth in the air, where rangers gather to rest and strategize");
    addNearDarkDescriptionTemplate("a silhouette of a hall framed by the dark forest, with flickering lights visible through the windows and the faint sound of the wilderness in the background");
    addLowLightDescriptionTemplate("a wooden building surrounded by towering trees, glowing with the light of torches and lanterns, where the rangers prepare to venture into the wild");
    addDimLightDescriptionTemplate("a hall surrounded by thick trees, the soft glow of firelight illuminating the stone walls, filled with the sounds of quiet conversation and nature beyond");
    addSomeLightDescriptionTemplate("a hall built into the heart of a forest, the interior alive with warmth and the scent of wood smoke, as rangers plan their next patrols or hunts");
}
