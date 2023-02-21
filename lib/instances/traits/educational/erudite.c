//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "educational");
    addSpecification("name", "erudite");
    addSpecification("description", "You have spent a great deal of time in study - to the detriment of other activities. You're book-smart but sometimes lack common sense.");
    addSpecification("root", "educated");
    addSpecification("opposing root", "uneducated");
    addSpecification("opinion", 10);
    addSpecification("bonus intelligence", 2);
    addSpecification("bonus ancient history", 2);
    addSpecification("bonus local history", 2);
    addSpecification("bonus astronomy", 2);
    addSpecification("bonus chemistry", 2);
    addSpecification("bonus engineering", 2);
    addSpecification("bonus geology", 2);
    addSpecification("bonus mathematics", 2);
    addSpecification("bonus linguistics", 2);
    addSpecification("bonus philosophy", 2);
    addSpecification("bonus physics", 2);
    addSpecification("bonus reading", 2);
    addSpecification("bonus writing", 2);
    addSpecification("penalty to dual wield", 1);
    addSpecification("penalty to shield", 1);
    addSpecification("penalty to axe", 1);
    addSpecification("penalty to long sword", 1);
    addSpecification("penalty to hand and a half sword", 1);
    addSpecification("penalty to short sword", 1);
    addSpecification("penalty to hammer", 1);
    addSpecification("penalty to bow", 1);
    addSpecification("penalty to crossbow", 1);
    addSpecification("penalty to two-handed sword", 1);
    addSpecification("penalty to pole arm", 1);
    addSpecification("penalty to mace", 1);
    addSpecification("penalty to flail", 1);
    addSpecification("cost", 1);
}
