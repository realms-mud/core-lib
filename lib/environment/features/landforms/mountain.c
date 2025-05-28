//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("mountain");
    addAdjectives(({ "majestic", "towering", "snow-capped", "rugged", "imposing",
        "ancient", "craggy", "steep", "jagged", "massive" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({
        " where first light touches the peak long before the lands below, painting "
        "the summit in gold and rose while valleys remain shrouded in shadow",
        " where morning mist clings to forested lower slopes while the upper reaches "
        "stand clear and sharp against the brightening sky"
        }));
    addTimeOfDayDescription("morning", ({
        " where sunlight gradually descends the eastern face, revealing rocky outcrops, "
        "hidden valleys, and the texture of forests clinging to its flanks",
        " where eagles soar on morning thermals rising along its massive slopes, "
        "their calls echoing against stone faces and distant ridges"
        }));
    addTimeOfDayDescription("noon", ({
        " where the full light of day reveals its true scale, from the broad base to "
        "the distant summit that seems to touch the clouds themselves",
        " where shadows retreat to crevices and northern slopes, leaving most of the "
        "mountain exposed to the harsh clarity of midday sun"
        }));
    addTimeOfDayDescription("afternoon", ({
        " where the western slopes begin to glow with warming light while eastern "
        "faces fall into deepening shadow, accentuating every ridge and valley",
        " where clouds sometimes gather around the peak, drawn to its height "
        "and building toward evening storms that may never reach lower ground"
        }));
    addTimeOfDayDescription("evening", ({
        " where the setting sun transforms the mountain into a silhouette of deep "
        "blue against a flaming sky, with the peak catching final golden rays",
        " where alpenglow paints the highest reaches in surreal pink and orange "
        "long after the surrounding lands have fallen into shadow"
        }));
    addTimeOfDayDescription("dusk", ({
        " where darkness climbs the slopes as day retreats, stars appearing first "
        "above the summit while the foot of the mountain still holds fading light",
        " where the mountain's massive presence remains imposing even as details "
        "dissolve into the growing night, its outline stark against the darkening sky"
        }));
    addTimeOfDayDescription("night", ({
        " where moonlight transforms rocky slopes into a silver landscape of light and "
        "shadow, revealing the mountain's form in stark contrast",
        " where the mountain stands as a dark sentinel against the star-filled sky, "
        "its immensity somehow more palpable in the quiet of night"
        }));
    addTimeOfDayDescription("late night", ({
        " where the mountain's presence is felt more than seen, a vast interruption "
        "in the star field that speaks of permanent defiance against time itself",
        " where occasional snow fields or glaciers catch moonlight and gleam faintly, "
        "suggesting the mountain's form in the deepest hours of night"
        }));
    addTimeOfDayDescription("midnight", ({
        " where the mountain stands timeless under the midnight sky, its slopes and "
        "summit a dark void against the stars, patient and eternal",
        " where not even darkness can diminish its majesty, the mountain's presence "
        "remaining a constant anchor in the landscape even when unseen"
        }));

    // Seasonal Descriptions
    addSeasonDescription("winter", ({
        " where snow blankets all but the steepest faces, transforming the rugged "
        "terrain into smooth white curves broken by dark stone outcroppings",
        " where ice gleams on exposed rock, storms shroud the peak for days, and "
        "avalanches occasionally thunder down remote slopes"
        }));

    addSeasonDescription("spring", ({
        " where snowmelt creates countless streams and waterfalls that cascade down "
        "its flanks, and new green appears first in the lowest meadows",
        " where life returns gradually up the slopes, a tide of renewal climbing "
        "toward the peak while snow still grips the highest reaches"
        }));

    addSeasonDescription("summer", ({
        " where alpine meadows burst with wildflowers, high pastures support grazing "
        "animals, and even the upper slopes enjoy brief weeks without snow",
        " where clear days reveal every detail from base to summit, though "
        "afternoon often brings swift-building clouds around the peak"
        }));

    addSeasonDescription("autumn", ({
        " where forested slopes display a tapestry of reds and golds that climb until "
        "trees give way to stone and the first new snow on the highest reaches",
        " where early morning frost in high meadows presages the coming winter, "
        "even as the lower slopes still bask in golden autumn light"
        }));

    // Base Description Template
    addDescriptionTemplate("a ##Adjective## mountain rising dramatically from the surrounding terrain, its immense form dominating the landscape with rocky slopes that climb through distinct zones of vegetation before reaching the barren upper reaches and summit");
}
