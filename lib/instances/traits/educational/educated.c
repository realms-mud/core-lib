//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "educational");
    addSpecification("name", "educated");
    addSpecification("description", "You have spent a great deal of time in study.");
    addSpecification("root", "educated");
    addSpecification("opposing root", "uneducated");
    addSpecification("opinion", 10);
    addSpecification("bonus intelligence", 1);
    addSpecification("bonus ancient history", 2);
    addSpecification("bonus local history", 2);
    addSpecification("bonus astronomy", 1);
    addSpecification("bonus chemistry", 1);
    addSpecification("bonus engineering", 1);
    addSpecification("bonus geology", 1);
    addSpecification("bonus mathematics", 2);
    addSpecification("bonus linguistics", 2);
    addSpecification("bonus philosophy", 1);
    addSpecification("bonus physics", 1);
    addSpecification("bonus reading", 2);
    addSpecification("bonus writing", 2);
    addSpecification("cost", 1);
}
