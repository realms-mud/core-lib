//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "educational");
    addSpecification("name", "poetic");
    addSpecification("description", "You have a way with words and can make even the most droll conversation seem like a work of art.");
    addSpecification("root", "educated");
    addSpecification("opposing root", "uneducated");
    addSpecification("opinion", 25);
    addSpecification("opposing opinion", 10);
    addSpecification("bonus charisma", 1);
    addSpecification("bonus ancient history", 2);
    addSpecification("bonus local history", 2);
    addSpecification("bonus linguistics", 2);
    addSpecification("bonus philosophy", 2);
    addSpecification("bonus singing", 2);
    addSpecification("bonus etiquette", 1);
    addSpecification("bonus persuasion", 1);
    addSpecification("bonus diplomacy", 1);
    addSpecification("bonus reading", 2);
    addSpecification("bonus writing", 2);
    addSpecification("bonus perception", 1);
    addSpecification("cost", 1);
}
