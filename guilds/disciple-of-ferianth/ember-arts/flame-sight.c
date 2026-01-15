//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Flame Sight");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of imbuing their eyes with sacred fire, granting enhanced "
        "perception and the ability to see in darkness.");
    addSpecification("usage summary", "Sustained ability granting enhanced vision");

    addPrerequisite("/guilds/disciple-of-ferianth/ember-arts/ember-arts-root.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 1
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 25);

    addSpecification("bonus perception", 10);
    addSpecification("bonus spot", 10);

    addSpecification("cooldown", 10);
    addSpecification("command template", "flame sight");

    addSpecification("use ability activate message", "##InitiatorName##'s "
        "eyes flicker with an inner flame, granting ##InitiatorObjective## "
        "enhanced sight.");
    addSpecification("use ability deactivate message", "The flame in "
        "##InitiatorName##'s eyes fades.");
}
