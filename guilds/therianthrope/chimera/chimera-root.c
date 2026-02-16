//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Chimera Form");
    addSpecification("source", "therianthrope");
    addSpecification("description", "This research provides the knowledge to "
        "transform yourself into a fearsome chimera. While in this form, you "
        "gain savage claws and fiery breath but sacrifice the use of "
        "weapons.");

    addSpecification("research type", "tree root");
    addSpecification("scope", "self");

    addSpecification("spell point cost", 50);
    addSpecification("stamina point cost", 75);

    addSpecification("bonus strength", 1);
    addSpecification("bonus constitution", 1);
    addSpecification("bonus soak", 1);
    addSpecification("bonus damage", 1);
    addSpecification("penalty to dexterity", 2);
    addSpecification("penalty to charisma", 2);
    addSpecification("remove weapon attacks", 1);
    addSpecification("bonus claw attack", 12);
    addSpecification("bonus teeth attack", 10);

    addSpecification("trait",
        "/guilds/therianthrope/chimera/chimera-form-active.c");

    addSpecification("command template", "chimera form");
    addSpecification("use ability activate message", "##InitiatorName## "
        "##Infinitive::roar## as ##InitiatorPossessive## body swells and "
        "twists into the monstrous form of a chimera! A mane of coarse "
        "fur erupts along ##InitiatorPossessive## spine while curved "
        "horns sprout from ##InitiatorPossessive## brow.");
    addSpecification("use ability deactivate message", "The chimeric fury "
        "subsides as ##InitiatorName## ##Infinitive::collapse## back into "
        "##InitiatorPossessive## humanoid form.");
}
