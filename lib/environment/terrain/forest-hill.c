//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/terrain/baseTerrain.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("forest hill");

    addAdjectives(({
        "wooded hill with trees clinging to its slopes",
        "rolling hill blanketed in dense forest",
        "hill where sunlight filters through leafy branches",
        "forested rise with mossy rocks and tangled roots",
        "hilltop crowned with ancient oaks and pines",
        "gentle hill where the forest thins near the summit",
        "hill covered in a patchwork of trees and undergrowth",
        "wooded knoll with a view through the treetops",
        "hill where birdsong echoes among the trees",
        "forest hill where deer trails wind between trunks"
        }));

    addTimeOfDayDescription("dawn", ({
        " bathed in the golden light of sunrise",
        " where mist clings to the trees and ground",
        " as the forest awakens with birdsong"
        }));

    addTimeOfDayDescription("morning", ({
        " with sunlight dappling the forest floor",
        " as the hill comes alive with the sounds of wildlife",
        " where the air is fresh and cool"
        }));

    addTimeOfDayDescription("noon", ({
        " under the bright midday sun",
        " where the canopy offers cool shade",
        " as the hill is alive with the hum of insects"
        }));

    addTimeOfDayDescription("afternoon", ({
        " as the sun slants through the trees",
        " with long shadows stretching across the hill",
        " where the breeze stirs the leaves"
        }));

    addTimeOfDayDescription("evening", ({
        " glowing in the warm light of sunset",
        " as the forest quiets and the air cools",
        " where the sky is painted in hues of orange and gold"
        }));

    addTimeOfDayDescription("night", ({
        " under a canopy of stars and the silhouettes of trees",
        " where the hill is quiet except for the sounds of night creatures",
        " as the forest is cloaked in darkness"
        }));

    addSeasonDescription("winter", ({
        " with bare branches and a dusting of snow",
        " where the hill is silent and the air is crisp",
        " as the forest waits for spring"
        }));

    addSeasonDescription("spring", ({
        " bursting with new leaves and wildflowers",
        " as the hill comes alive with color and scent"
        }));

    addSeasonDescription("summer", ({
        " at its greenest, with thick foliage and cool shade",
        " where the forest is lush and vibrant"
        }));

    addSeasonDescription("autumn", ({
        " golden with fallen leaves carpeting the ground",
        " as the trees blaze with color before winter"
        }));

    addDescriptionTemplate("a ##Adjective##");
    addNearDarkDescriptionTemplate("a shadowy forest hill where only the outlines of trees are visible");
    addLowLightDescriptionTemplate("a barely-lit forest hill where the land is little more than a silhouette");
    addDimLightDescriptionTemplate("a dimly-lit forest hill where the trees are painted in shades of gray");
    addSomeLightDescriptionTemplate("a sunlit forest hill where every tree and stone is clear");
}
