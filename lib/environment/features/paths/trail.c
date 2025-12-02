//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("trail");
    addAdjectives(({ "faint", "winding", "narrow", "rough", "animal",
        "meandering", "subtle", "hidden", "overgrown", "wilderness" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({
        " delicately marked by dew patterns",
        " lingering longer with mist",
        " concentrated with wildlife activity",
        " spanned occasionally by jeweled webs",
        " vanishing and reappearing in shadows",
        " concentrated with diverse birdsong",
        " revealed in disturbed vegetation",
        " emphasized by light angle",
        " patterned differently with frost",
        " subtly ribboned through disturbed dew"
        }));

    addTimeOfDayDescription("morning", ({
        " releasing earthy crushed scents",
        " rising with insects and butterflies",
        " revealed through different vegetation",
        " burning off in sun-determined patterns",
        " apparent in meeting plant communities",
        " shadowed in gentle depression",
        " important for wildlife tracking",
        " disappearing and reemerging ahead",
        " apparent in trampled versus untrampled",
        " concentrated in seed distribution"
        }));

    addTimeOfDayDescription("noon", ({
        " nearly disappearing in shadowless sections",
        " blurred by heat shimmer",
        " concentrated with microhabitat insects",
        " revealed by drought-resistant plants",
        " heated in rock outcropping areas",
        " strongly scented in warmed vegetation",
        " diminished in vegetation contrast",
        " possibly raising small dust clouds",
        " less apparent in elevation changes",
        " indicated by grass direction"
        }));

    addTimeOfDayDescription("afternoon", ({
        " increasingly distinct in lengthening shadows",
        " carrying mingled heated earth scents",
        " visible in thermal traces",
        " caught differently on bent grasses",
        " active with small edge animals",
        " illuminated differently in corridors",
        " evident at crossing intersections",
        " alternating visible and invisible",
        " warm in western-facing microhabitats",
        " appreciated in gentle meanders"
        }));

    addTimeOfDayDescription("evening", ({
        " outlined glowing in bent grasses",
        " releasing different cooling scents",
        " increased significantly with wildlife activity",
        " enhanced in low angle shadows",
        " traced sometimes with condensation mist",
        " followed by evening bird migrations",
        " highlighted in direct sunlight",
        " distinct in compressed soil vegetation",
        " softened visually but tactilely detectable",
        " concentrated with evening pollinators"
        }));

    addTimeOfDayDescription("dusk", ({
        " dependent on texture rather than sight",
        " sometimes creating subtle fog",
        " fading diurnal while increasing nocturnal",
        " relied upon through compacted feel",
        " creating narrow remaining light",
        " positioned by nocturnal hunters",
        " followed by hunting bats",
        " changed dramatically in scent profile",
        " briefly revealed in dew patterns",
        " detected through sensitive thermoreception"
        }));

    addTimeOfDayDescription("night", ({
        " subtly different in moonlight reflection",
        " dependent on underfoot feel",
        " extensively used by night creatures",
        " distinguished for night-adjusted vision",
        " opened with night-blooming edges",
        " bounded between nocturnal territories",
        " corrected with open sky",
        " significant in temperature differences",
        " revealed occasionally in eye-shine",
        " distinctive in movement sounds"
        }));

    addTimeOfDayDescription("late night", ({
        " almost theoretical in sections",
        " peak with nocturnal wildlife activity",
        " progressing with dew formation",
        " forming mist in lowest sections",
        " patrolled by night-hunting predators",
        " guided by subtle moonlight patterns",
        " traveling differently in open corridor",
        " connected between feeding and shelter",
        " peak in scent differentiation",
        " pronounced in moisture differences"
        }));

    addTimeOfDayDescription("midnight", ({
        " reduced to concept rather than visual",
        " maximized in temperature difference",
        " continued regardless by nocturnal creatures",
        " existing through negative space",
        " carrying subtlest sounds further",
        " releasing stored aromas differently",
        " ribboned with visible sky",
        " peaked in dew formation",
        " permitted detection of slightest disturbances",
        " connected disparate ecosystems regardless"
        }));

    // Seasonal Descriptions
    addSeasonDescription("winter", ({
        " most clearly revealed by snow compaction",
        " uniquely patterned by compressed frost",
        " swept or drifted inconsistently",
        " fully revealed through wooded areas",
        " dramatically increased in wildlife dependence",
        " varied in frozen earth textures",
        " hazardously but strikingly iced",
        " melted at different rates",
        " crucially marked by simple indicators",
        " sometimes serving as drainage course"
        }));

    addSeasonDescription("spring", ({
        " differently appeared along margins",
        " challenged by mud season compression",
        " timeline in spring growth progress",
        " bordered green by reduced competition",
        " revealed in drainage patterns",
        " followed by migrating birds",
        " concentrated with early warming insects",
        " gradually revealed by snow retreat",
        " sequenced in specific bloom progression",
        " emphasized in dampness scent markers"
        }));

    addSeasonDescription("summer", ({
        " peaked in vegetation contrast",
        " dominated by heat-resistant plants",
        " possibly raised with dust",
        " established with edge habitat insects",
        " concentrated with berry-producing margins",
        " narrowed by peak growth encroachment",
        " distinct in microclimates",
        " evident in dry period compaction",
        " maintained through regular wildlife use",
        " revealed in seed distribution function"
        }));

    addSeasonDescription("autumn", ({
        " differently collected with leaves",
        " vanished under autumn carpet",
        " distinctively patterned with frost",
        " concentrated with decay scents",
        " followed by seasonal migrations",
        " collected with nuts and seeds",
        " directed in rainfall flow",
        " emphasized in declining sunlight",
        " challenging with moisture and leaves",
        " serving as natural firebreak"
        }));

    // Base Description Template
    addDescriptionTemplate("a ##Adjective## trail winding through the "
        "landscape, marked by disturbed vegetation and compressed soil");

    addItemTemplate("the trail reveals itself as a subtle interruption in the natural "
        "environment, its course marked more by bent grasses and disturbed soil "
        "than by clear boundaries. Animal tracks frequently follow or cross this "
        "route, suggesting it serves wildlife as much as any purposeful travelers. "
        "In places, the trail nearly disappears before becoming evident again a "
        "few paces ahead.");
}
