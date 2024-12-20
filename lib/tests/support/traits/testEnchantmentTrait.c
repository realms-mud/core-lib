//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "health");
    addSpecification("name", "Stuff");
    addSpecification("description", "blah blah blah");
    addSpecification("root", "disfigured");
    addSpecification("opposing root", "normal");
    addSpecification("opinion", 10);
    addSpecification("opposing opinion", -10);
    addSpecification("cost", 1);
    addSpecification("bonus fire enchantment", 2);
    addSpecification("bonus electricity enchantment", 5);
    addSpecification("bonus magical enchantment", 1);
}
