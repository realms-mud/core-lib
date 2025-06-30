//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("sea shore bluff");
    addAdjectives(({ "towering", "majestic", "windswept", "rugged", "imposing" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({
        "with cliffs just catching the faint dawn light",
        "outlined softly against the brightening sky",
        "emerging from morning mists over the sea",
        "bathed in the pale colors of sunrise",
        "silhouetted against the dawn horizon",
        "touched by the first rays of morning light"
        }));
    addTimeOfDayDescription("morning", ({
        "bathed in gentle morning light",
        "with sunlight illuminating the cliff face",
        "gleaming in the fresh morning air",
        "standing proud in the clear morning sky",
        "highlighted by the climbing sun",
        "bright against the morning seascape"
        }));
    addTimeOfDayDescription("noon", ({
        "clearly visible in the full light of day",
        "stark and imposing at midday",
        "casting deep shadows below",
        "brilliant white in the noon sun",
        "standing bold against the azure sky",
        "gleaming in the intense midday light"
        }));
    addTimeOfDayDescription("afternoon", ({
        "with shadows playing across the rock face",
        "standing quietly in the afternoon warmth",
        "weathered by countless afternoon storms",
        "basking in the gentle afternoon sun",
        "painted in warm afternoon hues",
        "serene in the late day calm"
        }));
    addTimeOfDayDescription("evening", ({
        "with cliffs glowing in the golden evening light",
        "as the sun sets behind the towering heights",
        "painted in sunset colors of orange and red",
        "magnificent against the evening sky",
        "catching the last light of day",
        "transformed by the golden hour"
        }));
    addTimeOfDayDescription("dusk", ({
        "with details fading in the last light of day",
        "becoming dark silhouettes as dusk settles",
        "outlined against the deepening sky",
        "mysterious in the gathering twilight",
        "fading into evening shadows",
        "stark against the darkening horizon"
        }));
    addTimeOfDayDescription("night", ({
        "outlined against the starry sky",
        "discernable only as darker shapes in the night",
        "looming mysteriously in the darkness",
        "silhouetted against the moon-bright sea",
        "standing sentinel in the night",
        "barely visible in the star-touched darkness"
        }));
    addTimeOfDayDescription("midnight", ({
        "barely visible under the midnight sky",
        "lost in the deep shadows of night",
        "hidden in the profound darkness",
        "merged with the black night sky",
        "invisible save for crashing waves below",
        "swallowed by the midnight void"
        }));

    // Season Descriptions
    addSeasonDescription("winter", ({ " battered by fierce winter storms",
        " covered with snow and ice", " lashed by freezing ocean spray",
        " standing defiantly against winter gales", " whitened by frost and snow",
        " enduring the harsh winter seas" }));
    addSeasonDescription("spring", ({ " dotted with hardy cliff vegetation",
        " crowned with budding sea grasses", " hosting returning seabirds",
        " alive with spring nesting activity", " adorned with early wildflowers",
        " welcoming migrating birds back to their roosts" }));
    addSeasonDescription("summer", ({ " alive with seabird colonies",
        " crowned with lush coastal vegetation", " bustling with nesting activity",
        " adorned with summer wildflowers", " teeming with marine life below",
        " vibrant with the sounds of summer" }));
    addSeasonDescription("autumn", ({ " swept by autumn storm winds",
        " preparing for winter's approach", " colored by autumn's coastal plants",
        " witnessing the departure of migratory birds", " battered by fierce autumn gales",
        " standing resolute against seasonal storms" }));

    addAlias("bluff");
    addAlias("cliff");
    addAlias("cliffs");
    addAlias("sea shore");
    addAlias("shore");
    addAlias("coastline");

    addDescriptionTemplate("a ##Adjective## sea shore bluff");
    addItemTemplate("The sea shore bluff rises majestically from the "
        "churning waters below, its weathered face carved by countless "
        "years of wind and spray. Hardy sea grasses cling to ledges and "
        "crevices, while seabirds nest in the rocky alcoves. The sound "
        "of waves crashing against the base echoes upward, and salt spray "
        "mists the air. Erosion has carved dramatic formations into the "
        "cliff face, creating natural arches and sea caves. The bluff "
        "stands as a testament to the eternal struggle between land and "
        "sea, worn but unbroken by the relentless ocean forces.");
}
