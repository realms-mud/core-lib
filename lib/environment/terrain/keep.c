//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/terrain/baseTerrain.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("keep");

    addAdjectives(({
        "stone keep rising above the surrounding town",
        "fortified keep with high walls and towers",
        "ancient keep built atop a rocky hill",
        "keep with banners fluttering from the battlements",
        "imposing keep where guards patrol the ramparts",
        "medieval keep with a deep moat and drawbridge",
        "keep where the lord's banner flies proudly",
        "keep with arrow slits and heavy wooden gates",
        "keep surrounded by a bustling courtyard",
        "keep where the clang of armor echoes in the halls"
        }));

    addTimeOfDayDescription("dawn", ({
        " bathed in the first light of day",
        " where the guards change watch on the battlements",
        " as the keep awakens to the sound of horns"
        }));

    addTimeOfDayDescription("morning", ({
        " with sunlight glinting off the stone walls",
        " as servants and soldiers go about their duties",
        " where the air is filled with the sounds of activity"
        }));

    addTimeOfDayDescription("noon", ({
        " under the bright midday sun",
        " where the keep stands as a symbol of strength",
        " as the courtyard bustles with life"
        }));

    addTimeOfDayDescription("afternoon", ({
        " as the sun slants across the towers",
        " with long shadows stretching over the walls",
        " where the air is filled with the clang of armor"
        }));

    addTimeOfDayDescription("evening", ({
        " glowing in the warm light of sunset",
        " as the keep quiets and the torches are lit",
        " where the sky is painted in hues of orange and red"
        }));

    addTimeOfDayDescription("night", ({
        " under a sky filled with stars and the glow of torches",
        " where the keep is silent except for the watchful guards",
        " as the stone walls loom in the darkness"
        }));

    addSeasonDescription("winter", ({
        " with snow piled against the walls and smoke rising from chimneys",
        " where the keep is a refuge from the cold"
        }));

    addSeasonDescription("spring", ({
        " with banners fluttering in the fresh breeze",
        " as the keep comes alive with new activity"
        }));

    addSeasonDescription("summer", ({
        " at its busiest, with festivals and tournaments",
        " where the stone stays cool even in the heat"
        }));

    addSeasonDescription("autumn", ({
        " golden with falling leaves in the courtyard",
        " as the keep prepares for the coming winter"
        }));

    addDescriptionTemplate("a ##Adjective##");
    addNearDarkDescriptionTemplate("a shadowy keep where only the glow of torches reveals its presence");
    addLowLightDescriptionTemplate("a barely-lit keep where the walls are little more than shapes in the gloom");
    addDimLightDescriptionTemplate("a dimly-lit keep where the towers are painted in shades of gray");
    addSomeLightDescriptionTemplate("a sunlit keep where every stone and banner is clear");
}
