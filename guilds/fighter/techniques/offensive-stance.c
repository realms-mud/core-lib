//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Offensive Stance");
    addSpecification("source", "fighter");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of how to move into an aggressive, attacking stance. "
        "While in this stance, the fighter will sacrifice defense for "
        "offense.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "fighter",
            "value": 1
        ]));
    addPrerequisite("/guilds/fighter/techniques/root.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 4);
    addSpecification("stamina point cost", 25);
    addSpecification("command template", "offensive stance");
    addSpecification("trait", 
        "/guilds/fighter/techniques/traits/offensive-stance-trait.c");

    addSpecification("event handler", "offensiveStanceEvent");
    addSpecification("use ability activate message", "##InitiatorName## "
        "##Infinitive::take## an offensive stance, poising "
        "##InitiatorPossessive## ##InitiatorWeapon## to aggressively attacks.");
    addSpecification("use ability deactivate message", "##InitiatorName## "
        "##Infinitive::be## no longer in an offensive stance.");
}
