//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "educational");
    addSpecification("name", "poor fighter");
    addSpecification("description", "You have spent a great deal of time training in the martial arts. Unfortunately, you're terrible at them.");
    addSpecification("root", "educated");
    addSpecification("opposing root", "uneducated");
    addSpecification("opinion", 5);
    addSpecification("bonus shield", 1);
    addSpecification("bonus axe", 1);
    addSpecification("bonus long sword", 1);
    addSpecification("bonus short sword", 1);
    addSpecification("bonus pole arm", 1);
    addSpecification("bonus mace", 1);
    addSpecification("bonus flail", 1);
    addSpecification("bonus bow", 1);
    addSpecification("bonus crossbow", 1);
    addSpecification("bonus hammer", 1);
    addSpecification("penalty to parry", 1);
    addSpecification("penalty to attack", 5);
    addSpecification("penalty to defense", 5);
    addSpecification("penalty to damage", 1);
    addSpecification("cost", -1);
}
