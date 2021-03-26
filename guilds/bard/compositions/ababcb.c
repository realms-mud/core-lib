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

        addPrerequisite("level",
            (["type":"level",
                "guild": "bard",
                "value": 11
            ]));
        addPrerequisite("guilds/bard/compositions/abab.c",
            (["type":"research"]));

        addSpecification("research type", "points");
        addSpecification("research cost", 1);
        addSpecification("spell point cost", 50);
        addSpecification("stamina point cost", 50);

        addSpecification("segments", ({
            (["intro": ({ "instrumental rhythm", "instrumental solo" })]),
            (["verse 1": ({ "lyric", "instrumental rhythm" })]),
            (["chorus 1": ({ "lyric", "chorus lyric", "instrumental rhythm" })]),
            (["verse 2": ({ "lyric", "instrumental rhythm" })]),
            (["chorus 2": ({ "lyric", "chorus lyric", "instrumental rhythm" })]),
            (["bridge": ({ "lyric", "instrumental rhythm" })]),
            (["solo": ({ "instrumental solo" })]),
            (["chorus 3": ({ "lyric", "chorus lyric", "instrumental rhythm" })]),
            (["outro": ({ "instrumental rhythm", "instrumental solo" })]),
        }));   
        addSpecification("event handler", "ABABCBEvent");

        addSpecification("affected research", ([
            "Riff of Report": 10,
            "Coronach of Capitulation": 10,
            "Requiem of Release": 10,
            "Dirge of the Damned": 10,
            "Raena's Rhythm": 10,
        ]));
        addSpecification("affected research type", "percentage");
    }
}
