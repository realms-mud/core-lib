//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Panther Form");
    addSpecification("source", "therianthrope");
    addSpecification("description", "This research provides the knowledge to "
        "transform yourself into a sleek panther. While in this form, you gain "
        "blinding speed and lethal precision but sacrifice the use of weapons.");

    addSpecification("research type", "tree root");
    addSpecification("scope", "self");

    addSpecification("spell point cost", 50);
    addSpecification("stamina point cost", 75);

    addSpecification("bonus dexterity", 1);
    addSpecification("bonus attack", 2);
    addSpecification("bonus dodge", 2);
    addSpecification("penalty to constitution", 2);
    addSpecification("penalty to charisma", 2);
    addSpecification("remove weapon attacks", 1);
    addSpecification("bonus claw attack", 10);
    addSpecification("bonus claw attack", 10);
    addSpecification("bonus teeth attack", 12);

    addSpecification("trait",
        "/guilds/therianthrope/panther/panther-form-active.c");

    addSpecification("command template", "panther form");
    addSpecification("use ability activate message", "##InitiatorName## "
        "##Infinitive::drop## low as ##InitiatorPossessive## body stretches "
        "and reshapes into the lithe form of a panther! Midnight-dark fur "
        "ripples across ##InitiatorPossessive## sleek frame.");
    addSpecification("use ability deactivate message", "The feline grace "
        "fades as ##InitiatorName## ##Infinitive::rise## back into "
        "##InitiatorPossessive## humanoid form.");
}
