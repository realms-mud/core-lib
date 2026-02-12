//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Bear Form");
    addSpecification("source", "therianthrope");
    addSpecification("description", "This research provides the knowledge to "
        "transform yourself into a massive bear. While in this form, you gain "
        "tremendous strength and resilience but sacrifice the use of weapons.");

    addSpecification("research type", "tree root");
    addSpecification("scope", "self");

    addSpecification("spell point cost", 50);
    addSpecification("stamina point cost", 75);

    addSpecification("bonus strength", 1);
    addSpecification("bonus constitution", 1);
    addSpecification("bonus soak", 2);
    addSpecification("bonus damage", 2);
    addSpecification("penalty to dexterity", 2);
    addSpecification("penalty to charisma", 2);
    addSpecification("remove weapon attacks", 1);
    addSpecification("bonus claw attack", 12);
    addSpecification("bonus claw attack", 12);
    addSpecification("bonus teeth attack", 15);

    addSpecification("trait",
        "/guilds/therianthrope/bear/bear-form-active.c");

    addSpecification("command template", "bear form");
    addSpecification("use ability activate message", "Bones crack and muscles "
        "swell as ##InitiatorName## ##Infinitive::transform## into a massive "
        "bear! Thick fur sprouts across ##InitiatorPossessive## body as "
        "##InitiatorSubjective## ##Infinitive::rise## on powerful hind legs.");
    addSpecification("use ability deactivate message", "The bestial power "
        "recedes as ##InitiatorName## ##Infinitive::shrink## back into "
        "##InitiatorPossessive## humanoid form.");
}
