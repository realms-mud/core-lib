//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/terrain/baseTerrain.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("swamp");

    addAdjectives(({
        "murky swamp with stagnant pools and tangled roots",
        "boggy ground covered in moss and reeds",
        "shadowy swamp where willows droop over dark water",
        "dank marshland alive with the croak of frogs",
        "swampy expanse where mist clings to twisted trees",
        "sodden ground where every step squelches",
        "swamp filled with buzzing insects and hidden dangers",
        "gloomy wetland where the air is thick and humid",
        "marshy lowland with patches of open water",
        "swamp where the scent of decay hangs heavy"
        }));

    addTimeOfDayDescription("dawn", ({
        " shrouded in mist as the sun rises",
        " where the air is cool and damp",
        " as birds call from hidden perches"
        }));

    addTimeOfDayDescription("morning", ({
        " with sunlight filtering through the trees",
        " as the swamp comes alive with the sounds of insects",
        " where the water glistens in the early light"
        }));

    addTimeOfDayDescription("noon", ({
        " under the oppressive heat of midday",
        " where the air is thick and still",
        " as the swamp buzzes with life"
        }));

    addTimeOfDayDescription("afternoon", ({
        " as the sun slants through the canopy",
        " with shadows deepening among the trees",
        " where the air grows heavier and more humid"
        }));

    addTimeOfDayDescription("evening", ({
        " as the light fades and the swamp grows quiet",
        " with the croak of frogs echoing in the dusk",
        " where fireflies begin to dance above the water"
        }));

    addTimeOfDayDescription("night", ({
        " cloaked in darkness and thick with the sound of insects",
        " where the air is cool and the water reflects the moon",
        " as unseen creatures move through the shadows"
        }));

    addSeasonDescription("winter", ({
        " with water frozen in patches and the air biting cold",
        " where the swamp is quieter, life hidden beneath the surface"
        }));

    addSeasonDescription("spring", ({
        " alive with new growth and the calls of returning birds",
        " as the water rises and the swamp teems with life"
        }));

    addSeasonDescription("summer", ({
        " at its most lush and humid",
        " with thick vegetation and clouds of insects"
        }));

    addSeasonDescription("autumn", ({
        " as leaves fall and the water grows still",
        " with the scent of decay stronger in the air"
        }));

    addDescriptionTemplate("a ##Adjective##");
    addNearDarkDescriptionTemplate("a pitch-black swamp where only the sounds of creatures betray its presence");
    addLowLightDescriptionTemplate("a barely-lit swamp where trees and water merge into shadow");
    addDimLightDescriptionTemplate("a dimly-lit swamp where the ground is a patchwork of shadow and water");
    addSomeLightDescriptionTemplate("a sunlit swamp where every pool and tree is visible");
}
