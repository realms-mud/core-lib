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
        addSpecification("name", "Call of the Cats");
        addSpecification("source", "bard");
        addSpecification("description", "This research attunes the "
            "'The Wailing Cat' research to "
            "bring forth only the mightiest of animals.");

        addSpecification("limited by", ([
            "equipment": ({ "instrument: woodwind", "instrument: brass" }) ]));

        addPrerequisite("level", ([  
            "type":"level",
            "guild": "bard",
            "value": 19
        ]));

        addPrerequisite("guilds/bard/woodwind-brass/creatures-of-might.c",
            (["type":"research"]));

        addSpecification("research type", "points");
        addSpecification("research cost", 1);
        addSpecification("related research", ({
            "guilds/bard/woodwind-brass/the-wailing-cat.c",
        }));
    }
}
