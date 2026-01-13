//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Warmth");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of maintaining an aura of sacred warmth that provides "
        "ongoing protection against cold and minor regeneration.");
    addSpecification("usage summary", "A sustained aura providing cold resist and regen");

    addPrerequisite("/guilds/disciple-of-ferianth/purifying-flames/cauterize.c",
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

    addSpecification("bonus resist cold", 5);
    addSpecification("bonus heal hit points rate", 1);

    addSpecification("cooldown", 10);
    addSpecification("command template", "warmth");

    addSpecification("use ability activate message", "##InitiatorName## "
        "##Infinitive::surround## ##InitiatorReflexive## with an aura of "
        "sacred warmth.");
    addSpecification("use ability deactivate message", "##InitiatorName##'s "
        "aura of sacred warmth fades away.");
}
