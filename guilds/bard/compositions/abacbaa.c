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

        addSpecification("segments", ({ "chorus 1", "instrumental", "verse 1", 
            "pre-chorus", "chorus 2", "bridge", "breakdown", "chorus 3", "outro" }));
        addSpecification("event handler", "verseChorusEvent");
    }
}
