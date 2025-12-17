//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Ethereal Shroud");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This skill provides the user with an "
        "ethereal shroud that partially exists in the dream realm, granting "
        "significant defensive benefits.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "oneiromancer",
          "value": 25 ]));

    addPrerequisite("/guilds/oneiromancer/nightmare-persona/phantom-form.c",
        (["type":"research"]));

    addSpecification("limited by", (["research active":
        "/guilds/oneiromancer/nightmare-persona/persona-root.c"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus defense", 8);
    addSpecification("bonus soak", 3);
    addSpecification("bonus resist psionic", 10);
}
