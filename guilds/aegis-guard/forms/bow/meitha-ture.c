//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Meitha Ture");
    addSpecification("source", "Aegis Guard");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of an extremely meticulous means of aiming one's bow. "
        "While this is in effect, you cannot attack, but your archery "
        "skills will receive a large bonus dependent on how long you have "
        "taken to aim.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "Aegis Guard",
            "value": 5
        ]));
    addPrerequisite("/guilds/aegis-guard/forms/bow/bregol-adleg.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 4);
    addSpecification("stamina point cost", 50);
    addSpecification("command template", "meitha ture");
    addSpecification("trait", "/guilds/aegis-guard/forms/bow/aim-trait.c");

    addSpecification("use ability activate message", "##InitiatorName## "
        "##Infinitive::take## a stance of carefully aiming "
        "##InitiatorPossessive## ##InitiatorWeapon##.");
    addSpecification("use ability deactivate message", "##InitiatorName## "
        "##Infinitive::be## no longer carefully aiming "
        "##InitiatorPossessive## ##InitiatorWeapon##.");
}
