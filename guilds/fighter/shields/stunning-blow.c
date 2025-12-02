//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Stunning Blow");
    addSpecification("source", "fighter");

    addSpecification("description", "This skill provides the user with the "
        "knowledge of a shield-striking technique that knocks their foe "
        "off balance and prevents them from attacking until they recover.");

    addPrerequisite("level", 
        (["type": "level", 
          "guild": "fighter",
          "value": 5 ]));

    addSpecification("limited by", (["equipment":({ "shield" })]));

    addPrerequisite("/guilds/fighter/shields/root.c",
        (["type":"research"]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 20);

    addSpecification("stamina point cost", 25);

    addSpecification("apply paralysis", 1);
    addSpecification("duration", 4);

    addSpecification("event handler", "stunningBlowEvent");
    addSpecification("command template", "stunning blow [at ##Target##]");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::slam## ##InitiatorPossessive## shield into ##TargetName## "
        "in an attempt to stun.");
}
