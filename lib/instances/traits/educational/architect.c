//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "educational");
    addSpecification("name", "architect");
    addSpecification("description", "You have an innate skill in the design and construction of 'things' - be they mechanical contraptions or buildings.");
    addSpecification("root", "educated");
    addSpecification("opposing root", "uneducated");
    addSpecification("opinion", 5);
    addSpecification("bonus carpentry", 2);
    addSpecification("bonus stonemasonry", 2);
    addSpecification("bonus ancient history", 1);
    addSpecification("bonus astronomy", 1);
    addSpecification("bonus engineering", 5);
    addSpecification("bonus geology", 1);
    addSpecification("bonus local history", 1);
    addSpecification("bonus mathematics", 3);
    addSpecification("bonus physics", 2);
    addSpecification("bonus reading", 1);
    addSpecification("bonus writing", 1);
    addSpecification("cost", 1);
}
