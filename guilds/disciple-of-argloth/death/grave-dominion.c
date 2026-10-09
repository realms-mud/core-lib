//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Grave Dominion");
    addSpecification("source", "Disciple of Argloth");
    addSpecification("description", "This research grants the Disciple dominion over the grave itself - a passive command over death energy in all its forms.");

    addPrerequisite("/guilds/disciple-of-argloth/necromancy/death-mastery.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
          "guild": "Disciple of Argloth",
          "value": 55
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus body", 7);
    addSpecification("bonus magical essence", 4);
    addSpecification("bonus armor class", 4);
}
