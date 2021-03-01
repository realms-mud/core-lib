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
        addSpecification("name", "ABABCB (Verse/Chorus/Bridge/Solo)");
        addSpecification("source", "bard");
        addSpecification("description", "This research provides the user with the "
            "knowledge of how to create songs structured as an intro, a pair of "
            "verse/chorus sections, a bridge, a solo, a chorus, and an outro.");

        addSpecification("research type", "points");
        addSpecification("research cost", 1);
        addSpecification("spell point cost", 25);
        addSpecification("stamina point cost", 25);

        addSpecification("segments", ({ "intro", "verse 1", "chorus 1", "verse 2",
            "chorus 2", "bridge", "solo", "chorus 3", "outro" }));
        addSpecification("event handler", "verseChorusEvent");
    }
}
