//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "educational");
    addSpecification("name", "thespian");
    addSpecification("description", "You are an actor and a musician, capable of moving even the most dour of audiences.");
    addSpecification("root", "educated");
    addSpecification("opposing root", "uneducated");
    addSpecification("opinion", 10);
    addSpecification("opposing opinion", 20);
    addSpecification("bonus charisma", 2);
    addSpecification("bonus ancient history", 1);
    addSpecification("bonus local history", 1);
    addSpecification("bonus dancing", 1);
    addSpecification("bonus instrument: plucked", 1);
    addSpecification("bonus instrument: bowed", 1);
    addSpecification("bonus instrument: woodwind", 1);
    addSpecification("bonus instrument: brass", 1);
    addSpecification("bonus instrument: percussion", 1);
    addSpecification("bonus singing", 1);
    addSpecification("bonus dancing", 1);
    addSpecification("bonus dancing", 1);
    addSpecification("bonus persuasion", 3);
    addSpecification("bonus linguistics", 3);
    addSpecification("bonus philosophy", 2);
    addSpecification("bonus reading", 2);
    addSpecification("bonus writing", 2);
    addSpecification("cost", 2);
}
