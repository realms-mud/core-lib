//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/terrain/baseTerrain.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("forest");
    addAdjectives(({
        "sprawling forest with ancient trees reaching skyward",
        "forest thick with mighty trees; knotted arms rising upward",
        "grove of many trees forming a verdant canopy overhead",
        "towering forest where shafts of light pierce the dense foliage",
        "lush forest teeming with life hidden among the undergrowth",
        "serene forest where silence hangs heavy between moss-covered trunks",
        "primeval woodland where time seems to move more slowly",
        "dense forest with mysterious shadows lurking between the trees",
        "whispering forest where leaves rustle tales of forgotten times",
        "majestic forest standing sentinel over the surrounding landscape",
        "enchanting woodland where sunbeams dance through the leaves",
        "shadowy forest with tangled roots forming natural pathways",
        "majestic, ancient forest where every tree holds centuries of secrets",
        "vibrant forest alive with the sounds of unseen creatures"
        }));

    addTimeOfDayDescription("dawn", ({
        ", the sinuous mists of the early morning caressing their limbs",
        " just waking with the first light of dawn",
        " wrapped in the new morn's light",
        " shedding the shadows of its night-time slumber",
        " where birdsong rises in a crescendo to greet the day",
        " with dew glistening like diamonds on every leaf and spider web"
        }));

    addTimeOfDayDescription("morning", ({
        " lit from rays of light piercing through the canopy",
        " awash with the tender glow of the morning",
        " coming alive with the bustling activity of woodland creatures",
        " where shafts of golden light illuminate dancing particles of dust",
        " with shadows retreating beneath the growing warmth of day",
        " where the scents of earth and growth hang heavy in the air"
        }));

    addTimeOfDayDescription("noon", ({
        " bathed in the mid-day light",
        " lit by golden seams of light coming through the canopy",
        " with a patchwork of shadow and light dappling the forest floor",
        " where the sun stands directly overhead, warming the fertile soil",
        " at its most vibrant as life flourishes in the full light of day",
        " with a hushed quality as many creatures seek shade from the heat"
        }));

    addTimeOfDayDescription("afternoon", ({
        " lit by the fullness of the day",
        " where long shadows begin to stretch across the leaf-strewn ground",
        " with a golden quality to the light filtering through the leaves",
        " growing quieter as the day's heat begins to wane",
        " where sunlight slants at angles highlighting the rich textures of bark",
        " with a lazy, dreamy atmosphere settling among the trees"
        }));

    addTimeOfDayDescription("evening", ({
        " still lit by the waning day's light",
        " with lengthening shadows creating mysterious patterns on the ground",
        " where golden light sets the canopy aflame with color",
        " coming alive again as nocturnal creatures prepare for night's activities",
        " where the cooling air carries the rich scent of earth and greenery",
        " with a magical quality as day transitions toward night"
        }));

    addTimeOfDayDescription("dusk", ({
        ", the details of which the last failing light of the day barely show",
        " where shadows deepen and merge beneath the darkening canopy",
        " with the last rays of sun creating an ethereal glow through the trees",
        " falling silent as day creatures settle and night beings awaken",
        " where darkness rises from the ground like a slow tide",
        " with a mysterious quality as familiar shapes transform in the fading light"
        }));

    addTimeOfDayDescription("night", ({
        " outlined in the dark",
        " where moonlight creates silver paths between the shadowed trunks",
        " filled with the soft sounds of nocturnal life moving unseen",
        " with branches creating intricate patterns against the starry sky",
        " where darkness reigns except for the occasional gleam of watchful eyes",
        " holding secrets that only emerge under cover of darkness"
        }));

    addTimeOfDayDescription("late night", ({
        " outlined in the dark",
        " where the deepest silence holds sway, broken only by occasional rustling",
        " shrouded in mystery as even nocturnal creatures grow quiet",
        " where trees stand as silent sentinels guarding the sleeping world",
        " with an ancient presence felt more strongly in the depth of night",
        " where time seems suspended between one day and the next"
        }));

    addTimeOfDayDescription("midnight", ({
        " scarcely outlined in eery black",
        " where darkness is most complete, broken only by faint starlight",
        " standing timeless under the midnight sky",
        " where even the wind seems to hold its breath",
        " with an otherworldly quality as the boundary between realms thins",
        " where the forest keeps its most ancient secrets hidden"
        }));

    addSeasonDescription("winter", ({
        " covered with a thick layer of snow",
        " where bare branches create intricate patterns against the sky",
        " silent under winter's heavy blanket of white",
        " with ice crystals adorning every twig like delicate jewelry",
        " where tracks in the snow reveal the secret movements of wildlife",
        " standing stoic against the bitter cold, life withdrawn to its core"
        }));

    addSeasonDescription("spring", ({
        " with leaves just beginning to bud",
        " bursting with new life as green unfurls from every branch",
        " where wildflowers carpet the forest floor in vibrant colors",
        " alive with the sounds of birds returning to build their nests",
        " where tender shoots push through the leaf litter of seasons past",
        " awakening from winter's sleep with renewed vigor"
        }));

    addSeasonDescription("summer", ({
        " with branches laden with leaves",
        " in full flourish, the canopy a dense ceiling of vibrant green",
        " where the air hangs heavy with the scent of growth and greenery",
        " offering cool shade from the summer heat",
        " alive with countless insects buzzing among the foliage",
        " at the peak of its yearly cycle, life abundant in every corner"
        }));

    addSeasonDescription("autumn", ({
        " carpeting the ground in fallen leaves of red, yellow, and orange",
        " aflame with color as leaves transform before falling",
        " where the scent of decay mingles with earthy richness",
        " with a crunch underfoot from the tapestry of fallen leaves",
        " preparing for winter's rest as seeds and nuts lay scattered",
        " where mist often clings between the trees in the cooling air"
        }));

    addDescriptionTemplate("a ##Adjective##");
    addNearDarkDescriptionTemplate("a very dark forest where shapes loom ominously and sounds seem magnified in the blackness");
    addLowLightDescriptionTemplate("a barely-lit forest where trees appear as looming silhouettes against the gloom");
    addDimLightDescriptionTemplate("a dimly-lit forest where shadows play between the trees and details emerge in shades of gray");
    addSomeLightDescriptionTemplate("a forest with light filtering through the canopy, illuminating the complex ecosystem within");
}
