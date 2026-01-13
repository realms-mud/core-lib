//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Sanctum of Flame");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of maintaining a sanctum of sacred fire that provides "
        "continuous healing and protection to all nearby allies.");
    addSpecification("usage summary", "Sustained area healing aura");

    addPrerequisite("/guilds/disciple-of-ferianth/purifying-flames/holy-pyre.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 43
        ]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 75);

    addSpecification("bonus heal hit points rate", 4);
    addSpecification("bonus defense", 4);
    addSpecification("bonus resist fire", 10);

    addSpecification("cooldown", 30);
    addSpecification("command template", "sanctum of flame");

    addSpecification("use ability activate message", "##InitiatorName## "
        "##Infinitive::create## a sanctum of sacred flame! Healing fire "
        "radiates outward, protecting all allies.");
    addSpecification("use ability deactivate message", "##InitiatorName##'s "
        "sanctum of flame dissipates.");
}   
