//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Heat Aura");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of radiating an aura of intense heat that provides "
        "protection and damages nearby enemies.");
    addSpecification("usage summary", "Sustained aura with defense and damage reflection");

    addPrerequisite("/guilds/disciple-of-ferianth/ember-arts/fire-shield.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 11
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 35);

    addSpecification("bonus defense", 2);
    addSpecification("bonus resist fire", 15);
    addSpecification("apply damage reflection", 8);

    addSpecification("cooldown", 15);
    addSpecification("command template", "heat aura");

    addSpecification("use ability activate message", "##InitiatorName## "
        "##Infinitive::radiate## an intense heat aura! The air shimmers "
        "around ##InitiatorObjective##.");
    addSpecification("use ability deactivate message", "##InitiatorName##'s "
        "heat aura dissipates.");
}
