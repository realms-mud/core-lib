//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Inner Fire");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of stoking their inner fire, granting protection against "
        "cold and fire damage.");
    addSpecification("usage summary", "Sustained resistance to fire and cold");

    addPrerequisite("/guilds/disciple-of-ferianth/ember-arts/flame-sight.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 3
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 20);

    addSpecification("bonus resist fire", 10);
    addSpecification("bonus resist cold", 5);

    addSpecification("cooldown", 10);
    addSpecification("command template", "inner fire");

    addSpecification("use ability activate message", "##InitiatorName## "
        "##Infinitive::stoke## ##InitiatorPossessive## inner fire, and warmth "
        "spreads through ##InitiatorPossessive## body.");
    addSpecification("use ability deactivate message", "##InitiatorName##'s "
        "inner fire cools.");
}
