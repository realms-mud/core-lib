//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "health");
    addSpecification("name", "sickly");
    addSpecification("description", "You are prone to diseases and have a below-normal constitution.");
    addSpecification("root", "sickly");
    addSpecification("opposing root", "hale");
    addSpecification("opinion", -5);
    addSpecification("penalty to constitution", 2);
    addSpecification("penalty to heal hit points", 1);
    addSpecification("penalty to heal hit points rate", 30);
    addSpecification("cost", -1);
}
