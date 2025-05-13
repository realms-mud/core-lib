//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("crag");
    addAdjectives(({ "wind-swept", "rocky", "towering", "rugged", "isolated" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({
        " where the first light of day casts long shadows across the rocky spires, revealing their sharp, imposing shapes against the soft sky",
        " where the crag glows faintly in the early light, its silhouette dark and sharp against the softening horizon"
        }));
    addTimeOfDayDescription("morning", ({
        " where the rising sun strikes the crag's cliffs with harsh light, highlighting their rough texture and sending long shadows down the slopes",
        " where the cool morning light brings out the stark beauty of the jagged rock faces, making the crag seem even more daunting"
        }));
    addTimeOfDayDescription("noon", ({
        " where the midday sun beats down on the crag, making the stone glow with heat, and casting little shade in the barren landscape",
        " where the crag's sharp features are silhouetted by the high sun, the rocks glistening with intensity"
        }));
    addTimeOfDayDescription("afternoon", ({
        " where the sun begins to dip, and the crag's edges are softened by the longer, more muted light of the late afternoon",
        " where the crag is bathed in a warm, golden hue as the sun lowers, but its roughness remains imposing"
        }));
    addTimeOfDayDescription("evening", ({
        " where the light fades quickly, casting the crag in deep shadows and turning the landscape into a study of dark rock and dusky air",
        " where the crag is enveloped in twilight, the sharp edges softened by the dimming light"
        }));
    addTimeOfDayDescription("dusk", ({
        " where the last remnants of light cling to the jagged cliffs, creating dramatic contrasts between the shadowed crag and the faint glow of the sky",
        " where the crag lies in the darkening quiet, its silhouette fading against the twilight"
        }));
    addTimeOfDayDescription("night", ({
        " where the crag stands stark and silent beneath the vast, starry sky, the jagged edges barely visible in the darkness",
        " where the night swallows the crag's harsh features, leaving it a shadowy, intimidating presence against the sky"
        }));
    addTimeOfDayDescription("late night", ({
        " where the crag looms in the still of the night, the only sound the occasional whisper of the wind between the rock faces",
        " where the crag feels even more isolated in the deep quiet of the night, the cold stone unyielding in the darkness"
        }));
    addTimeOfDayDescription("midnight", ({
        " where the crag is nothing more than a silhouette against the endless expanse of stars, the moonlight casting a silver glow across its rugged surface",
        " where the crag is entirely dark, a mere shadow under the velvet sky, with no light to reveal its sharp features"
        }));

    // Seasonal Descriptions
    addSeasonDescription("winter", ({
        " where the crag is dusted with a thin layer of snow, its harsh edges softened by frost and ice clinging to the stone",
        " where the biting cold wind howls through the crag's narrow passes, and the rock is coated with patches of ice, making the climb treacherous"
        }));

    addSeasonDescription("spring", ({
        " where snow begins to melt, creating small streams that trickle down the crag's rock faces, and the air feels fresh but still sharp",
        " where patches of green start to emerge at the base of the crag, but the jagged stones remain unforgiving and cold in the higher reaches"
        }));

    addSeasonDescription("summer", ({
        " where the crag stands in full sun, the stone radiating heat and the air thick with the scent of dry earth and rocks",
        " where the crag's steep slopes are dry and bare, the sun beating down relentlessly on the sharp rocks"
        }));

    addSeasonDescription("autumn", ({
        " where the crag is swept by cool winds, and the scattered leaves at its base rustle, contrasting with the unyielding rock",
        " where the crag's dark stones seem even more imposing as the air turns crisp and the light grows softer with the fall season"
        }));

    // Base Description Template
    addDescriptionTemplate("a ##Adjective## crag, its jagged cliffs towering over the landscape, standing stark against the sky with sparse vegetation clinging to its base");
}