//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "educational");
    addSpecification("name", "botanist");
    addSpecification("description", "You have a deep knowledge of plants and how to use and manipulate them.");
    addSpecification("root", "educated");
    addSpecification("opposing root", "uneducated");
    addSpecification("opinion", 5);
    addSpecification("opposing opinion", 5);
    addSpecification("bonus search", 1);
    addSpecification("bonus spot", 1);
    addSpecification("bonus agriculture", 5);
    addSpecification("bonus plant", 1);
    addSpecification("bonus cooking", 2);
    addSpecification("bonus camp skills", 1);
    addSpecification("bonus herbalism", 5);
    addSpecification("cost", 1);
}
