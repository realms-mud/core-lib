//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "educational");
    addSpecification("name", "theologian");
    addSpecification("description", "You have spent a great deal of time in study of the ways of the gods.");
    addSpecification("root", "educated");
    addSpecification("opposing root", "uneducated");
    addSpecification("opinion", 5);
    addSpecification("opposing opinion", 10);
    addSpecification("bonus ancient history", 1);
    addSpecification("bonus local history", 1);
    addSpecification("bonus astronomy", 1);
    addSpecification("bonus persuasion", 5);
    addSpecification("bonus linguistics", 1);
    addSpecification("bonus philosophy", 3);
    addSpecification("bonus reading", 2);
    addSpecification("bonus writing", 2);
    addSpecification("bonus theology", 5);
    addSpecification("cost", 1);
}
