//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "genetic");
    addSpecification("name", "Hunchback");
    addSpecification("description", "blah blah blah");
    addSpecification("root", "disfigured");
    addSpecification("opposing root", "normal");
    addSpecification("opinion", 10);
    addSpecification("opposing opinion", -10);
    addSpecification("cost", 1);
}
