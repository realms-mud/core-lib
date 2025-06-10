//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/terrain/baseTerrain.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("forest mountain");

    addAdjectives(({
        "towering mountain cloaked in dense forest",
        "steep forested slopes rising toward the sky",
        "mountain where pines and firs cling to rocky ridges",
        "craggy peak with trees growing in every crevice",
        "mountain shrouded in mist and ancient woodland",
        "rugged mountain where waterfalls tumble through the trees",
        "forest mountain with mossy boulders and hidden glens",
        "mountain where the forest thins near the summit",
        "wooded mountain where eagles soar above the canopy",
        "mountain where the air is cool and filled with the scent of pine"
        }));

    addTimeOfDayDescription("dawn", ({
        " bathed in the first light of day",
        " where mist drifts between the trees and rocks",
        " as the mountain awakens with birdsong"
        }));

    addTimeOfDayDescription("morning", ({
        " with sunlight streaming through the forest",
        " as the slopes come alive with the sounds of wildlife",
        " where the air is crisp and fresh"
        }));

    addTimeOfDayDescription("noon", ({
        " under the bright midday sun",
        " where the forest offers cool shade on the mountain",
        " as the air is filled with the hum of insects"
        }));

    addTimeOfDayDescription("afternoon", ({
        " as the sun slants across the slopes",
        " with long shadows stretching over the mountain",
        " where the wind stirs the treetops"
        }));

    addTimeOfDayDescription("evening", ({
        " glowing in the warm light of sunset",
        " as the mountain quiets and the air cools",
        " where the sky is painted in hues of orange and purple"
        }));

    addTimeOfDayDescription("night", ({
        " under a sky filled with stars and the silhouettes of trees",
        " where the mountain is quiet except for the sounds of night creatures",
        " as the forest is cloaked in darkness"
        }));

    addSeasonDescription("winter", ({
        " with snow-laden branches and icy slopes",
        " where the mountain is silent and the air is biting cold"
        }));

    addSeasonDescription("spring", ({
        " bursting with new growth and the sound of rushing water",
        " as the forest comes alive with color and scent"
        }));

    addSeasonDescription("summer", ({
        " at its greenest, with thick foliage and cool shade",
        " where the mountain is lush and vibrant"
        }));

    addSeasonDescription("autumn", ({
        " ablaze with the colors of changing leaves",
        " as the forest prepares for winter"
        }));

    addDescriptionTemplate("a ##Adjective##");
    addNearDarkDescriptionTemplate("a shadowy forest mountain where only the outlines of trees and rocks are visible");
    addLowLightDescriptionTemplate("a barely-lit forest mountain where the land is little more than a silhouette");
    addDimLightDescriptionTemplate("a dimly-lit forest mountain where the trees and rocks are painted in shades of gray");
    addSomeLightDescriptionTemplate("a sunlit forest mountain where every tree and crag is clear");
}
