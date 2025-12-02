//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("well-travelled path");
    addAlias("path");

    addAdjectives(({ "beaten", "hard-packed", "familiar", "winding",
        "wide", "established", "rutted", "time-worn", "trusted" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({
        " revealing countless preserved tracks",
        " dampened to show recent crossings",
        " silent testament to continuous use",
        " emphasized in worn contours",
        " vibrant with corridor birdsong",
        " illuminated in smoothed stones and roots",
        " temporarily abandoned but freshly tracked",
        " visible through meadow dew collection",
        " rich with past traffic scents",
        " highlighted in polished sections"
        }));

    addTimeOfDayDescription("morning", ({
        " releasing crushed herb scents",
        " drying center outward to edges",
        " crossed by territorial small creatures",
        " rising dust from hooves and wheels",
        " reflected differently from warming light",
        " attracting insects above surface",
        " revealed in subtle crowned contours",
        " creating clear corridors through growth",
        " attracting seed-seeking songbirds",
        " hovering with ribbons of mist"
        }));

    addTimeOfDayDescription("noon", ({
        " scarce with shade from trees",
        " intensely reflecting heat",
        " shimmering in midday intensity",
        " stirred occasionally by dust devils",
        " ribbon of detectible warmth",
        " starkest in relief tracks",
        " buzzing with verge insects",
        " revealing meandering distant course",
        " framed colorfully by wildflowers",
        " apparent in intentional clearing"
        }));

    addTimeOfDayDescription("afternoon", ({
        " completely dried in track tapestry",
        " momentarily reclaimed by seed gatherers",
        " cooler encouraging edge wildlife",
        " patterned with lengthening tree shadows",
        " worn center more than edges",
        " providing hunting grounds overhead",
        " retained with accumulated warmth",
        " raised with occasional dust breezes",
        " carved with parallel wheel impressions",
        " revealed in complex use topography"
        }));

    addTimeOfDayDescription("evening", ({
        " glowing hazed above surface",
        " settled more heavily with scents",
        " striped with merging tree shadows",
        " emerged with peripheral wild creatures",
        " carrying sounds from greater distances",
        " begun with evening bat flights",
        " glowing briefly with stored sunlight",
        " emerged with edge-burrowing rodents",
        " distinct against darkening vegetation",
        " dry while surrounding dampens with dew"
        }));

    addTimeOfDayDescription("dusk", ({
        " visible as lighter strip",
        " replaced with evening insect chorus",
        " efficiently used for movement",
        " changed in scent from dust to earth",
        " formed with subtle low fog",
        " softened but distinct boundaries",
        " served as overhead hunting corridor",
        " warmer than surrounding ground",
        " creating strange shadows",
        " increased with fox and badger tracks"
        }));

    addTimeOfDayDescription("night", ({
        " revealed pale between darker fields",
        " silvery reflecting starlight",
        " occasionally heard with wildlife crossing",
        " replaced with rustling and nocturnal sounds",
        " wider than visual, sensed at edges",
        " distinguished for night-adapted eyes",
        " perfumed with night-blooming flowers",
        " occasionally reflected with small eyes",
        " marked with barking and hooting territories",
        " settled differently with moisture"
        }));

    addTimeOfDayDescription("late night", ({
        " perceptible in texture and elevation",
        " narrowed psychologically in darkness",
        " distantly marked with howling wolves",
        " occasionally broken with owl hoots",
        " traveled along by nocturnal animals",
        " glimpsed with reflecting predator eyes",
        " formed heavily with surrounding dew",
        " pronounced with temperature variations",
        " carried great distances in cold air",
        " formed ethereally in low sections"
        }));

    addTimeOfDayDescription("midnight", ({
        " deepest broken only by darkness creatures",
        " diminished in terrain contrast",
        " finally settled with moisture",
        " revealed with foraging rustling",
        " persisted with crushed vegetation scents",
        " still warmer than untraveled areas",
        " transformed in familiar landmarks",
        " reliable with ancient star patterns",
        " peaked with dew chill",
        " occasionally marked with nightjar cries"
        }));

    // Seasonal Descriptions
    addSeasonDescription("winter", ({
        " compacted differently creating clearer route",
        " frozen more quickly with rut ice",
        " framed with intricate branch patterns",
        " revealed with various tracked snow",
        " most evident connecting isolated areas",
        " drifted while shallow at vegetation",
        " ensured with cairns or posts",
        " increased with easier animal navigation",
        " contrasted between white and darker surface",
        " preserved with frozen mud impressions"
        }));

    addSeasonDescription("spring", ({
        " morass of remarkable mud depth",
        " appeared with returning migrant tracks",
        " bordered with additional sunlight flowers",
        " formed with erosion channels",
        " contrasted with brown recovery margins",
        " formed with depressions and ruts",
        " higher use with rapidly drying",
        " gathered with sun-warmed insects",
        " revealed with winter damage extent",
        " marked with damp earth scents"
        }));

    addSeasonDescription("summer", ({
        " constant with rising dust clouds",
        " contrasted sharply with lush growth",
        " shimmering with heat visibility",
        " widened toward edges avoiding heat",
        " narrowed by encroaching growth",
        " swarmed with greater insect numbers",
        " appeared with dusty creature tracks",
        " steamed with rain hitting hot surface",
        " exposed with vulnerable dust erosion",
        " contrasted with golden and brown track"
        }));

    addSeasonDescription("autumn", ({
        " collected with colorful decaying leaves",
        " rutted deeply with harvest traffic",
        " patterned with lasting frost",
        " appeared marginally with seasonal fungi",
        " emphasized with worn earth contours",
        " followed by certain migratory birds",
        " revealed with effective moisture shedding",
        " framed with spectacular seasonal displays",
        " created with natural feeding stations",
        " changed with crackling leaf carpet"
        }));

    // Base Description Template
    addDescriptionTemplate("a ##Adjective## well-travelled path connecting "
        "settlements and vital locations worn smooth by countless travelers");

    addItemTemplate("the path reveals years of continuous use, its surface packed hard and "
        "smooth from countless travelers. The center is worn lower than the edges, "
        "creating a subtle channel that guides foot traffic and sheds rainwater. "
        "Exposed roots and occasional stones break the surface in places, while "
        "the margins show where vegetation struggles to reclaim territory. "
        "##UseDescriptionSet##");
}
