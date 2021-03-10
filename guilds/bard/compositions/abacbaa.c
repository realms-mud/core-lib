//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/compositeResearchTemplate.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        activeResearchItem::reset(arg);
        addSpecification("name", "ABACBAA (Chorus/Verse/Chorus/Bridge)");
        addSpecification("source", "bard");
        addSpecification("description", "This research provides the user with the "
            "knowledge of how to create songs structured as a chorus, an "
            "instrumental, a verse, pre-chorus, chorus, a bridge, a verse "
            "breakdown, a chorus, and an outro.");

        addSpecification("research type", "points");
        addSpecification("research cost", 1);
        addSpecification("spell point cost", 25);
        addSpecification("stamina point cost", 25);

        addSpecification("segments", ({ 
            (["chorus 1": ({ "lyric", "chorus lyric", "instrumental rhythm" })]),
            (["instrumental": ({ "instrumental solo" })]),
            (["verse 1": ({ "lyric", "instrumental rhythm" })]),
            (["pre-chorus": ({ "lyric", "chorus lyric", "instrumental rhythm" })]),
            (["chorus 2": ({ "lyric", "chorus lyric", "instrumental rhythm" })]),
            (["bridge": ({ "lyric", "instrumental rhythm" })]),
            (["breakdown": ({ "lyric", "instrumental rhythm" })]),
            (["chorus 3": ({ "lyric", "chorus lyric", "instrumental rhythm" })]),
            (["outro": ({ "instrumental rhythm", "instrumental solo" })]),
        }));   

        addSpecification("event handler", "verseChorusEvent");
    }
}
