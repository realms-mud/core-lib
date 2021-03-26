//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        knowledgeResearchItem::reset(arg);
        addSpecification("name", "Chromatic Movement");
        addSpecification("source", "bard");
        addSpecification("description", "This research increases the "
            "effectiveness of the various soloing techniques.");

        addSpecification("limited by", ([
            "equipment": ({ "instrument: plucked", "instrument: bowed" }) ]));

        addPrerequisite("level", ([  
            "type":"level",
            "guild": "bard",
            "value": 71
        ]));

        addPrerequisite("guilds/bard/strings/mixed-mode-playing.c",
            (["type":"research"]));

        addSpecification("research type", "points");
        addSpecification("research cost", 1);
        addSpecification("affected research", ([
            "Elegy of Energy": 25,
            "Enchanting Ostinato": 25,
            "Tune of Temerity": 25,
            "Sanguine Solo": 25,
        ]));
        addSpecification("affected research type", "percentage");
    }
}
