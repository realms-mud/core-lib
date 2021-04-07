//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "genetic");
    addSpecification("name", "wise");
    addSpecification("description", "You have knowledge and good judement to spare.");
    addSpecification("root", "wise");
    addSpecification("opposing root", "foolish");
    addSpecification("opinion", 10);
    addSpecification("bonus wisdom", 2);
    addSpecification("bonus spot", 2);
    addSpecification("bonus search", 2);
    addSpecification("cost", 1);
}
