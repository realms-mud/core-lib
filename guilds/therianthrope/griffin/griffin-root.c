//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Griffin Form");
    addSpecification("source", "therianthrope");
    addSpecification("description", "This research provides the knowledge to "
        "transform yourself into a majestic griffin. While in this form, you "
        "gain keen senses and powerful talons but sacrifice the use of "
        "weapons.");

    addSpecification("research type", "tree root");
    addSpecification("scope", "self");

    addSpecification("spell point cost", 50);
    addSpecification("stamina point cost", 75);

    addSpecification("bonus dexterity", 1);
    addSpecification("bonus wisdom", 1);
    addSpecification("bonus dodge", 1);
    addSpecification("bonus attack", 1);
    addSpecification("penalty to constitution", 2);
    addSpecification("penalty to charisma", 2);
    addSpecification("remove weapon attacks", 1);
    addSpecification("bonus talons attack", 12);
    addSpecification("bonus beak attack", 10);

    addSpecification("trait",
        "/guilds/therianthrope/griffin/griffin-form-active.c");

    addSpecification("command template", "griffin form");
    addSpecification("use ability activate message", "##InitiatorName## "
        "##Infinitive::cry## out as enormous wings erupt from "
        "##InitiatorPossessive## back and ##InitiatorPossessive## hands "
        "twist into razor-sharp talons! Golden feathers and tawny fur "
        "spread across ##InitiatorPossessive## transforming body.");
    addSpecification("use ability deactivate message", "The regal power "
        "fades as ##InitiatorName## ##Infinitive::fold## back into "
        "##InitiatorPossessive## humanoid form.");
}
