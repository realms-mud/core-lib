//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "genetic");
    addSpecification("name", "keen");
    addSpecification("description", "You are extremely astute.");
    addSpecification("root", "wise");
    addSpecification("opposing root", "foolish");
    addSpecification("opinion", 10);
    addSpecification("bonus wisdom", 1);
    addSpecification("bonus intelligence", 1);
    addSpecification("cost", 1);
}
