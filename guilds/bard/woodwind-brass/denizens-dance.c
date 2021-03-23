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
        addSpecification("name", "Denizen's Dance");
        addSpecification("source", "bard");
        addSpecification("description", "This research attunes the "
            "'Creatures of the Forest' and 'The Wailing Cat' research to "
            "bring forth only the mightiest of animals.");

        addSpecification("limited by", ([
            "equipment": ({ "instrument: woodwind", "instrument: brass" }) ]));

        addPrerequisite("level", ([  
            "type":"level",
            "guild": "bard",
            "value": 23
        ]));

        addPrerequisite("guilds/bard/woodwind-brass/creatures-of-might.c",
            (["type":"research"]));

        addSpecification("research type", "points");
        addSpecification("research cost", 1);
        addSpecification("related research", ({
            "guilds/bard/woodwind-brass/creatures-of-the-forest.c",
            "guilds/bard/woodwind-brass/the-wailing-cat.c",
            "guilds/bard/woodwind-brass/ballad-of-the-bear.c",
        }));
    }
}
