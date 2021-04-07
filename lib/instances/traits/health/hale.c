//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "health");
    addSpecification("name", "hale");
    addSpecification("description", "You have an above normal constitution.");
    addSpecification("root", "hale");
    addSpecification("opposing root", "sickly");
    addSpecification("opinion", 5);
    addSpecification("bonus constitution", 2);
    addSpecification("bonus heal hit points", 1);
    addSpecification("cost", 1);
}
