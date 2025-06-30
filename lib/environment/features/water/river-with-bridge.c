//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("river with bridge");
    addAdjectives(({ "spanning", "crossing", "connecting", "ancient", "weathered" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({
        "with bridge catching the faint dawn light",
        "outlined against the brightening river",
        "emerging from morning river mist",
        "touched by the first rays over flowing water",
        "reflected in the calm morning river",
        "awakening with the new day"
        }));
    addTimeOfDayDescription("morning", ({
        "bathed in gentle morning light",
        "with sunlight dancing on the river below",
        "bright with morning activity",
        "alive with travelers crossing the span",
        "sparkling with reflected morning sun",
        "busy with morning river traffic"
        }));
    addTimeOfDayDescription("noon", ({
        "clearly visible in the full light of day",
        "casting shadows on the river below",
        "brilliant in the noon sun",
        "busy with midday crossings",
        "imposing under the high sun",
        "prominent in the bright daylight"
        }));
    addTimeOfDayDescription("afternoon", ({
        "with people crossing in the afternoon warmth",
        "peaceful over the flowing river",
        "connecting shores in the gentle light",
        "warmed by the afternoon sun",
        "serene in the late afternoon calm",
        "comfortable for afternoon travel"
        }));
    addTimeOfDayDescription("evening", ({
        "with stones glowing in the golden evening light",
        "as the sun sets behind the bridge span",
        "painted in magnificent sunset colors",
        "beautiful against the evening river",
        "transformed by the golden hour",
        "romantic in the fading river light"
        }));
    addTimeOfDayDescription("dusk", ({
        "with details fading in the last light of day",
        "becoming a silhouette as dusk settles",
        "mysterious in the gathering twilight",
        "outlined against the darkening water",
        "peaceful as night approaches",
        "contemplative in the river dusk"
        }));
    addTimeOfDayDescription("night", ({
        "outlined by moonlight on the river",
        "discernable by the sound of flowing water",
        "silvered by moonlight on the span",
        "peaceful under the starry sky",
        "quiet save for the river's song",
        "enchanted by the night river sounds"
        }));
    addTimeOfDayDescription("midnight", ({
        "barely visible under the midnight sky",
        "lost in the river shadows",
        "hidden in the profound darkness",
        "merged with the dark flowing waters",
        "invisible save for water sounds",
        "embraced by the midnight river"
        }));

    // Season Descriptions
    addSeasonDescription("winter", ({ " dusted with snow and ice",
        " spanning the partially frozen river", " weathered by winter storms",
        " connecting banks through winter's grasp", " standing firm against winter floods",
        " beautiful in winter's stark embrace" }));
    addSeasonDescription("spring", ({ " spanning the river swollen with snowmelt",
        " surrounded by budding riverside vegetation", " busy with spring travelers",
        " connecting communities after winter's isolation", " alive with returning river life",
        " renewed by spring's warming touch" }));
    addSeasonDescription("summer", ({ " perfect for summer crossings",
        " connecting shores over the peaceful river", " busy with summer traffic",
        " beautiful in summer's gentle light", " alive with summer river activity",
        " ideal for leisurely travel" }));
    addSeasonDescription("autumn", ({ " spanning waters reflecting autumn colors",
        " connecting banks lined with fall foliage", " beautiful in autumn's golden light",
        " peaceful as the river carries fallen leaves", " contemplative in the changing season",
        " preparing for winter's approach" }));

    addAlias("bridge");
    addAlias("river");
    addAlias("crossing");
    addAlias("span");
    addAlias("water");
    addAlias("flowing water");

    addDescriptionTemplate("a ##Adjective## river with bridge");
    addItemTemplate("The bridge spans the flowing river with grace and "
        "purpose, its weathered stone arches or timber framework "
        "connecting distant shores with bonds of human ingenuity. "
        "The river flows steadily beneath, its current carrying "
        "leaves, debris, and the stories of distant lands toward "
        "unknown destinations. Fish rise to feed in the shadow of "
        "the bridge while swallows nest in its protective alcoves. "
        "The structure has witnessed countless crossings - merchants "
        "with laden carts, travelers seeking new horizons, and lovers "
        "meeting at its center to watch the endless flow of time "
        "and water beneath their feet.");
}
