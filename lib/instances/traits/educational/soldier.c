//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "educational");
    addSpecification("name", "soldier");
    addSpecification("description", "You have spent a great deal of time training in the martial arts.");
    addSpecification("root", "educated");
    addSpecification("opposing root", "uneducated");
    addSpecification("opinion", 5);
    addSpecification("bonus parry", 1);
    addSpecification("bonus dodge", 1);
    addSpecification("bonus shield", 1);
    addSpecification("bonus chainmail", 1);
    addSpecification("bonus hard leather", 1);
    addSpecification("bonus axe", 2);
    addSpecification("bonus long sword", 2);
    addSpecification("bonus short sword", 2);
    addSpecification("bonus pole arm", 2);
    addSpecification("bonus mace", 2);
    addSpecification("bonus flail", 1);
    addSpecification("bonus bow", 2);
    addSpecification("bonus crossbow", 2);
    addSpecification("bonus hammer", 2);
    addSpecification("cost", 1);
}
