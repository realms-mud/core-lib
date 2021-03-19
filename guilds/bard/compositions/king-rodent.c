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
        addSpecification("name", "King Rodent");
        addSpecification("source", "bard");
        addSpecification("description", "This research attunes the "
            "'A Rat's Serenade' research to bring forth king-sized "
            "rats.");

        addPrerequisite("level", ([  
            "type":"level",
            "guild": "bard",
            "value": 10
        ]));

        addPrerequisite("guilds/bard/compositions/rous.c",
            (["type":"research"]));

        addSpecification("research type", "points");
        addSpecification("research cost", 1);
        addSpecification("related research", ({
            "guilds/bard/compositions/a-rats-serenade.c" }));
    }
}
