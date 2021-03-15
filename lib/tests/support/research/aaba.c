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
        addSpecification("name", "AABA (Verse, Verse, Bridge, Verse)");
        addSpecification("source", "blarg");
        addSpecification("description", "This research provides the user with the "
            "knowledge of how to create songs structured as two verses, a bridge, "
            "and a final verse.");

        addSpecification("research type", "points");
        addSpecification("research cost", 1);
        addSpecification("spell point cost", 25);
        addSpecification("stamina point cost", 25);

        addSpecification("segments", ({ 
            (["verse 1": ({ "lyric", "instrumental rhythm" }) ]),
            (["verse 2": ({ "lyric", "instrumental rhythm" }) ]),
            (["bridge": ({ "lyric", "instrumental rhythm", "instrumental solo" }) ]),
            (["verse 3": ({ "lyric", "instrumental rhythm" }) ])
        }));            
        addSpecification("event handler", "aabaEvent");
    }
}
