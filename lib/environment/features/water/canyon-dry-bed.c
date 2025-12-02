//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("canyon dry bed");
    addAdjectives(({ "empty", "carved", "ancient", "weathered", "silent" }));

    // Time of Day Descriptions
    addTimeOfDayDescription("dawn", ({
        "with stones catching filtered dawn light",
        "outlined in the brightening canyon",
        "emerging from morning canyon shadows",
        "touched by rays penetrating the deep canyon",
        "revealed in the pale morning light",
        "awakening to another quiet day"
        }));
    addTimeOfDayDescription("morning", ({
        "bathed in gentle filtered morning light",
        "with sunlight illuminating dry canyon stones",
        "bright in the deep morning canyon shadows",
        "peaceful in its silent canyon emptiness",
        "clear in the reflected canyon morning sun",
        "serene despite its absence of water"
        }));
    addTimeOfDayDescription("noon", ({
        "clearly visible when sunlight penetrates deeply",
        "stark and empty in the canyon depths",
        "warmed by the filtered noon sun",
        "prominent in the canyon's dramatic emptiness",
        "exposed under the canyon sun",
        "dramatic in its waterless canyon state"
        }));
    addTimeOfDayDescription("afternoon", ({
        "with warmth radiating from sun-warmed canyon stones",
        "silent in the afternoon canyon calm",
        "peaceful in its empty canyon tranquility",
        "warmed by the filtered afternoon sun",
        "contemplative in the canyon's afternoon emptiness",
        "beautiful despite its canyon emptiness"
        }));
    addTimeOfDayDescription("evening", ({
        "with stones glowing in filtered evening light",
        "as sunset light reaches into the canyon",
        "painted in muted canyon evening colors",
        "beautiful in the canyon evening glow",
        "romantic despite its empty canyon state",
        "transformed by the filtered golden hour"
        }));
    addTimeOfDayDescription("dusk", ({
        "with details fading in the canyon shadows",
        "becoming mysterious as canyon dusk deepens",
        "outlined in the darkening canyon depths",
        "peaceful despite its empty canyon silence",
        "cool in the evening canyon shadows",
        "contemplative in the gathering canyon darkness"
        }));
    addTimeOfDayDescription("night", ({
        "barely visible in the canyon darkness",
        "outlined by moonlight filtering down",
        "mysterious in the canyon night silence",
        "peaceful in its waterless canyon state",
        "quiet in its empty canyon darkness",
        "enchanted by the canyon night stillness"
        }));
    addTimeOfDayDescription("midnight", ({
        "barely visible in the deep canyon shadows",
        "lost in the profound canyon darkness",
        "hidden in the canyon's midnight depths",
        "silent in the midnight canyon hour",
        "mysterious in its empty canyon midnight",
        "embraced by the canyon's darkness"
        }));

    // Season Descriptions
    addSeasonDescription("winter", ({ 
        " dusted with snow in its empty canyon channel",
        " marked by frost on exposed canyon stones", 
        " peaceful in winter's quiet canyon embrace",
        " transformed by winter's canyon coating", 
        " beautiful in its stark canyon simplicity",
        " waiting for spring's canyon renewal" }));
    addSeasonDescription("spring", ({ 
        " showing signs of recent spring canyon floods",
        " hopeful for returning spring canyon waters", 
        " marked by new canyon vegetation growth",
        " alive with sprouting canyon plants",
        " promising future canyon water flow",
        " renewed by spring's canyon potential" }));
    addSeasonDescription("summer", ({ 
        " dry in the canyon's summer embrace",
        " waterless during summer's canyon peak", 
        " waiting for autumn canyon rains",
        " beautiful despite its canyon emptiness", 
        " peaceful in summer's canyon quiet",
        " contemplative in its dry canyon state" }));
    addSeasonDescription("autumn", ({ 
        " scattered with leaves fallen into the canyon",
        " hoping for autumn's returning canyon rains", 
        " beautiful in autumn's filtered canyon light",
        " peaceful in the cooling canyon air", 
        " contemplative as seasons change in the canyon",
        " preparing for potential winter canyon flows" }));

    addAlias("dry bed");
    addAlias("creek bed");
    addAlias("river bed");
    addAlias("canyon");
    addAlias("channel");

    addDescriptionTemplate("a ##Adjective## canyon dry bed");
    addItemTemplate("The canyon dry bed winds through the spectacular "
        "gorge as a testament to water's seasonal power, its channel "
        "carved deep into solid rock by seasonal flows that thunder "
        "through this natural cathedral during spring snowmelt and "
        "heavy autumn rains. Smooth stones and weathered boulders "
        "lie scattered across the empty bed, polished by waters that "
        "shaped this magnificent canyon through countless seasonal "
        "cycles. The dry channel tells stories of flash floods and "
        "gentle flows through the intricate patterns worn into stone "
        "and the dramatic high water marks visible on the towering "
        "canyon walls. Forest plants and seasonal vegetation have "
        "claimed portions of the bed, their roots extending deep to "
        "access hidden moisture while awaiting the return of flowing "
        "water in this testament to nature's cyclical patterns.");
}
